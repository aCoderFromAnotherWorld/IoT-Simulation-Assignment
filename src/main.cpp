/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID "TMPL6QpehLkcG"
// #define BLYNK_TEMPLATE_NAME "Quickstart Template"
// #define BLYNK_AUTH_TOKEN "X_u8RKqSKZ0xzAmJwcuoexsqyqmrnC47"
// #define BLYNK_TEMPLATE_ID "TMPL6ev56X4Mz"
// #define BLYNK_TEMPLATE_NAME "Sample IoT Project ESP32"
// #define BLYNK_AUTH_TOKEN "IrEBjDzSWcXDbvFzUdAcNsKGbLK-BsII"

#define BLYNK_TEMPLATE_ID "TMPL6MN6-_Lxl"
#define BLYNK_TEMPLATE_NAME "IoT Assignment"
#define BLYNK_AUTH_TOKEN "_0nO1j0tZLTQIYNZdpgOq2IozLUkEWcw"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <string.h>
#include <DHT.h>
// DHT define

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define LED_PIN 23

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

void setup()
{
  // Debug console
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();

  float t = dht.readTemperature();

  float h = dht.readHumidity();

  if (isnan(h) || isnan(t))
  {
    delay(500);
    Serial.println("Failed to read from DHT sensor!\n");
    return;
  }

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}
BLYNK_WRITE(V3)
{

  if (param.asInt() == HIGH)
  {

    digitalWrite(LED_PIN, HIGH);
  }
  else
  {

    digitalWrite(LED_PIN, LOW);
  }
}