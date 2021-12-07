/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2020 Sensnology AB
 * Full contributor list: https://github.com/mysensors/MySensors/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

/**
* @file MyEepromAddresses.h
* @brief Eeprom addresses for MySensors library data
*
* @defgroup MyEepromAddressesgrp MyEepromAddresses
* @ingroup internals
* @{
*
*/


#ifndef MyEepromAddresses_h
#define MyEepromAddresses_h
#define SIZE_ROUTES							(256u)	//!< Size routing table
/*
// EEPROM variable sizes, in bytes
#define SIZE_NODE_ID						(1u)		//!< Size node ID
#define SIZE_PARENT_NODE_ID					(1u)		//!< Size parent node ID
#define SIZE_DISTANCE						(1u)		//!< Size GW distance

#define SIZE_CONTROLLER_CONFIG				(23u)	//!< Size controller config
#define SIZE_PERSONALIZATION_CHECKSUM	(1u)  //!< Size personalization checksum
#define SIZE_FIRMWARE_TYPE					(2u)		//!< Size firmware type
#define SIZE_FIRMWARE_VERSION				(2u)		//!< Size firmware version
#define SIZE_FIRMWARE_BLOCKS				(2u)		//!< Size firmware blocks
#define SIZE_FIRMWARE_CRC					(2u)		//!< Size firmware CRC
#define SIZE_SIGNING_REQUIREMENT_TABLE		(32u)	//!< Size signing requirement table
#define SIZE_WHITELIST_REQUIREMENT_TABLE	(32u)	//!< Size whitelist requirement table
#define SIZE_SIGNING_SOFT_HMAC_KEY			(32u)	//!< Size soft signing HMAC key
#define SIZE_SIGNING_SOFT_SERIAL			(9u)		//!< Size soft signing serial
#define SIZE_RF_ENCRYPTION_AES_KEY			(16u)	//!< Size RF AES encryption key
#define SIZE_NODE_LOCK_COUNTER				(1u)		//!< Size node lock counter
*/

#endif // MyEepromAddresses_h

/** @}*/
