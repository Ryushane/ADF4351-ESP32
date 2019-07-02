# ADF4351 controlled with ESP32

This repository contains drivers for ADF4351 and a ESP32 example.

## Usage

- Follow the ADF4351example.ino, first instantiate a ADF4351 object.

> ADF4351 adf4351(clock,data,LE,CE); *// declares object PLL of type ADF4351*

- Then use **adf4351.begin();** to initialize the adf4351 object, including setting the pinMode and the initial state of four pins(SCLK, DATA, LE, CE)
- Finally load the data into corresponding registers, then ADF4351 will work.

## Connection

![ADF4351-ESP32-Connection](D:\Desktop\ADF4351-ESP32\assets\ADF4351-ESP32-Connection.jpg)

- There are five lines to connect.

  | ESP32                                        | ADS4351 | Description         |
  | :------------------------------------------- | :-----: | :------------------ |
  | GND                                          |   GND   | Ground              |
  | VSCK/HSCK                                    |   CLK   | SPI Clock           |
  | MOSI                                         |  DATA   | Master Out Slave In |
  | SS                                           |   LE    | Load Enable         |
  | Any GPIO pin and set to OUTPUT mode and HIGH |   CE    | Chip Enable         |

## Frequency Calculation

Using ADI ADF4351 Evaluation Board Software, we can conveniently calculate the registers.

https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/eval-adf4351.html#eb-overview



![1562062983662](D:\Desktop\ADF4351example\assets\1562062983662.png)

- Then just fill in the registers on given example.

![1562062997772](D:\Desktop\ADF4351example\assets\1562062997772.png)

