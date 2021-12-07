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
 * @defgroup MySensorsgrp MySensors
 * @ingroup publics
 * @{
 * @brief The primary public API declaration for the MySensors library
 */

/**
 * @file MySensors.h
 *
 * @brief API declaration for MySensors
 *
 * Include this header into your sketch to include the MySensors library and harness the power of
 * all those sensors!
 */
#ifndef MySensors_h
#define MySensors_h

#ifdef __cplusplus
#include <Arduino.h>
#endif
#include <stdint.h>

#include "MyConfig.h"
#include "core/MyHelperFunctions.cpp"
#include "core/MySensorsCore.h"

#define STR_HELPER(x) #x			//!< Helper macro, STR_HELPER()
#define STR(x) STR_HELPER(x)	//!< Helper macro, STR()

#define MYSENSORS_LIBRARY_VERSION_MAJOR							2							//!< Major release version
#define MYSENSORS_LIBRARY_VERSION_MINOR							4							//!< Minor release version
#define MYSENSORS_LIBRARY_VERSION_PATCH							0							//!< Patch version
#define MYSENSORS_LIBRARY_VERSION_PRERELEASE					"alpha"							//!< Pre-release suffix, i.e. alpha, beta, rc.1, etc
#define MYSENSORS_LIBRARY_VERSION_PRERELEASE_NUMBER				0x00						//!< incremental counter, starting at 0x00. 0xFF for final release
#if (MYSENSORS_LIBRARY_VERSION_PRERELEASE_NUMBER != 0xFF)
#define MYSENSORS_LIBRARY_VERSION STR(MYSENSORS_LIBRARY_VERSION_MAJOR) "." STR(MYSENSORS_LIBRARY_VERSION_MINOR) "." STR(MYSENSORS_LIBRARY_VERSION_PATCH) "-" MYSENSORS_LIBRARY_VERSION_PRERELEASE	//!< pre-release versioning
#else
#define MYSENSORS_LIBRARY_VERSION STR(MYSENSORS_LIBRARY_VERSION_MAJOR) "." STR(MYSENSORS_LIBRARY_VERSION_MINOR) "." STR(MYSENSORS_LIBRARY_VERSION_PATCH) //!< final release versioning
#endif

#define MYSENSORS_LIBRARY_VERSION_INT ( ((uint32_t)MYSENSORS_LIBRARY_VERSION_MAJOR) << 24 | ((uint32_t)MYSENSORS_LIBRARY_VERSION_MINOR) << 16 | ((uint32_t)MYSENSORS_LIBRARY_VERSION_PATCH) << 8 | ((uint32_t)MYSENSORS_LIBRARY_VERSION_PRERELEASE_NUMBER) ) //!< numerical versioning


// HARDWARE
#include "hal/architecture/MyHwHAL.h"
//#include "hal/crypto/MyCryptoHAL.h"
#include "hal/architecture/AVR/MyHwAVR.cpp"
//#include "hal/crypto/AVR/MyCryptoAVR.cpp"
#include "hal/architecture/MyHwHAL.cpp"

// commonly used macros, sometimes missing in arch definitions
#if !defined(_BV)
#define _BV(x) (1<<(x))	//!< _BV
#endif

#if !defined(min) && !defined(__linux__)
#define min(a,b) ((a)<(b)?(a):(b)) //!< min
#endif

#if !defined(max) && !defined(__linux__)
#define max(a,b) ((a)>(b)?(a):(b)) //!< max
#endif

#if !defined(MIN)
#define MIN min //!< MIN
#endif

#if !defined(MAX)
#define MAX max //!< MAX
#endif

#include "core/MyIndication.cpp"

#if defined(MY_GATEWAY_FEATURE)
// GATEWAY - COMMON FUNCTIONS
#include "core/MyGatewayTransport.cpp"
#include "core/MyProtocol.cpp"
#if defined(MY_GATEWAY_SERIAL)
// GATEWAY - SERIAL
#include "core/MyGatewayTransportSerial.cpp"
#endif
#endif

// GATEWAY - CONFIGURATION
#if defined(MY_SENSOR_NETWORK)
// We assume that a gateway having a radio also should act as repeater
#define MY_REPEATER_FEATURE
#endif


//#elif defined(MY_GATEWAY_SERIAL)
// GATEWAY - SERIAL
//#include "core/MyGatewayTransportSerial.cpp"

#if defined(MY_CAN)
#define __CANCNT 1	//!< __CANCNT
#else
#define __CANCNT 0	//!< __CANCNT
#endif


// SANITY CHECK
#if defined(MY_REPEATER_FEATURE) || defined(MY_GATEWAY_FEATURE)
#define MY_TRANSPORT_SANITY_CHECK		//!< enable regular transport sanity checks

#endif

// TRANSPORT INCLUDES
#include "hal/transport/MyTransportHAL.h"
#include "core/MyTransport.h"

// PARENT CHECK
#if defined(MY_PARENT_NODE_IS_STATIC) && (MY_PARENT_NODE_ID == AUTO)
#error Parent is static but no parent ID defined, set MY_PARENT_NODE_ID.
#endif

#if defined(MY_TRANSPORT_DONT_CARE_MODE)
#error MY_TRANSPORT_DONT_CARE_MODE is deprecated, set MY_TRANSPORT_WAIT_READY_MS instead!
#endif




// Transport drivers
#include "hal/transport/CAN/MyTransportCAN.cpp"


#include "hal/transport/MyTransportHAL.cpp"

// PASSIVE MODE
#if defined(MY_PASSIVE_NODE) && !defined(DOXYGEN)
#define MY_TRANSPORT_UPLINK_CHECK_DISABLED
#define MY_PARENT_NODE_IS_STATIC
#undef MY_REGISTRATION_FEATURE
#undef MY_SIGNING_FEATURE
#undef MY_OTA_FIRMWARE_FEATURE
#if defined(MY_GATEWAY_FEATURE) || defined(MY_REPEATER_FEATURE)
#error This node is configured as GW/repeater, MY_PASSIVE_NODE cannot be set simultaneously
#endif
#if (MY_NODE_ID == AUTO)
#error MY_PASSIVE_NODE configuration requires setting MY_NODE_ID
#endif
#endif

#if !defined(MY_GATEWAY_FEATURE) && !defined(MY_NODE_ID)
#error MY_NODE_ID configuration is not set.
#endif


#include "core/MyTransport.cpp"


// Make sure to disable child features when parent feature is disabled
#if !defined(MY_SENSOR_NETWORK)
#undef MY_OTA_FIRMWARE_FEATURE
#undef MY_REPEATER_FEATURE
#undef MY_SIGNING_NODE_WHITELISTING
#undef MY_SIGNING_FEATURE
#endif

#if !defined(MY_CORE_ONLY)
#if !defined(MY_GATEWAY_FEATURE) && !defined(MY_SENSOR_NETWORK)
#error No forward link or gateway feature activated. This means nowhere to send messages! Pretty pointless.
#endif
#endif

//#include "core/MyCapabilities.h"
#include "core/MyMessage.cpp"
//#include "core/MySplashScreen.cpp"
#include "core/MySensorsCore.cpp"

// HW mains
#include "hal/architecture/AVR/MyMainAVR.cpp"


#endif