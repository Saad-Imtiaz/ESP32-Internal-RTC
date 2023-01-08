#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <time.h> // include the time.h library

const char *ssid = "your-ssid";
const char *password = "your-password";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  timeClient.begin();
  timeClient.setTimeOffset(0); // set time offset to your local timezone

  // Fetch the time from the NTP server and save it to the RTC
  timeClient.update();
  while (!timeClient.update())
  {
    timeClient.forceUpdate();
  }
  // The formattedDate comes with the following format: 2018-03-28T16:00:13Z
  String formattedDate = timeClient.getFormattedTime();
  Serial.println(formattedDate);
  // You can also obtain the UNIX timestamp (number of seconds since Jan 1, 1970)
  // by calling the getEpochTime() function.
  long epochTime = timeClient.getEpochTime();
  Serial.println(epochTime);

  // Convert the UNIX timestamp to a tm structure
  time_t t = epochTime;
  struct tm *tm = localtime(&t);

  // Set the RTC time using the settimeofday function
  struct timeval tv;
  tv.tv_sec = epochTime;
  tv.tv_usec = 0;
  settimeofday(&tv, 0);
}

void loop()
{
  // Display the current time from the RTC in the desired format
  time_t now;
  time(&now);
  struct tm *tm = localtime(&now);

  char formattedTime[20];
  sprintf(formattedTime, "%04d-%02d-%02dT%02d:%02d:%02dZ", 1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

  Serial.println(formattedTime);
  delay(1000); // update time every 1 second
}
