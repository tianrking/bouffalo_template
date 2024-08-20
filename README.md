# gpio_output_with_input

demo test on bl616 AI-M62-32S

## Support CHIP

|      CHIP        | Remark |
|:----------------:|:------:|
|BL602/BL604       |        |
|BL702/BL704/BL706 |        |
|BL702L/BL704L     |        |
|BL616/BL618       |        |
|BL808             |        |

## ENV

git clone  https://github.com/bouffalolab/bouffalo_sdk ~/BL_PATH
pushd ~BL_PATH
git submodule update --init --recursive
popd
export BL_PATH = ~/BL_PATH

make CHIP=bl616 BOARD=bl616dk
make flash CHIP=bl616 COMX=/dev/ttyUSB0

## Compile

- BL602/BL604

```
make CHIP=bl602 BOARD=bl602dk
```

- BL702/BL704/BL706

```
make CHIP=bl702 BOARD=bl702dk
```

- BL702L/BL704L

```
make CHIP=bl702l BOARD=bl702ldk
```

- BL616/BL618

```
make CHIP=bl616 BOARD=bl616dk
```

- BL808

```
make CHIP=bl808 BOARD=bl808dk CPU_ID=m0
make CHIP=bl808 BOARD=bl808dk CPU_ID=d0
```

## Flash

```
make flash CHIP=chip_name COMX=xxx # xxx is your com name
```

## USB Serial
- Windows: It's recommended to use tools that don't automatically control RTS, such as XCOM or VOFA+
- Linux: Cutecom is recommended, which can be installed with:

```bash
sudo apt install cutecom
```