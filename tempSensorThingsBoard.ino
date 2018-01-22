/*
 * 
 * Firmware for ESP8266
 * 
 * Device: Temperature Sensor Node for ThingsBoard IOT Platform.
 * Temperature Sensor: Dallas Semiconductors DS1620
 * 
 * Author: Kike Ramirez
 * Date: 20/1/2018
 * 
 */


#include <DS1620.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#define WIFI_AP "KikeRamirez"
#define WIFI_PASSWORD "12345679"

#define TOKEN "Z8rgVlZZgh6vzI2OYLtT"

// #define WIFI_AP "CarmenLauraKike"
// #define WIFI_PASSWORD "Carmen2016"

// #define TOKEN "q5d18ZijUYUCShdyaza0"

/* DS1620 pin connection
    
    ESP8266       DS1620
    -------       --------------
    +3.3 V        +3.3 V
    GND           Pin 4 GND
    GPIO0         Pin 1 DQ
    GPIO1 (TX)    Pin 2 CLK/CONV
    GPIO2         Pin 3 RST
*/

    
#define GPIO0 0
#define GPIO1 1
#define GPIO2 2

char thingsboardServer[] = "demo.thingsboard.io";

WiFiClient wifiClient;
PubSubClient client(wifiClient);

int status = WL_IDLE_STATUS;
unsigned long lastSend;

DS1620 ds1620(0, 1, 2);

void setup()
{


  // Call DS1620 constructor using pin variables
  // DS1620 ds1620(GPIO0, GPIO1, GPIO2);

  // GPIO 1 (TX) swap the pin to a GPIO.
  // pinMode(GPIO1, FUNCTION_3);
  
  ds1620.config();
  delay(1000);
  InitWiFi();
  client.setServer( thingsboardServer, 1883 );
  lastSend = 0;
}

void loop()
{
  if ( !client.connected() ) {
    reconnect();
  }

  if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
    getAndSendTemperatureAndHumidityData();
    lastSend = millis();
  }

  client.loop();
}

void getAndSendTemperatureAndHumidityData()
{

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = 0.0;
  // Read temperature as Celsius (the default)
  float t = ds1620.temp_c();
 
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    return;
  }

  String temperature = String(t);
  String humidity = String(h);

  // Prepare a JSON payload string
  String payload = "{";
  payload += "\"temperature\":"; payload += temperature; payload += ",";
  payload += "\"humidity\":"; payload += humidity;
  payload += "}";

  // Send payload
  char attributes[100];
  payload.toCharArray( attributes, 100 );
  client.publish( "v1/devices/me/telemetry", attributes );

}

void InitWiFi()
{
  // attempt to connect to WiFi network
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
      }
    }
    if ( client.connect("tempSensorThingsBoard Device", TOKEN, NULL) ) {
    } else {
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}




