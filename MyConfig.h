/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in RAM or EEPROM which keeps track of the
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
 * @file MyConfig.h
 * @ingroup MyConfigGrp
 * @brief MySensors specific configuration flags.
 * @{
 * Set these in your sketch before including MySensors.h to customize the library to your needs.
 * If the sketch does not define these flags, they will get default values where applicable.
 */
#ifndef MyConfig_h
#define MyConfig_h

/**
 * @defgroup SerialDebugGrpPub Serial and debugging
 * @ingroup MyConfigGrp
 * @brief These options control serial and debugging features and functionalities in the library.
 * @{
 */

/**
 * @def MY_DEBUG
 * @brief Define MY_DEBUG to show debug prints.
 *
 * This option will add a lot to the size of the final sketch but is helpful to see what is actually
 * is happening during development.
 *
 * @note Values in parenthesis indicate default values which will be used if you have not defined
 * the flag in your sketch.
 */
//#define MY_DEBUG


/**
 * @def MY_SPECIAL_DEBUG
 * @brief Define MY_SPECIAL_DEBUG to enable support for I_DEBUG messages.
 *
 * I_DEBUG messages are sent from the controller to the node, which responds with the requested
 * data. The request can be one of the following:
 * - 'R': routing info (only repeaters): received msg XXYY (as stream), where XX is the node and YY
 *   the routing node
 * - 'V': CPU voltage
 * - 'F': CPU frequency
 * - 'M': free memory
 * - 'E': clear MySensors EEPROM area and reboot (i.e. "factory" reset)
 */
//#define MY_SPECIAL_DEBUG

/**
 * @def MY_DISABLED_SERIAL
 * @brief Define MY_DISABLED_SERIAL if you want to use the UART TX/RX pins as normal I/O pins.
 *
 * @note When defined, if you want to use the pins as a UART, you need to handle initialization and
 * configuration yourself.
 */
//#define MY_DISABLED_SERIAL

/**
 * @def MY_SPLASH_SCREEN_DISABLED
 * @ingroup memorysavings
 * @brief If defined, will disable the MySensors splash screen.
 *
 * @note This saves 120 bytes of flash.
 */
//#define MY_SPLASH_SCREEN_DISABLED

/**
 * @def MY_BAUD_RATE
 * @brief Serial output baud rate (debug prints and serial gateway speed).
 *
 * The baud rate configured here must match the baud rate at the "other" end.
 *
 * @warning Depending on your target device and clock speed, certain baud rates might not work well.
 */
#ifndef MY_BAUD_RATE
#define MY_BAUD_RATE (115200ul)
#endif

/**
 * @def MY_SERIAL_OUTPUT_SIZE
 * @brief Maximum characters for serial output.
 *
 * If you are running extremely low on memory, reducing this size might just save your day.
 */
#ifndef MY_SERIAL_OUTPUT_SIZE
#define MY_SERIAL_OUTPUT_SIZE (120u)
#endif
/** @}*/ // End of SerialDebugGrpPub group

/**
 * @def MY_DEBUG_VERBOSE_OTA_UPDATE
 * @brief Define this for verbose debug prints related to FOTA updates.
 */
//#define MY_DEBUG_VERBOSE_OTA_UPDATE



/**
 * @defgroup TransportSettingGrpPub Transport selection
 * @ingroup MyConfigGrp
 * @brief These options control what transport type to use and various transport specific customisations.
 * @{
 */

/**
 * @defgroup RS485SettingGrpPub RS485
 * @ingroup TransportSettingGrpPub
 * @brief These options are specific to the RS485 wired transport.
 * @{
 */

/**
 * @def MY_RS485
 * @brief Define this to use the RS485 wired transport for sensor network communication.
 */
//#define MY_RS485

/**
 * @def MY_CAN
 * @brief Define this to use the CAN wired transport for sensor network communication.
 */
//#define MY_CAN
/**
 * @def MY_DEBUG_VERBOSE_CAN
 * @brief Define this for verbose debug prints related to the %CAN driver.
 */
//#define MY_DEBUG_VERBOSE_CAN
/**
 * @def CAN_INT
 * @brief Message arrived interrupt pin.
 */
#ifndef CAN_INT
#define CAN_INT (9u)
#endif
/**
 * @def CAN_CS
 * @brief Chip select pin.
 */
#ifndef CAN_CS
#define CAN_CS (10u)
#endif
/**
 * @def CAN_SPEED
 * @brief Baud rate. Allowed values can be found in mcp_can_dfs.h
 */
#ifndef CAN_SPEED
#define CAN_SPEED CAN_50KBPS
#endif
/**
 * @def CAN_CLOCK
 * @brief can clock. Allowed values can be found in mcp_can_dfs.h
 */
#ifndef CAN_CLOCK
#define CAN_CLOCK MCP_16MHZ
#endif
/**
 * @def CAN_BUF_SIZE
 * @brief assemble buffer size. Since long messages can be sliced and arrive mixed with other messages, assemble buffer is required.
 */
#ifndef CAN_BUF_SIZE
#define CAN_BUF_SIZE (8u)
#endif

/**
 * @def MY_RS485_BAUD_RATE
 * @brief The RS485 BAUD rate.
 */
#ifndef MY_RS485_BAUD_RATE
#define MY_RS485_BAUD_RATE (9600)
#endif

/**
 * @def MY_RS485_MAX_MESSAGE_LENGTH
 * @brief The maximum message length used for RS485.
 */
#ifndef MY_RS485_MAX_MESSAGE_LENGTH
#define MY_RS485_MAX_MESSAGE_LENGTH (40)
#endif

/**
 * @def MY_RS485_SOH_COUNT
 * @brief Use this in case of collisions on the bus. 3 might be a good setting.
 */
#ifndef MY_RS485_SOH_COUNT
#define MY_RS485_SOH_COUNT (1)
#endif


/**
 * @def MY_RS485_DE_PIN
 * @brief RS485 driver enable pin.
 */
//#define MY_RS485_DE_PIN (2)

/**
 * @def MY_RS485_DE_INVERSE
 * @brief Define this if RS485 driver enable pin polarity is inverted (low-active).
 */
//#define MY_RS485_DE_INVERSE

/**
 * @def MY_RS485_HWSERIAL
 * @brief Define this if RS485 is connected to a hardware serial port.
 *
 * Example: @code #define MY_RS485_HWSERIAL Serial1 @endcode
 */
//#define MY_RS485_HWSERIAL (Serial1)
/** @}*/ // End of RS485SettingGrpPub group

/**
 * @defgroup SoftSpiSettingGrpPub Soft SPI
 * @ingroup TransportSettingGrpPub
 * @brief These options are specific the soft SPI driver for certain radio transport drivers.
 *
 * The following transport drivers supported by this driver:
 * - The RF24 driver @see RF24SettingGrpPub
 * - The new %RFM69 driver @see RFM69SettingGrpPub @see MY_RFM69_NEW_DRIVER
 * - The RFM95 driver @see RFM95SettingGrpPub
 * @{
 */

/**
 * @def MY_SOFTSPI
 * @brief Define this to use a software based SPI driver which allows more freedom in pin selection
 * for the (supported) radio module.
 */
//#define MY_SOFTSPI

/**
 * @def MY_SOFT_SPI_SCK_PIN
 * @brief Soft SPI SCK pin.
 */
#ifndef MY_SOFT_SPI_SCK_PIN
#define MY_SOFT_SPI_SCK_PIN (14)
#endif

/**
 * @def MY_SOFT_SPI_MISO_PIN
 * @brief Soft SPI MISO pin.
 */
#ifndef MY_SOFT_SPI_MISO_PIN
#define MY_SOFT_SPI_MISO_PIN (16)
#endif

/**
 * @def MY_SOFT_SPI_MOSI_PIN
 * @brief Soft SPI MOSI pin.
 */
#ifndef MY_SOFT_SPI_MOSI_PIN
#define MY_SOFT_SPI_MOSI_PIN (15)
#endif
/** @}*/ // End of SoftSpiSettingGrpPub group

/** @}*/ // End of TransportSettingGrpPub group

/**
 * @defgroup RoutingNodeSettingGrpPub Routing and node
 * @ingroup MyConfigGrp
 * @brief These options control message routing and node configurations.
 * @{
 */
/**
 * @def MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
 * @ingroup memorysavings
 * @brief If defined, routing table will not be kept in RAM.
 * @see MY_RAM_ROUTING_TABLE_FEATURE
 */
/**
 * @def MY_RAM_ROUTING_TABLE_FEATURE
 * @brief If enabled, the routing table is kept in RAM (if memory allows) and saved in regular
 *        intervals.
 * @note Enabled by default on most platforms, but on AVR only for atmega1280, atmega1284 and
 *       atmega2560.
 * @see MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
 */
#ifndef MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
#define MY_RAM_ROUTING_TABLE_FEATURE
#endif

/**
 * @def MY_ROUTING_TABLE_SAVE_INTERVAL_MS
 * @brief Interval to dump content of routing table to EEPROM
 */
#ifndef MY_ROUTING_TABLE_SAVE_INTERVAL_MS
#define MY_ROUTING_TABLE_SAVE_INTERVAL_MS (30*60*1000ul)
#endif

/**
 * @def MY_PARENT_NODE_ID
 * @brief Node parent defaults to AUTO (tries to find a parent automatically).
 */
#ifndef MY_PARENT_NODE_ID
#define MY_PARENT_NODE_ID 0
#endif

/**
 * @def MY_PARENT_NODE_IS_STATIC
 * @brief Define MY_PARENT_NODE_IS_STATIC to disable fall back if parent node fails
 */
#define MY_PARENT_NODE_IS_STATIC

/**
 * @def MY_TRANSPORT_SANITY_CHECK
 * @brief If defined, will cause node to check transport in regular intervals to detect HW issues
 *        and re-initialize in case of failure.
 * @note This feature is enabled for all repeater nodes (incl. GW)
 */
//#define MY_TRANSPORT_SANITY_CHECK

/**
 * @def MY_TRANSPORT_SANITY_CHECK_INTERVAL_MS
 * @brief Interval (in ms) for transport sanity checks
 */
#ifndef MY_TRANSPORT_SANITY_CHECK_INTERVAL_MS
#define MY_TRANSPORT_SANITY_CHECK_INTERVAL_MS (15*60*1000ul)
#endif
/**
 * @def MY_TRANSPORT_DISCOVERY_INTERVAL_MS
 * @brief This is a gateway-only feature: Interval (in ms) to issue network discovery checks
 */
#ifndef MY_TRANSPORT_DISCOVERY_INTERVAL_MS
#define MY_TRANSPORT_DISCOVERY_INTERVAL_MS (20*60*1000ul)
#endif

/**
 *@def MY_TRANSPORT_UPLINK_CHECK_DISABLED
 *@brief If defined, disables uplink check to GW during transport initialisation
 */
#define MY_TRANSPORT_UPLINK_CHECK_DISABLED

/**
 *@def MY_TRANSPORT_MAX_TX_FAILURES
 *@brief Define to override max. consecutive TX failures until SNP is initiated
 */
//#define MY_TRANSPORT_MAX_TX_FAILURES (10u)

/**
 * @def MY_TRANSPORT_WAIT_READY_MS
 * @brief Timeout in ms until transport is ready during startup, set to 0 for no timeout
 */
#ifndef MY_TRANSPORT_WAIT_READY_MS
#define MY_TRANSPORT_WAIT_READY_MS (0)
#endif

/**
* @def MY_SIGNAL_REPORT_ENABLED
* @brief Enables signal report functionality.
* @note This feature adds ~1kB code to the sketch.
*/
//#define MY_SIGNAL_REPORT_ENABLED

/** @}*/ // End of RoutingNodeSettingGrpPub group

/**
 * @defgroup RegistrationSettingGrpPub Node registration
 * @ingroup MyConfigGrp
 * @brief These options control node registration configurations.
 * @{
 */
/**
 * @def MY_REGISTRATION_FEATURE
 * @brief If enabled, node has to register to GW/controller before being allowed to send sensor
 *        data.
 * @note Enabled by default.
 */
#define MY_REGISTRATION_FEATURE

/**
 * @def MY_REGISTRATION_RETRIES
 * @brief Number of registration retries if no reply received from GW/controller.
 */

#ifndef MY_REGISTRATION_RETRIES
#define MY_REGISTRATION_RETRIES (3u)
#endif

/**
* @def MY_REGISTRATION_DEFAULT
* @brief Node registration default - this applies if no registration response is received from
 *       controller.
*/
#define MY_REGISTRATION_DEFAULT (true)

/**
 * @def MY_REGISTRATION_CONTROLLER
 * @brief If defined, node registration request has to be handled by controller
 */
//#define MY_REGISTRATION_CONTROLLER
/** @}*/ // End of RegistrationSettingGrpPub group

/**
 * @defgroup CoreSettingGrpPub Core
 * @ingroup MyConfigGrp
 * @brief These options control the library core configurations.
 * @{
 */
/**
 * @def MY_CORE_ONLY
 * @brief Define this if you want to use core functions without loading the framework.
 */
//#define MY_CORE_ONLY

/**
 * @def MY_CORE_COMPATIBILITY_CHECK
 * @brief If defined, library compatibility is checked during node registration.
 *        Incompatible libraries are unable to send sensor data.
 */
#define MY_CORE_COMPATIBILITY_CHECK
/** @}*/ // End of CoreSettingGrpPub group

/**
 * @defgroup SleepSettingGrpPub Sleep
 * @ingroup MyConfigGrp
 * @brief These options control sleep configurations.
 * @{
 */
/**
 * @def MY_SLEEP_TRANSPORT_RECONNECT_TIMEOUT_MS
 * @brief Timeout (in ms) to re-establish link if node is send to sleep and transport is not ready.
 */
#ifndef MY_SLEEP_TRANSPORT_RECONNECT_TIMEOUT_MS
#define MY_SLEEP_TRANSPORT_RECONNECT_TIMEOUT_MS (10*1000ul)
#endif

/**
 * @def MY_SMART_SLEEP_WAIT_DURATION_MS
 * @brief The wait period (in ms) before going to sleep when using smartSleep-functions.
 *
 * This period has to be long enough for controller to be able to send out
 * potential buffered messages.
 */
#ifndef MY_SMART_SLEEP_WAIT_DURATION_MS
#define MY_SMART_SLEEP_WAIT_DURATION_MS (500ul)
#endif

/**
 * @def MY_SLEEP_HANDLER
 * @brief Define this to enable the custom pre- & post-sleep handler.
 *
 * Sleep handler is invoked right before entering the sleep function, as well a just after the sleep
 * completes. Applications can use this handler to turn off peripherals or put pins into a best
 * possible low power state according to the concrete hardware design.
 */
//#define MY_SLEEP_HANDLER
/** @}*/ // End of SleepSettingGrpPub group

/**
 * @def MY_DISABLE_REMOTE_RESET
 * @brief Disables over-the-air reset of node
 */
//#define MY_DISABLE_REMOTE_RESET
/** @}*/ // End of OTASettingGrpPub group

/**
 * @defgroup GatewaySettingGrpPub Gateway
 * @ingroup MyConfigGrp
 * @brief These options control gateway specific configurations.
 * @{
 */
/**
 * @def MY_GATEWAY_MAX_RECEIVE_LENGTH
 * @brief Max buffersize needed for messages coming from controller.
 */
#ifndef MY_GATEWAY_MAX_RECEIVE_LENGTH
#define MY_GATEWAY_MAX_RECEIVE_LENGTH (100u)
#endif

/**
 * @def MY_GATEWAY_MAX_SEND_LENGTH
 * @brief Max buffer size when sending messages.
 */
#ifndef MY_GATEWAY_MAX_SEND_LENGTH
#define MY_GATEWAY_MAX_SEND_LENGTH (120u)
#endif

/**
 * @def MY_GATEWAY_MAX_CLIENTS
 * @brief Max number of parallel clients (sever mode).
 */
#ifndef MY_GATEWAY_MAX_CLIENTS
#define MY_GATEWAY_MAX_CLIENTS (1u)
#endif

/**************************************
* Ethernet Gateway Transport Defaults
***************************************/
/**
 * @def MY_GATEWAY_SERIAL
 * @brief Define this for Serial GW.
 */
// The gateway options available
//#define MY_GATEWAY_SERIAL


/**
* @def MY_DEBUG_VERBOSE_GATEWAY
* @brief Define this for verbose debug prints related to the gateway transport.
*/
//#define MY_DEBUG_VERBOSE_GATEWAY

/**
 * @defgroup LEDSettingGrpPub LED
 * @ingroup MyConfigGrp
 * @brief These options control LED specific configurations.
 * @{
 */
/**
 * @def MY_DEFAULT_ERR_LED_PIN
 * @brief Define this with a value that correspond to your placement of the error indication LED.
 *
 * @note This is optional.
 * @note On some platforms (for example sensebender GW) the hardware definitions can enable the LED
 *       by default. That default can be overridden by defining this flag.
 */
//#define MY_DEFAULT_ERR_LED_PIN (6)

/**
 * @def MY_DEFAULT_TX_LED_PIN
 * @brief Define this with a value that correspond to your placement of the TX indication LED.
 *
 * @note This is optional.
 * @note On some platforms (for example sensebender GW) the hardware definitions can enable the LED
 *       by default. That default can be overridden by defining this flag.
 */
//#define MY_DEFAULT_TX_LED_PIN (7)

/**
 * @def MY_DEFAULT_RX_LED_PIN
 * @brief Define this with a value that correspond to your placement of the RX indication LED.
 *
 * @note This is optional.
 * @note On some platforms (for example sensebender GW) the hardware definitions can enable the LED
 *       by default. That default can be overridden by defining this flag.
 */
//#define MY_DEFAULT_RX_LED_PIN (8)

/**
 * @def MY_WITH_LEDS_BLINKING_INVERSE
 * @brief Define this to inverse the LED blinking.
 *
 * When defined LEDs are normally turned on and switches off when blinking.
 */
//#define MY_WITH_LEDS_BLINKING_INVERSE

/**
 * @def MY_INDICATION_HANDLER
 * @brief Define to use own indication handler.
 */
//#define MY_INDICATION_HANDLER

/**
* @def MY_DEFAULT_LED_BLINK_PERIOD
* @brief Default LEDs blinking period in milliseconds.
*/
#ifndef MY_DEFAULT_LED_BLINK_PERIOD
#define MY_DEFAULT_LED_BLINK_PERIOD 300
#endif
/** @}*/ // End of LEDSettingGrpPub group

/**
 * @defgroup SigningSettingGrpPub Signing
 * @ingroup SecuritySettingGrpPub
 * @brief These options control signing related configurations.
 *
 * @see MySigninggrpPub
 * @{
 */
/**
* @def MY_DEBUG_VERBOSE_SIGNING
* @brief Define this for verbose debug prints related to signing.
*/
//#define MY_DEBUG_VERBOSE_SIGNING

/**
 * @def MY_SIGNING_SIMPLE_PASSWD
 * @brief Enables SW backed signing functionality in library and uses provided password as key.
 *
 * This flag is automatically set if @ref MY_SECURITY_SIMPLE_PASSWD is used.
 *
 * This flag will enable signing and signature requests. It has to be identical on ALL nodes in the
 * network.
 *
 * Whitelisting is supported and serial will be the first 8 characters of the password, the ninth
 * character will be the node ID (to make each node have a unique serial).
 *
 * As with the regular signing modes, whitelisting is only activated if a whitelist is specified in
 * the sketch.
 *
 * No @ref personalization is required for this mode.
 *
 * It is allowed to set @ref MY_SIGNING_WEAK_SECURITY for deployment purposes in this mode as it is
 * with the regular software and ATSHA204A based modes.
 *
 * If the provided password is shorter than the size of the HMAC key, it will be null-padded
 * to accommodate the key size in question. A 32 character password is the maximum length. Any
 * password longer than that will be truncated.
 *
 * Example: @code #define MY_SIGNING_SIMPLE_PASSWD "MyInsecurePassword" @endcode
 *
 * @see MY_SECURITY_SIMPLE_PASSWD
 *
 */
//#define MY_SIGNING_SIMPLE_PASSWD "MyInsecurePassword"
#if defined(MY_SIGNING_SIMPLE_PASSWD)
#define MY_SIGNING_SOFT
#define MY_SIGNING_REQUEST_SIGNATURES
#endif

/**
 * @def MY_SIGNING_ATSHA204
 * @brief Enables HW backed signing functionality in library.
 */
//#define MY_SIGNING_ATSHA204

/**
 * @def MY_SIGNING_SOFT
 * @brief Enables SW backed signing functionality in library.
 */
//#define MY_SIGNING_SOFT

/**
 * @def MY_SIGNING_REQUEST_SIGNATURES
 * @brief Enable this to inform gateway to sign all messages sent to this node.
 *
 * If used for a gateway, gateway will by default require signatures from ALL nodes. This behavior
 * can be disabled by weakening security.
 * @see MY_SIGNING_WEAK_SECURITY
 */
//#define MY_SIGNING_REQUEST_SIGNATURES

/**
 * @def MY_SIGNING_WEAK_SECURITY
 * @brief Enable this to permit downgrade of security preferences and relaxed gateway signing
 *        requirements.
 *
 * Use this for evaluating security. It allows for gradual introduction of signing requirements in
 * a network. Nodes that present themselves as not requiring signing or whitelisting will be
 * cleared of this requirement at the receiving end. A gateway which require signatures will only do
 * so from nodes that in turn require signatures.
 *
 * When not set, any node that has presented themselves as a node that require signatures or
 * whitelisting, will be permanently remembered as doing so at the receiver until EEPROM is cleared
 * or the receiver is reconfigured with this flag set or has signing disabled alltogether.
 *
 * @warning This flag when set will weaken security significantly
 */
//#define MY_SIGNING_WEAK_SECURITY

/**
 * @def MY_VERIFICATION_TIMEOUT_MS
 * @brief Define a suitable timeout for a signature verification session
 *
 * Consider the turnaround from a nonce being generated to a signed message being received
 * which might vary, especially in networks with many hops.
 *
 * Shorter time gives less time for an attacker to figure a way to hijack the nonce and attempt to
 * brute force attack the node. Longer time permits more network hops and node or GW processing
 * time. 5s ought to be enough for anyone.
 */
#ifndef MY_VERIFICATION_TIMEOUT_MS
#define MY_VERIFICATION_TIMEOUT_MS (5*1000ul)
#endif

/**
 * @def MY_LOCK_DEVICE
 * @brief Enable read back protection
 *
 * Enable read back protection feature. Currently only supported by NRF51+NRF52.
 * Use this flag to protect signing and encryption keys stored in the MCU.
 *
 * Set this flag, when you use softsigning in MySensors. Don't set this
 * in SecurityPersonalizer.
 *
 * @warning YOU CAN BRICK YOUR DEVICE!!!
 *          Don't set this flag without having an boot loader, OTA firmware update and
 *          an Gateway connection. To reset an device, you can try >>
 *          openocd -f interface/cmsis-dap.cfg -f target/nrf52.cfg -c "program dap apreg 1 0x04 0x01"
 */
//#define MY_LOCK_DEVICE

//#define MY_NODE_LOCK_FEATURE

/**
 * @def MY_NODE_UNLOCK_PIN
 * @brief By grounding this pin during reset of a locked node, the node will unlock.
 *
 * If using a secure bootloader, grounding the pin is the only option to reactivate the node.
 * If using stock Android bootloader or a DualOptiBoot it is also possible to download a sketch
 * using serial protocol to erase EEPROM to unlock the node.
 */
#ifndef MY_NODE_UNLOCK_PIN
#define MY_NODE_UNLOCK_PIN (14)
#endif

/**
 * @def MY_NODE_LOCK_COUNTER_MAX
 * @brief Maximum accepted occurrences of suspected malicious activity in a node.
 *
 * Counter decrements on reoccurring incidents but resets if legitimate behaviour is identified.
 */
#ifndef MY_NODE_LOCK_COUNTER_MAX
#define MY_NODE_LOCK_COUNTER_MAX (5)
#endif
/** @}*/ // Node lock group
/** @}*/ // End of SecuritySettingGrpPub group

/**
 * @defgroup PlatformSettingGrpPub Platform specifics
 * @ingroup MyConfigGrp
 * @brief These options control platform specific configurations.
 * @{
 */
/**
 * @defgroup ESP8266SettingGrpPub ESP8266
 * @ingroup PlatformSettingGrpPub
 * @brief These options control ESP8266 specific configurations.
 * @{
 */
/**
 * @def MY_ESP8266_SERIAL_MODE
 * @brief ESP8266 serial modes
 *
 * - SERIAL_FULL: Default mode.
 * - SERIAL_TX_ONLY: allows to use RX (GPIO3) as a general purpose input/output.
 * - SERIAL_RX_ONLY: allows to use TX (GPIO1) as a general purpose input/output.
 */
#ifndef MY_ESP8266_SERIAL_MODE
#define MY_ESP8266_SERIAL_MODE SERIAL_FULL
#endif
/** @}*/ // End of ESP8266SettingGrpPub group

/**
* @defgroup ESP32SettingGrpPub ESP32
* @ingroup PlatformSettingGrpPub
* @brief These options control ESP32 specific configurations.
* @{
*/

//
// no ESP32 settings
//

/** @}*/ // End of ESP32SettingGrpPub group

/**
 * @defgroup LinuxSettingGrpPub Linux
 * @ingroup PlatformSettingGrpPub
 * @brief These options control Linux specific configurations.
 * @{
 */

/**
 * @def MY_LINUX_SERIAL_PORT
 * @brief Serial device port
 */
//#define MY_LINUX_SERIAL_PORT "/dev/ttyUSB0"

/**
 * @def MY_LINUX_SERIAL_PTY
 * @brief deprecated option
 */
#ifdef MY_LINUX_SERIAL_PTY
#warning MY_LINUX_SERIAL_PTY is deprecated, please use MY_LINUX_SERIAL_PORT
#define MY_LINUX_SERIAL_PORT MY_LINUX_SERIAL_PTY
#endif

/**
 * @def MY_LINUX_IS_SERIAL_PTY
 * @brief deprecated option
 */
#ifdef MY_LINUX_IS_SERIAL_PTY
#warning MY_LINUX_IS_SERIAL_PTY is deprecated, please use MY_LINUX_SERIAL_IS_PTY
#define MY_LINUX_SERIAL_IS_PTY
#endif

/**
 * @def MY_LINUX_SERIAL_IS_PTY
 * @brief Set serial as a pseudo terminal.
 *
 * Enable this if you need to connect to a controller running on the same device.
 * You also need to define MY_LINUX_SERIAL_PORT with the symlink name for the PTY device.
 */
//#define MY_LINUX_SERIAL_IS_PTY

/**
 * @def MY_LINUX_SERIAL_GROUPNAME
 * @brief Grant access to the specified system group for the serial device.
 */
//#define MY_LINUX_SERIAL_GROUPNAME "tty"

/**
 * @def MY_LINUX_CONFIG_FILE
 * @brief Sets the filepath for the gateway config file.
 *
 * @note For now the configuration file is only used to store the emulated eeprom state.
 */
#ifndef MY_LINUX_CONFIG_FILE
#define MY_LINUX_CONFIG_FILE "/etc/mysensors.conf"
#endif
/** @}*/ // End of LinuxSettingGrpPub group
/** @}*/ // End of PlatformSettingGrpPub group

/*
* "Helper" definitions
*/

/*
 * Detect node type
 * MY_GATEWAY_FEATURE is set for gateway sketches.
 * MY_IS_GATEWAY is true when @ref MY_GATEWAY_FEATURE is set.
 * MY_NODE_TYPE contain a string describing the class of sketch/node (gateway/repeater/node).
 */
#if defined(MY_GATEWAY_SERIAL) || defined(MY_GATEWAY_W5100) || defined(MY_GATEWAY_ENC28J60) || defined(MY_GATEWAY_ESP8266) || defined(MY_GATEWAY_ESP32)|| defined(MY_GATEWAY_LINUX) || defined(MY_GATEWAY_MQTT_CLIENT) || defined(MY_GATEWAY_TINYGSM)
#define MY_GATEWAY_FEATURE
#define MY_IS_GATEWAY (true)
#define MY_NODE_TYPE "GW"
#else
#define MY_IS_GATEWAY (false)
#define MY_NODE_TYPE "NODE"
#endif

// DEBUG
#if defined(MY_DISABLED_SERIAL) && !defined(MY_DEBUG_OTA)
#undef MY_DEBUG
#endif
#if defined(MY_DEBUG)
// standard debug output
#define MY_DEBUG_VERBOSE_CORE	//!< MY_DEBUG_VERBOSE_CORE
#define MY_DEBUG_VERBOSE_TRANSPORT	//!< MY_DEBUG_VERBOSE_TRANSPORT
#define MY_DEBUG_VERBOSE_GATEWAY //!< MY_DEBUG_VERBOSE_GATEWAY
#define MY_DEBUG_VERBOSE_OTA_UPDATE //!< MY_DEBUG_VERBOSE_OTA_UPDATE
#endif

#if defined(MY_DEBUG) || defined(MY_DEBUG_VERBOSE_CORE) || defined(MY_DEBUG_VERBOSE_TRANSPORT) || defined(MY_DEBUG_VERBOSE_GATEWAY) || defined(MY_DEBUG_VERBOSE_SIGNING) || defined(MY_DEBUG_VERBOSE_OTA_UPDATE) || defined(MY_DEBUG_VERBOSE_RF24) || defined(MY_DEBUG_VERBOSE_NRF5_ESB) || defined(MY_DEBUG_VERBOSE_RFM69) || defined(MY_DEBUG_VERBOSE_RFM95) || defined(MY_DEBUG_VERBOSE_TRANSPORT_HAL)
#define DEBUG_OUTPUT_ENABLED	//!< DEBUG_OUTPUT_ENABLED
#ifndef MY_DEBUG_OTA
#define DEBUG_OUTPUT(x,...)		hwDebugPrint(x, ##__VA_ARGS__)	//!< debug
#else
#ifndef MY_OTA_LOG_SENDER_FEATURE
#define MY_OTA_LOG_SENDER_FEATURE
#endif
#ifndef MY_DEBUG_OTA_DISABLE_ECHO
#define DEBUG_OUTPUT(x,...)		OTALog((MY_DEBUG_OTA), true, x, ##__VA_ARGS__)	//!< debug
#else
#define DEBUG_OUTPUT(x,...)		OTALog((MY_DEBUG_OTA), false, x, ##__VA_ARGS__)	//!< debug
#endif
// disable radio related debugging messages
#undef MY_DEBUG_VERBOSE_RF24
#undef MY_DEBUG_VERBOSE_NRF5_ESB
#undef MY_DEBUG_VERBOSE_RFM69
#undef MY_DEBUG_VERBOSE_RFM69_REGISTERS
#undef MY_DEBUG_VERBOSE_RFM95
#endif
#else
#define DEBUG_OUTPUT(x,...)								//!< debug NULL
#endif

// temp. workaround for nRF5 verifier: redirect RF24 to NRF_ESB
#if defined(ARDUINO_ARCH_NRF5) && (defined(MY_RADIO_RF24) )
#undef MY_RADIO_RF24
#define MY_RADIO_NRF5_ESB
#endif

// Enable sensor network "feature" if one of the transport types was enabled
#if defined(MY_RADIO_RF24) || defined(MY_RADIO_NRF5_ESB) || defined(MY_RADIO_RFM69) || defined(MY_RADIO_RFM95) || defined(MY_RS485) || defined(MY_PJON) || defined(MY_CAN)
#define MY_SENSOR_NETWORK
#endif

// LEDS
#if !defined(MY_DEFAULT_ERR_LED_PIN) && defined(MY_HW_ERR_LED_PIN)
#define MY_DEFAULT_ERR_LED_PIN MY_HW_ERR_LED_PIN
#endif

#if !defined(MY_DEFAULT_TX_LED_PIN) && defined(MY_HW_TX_LED_PIN)
#define MY_DEFAULT_TX_LED_PIN MY_HW_TX_LED_PIN
#endif

#if !defined(MY_DEFAULT_RX_LED_PIN) && defined(MY_HW_TX_LED_PIN)
#define MY_DEFAULT_RX_LED_PIN MY_HW_TX_LED_PIN
#endif

#endif	// MyConfig_h

// Doxygen specific constructs, not included when built normally
// This is used to enable disabled macros/definitions to be included in the documentation as well.
#if DOXYGEN
/**
 * @def ARDUINO_ARCH_SAMD
 * @brief Automatically set when building for SAMD targets
 */
#define ARDUINO_ARCH_SAMD

/**
 * @def ARDUINO_ARCH_NRF5
 * @brief Automatically set when building for nRF5 targets
 */
#define ARDUINO_ARCH_NRF5

/**
 * @def ARDUINO_ARCH_ESP8266
 * @brief Automatically set when building for ESP8266 targets
 */
#define ARDUINO_ARCH_ESP8266

/**
 * @def ARDUINO_ARCH_ESP32
 * @brief Automatically set when building for ESP32 targets
 */
#define ARDUINO_ARCH_ESP32

/**
 * @def ARDUINO_ARCH_AVR
 * @brief Automatically set when building for AVR targets
 */
#define ARDUINO_ARCH_AVR

/**
 * @def ARDUINO_ARCH_STM32F1
 * @brief Automatically set when building for STM32F1 targets
 */
#define ARDUINO_ARCH_STM32F1

/**
 * @def TEENSYDUINO
 * @brief Automatically set when building for Teensy targets
 */
#define TEENSYDUINO

// debug
#define MY_DEBUG
#define MY_DEBUGDEVICE
#define MY_DEBUG_OTA
#define MY_DEBUG_OTA_DISABLE_ECHO
#define MY_SPECIAL_DEBUG
#define MY_DISABLED_SERIAL
#define MY_SPLASH_SCREEN_DISABLED
// linux
#define MY_LINUX_SERIAL_PORT
#define MY_LINUX_SERIAL_IS_PTY
#define MY_LINUX_SERIAL_GROUPNAME
#define MY_LINUX_SERIAL_PTY
#define MY_LINUX_IS_SERIAL_PTY
// inclusion mode
#define MY_INCLUSION_MODE_FEATURE
#define MY_INCLUSION_BUTTON_FEATURE
// OTA logging and debug
#define MY_OTA_LOG_RECEIVER_FEATURE
#define MY_OTA_LOG_SENDER_FEATURE
// transport
#define MY_PARENT_NODE_IS_STATIC
#define MY_REGISTRATION_CONTROLLER
#define MY_TRANSPORT_UPLINK_CHECK_DISABLED
#define MY_TRANSPORT_SANITY_CHECK
#define MY_NODE_LOCK_FEATURE
#define MY_REPEATER_FEATURE
#define MY_PASSIVE_NODE
#define MY_MQTT_CLIENT_PUBLISH_RETAIN
#define MY_MQTT_PASSWORD
#define MY_MQTT_USER
#define MY_MQTT_CLIENT_ID
#define MY_MQTT_PUBLISH_TOPIC_PREFIX
#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX
#define MY_MQTT_CA_CERT
#define MY_MQTT_CLIENT_CERT
#define MY_MQTT_CLIENT_KEY
#define MY_SIGNAL_REPORT_ENABLED
// general
#define MY_WITH_LEDS_BLINKING_INVERSE
#define MY_INDICATION_HANDLER
#define MY_DISABLE_REMOTE_RESET
#define MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
#define MY_LOCK_DEVICE
#define MY_SLEEP_HANDLER
// core
#define MY_CORE_ONLY
// GW
#define MY_DEBUG_VERBOSE_GATEWAY
#define MY_INCLUSION_BUTTON_EXTERNAL_PULLUP
#define MY_INCLUSION_LED_PIN
#define MY_GATEWAY_W5100
#define MY_GATEWAY_ENC28J60
#define MY_GATEWAY_ESP8266
#define MY_GATEWAY_ESP32
#define MY_WIFI_SSID
#define MY_WIFI_BSSID
#define MY_WIFI_PASSWORD
#define MY_GATEWAY_LINUX
#define MY_GATEWAY_TINYGSM
#define MY_GATEWAY_MQTT_CLIENT
#define MY_GATEWAY_SERIAL
#define MY_IP_ADDRESS
#define MY_IP_GATEWAY_ADDRESS
#define MY_IP_SUBNET_ADDRESS
#define MY_USE_UDP
#define MY_CONTROLLER_IP_ADDRESS
#define MY_CONTROLLER_URL_ADDRESS
// TinyGSM
#define MY_GSM_APN
#define MY_GSM_BAUDRATE
#define MY_GSM_PIN
#define MY_GSM_PSW
#define MY_GSM_RX
#define MY_GSM_SSID
#define MY_GSM_TX
#define MY_GSM_USR
// LED
#define MY_DEFAULT_ERR_LED_PIN
#define MY_DEFAULT_TX_LED_PIN
#define MY_DEFAULT_RX_LED_PIN
// signing
#define MY_SECURITY_SIMPLE_PASSWD
#define MY_SIGNING_SIMPLE_PASSWD
#define MY_ENCRYPTION_SIMPLE_PASSWD
#define MY_SIGNING_ATSHA204
#define MY_SIGNING_SOFT
#define MY_SIGNING_REQUEST_SIGNATURES
#define MY_SIGNING_WEAK_SECURITY
#define MY_SIGNING_NODE_WHITELISTING
#define MY_DEBUG_VERBOSE_SIGNING
#define MY_SIGNING_FEATURE
#define MY_ENCRYPTION_FEATURE
// FOTA update
#define MY_DEBUG_VERBOSE_OTA_UPDATE
#define MY_OTA_USE_I2C_EEPROM
// RS485
#define MY_RS485
#define MY_RS485_DE_PIN
#define MY_RS485_DE_INVERSE
#define MY_RS485_HWSERIAL
// PJON
#define MY_PJON
#define MY_DEBUG_VERBOSE_PJON
// CAN
#define MY_CAN
#define MY_DEBUG_VERBOSE_CAN
// RF24
#define MY_RADIO_RF24
#define MY_RADIO_NRF24 //deprecated
#define MY_DEBUG_VERBOSE_RF24
#define MY_RF24_POWER_PIN
#define MY_RF24_IRQ_PIN
#define MY_RF24_ENABLE_ENCRYPTION
#define MY_RX_MESSAGE_BUFFER_FEATURE
#define MY_RX_MESSAGE_BUFFER_SIZE
// NRF5_ESB
#define MY_RADIO_NRF5_ESB
#define MY_NRF5_ESB_ENABLE_ENCRYPTION
#define MY_DEBUG_VERBOSE_NRF5_ESB
#define MY_NRF5_ESB_REVERSE_ACK_RX
#define MY_NRF5_ESB_REVERSE_ACK_TX
// RFM69
#define MY_RADIO_RFM69
#define MY_IS_RFM69HW
#define MY_RFM69_NEW_DRIVER
#define MY_RFM69_POWER_PIN
#define MY_RFM69_MODEM_CONFIGURATION
#define MY_RFM69_ENABLE_ENCRYPTION
#define MY_RFM69_ATC_MODE_DISABLED
#define MY_RFM69_MAX_POWER_LEVEL_DBM
#define MY_RFM69_RST_PIN
#define MY_DEBUG_VERBOSE_RFM69
#define MY_DEBUG_VERBOSE_RFM69_REGISTERS
// RFM95
#define MY_RADIO_RFM95
#define MY_DEBUG_VERBOSE_RFM95
#define MY_RFM95_ENABLE_ENCRYPTION
#define MY_RFM95_ATC_MODE_DISABLED
#define MY_RFM95_RST_PIN
#define MY_RFM95_MODEM_CONFIGRUATION
#define MY_RFM95_POWER_PIN
#define MY_RFM95_TCXO
#define MY_RFM95_MAX_POWER_LEVEL_DBM
// SOFT-SPI
#define MY_SOFTSPI
#endif
/** @}*/ // End of MyConfig group
