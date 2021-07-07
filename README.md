### **BW16 (RTL8720DN) Module - Getting Started with Arduino**
**Revisions**

- **March 3, 2021** - Implemented the recommendation from @moononournation that changes the variant.cpp file to be compatible with the SPI1 pin definition in the SPI.cpp file. This simplifies the sketches that use SPI so that the creation of another SPIClass is not required. So this is a 'major' change for the sketches that use SPI.  A new 'modified variant.cpp can be found in the variant_cpp_mod folder.  I also corrected and updated some comments in the sketches.

- **March 17, 2021** - Slightly updated the RTL8720DN multi function board with additional Power and ground connection holes.  Added a sketch for rtlduino/BW16 board.  The sketch describes the modifications to make the board more useful.

- **March 24, 2021** - Added RTL8720DN/BW16 and rtlduino pinout images supplied by @moononournation.

- **March 28, 2021** - Small corrections, add information on rtlduino modifications and link to @moononournation Instructable to program rtlduino.

- **July 7, 2021** - Include a modified variant.h file in the variant_cpp_mod folder so the AT serial can be used as noted by @flowlow in the issues.

**Background**

- I decided to try the BW16 (RTL8720DN) module because it supports 5GHz WiFi and my 2.4 GHz WiFi band is very busy with old electronics, WiFi security cameras, neighbors networks, microwave oven and many IOT 2.4 GHz only (ESP8266 and ESP32) modules connected. My 2.4 GHz channel can quite often spike over to over 40% utilization whereas my 5GHz channel is less than 10%. I also recommend creating a second WLAN with only a 5 GHz channel.  It should also use a different SSID than the main WLAN.  That way the module can only connect to the 5 GHZ and won't connect to the 2.4 GHz because it has a stronger signal.

- The module I purchased is from Digikey for $4.25 Part number ‎1597-102110419-ND‎, manufactured by Seeed Technology Co., Ltd.  It can be purchased on ebay, AliExpress, and of course the Seed Studio website.

**Getting Started with Arduino and BW16 Module**

- To get started with arduino I used the ambd_arduino package found at https://github.com/ambiot/ambd_arduino/tree/master/Arduino_package.  
- I followed the Arduino IDE installation instructions as outlined in step 2 of the webpage at https://www.amebaiot.com/en/amebad-arduino-getting-started/
- One the package is installed the variant.cpp file needs to be modified to map some of the pins of the BW16 module.  This file can be found at **"C:\Users\your_user\AppData\Local\Arduino15\packages\realtek\hardware\AmebaD\3.0.7\variants\rtl8721d\variant.cpp"**  where "your_user" is the user name of the your windows login.  Version 3.0.7 was the latest version at this time. The modified file can be found in the variant_cpp_mod folder. The modifications made to the variant.cpp file are shown in the 'variant.cpp changes.png file found in the info folder.   The original variant.cpp file will have to be replaced with the modified file every time the package is updated.  I am sure that there is a better way to do this probably by creating a RTL8720DN/BW16 variant. Thanks to @moononournation, pinout pictures for the RTL8720DN and the rtlduino devices that include the Arduino pin numbers defined in the modified variant.cpp file are shown below. Larger images of the pinouts can be found in the Info folder.

<IMG SRC="https://github.com/mikey60/BW16-RTL8720DN-Module-Arduino/blob/main/Info/RTL8720DN_Pinout_Small.png">

<IMG SRC="https://github.com/mikey60/BW16-RTL8720DN-Module-Arduino/blob/main/Info/rtlduino_Pinout_Small.png">


- Many of the example sketches of the repository found in the sketches folder have been modified from the original examples in the Realtek Arduino package. In many cases the pin numbers were changed to work with the BW16 module.  I also modified code to use the hardware SPI channel 1 of the BW16 module.
- I could not figure out how to easily get the BW16 module to work with the FastLED library so I opted to use the APA102/sk9822 LED strips that use both data and clock lines and can be driven with the SPI hardware.
- The Hard way to get started is to attach breadboard interconnect pigtails to all the pins of the BW16 module.  See the Hard_way_to_test pictures in the info folder.
- An easy way to get started is to solder the module to an ESP8266 Serial Wireless WiFi Module Adapter Plate.  These are ones I purchased: <https://www.amazon.com/gp/product/B07WDBLQ7H/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1> The pulldown resistor on pin 10 should be removed.  I did not install the LDO regulator.  I just plugged the module adapter into a solder-less breadboard and supplied +3.3 volts to the VCC pin and ground to the GND pin.  I connected a SPST switch from pin 3 (CHIP_EN) to ground and a second SPST switch from pin 11 (PA7) to ground through a 2K resistor to put the module in download mode like the ESP modules. I then used a USB to 3.3v TTL adapter to connect to TXD (PA7) and RXD (PA8) pins. See the pdf schematic in the 'RTL8720DN multi function board' folder for reference for the connections.   A BW16 product specification can be found in the info folder. A picture of the board with the mounted BW16 module and the labeled pins is shown below.

<IMG SRC="https://github.com/mikey60/BW16-RTL8720DN-Module-Arduino/blob/main/Info/BW16%20on%20ESP-07%20Breakout%20Board.jpg">

- Before downloading you can interact with the BW16 module using pins 15 (PB2/LP_UART_RXD) and pin 16 (PB1/LP_UART_TXD) connected to the USB to 3.3v TTL adapter with AT commands. You can also interact with the Test Command Mode by connecting the USB to 3.3v TTL adapter to the TXD (PA7) and RXD (PA8) pins.  See the txt files in the info folder for brief captures of the interactions.  Note that once the BW16 module is downloaded with an arduino sketch those interfaces are no longer available unless you somehow reload the original firmware.
- **To put the module in the download mode:**

        Press and hold the switch to PA7.
        Press and release the switch to the CHIP_EN pin.
        Release the switch to PA7.  
- A another way to use the BW16 module is to use an ESP8266 Burning Fixture Development Board but that requires some cuts, jumpers and a resistor to work properly.  Then a separate 3.3 volt power supply and USB to 3.3v TTL adapter are not required.
- The 'RTL8720DN multi function board' folder contains all the files for a 'general purpose' PCB that I created using KiCad for the door switch and MQTT Digital LED projects.
- rtlduino module modifications - In my opinion the USB port should be connected to the LOG_TX and LOG_RX pins rather than the AT_TX and AT_RX pins. I don’t believe that many people use the AT port. The first thing I did is cut and jumper the board so the USB port was connected to the LOG port so I could do downloads and terminal interaction with the USB using Arduino. Also I replaced the zero ohm resistor in series with the burn switch with 1.8 Kohm to comply with the >1 Kohm of the ‘GPIO Pull Low Restriction’ of the RTL872xD data sheet. See the 'rtlduino_modifications.pdf' file in the Info folder.  Another way to program the rtlduino can be found at https://www.instructables.com/RTL8720DN/.