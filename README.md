# Water Filler Controller

An Arduino setup to safely control the filling of water from a reservoir via a solenoid valve and pump.

## COMPONENTS

Arudino Nano

Rotary Encoder with Switch

Green LED ("OKAY!")

Red LED ("ISSUE")

Blue LED ("FILLING")

SSD1306 for a bit more display because why not

//

Solenoid water valve

Water pump

## Nano Pinout

| Pin                | _module_       | _module pin_     | _notes_                   |
| ------------------ | -------------- | ---------------- | ------------------------- |
| **_A0_**           |                |                  |                           |
| **_A1_**           |                |                  |
| **_A2_**           |                |                  |
| **_A3_**           |                |                  |
| **_A4_** - _SDA_   | SSD1306 OLED   | _SDA_            |
| **_A5_** - _SCL_   | SSD1306 OLED   | _SCL_            |
| **_A6_**           |                |                  | \* Exclusively analog pin |
| **_A7_**           |                |                  | \* Exclusively analog pin |
| **_D0_** - _RX0_   | ---USB-COM---  | ---USB-COM---    |                           |
| **_D1_** - _TX1_   | ---USB-COM---  | ---USB-COM---    |
| **_D2_**           | Blue LED       | +                |
| **_D3_**           | Red LED        | +                |
| **_D4_**           | Green LED      | +                |
| **_D5_**           |                |                  |
| **_D6_**           |                |                  |
| **_D7_**           | Rotary Encoder | _Sw_             |
| **_D8_**           | Rotary Encoder | _DT (Output B)_  |                           |
| **_D9_**           | Rotary Encoder | _CLK (Output A)_ |                           |
| **_D10_** _SS_     |                |                  |
| **_D11_** - _MOSI_ |                |                  |
| **_D12_** - _MISO_ |                |                  |
| **_D13_** - _SCK_  |                |                  |
