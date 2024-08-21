#include "audio_driver.h"
#include "bflb_gpio.h"
#include "bl616_glb.h"
#include "board.h"
#include "log.h"

static struct bflb_device_s *audio_dma_hd;
static struct bflb_device_s *audio_hd;
static struct bflb_dma_channel_lli_pool_s audio_lli_pool[10];

static const uint16_t audio_sine_wave[32] = {
    /* 32-point sine wave at 0dB */
    0x0000, 0x18F8, 0x30FB, 0x471C, 0x5A81, 0x6A6C, 0x7640, 0x7D89, 0x7FFF, 0x7D89, 0x7640, 0x6A6C, 0x5A81, 0x471C, 0x30FB, 0x18F8,
    0x0000, 0xE708, 0xCF05, 0xB8E4, 0xA57F, 0x9594, 0x89C0, 0x8277, 0x8001, 0x8277, 0x89C0, 0x9594, 0xA57F, 0xB8E4, 0xCF05, 0xE708,
};

static void audio_dma_callback(void *arg)
{
    static uint16_t num = 0;
    num++;
    LOG_I("Audio DMA cycle %d\r\n", num);
}

void audio_gpio_init(void)
{
    struct bflb_device_s *gpio = bflb_device_get_by_name("gpio");

    /* Audio PWM output mode */
    bflb_gpio_init(gpio, GPIO_PIN_14, GPIO_FUNC_AUDAC_PWM | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_2);
    bflb_gpio_init(gpio, GPIO_PIN_15, GPIO_FUNC_AUDAC_PWM | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_2);

    /* PA enable */
    bflb_gpio_init(gpio, GPIO_PIN_10, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(gpio, GPIO_PIN_11, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_set(gpio, GPIO_PIN_10);
    bflb_gpio_set(gpio, GPIO_PIN_11);
}

void audio_driver_init(void)
{
    struct bflb_audac_init_config_s audac_init_cfg = {
        .sampling_rate = AUDIO_SAMPLE_RATE,
        .output_mode = AUDAC_OUTPUT_MODE_PWM,
        .source_channels_num = AUDIO_CHANNEL_NUM,
        .mixer_mode = AUDAC_MIXER_MODE_ONLY_L,
        .data_format = AUDIO_DATA_FORMAT,
        .fifo_threshold = AUDIO_FIFO_THRESHOLD,
    };

    struct bflb_audac_volume_config_s audac_volume_cfg = {
        .mute_ramp_en = true,
        .mute_up_ramp_rate = AUDAC_RAMP_RATE_FS_32,
        .mute_down_ramp_rate = AUDAC_RAMP_RATE_FS_8,
        .volume_update_mode = AUDAC_VOLUME_UPDATE_MODE_RAMP,
        .volume_ramp_rate = AUDAC_RAMP_RATE_FS_128,
        .volume_zero_cross_timeout = AUDAC_RAMP_RATE_FS_128,
    };

    /* Clock configuration */
    GLB_Config_AUDIO_PLL_To_491P52M();
    GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_AUDIO);

    /* Audio DAC initialization */
    audio_hd = bflb_device_get_by_name("audac");
    bflb_audac_init(audio_hd, &audac_init_cfg);
    bflb_audac_feature_control(audio_hd, AUDAC_CMD_SET_VOLUME_VAL, (size_t)(-15 * 2));
    bflb_audac_volume_init(audio_hd, &audac_volume_cfg);

    /* Audio DMA initialization */
    audio_dma_hd = bflb_device_get_by_name("dma0_ch0");
    bflb_dma_channel_init(audio_dma_hd, &(struct bflb_dma_channel_config_s){
        .direction = DMA_MEMORY_TO_PERIPH,
        .src_req = DMA_REQUEST_NONE,
        .dst_req = DMA_REQUEST_AUDAC_TX,
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,
        .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE,
        .src_burst_count = DMA_BURST_INCR8,
        .dst_burst_count = DMA_BURST_INCR8,
        .src_width = DMA_DATA_WIDTH_16BIT,
        .dst_width = DMA_DATA_WIDTH_16BIT,
    });
    bflb_dma_channel_irq_attach(audio_dma_hd, audio_dma_callback, NULL);

    /* Load sine wave data into DMA */
    struct bflb_dma_channel_lli_transfer_s transfers[1] = {
        {
            .src_addr = (uint32_t)audio_sine_wave,
            .dst_addr = (uint32_t)DMA_ADDR_AUDAC_TDR,
            .nbytes = sizeof(audio_sine_wave),
        },
    };
    uint32_t dma_lli_cnt = bflb_dma_channel_lli_reload(audio_dma_hd, audio_lli_pool, 10, transfers, 1);
    bflb_dma_channel_lli_link_head(audio_dma_hd, audio_lli_pool, dma_lli_cnt);

    audio_gpio_init();
}

void audio_driver_start(void)
{
    bflb_audac_feature_control(audio_hd, AUDAC_CMD_PLAY_START, 0);
    bflb_dma_channel_start(audio_dma_hd);
}

void audio_driver_stop(void)
{
    bflb_audac_feature_control(audio_hd, AUDAC_CMD_PLAY_STOP, 0);
    bflb_dma_channel_stop(audio_dma_hd);
}

void audio_driver_set_volume(int16_t volume_db)
{
    bflb_audac_feature_control(audio_hd, AUDAC_CMD_SET_VOLUME_VAL, (size_t)(volume_db * 2));
}

void audio_driver_set_mute(bool mute)
{
    bflb_audac_feature_control(audio_hd, AUDAC_CMD_SET_MUTE, mute);
}

void audio_task(void *pvParameters)
{
    audio_driver_init();
    audio_driver_start();

    while (1) {
        audio_driver_set_volume(-35);
        vTaskDelay(pdMS_TO_TICKS(1500));

        audio_driver_set_volume(-15);
        vTaskDelay(pdMS_TO_TICKS(1000));

        audio_driver_set_mute(true);
        vTaskDelay(pdMS_TO_TICKS(1000));

        audio_driver_set_mute(false);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}