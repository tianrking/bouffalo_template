#ifndef AUDIO_DRIVER_H
#define AUDIO_DRIVER_H

#include "bflb_audac.h"
#include "bflb_dma.h"

#define AUDIO_SAMPLE_RATE AUDAC_SAMPLING_RATE_32K
#define AUDIO_CHANNEL_NUM AUDAC_SOURCE_CHANNEL_DUAL
#define AUDIO_DATA_FORMAT AUDAC_DATA_FORMAT_16BIT
#define AUDIO_FIFO_THRESHOLD 7

void audio_driver_init(void);
void audio_driver_start(void);
void audio_driver_stop(void);
void audio_driver_set_volume(int16_t volume_db);
void audio_driver_set_mute(bool mute);
void audio_task(void *pvParameters);
#endif // AUDIO_DRIVER_H