/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2020 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 */

#include "MyTransportHAL.h"

#if defined(MY_DEBUG_VERBOSE_TRANSPORT_HAL)
#define TRANSPORT_HAL_DEBUG(x,...) DEBUG_OUTPUT(x, ##__VA_ARGS__)	//!< debug
#else
#define TRANSPORT_HAL_DEBUG(x,...)	//!< debug NULL
#endif

bool transportHALInit(void)
{
	TRANSPORT_HAL_DEBUG(PSTR("THA:INIT\n"));

	bool result = transportInit();

	return result;
}

void transportHALSetAddress(const uint8_t address)
{
	TRANSPORT_HAL_DEBUG(PSTR("THA:SAD:ADDR=%" PRIu8 "\n"), address);
	transportSetAddress(address);
}

uint8_t transportHALGetAddress(void)
{
	uint8_t result = transportGetAddress();
	TRANSPORT_HAL_DEBUG(PSTR("THA:GAD:ADDR=%" PRIu8 "\n"), result);
	return result;
}

bool transportHALDataAvailable(void)
{
	bool result = transportDataAvailable();
#if defined(MY_DEBUG_VERBOSE_TRANSPORT_HAL)
	if (result) {
		TRANSPORT_HAL_DEBUG(PSTR("THA:DATA:AVAIL\n"));
	}
#endif
	return result;
}

bool transportHALSanityCheck(void)
{
	bool result = transportSanityCheck();
	TRANSPORT_HAL_DEBUG(PSTR("THA:SAN:RES=%" PRIu8 "\n"), result);
	return result;
}

bool transportHALReceive(MyMessage *inMsg, uint8_t *msgLength)
{
	// set pointer to first byte of data structure
	uint8_t *rx_data = &inMsg->last;
	uint8_t payloadLength = transportReceive((void *)rx_data);
#if defined(MY_DEBUG_VERBOSE_TRANSPORT_HAL)
	hwDebugBuf2Str((const uint8_t *)rx_data, payloadLength);
	TRANSPORT_HAL_DEBUG(PSTR("THA:RCV:MSG=%s\n"), hwDebugPrintStr);
#endif

	// Reject messages with incorrect protocol version
	MyMessage tmp = *inMsg;
	if (!tmp.isProtocolVersionValid()) {
		setIndication(INDICATION_ERR_VERSION);
		TRANSPORT_HAL_DEBUG(PSTR("!THA:RCV:PVER=%" PRIu8 "\n"),
		                    tmp.getVersion());	// protocol version mismatch
		return false;
	}
	*msgLength = tmp.getLength();

	// Reject payloads with incorrect length
	const uint8_t expectedMessageLength = tmp.getExpectedMessageSize();	
	if (payloadLength != expectedMessageLength) {
		setIndication(INDICATION_ERR_LENGTH);
		TRANSPORT_HAL_DEBUG(PSTR("!THA:RCV:LEN=%" PRIu8 ",EXP=%" PRIu8 "\n"), payloadLength,
		                    expectedMessageLength); // invalid payload length
	uint8_t noOfFrames = expectedMessageLength / 8;
	if (expectedMessageLength % 8 != 0) {
		noOfFrames++;
	}	
	    if (payloadLength == noOfFrames*8){
			payloadLength = expectedMessageLength;
			TRANSPORT_HAL_DEBUG(PSTR("Fix PL Len"));
		}
		else {
			return false;
		} 		
		 
	}

	TRANSPORT_HAL_DEBUG(PSTR("THA:RCV:MSG LEN=%" PRIu8 "\n"), payloadLength);
	return true;
}

bool transportHALSend(const uint8_t nextRecipient, const MyMessage *outMsg, const uint8_t len,
                      const bool noACK)
{
	if (outMsg == NULL) {
		// nothing to send
		return false;
	}
#if defined(MY_DEBUG_VERBOSE_TRANSPORT_HAL)
	/*hwDebugBuf2Str((const uint8_t *)outMsg->last, 1);
	TRANSPORT_HAL_DEBUG(PSTR("THA:SND:lSG=%s\n"), hwDebugPrintStr);
	hwDebugBuf2Str((const uint8_t *)outMsg, len);
	*/TRANSPORT_HAL_DEBUG(PSTR("THA:SND:oSG=%s\n"), hwDebugPrintStr);
	hwDebugBuf2Str((const uint8_t *)&outMsg->last, len);
	TRANSPORT_HAL_DEBUG(PSTR("THA:SND:MSG=%s\n"), hwDebugPrintStr);
#endif

	const uint8_t *tx_data = &outMsg->last;
	const uint8_t finalLength = len;


	bool result = transportSend(nextRecipient, (void *)tx_data, finalLength, noACK);
	TRANSPORT_HAL_DEBUG(PSTR("THA:SND:MSG LEN=%" PRIu8 ",RES=%" PRIu8 "\n"), finalLength, result);
	return result;
}

void transportHALPowerDown(void)
{
	transportPowerDown();
}

void transportHALPowerUp(void)
{
	transportPowerUp();
}

void transportHALSleep(void)
{
	transportSleep();
}

void transportHALStandBy(void)
{
	transportStandBy();
}

int16_t transportHALGetSendingRSSI(void)
{
	int16_t result = transportGetSendingRSSI();
	return result;
}

int16_t transportHALGetReceivingRSSI(void)
{
	int16_t result = transportGetReceivingRSSI();
	return result;
}

int16_t transportHALGetSendingSNR(void)
{
	int16_t result = transportGetSendingSNR();
	return result;
}

int16_t transportHALGetReceivingSNR(void)
{
	int16_t result = transportGetReceivingSNR();
	return result;
}

int16_t transportHALGetTxPowerPercent(void)
{
	int16_t result = transportGetTxPowerPercent();
	return result;
}

bool transportHALSetTxPowerPercent(const uint8_t powerPercent)
{
	bool result = transportSetTxPowerPercent(powerPercent);
	return result;
}

int16_t transportHALGetTxPowerLevel(void)
{
	int16_t result = transportGetTxPowerLevel();
	return result;
}
