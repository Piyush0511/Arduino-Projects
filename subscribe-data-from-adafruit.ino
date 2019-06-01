#include<ESP8266WiFi.h>
#include<Adafruit_MQTT_Client.h>

#define ldr A0
#define wifi ""
#define password ""

#define server "io.adafruit.com"
#define port 1883
#define username ""
#define key ""

WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp, server, port, username, key);
Adafruit_MQTT_Subscribe feed(&mqtt, username"/feeds/");

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit mqtt  ");
  Serial.print("Connecting  to");
  Serial.println(wifi);
  WiFi.begin(wifi, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi connected");
  Serial.println("IP address");
  Serial.println(WiFi.localIP());

  mqtt.subscribe(&feed);

  Serial.println("Connecting to mqtt");
  while (mqtt.connect())
  {
    Serial.print(".");
  }
}

void loop()
{
  while (mqtt.readSubscription(1000))
  {
    //Serial.print("Got: ");
    //Serial.print((char*)feed.lastread);
    int a = atoi((char*)feed.lastread);
    // Serial.print(" ");
    //Serial.println(a);
    if (a == 0)
    {
      Serial.println("sze");
      mqtt.readSubscription(1000);
    }
    else if (a == 1)
    {
      Serial.println("sae") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 2)
    {
      Serial.println("sbe") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 3)
    {
      Serial.println("sce") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 4)
    {
      Serial.println("sde") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 5)
    {
      Serial.println("see") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 6)
    {
      Serial.println("sfe") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 7)
    {
      Serial.println("sge") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 8)
    {
      Serial.println("she") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 9)
    {
      Serial.println("sie") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 10)
    {
      Serial.println("sje") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 11)
    {
      Serial.println("ske") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 12)
    {
      Serial.println("sle") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 13)
    {
      Serial.println("sme") ;
      mqtt.readSubscription(1000);
    }
    else if (a == 14)
    {
      Serial.println("soe") ;
      mqtt.readSubscription(1000);
    }
  }
}



