## 🔷 Real-Time User-Interactive Wireless Dot-Matrix Display System Using ARM7
---

## 📌 Project Overview

The Real-Time User-Interactive Wireless Dot-Matrix Display System is an ARM7-based embedded system designed to provide wireless control of a 4×8×8 dot-matrix LED display using an Android Bluetooth terminal application.

The system is developed around the LPC2148 ARM7 microcontroller and integrates several peripherals and external devices, including:

• HC-05 Bluetooth module for wireless communication
• UART0 for serial communication+
• 74HC164 shift registers for dot-matrix interfacing
• SPI EEPROM for non-volatile configuration storage
• RTC for real-time clock and date information
• LM35 temperature sensor for temperature measurement
• ADC for analog temperature acquisition
• 4×8×8 dot-matrix display for visual output

The user can wirelessly select different display modes, enter custom text, edit RTC information, and display real-time temperature and clock information.

## 🎯 1. Project Objectives

The main objective of this project is to develop a wireless and user-interactive real-time display system capable of:

• Receiving commands wirelessly from an Android phone
•  Providing a menu-based Bluetooth user interface
• Displaying fixed messages
•  Displaying blinking messages
• Displaying scrolling messages
• Displaying real-time clock information
• Displaying RTC information with scrolling
• Measuring temperature using LM35
•  Displaying temperature on the dot matrix
•  Editing display text through Bluetooth
• Editing RTC values through Bluetooth
• Storing configuration information in SPI EEPROM
• Restoring the saved configuration after power ON
• Providing responsive real-time user interaction

## 🏗️ 2. System Architecture

The overall system consists of the following major blocks:


![image alt](https://github.com/akshithavemana/REAL-TIME-USER-INTERACTIVE-WIRELESS-DOT-MATRIX-DISPLAY-SYSTEM/blob/main/Screenshot%202026-09-24%20170110.png)


## 🔩 3. Hardware Components

• LPC2148 ARM7 microcontroller
• HC-05	Wireless Bluetooth communication
• 4×8×8 Dot Matrix Displays
• 74HC164	Serial-to-parallel shift register
• SPI EEPROM Stores configuration data
• LM35 Temperature sensing
• RTC Provides time and date
• Android Phone User interface
• Power Supply Provides required power to the system

## 💻 4. Software Requirements

The firmware is developed using Embedded C.

• Development Tools
• Keil µVision
• Flash Magic
• Embedded C
• Android Bluetooth Terminal Application

## 🔌 5. Major Interfaces Used

# UART

UART is used for communication between the LPC2148 and HC-05.

Android Phone
      ↓
    HC-05
      ↓
   UART0
      ↓
   LPC2148
# SPI

SPI is used for communication between the LPC2148 and external EEPROM.

LPC2148
   │
   ├── SCK
   ├── MOSI
   ├── MISO
   └── CS
        │
        ▼
    SPI EEPROM
# ADC

ADC is used to convert the analog voltage from the LM35 into a digital value.

LM35
 ↓
Analog Voltage
 ↓
LPC2148 ADC
 ↓
Digital Value
# RTC

The LPC2148 internal RTC provides:

Hours
Minutes
Seconds
Date
Month
Year
Day
# GPIO / Shift Register

GPIO and shift-register signals are used to control the dot-matrix display.
