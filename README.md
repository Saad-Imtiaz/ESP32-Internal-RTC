# ESP32-Internal-RTC
This is an ESP32 sketch that connects to a WiFi network and retrieves the current time from an NTP (Network Time Protocol) server. The time is then set on the ESP32's real-time clock (RTC).

## Required Libraries
This sketch requires the following libraries:

Arduino.h
WiFi.h
NTPClient.h
WiFiUdp.h

## Configuration
Before uploading the sketch to your Arduino, you'll need to configure it with your WiFi network's SSID and password. Replace the following lines of code with your own values:

```
const char *ssid = "your-ssid";
const char *password = "your-password";

```

You may also need to adjust the time offset to your local timezone. Replace 0 with the correct value:

```
timeClient.setTimeOffset(0); // set time offset to your local timezone
```
## Usage

1. Upload the sketch to your Arduino
2. Connect the Arduino to your WiFi network
3. The Arduino will retrieve the current time from the NTP server and set it on the RTC
4. The current time will be displayed on the serial monitor in the following format: **YYYY-MM-DDTHH:MM:SSZ**
5. The time will be updated every 1 second.

## Troubleshooting
- If the Arduino is unable to connect to the WiFi network, check that the SSID and password are correct.
- If the time is not being displayed correctly, check that the time offset is set to your local timezone.
- If the time is not being updated, try forcing an update by calling the ```timeClient.forceUpdate``` function.
