# ESP8266 IoT – Phone & IR Controlled LED

## Overview
An ESP8266-based IoT project demonstrating bi-directional control between a phone app and hardware.  

- The **phone app switch** controls the **LED on the breadboard**  
- The **IR remote** controls the **LED symbol on the phone app**

## Features
- Phone app switch controls physical LED on breadboard
- IR remote controls LED symbol in phone app
- ESP8266 handles communication between devices

## Hardware
- ESP8266 (NodeMCU)
- LED (Breadboard)
- IR remote
- Connecting wires

## Communication
- ESP8266 reads IR remote input and updates phone app LED
- Phone app switch controls physical LED on breadboard

## Libraries
- ESP8266WiFi
- PubSubClient (for MQTT communication if used)

## Notes
WiFi credentials and sensitive info are excluded for security.  

