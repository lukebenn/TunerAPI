/** @mainpage
 * @author Luke Bennett
 * 
 * Created for an undergraduate project for the course EECS 3215.
 * 
 * @section Introduction 
 * This is a C++ API for operating the RDA5807M FM chip using I2C on an LPC802 MCU
 * 
 * @section Prerequisites
 * 
 * To use this file on other project you need the following:  
 *  - LPC802 MCU  
 *  - MCUXpresso Version 11.1.0 or Later  
 *  - LPC802 SDK  
 *  - C++ project  
 * 
 * 
 * @section Install
 *
 * Go to:  https://github.com/lukebenn/TunerAPI
 *
 * Copy the following files into your source directory:  
 * - /source/i2c.h
 * - /source/i2c.cpp
 * - /source/tuner.h
 * - /source/tuner.cpp
 * 
 * 
 * Use the following include statements in your program:
 * ```
 * #include "tuner.h"
 * #include "i2c.h"
 * ```
 * 
 * @section Usage
 * 
 * Add these define statements (they can be changed at any time):
 *	
 * ```
 * #define I2C_BAUD		(100000)
 * #define MAIN_CLK		(12000000)
 * #define TUNER_ADDRESS	(0x10)
 * #define SDA_PIN			(10)
 * #define SCL_PIN			(16)
 * ```
 *
 * Define a new tuner with the following:
 * ```
 * Tuner tuner(TUNER_ADDRESS,SDA_PIN,SCL_PIN, MAIN_CLK);
 * ```
 * 
 * The I2C address is: *0x10*
 * 
 * Next is to initialize i2c followed by the tuner. The order is very important:
 * ```
 * I2Cinit(I2C_BAUD,MAIN_CLK);
 * tuner.init();
 * ```
 * Everything is now set and you are ready to run any of the commands found in the Tuner class.
 *
 *
 * @section Need Need a working example?
 * 
 * The whole github repo is a working MCUXpresso project made for the LPC802!
 * 
 */
 
/**
 * @file    TunerAPI.cpp
 * @brief   API example and application entry point.
 *
 * Provides an example of the working program (DEBUG is enabled)
 */
#include "LPC802.h"
#include "tuner.h"
#include "i2c.h"

#define I2C_BAUD		(100000)
#define MAIN_CLK		(12000000)
#define TUNER_ADDRESS	(0x10)
#define SDA_PIN			(10)
#define SCL_PIN			(16)

#define DEBUG			1	//Allows program to run without tuner connected

uint8_t DumpedReadBuf[12];	// 6 16-bit registers with a high and low byte separated
uint8_t DumpedWriteBuf[12];  // 6 16-bit registers with a high and low byte separated

/*
 * @brief   Application entry point.
 *
 * This simple program runs a few tuner commands and
 * enters an infinite loop.
 */
Tuner tuner(TUNER_ADDRESS,SDA_PIN,SCL_PIN, MAIN_CLK);

int main(void) {

	I2Cinit(I2C_BAUD,MAIN_CLK);

	tuner.init();
	tuner.dumpBuffers(DumpedReadBuf, DumpedWriteBuf);	//Breakpoint here and debug
	tuner.setStation(1073);
	tuner.dumpBuffers(DumpedReadBuf, DumpedWriteBuf);	//Breakpoint here and debug
	tuner.setVolume(6);
	tuner.dumpBuffers(DumpedReadBuf, DumpedWriteBuf);	//Breakpoint here and debug
	tuner.updateDevice();	//Any information that is read will not update device immediately,
							//update must be preformed first.
	int station = tuner.getStation();

	while(1) {
        asm("nop");
    }
    return 0 ;
}
