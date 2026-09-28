# 🔷 Real-Time User-Interactive Wireless Dot-Matrix Display System Using ARM7
---

##  Project Overview

The Real-Time User-Interactive Wireless Dot-Matrix Display System is an ARM7-based embedded system designed to provide wireless control of a 4×8×8 dot-matrix LED display using an Android Bluetooth terminal application.

The system is developed around the LPC2148 ARM7 microcontroller and integrates several peripherals and external devices, including:

 HC-05 Bluetooth module for wireless communication,
 UART0 for serial communication,
 74HC164 shift registers for dot-matrix interfacing,
 SPI EEPROM for non-volatile configuration storage,
 RTC for real-time clock and date information,
 LM35 temperature sensor for temperature measurement,
 ADC for analog temperature acquisition,
 4×8×8 dot-matrix display for visual output.

The user can wirelessly select different display modes, enter custom text, edit RTC information, and display real-time temperature and clock information.

##  1. Project Objectives

The main objective of this project is to develop a wireless and user-interactive real-time display system capable of:

 Receiving commands wirelessly from an Android phone,
  Providing a menu-based Bluetooth user interface,
 Displaying fixed messages,
  Displaying blinking messages,
 Displaying scrolling messages,
 Displaying real-time clock information,
 Displaying RTC information with scrolling,
 Measuring temperature using LM35,
  Displaying temperature on the dot matrix,
  Editing display text through Bluetooth,
 Editing RTC values through Bluetooth,
 Storing configuration information in SPI EEPROM,
 Restoring the saved configuration after power ON,
 Providing responsive real-time user interaction.

##  2. System Architecture

The overall system consists of the following major blocks:


