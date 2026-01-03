#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3QMhmumdb"
#define BLYNK_TEMPLATE_NAME "Esp LED"
#define BLYNK_AUTH_TOKEN "ZoILkEbZOXh42ynHiewg3emzpWnOocan"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int value = param.asInt();   // 0 or 1
  if (value == 1)
  {
    digitalWrite(2, HIGH);
    Serial.println("LED ON ✅");
  }
  else
  {
    digitalWrite(2, LOW);
    Serial.println("LED OFF ❌");
  }
}