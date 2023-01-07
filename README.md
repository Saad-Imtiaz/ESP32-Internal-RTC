# ESP32-Internal-RTC

## Overview
This code fetches the current time from an NTP server and saves it to the internal real-time clock (RTC) of the ESP32. It then uses the RTC to display the time on the serial monitor in the format 2018-03-28T16:00:13Z after every 1 second.

## Dependencies
This code requires the following libraries:

- WiFi: This library is used to connect the ESP32 to a WiFi network.
- NTPClient: This library is used to fetch the time from an NTP server.
- WiFiUDP: This library is used to create a UDP connection for the NTPClient.

## Setup
1- Specify the SSID and password of your WiFi network in the ssid and password variables, respectively.

2- Set the time offset to your local timezone using the setTimeOffset function.

3- Upload the code to the ESP32.

## How it works
1- The code connects to the WiFi network using the WiFi.begin function.

2- It then initializes the NTPClient object and fetches the time from the NTP server using the update function.

3- The current time is extracted from the NTPClient object and saved to the RTC using the rtc_clk_set_time function.

4- In the loop function, the code retrieves the current time from the RTC using the rtc_clk_get_time function and formats it in the desired format using the String class.

5- The formatted time is then displayed on the serial monitor.

## Note
You can also set the RTC time using the "rtc_clk_set_epoch" function, which takes the UNIX timestamp (number of seconds since Jan 1, 1970) as an input. You can obtain the UNIX timestamp by calling the getEpochTime function of the NTPClient object.
The NTPClient object returns the time in the format 2018-03-28T16:00:13Z, which can be extracted using the getFormattedDate function.

## Customization
- You can change the time interval at which the time is displayed by modifying the delay time in the delay function in the loop function.
- You can customize the format in which the time is displayed by modifying the formattedTime string in the loop function.

## Troubleshooting
- If the ESP32 is unable to connect to the WiFi network, check that the ssid and password variables are set correctly and that the WiFi network is within range.
- If the time is not being displayed correctly, check that the time offset is set correctly using the setTimeOffset function.

## Additional resources

ESP32 Arduino Core documentation
WiFi library documentation
NTPClient library documentation
WiFiUDP library documentation