![image alt](https://github.com/akshithavemana/REAL-TIME-USER-INTERACTIVE-WIRELESS-DOT-MATRIX-DISPLAY-SYSTEM/blob/main/Screenshot%202026-09-24%20170110.png)


##  3. Hardware Components

 LPC2148 ARM7 microcontroller,
 HC-05	Wireless Bluetooth communication,
 4×8×8 Dot Matrix Displays,
 74HC164	Serial-to-parallel shift register,
 SPI EEPROM Stores configuration data,
 LM35 Temperature sensing,
 RTC Provides time and date,
 Android Phone User interface,
 Power Supply Provides required power to the system.

##  4. Software Requirements

The firmware is developed using Embedded C.

• Development Tools
• Keil µVision
• Flash Magic
• Embedded C
• Android Bluetooth Terminal Application

##  5. Major Interfaces Used

 UART

UART is used for communication between the LPC2148 and HC-05.

 SPI

SPI is used for communication between the LPC2148 and external EEPROM.

 ADC

ADC is used to convert the analog voltage from the LM35 into a digital value.

 RTC

The LPC2148 internal RTC provides:

Hours,
Minutes,
Seconds,
Date,
Month,
Year,
Day.

 GPIO / Shift Register

GPIO and shift-register signals are used to control the dot-matrix display.

##  6. User Interface

The Android Bluetooth terminal acts as the main user interface.

After connecting the phone to the HC-05, the system displays a menu.

--
      BLUETOOTH DISPLAY MENU
--

1. FIXED STRING
2. FIXED STRING WITH BLINKING
3. STRING WITH SCROLLING
4. TIME DISPLAY
5. RTC DISPLAY WITH SCROLLING
6. TEMPERATURE DISPLAY
7. TEXT EDIT MODE
8. TIME EDIT MODE
9. EXIT


The user selects an option by sending the corresponding number.

##  7. Step-by-Step System Working Process

## Step 1 — Power ON
When the system is powered ON, the LPC2148 starts executing the firmware.

The microcontroller initializes the required hardware peripherals.

## Step 2 — Peripheral Initialization

The LPC2148 initializes:
GPIO
UART0
SPI
RTC
ADC
Dot-matrix interface

The initialization ensures that all hardware modules are ready before the main application starts.

 ## Step 3 — Initialize HC-05 Bluetooth

   The HC-05 Bluetooth module is connected to UART0 of the LPC2148.

The Android phone connects to the HC-05 using a Bluetooth terminal application.

## Step 4 — Initialize SPI EEPROM

The external SPI EEPROM is initialized.

The LPC2148 communicates with the EEPROM using:

SCK
MOSI
MISO
Chip Select

The EEPROM is used for storing configuration information.

## Step 5 — Read Stored Configuration

After initialization, the LPC2148 reads the previously stored configuration from EEPROM.
Because EEPROM is non-volatile, the information can remain stored even after power is removed.

## Step 6 — Display Bluetooth Menu

After initialization, the system sends the menu to the Android Bluetooth terminal.

The user can now select the required operation.

## Step 6 — Display Bluetooth Menu

After initialization, the system sends the menu to the Android Bluetooth terminal.

The user can now select the required operation.

## Step 7 — Receive User Selection

The user selects a menu option.

For example:

1

for fixed-string display.

The data travels through UART interrupts allow the controller to receive data without continuously waiting for incoming characters.

## Step 8 — Execute the Selected Function

The LPC2148 checks the received option and executes the corresponding function.
The system supports multiple operating modes.

##  8. Display Mode 1 — Fixed String

In this mode, a predefined message is displayed on the dot matrix.

Example:

HELP

The LPC2148 obtains the character pattern from the character table and sends the required data to the shift registers.

##  9. Display Mode 2 — Fixed String with Blinking

In this mode, the selected message is displayed with a blinking effect.

The display is periodically switched ON and OFF.

Example:

LUCK

The user sees the message repeatedly appearing and disappearing.

This mode demonstrates timing control and dynamic display operation.

##  10. Display Mode 3 — Scrolling String

This mode is used to display messages longer than the physical display width.

Example:

PROJECT SUCCESSFULLY COMPLETED

The characters are shifted continuously across the dot matrix.
The continuous shifting creates a scrolling effect.

Applications
Digital notice boards
Advertisements
Status messages
Information displays

##  11. Display Mode 4 — Time Display

The LPC2148 internal RTC maintains the current time.

The firmware reads:

Hours
Minutes
Seconds

Example:

12:45:30

The RTC data is converted into character patterns and displayed on the dot matrix.

##  12. Display Mode 5 — RTC Display with Scrolling

This mode displays complete RTC information.

Example:

TIME: 12:45:30
DATE: 28/09/26
DAY: MON

Since this information is longer than the display width, it can be presented as scrolling text.

The RTC continuously provides updated information.

##  13. Display Mode 6 — Temperature Display

The LM35 temperature sensor is connected to an ADC input of the LPC2148.

The LM35 produces an approximately linear voltage proportional to temperature.
 ---          
   10 mV ≈ 1°C
 ---         
   Temperature Acquisition Process
 ---  
Example:

30°C

The ADC value is converted into temperature using the reference voltage and ADC resolution.

General Formula
-----
   Temperature (°C)
    ---
    ADC Value × Vref
----
   ADC Resolution × 10 mV
-----

##  14. Display Mode 7 — Text Edit Mode

Text Edit Mode allows the user to enter a custom message using the Android Bluetooth terminal.

For example, the user can enter:

WELCOME

The microcontroller processes the received characters and displays the message on the dot matrix.

This eliminates the need to modify the firmware every time the display message needs to be changed.

##  15. Display Mode 8 — Time Edit Mode

Time Edit Mode allows the user to update the RTC through Bluetooth.

The user can enter values for:

Seconds
Minutes
Hours
Day
Date
Month
Year

Example format:
---
   SS:MM:HH,
---
   DAY DD/MM/YY
---
Example
30:45:12
MON 28/09/26

The firmware validates the received values before updating the RTC.

##  16. Input Validation

Input validation prevents incorrect values from being written to the RTC.

Valid Ranges
---
   Seconds	: 00–59
   ---
   Minutes	: 00–59
   ---
   Hours	: 00–23
   ---
   Date	: 01–31
   ---
   Month	: 01–12
   ---
   Year	: 00–99
   ---
   Day	: 01–07
---
If invalid data is received, the system rejects the input and sends an appropriate error message.

Example:

INVALID DATA

This demonstrates defensive programming and reliable embedded-system design.

##  17. EEPROM Data Storage

The external SPI EEPROM provides non-volatile storage.

The system can store selected configuration information such as:

Operating mode
Fixed text
Scrolling text
Write Process
Read Process
The stored information is retained even when the system is powered OFF.

##  18. Returning to the Main Menu

A special character is used to stop the current display operation.

!

This provides user control over the running operation.

##  19. Dot-Matrix Display Processing

The dot-matrix display requires appropriate row and column patterns to illuminate the required LEDs.

The LPC2148 sends serial data to the 74HC164 shift registers.           
The firmware continuously updates the required display patterns to produce stable characters.

##  20. 74HC164 Shift Register

The 74HC164 is an 8-bit serial-in/parallel-out shift register.

It receives serial data and shifts the data according to the clock signal.

Main Signals:
---
   Data — serial input
   ---
   Clock — shifts the data
   ---
   Parallel outputs — connected to display control lines
---
In this project, multiple 74HC164 devices are used to provide sufficient outputs for controlling the dot-matrix display.

##  21. UART Interrupt-Based Communication

UART0 is used for communication with the HC-05.

Instead of continuously polling the UART receive register, the system uses a UART receive interrupt.

Advantages
Non-blocking data reception
Better system responsiveness
Efficient CPU utilization
Suitable for real-time applications
Reliable command reception

##  22. SPI EEPROM Communication

The LPC2148 acts as the SPI master and the EEPROM acts as the SPI slave.

SPI Signals:
---
   SCK  → Serial Clock
---
   MOSI → Master Out Slave In
---
   MISO → Master In Slave Out
---
   CS   → Chip Select
---
The EEPROM supports operations such as:

WRITE
READ
WRITE ENABLE
WRITE DISABLE

The firmware uses these operations to store and retrieve configuration data.

##  23. Real-Time Clock Operation

The LPC2148 internal RTC maintains the current date and time.

The RTC provides:

Hour
Minute
Second
Date
Month
Year
Day

The application reads these values whenever RTC information is required.

This eliminates the need for a separate external RTC module for the basic timekeeping function.

##  24. Temperature Measurement

The LM35 provides an analog voltage proportional to temperature.

The LPC2148 ADC converts this analog signal into a digital value.

For example:
-----
   LM35 Output ≈ 300 mV
        ---
   Temperature ≈ 30°C
-----
The actual conversion depends on the ADC reference voltage and configuration.

## 25. Hardware output

![image alt](https://github.com/akshithavemana/REAL-TIME-USER-INTERACTIVE-WIRELESS-DOT-MATRIX-DISPLAY-SYSTEM/blob/main/hardware.png)

##  26. Engineering Challenges and Solutions

Challenge	Solution,
Wireless communication	HC-05 Bluetooth,
Continuous UART reception	UART interrupt,
Long message display	Scrolling algorithm,
Multiple display patterns	Character pattern table,
Limited GPIO outputs	74HC164 shift registers,
Configuration retention	SPI EEPROM,
Real-time clock information	LPC2148 RTC,
Temperature measurement	LM35 + ADC,
Invalid RTC input	Range validation,
User control during display	Special ! command,
Custom messages	Bluetooth Text Edit Mode

##  27. Key Features

🔹 Wireless Control

The display can be controlled through an Android phone using Bluetooth.

🔹 Multiple Display Modes

The system supports fixed, blinking, scrolling, time, RTC, and temperature displays.

🔹 Real-Time Operation

RTC and ADC information can be processed and displayed during runtime.

🔹 User Programmability

The user can edit text and RTC information through the Bluetooth terminal.

🔹 Non-Volatile Storage

SPI EEPROM stores selected configuration information.

🔹 Interrupt-Based Communication

UART interrupts provide responsive Bluetooth data reception.

🔹 Modular Firmware

Separate drivers can be developed for each hardware peripheral.

🔹 Expandable Architecture

Additional sensors, display modes, and communication functions can be added in future versions.

##  28. Applications

Wireless digital notice boards
College and school information displays
Industrial status displays
Factory information panels
Temperature monitoring systems
Laboratory monitoring systems
Digital advertising boards
Real-time clock displays
Wireless message boards
Embedded-system educational platforms
Event information displays
Smart display systems

## 29. Conclusion

The Real-Time User-Interactive Wireless Dot-Matrix Display System successfully integrates an LPC2148 ARM7 microcontroller, HC-05 Bluetooth module, UART, SPI EEPROM, RTC, ADC, LM35 temperature sensor, 74HC164 shift registers, and a 4×8×8 dot-matrix display into a single embedded system.

The system allows users to wirelessly select display modes, display fixed and scrolling messages, display real-time clock information, monitor temperature, edit text, and update RTC settings.

The use of UART interrupts improves communication responsiveness, while SPI EEPROM provides non-volatile configuration storage. The RTC provides real-time date and time information, and the LM35 with ADC enables temperature measurement.

Overall, this project demonstrates practical knowledge of ARM7 architecture, Embedded C programming, peripheral register programming, wireless communication, serial protocols, sensor interfacing, memory interfacing, display control, and real-time embedded-system design.
