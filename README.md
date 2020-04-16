# TunerAPI
A C++ API for operating the RDA5807M FM chip using I2C on an LPC802 MCU  
  
Created for an undergraduate project for the course EECS 3215.

## Prerequisites

To use this file on other project you need the following:  
 - LPC802 MCU  
 - MCUXpresso Version 11.1.0 or Later 
 - LPC802 SDK  
 - C++ project  

## Install

Copy the following files into your source directory:  
 - /source/i2c.h
- /source/i2c.cpp
- /source/tuner.h
- /source/tuner.cpp


Use the following include statements in your program:
```C++
#include "tuner.h"
#include "i2c.h"
```

## Usage

Add these define statements (they can be changed at any time):

```C++
#define I2C_BAUD		(100000)
#define MAIN_CLK		(12000000)
#define TUNER_ADDRESS	(0x10)
#define SDA_PIN			(10)
#define SCL_PIN			(16)
```
Define a new tuner with the following:
```C++
Tuner tuner(TUNER_ADDRESS,SDA_PIN,SCL_PIN, MAIN_CLK);
```
The I2C address is: *0x10*

Next is to initialize i2c followed by the tuner. The order is very important:
```C++
I2Cinit(I2C_BAUD,MAIN_CLK);
tuner.init();
```
Everything is now set and you are ready to run any of the commands found in the tuner class.

## Need a working example?

This whole repo is a working MCUXpresso project made for the LPC802!
