# ESP8266 MQTT IR & LED Control

## Overview
An ESP8266-based project that uses MQTT to control an LED remotely and publish IR sensor data in real time.

## Features
- WiFi connection using ESP8266
- MQTT communication using EMQX broker
- LED control via subscribed MQTT topic
- IR sensor state published every 1 second

## Hardware
- ESP8266 (NodeMCU)
- LED (D5)
- IR sensor (D2)

## MQTT Topics
- Subscribe: `/sector/salma/led`
- Publish: `/sector/salma/ir`

## Libraries
- ESP8266WiFi
- PubSubClient

## Broker
- broker.emqx.io (Port 1883)

## Notes
WiFi credentials are intentionally excluded for security reasons.
