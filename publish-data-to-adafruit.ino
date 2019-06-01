#include<ESP8266WebServer.h>
#include<ESP8266WiFi.h>
#include<Adafruit_MQTT_Client.h>
#define wifi ""   // add ur wifi name
#define password ""

#define server1 "io.adafruit.com"
#define port 1883
#define username ""
#define key ""

ESP8266WebServer server;
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp, server1, port, username, key);
Adafruit_MQTT_Publish feed(&mqtt, username"");// ur path


const char username2[] = ""; // local wifi name that u want to create
const char password2[] = "";

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit mqtt demo");
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
  Serial.println("Connecting to mqtt");

  while (mqtt.connect())
  {
    Serial.print(".");
  }
  Serial.begin(115200);  //initialize serial comms
  WiFi.softAP(username2, password2);
  IPAddress myip = WiFi.softAPIP();
  Serial.println("the ip address: ");
  Serial.println(myip);
  server.begin();
  server.on("/led", led);

}

void loop()
{
  server.handleClient();

}

void led()
{
  String myhtml = "<html><head><title></title></head><body style=\"background-color: yellow;\"><h1><center>Robo-Sapien</center></h1><form><center><button name=\"status\"type=\"submit\" value=\"1\">Bulb1 ON</button><button name=\"status\"type=\"submit\" value=\"2\">Bulb2 ON</button><button name=\"status\"type=\"submit\" value=\"3\">Bulb3 ON </button><button name=\"status\"type=\"submit\" value=\"4\">Fan ON </button><br><button name=\"status\"type=\"submit\" value=\"6\">Bulb1 OFF</button><button name=\"status\"type=\"submit\" value=\"7\">Bulb2 OFF</button><button name=\"status\"type=\"submit\" value=\"8\">Bulb3 OFF</button><button name=\"status\"type=\"submit\" value=\"9\">Fan OFF</button></center></form></body>/html>";
  server.send(200, "text/html", myhtml);
  if (server.arg("status") == "0")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(0);
      Serial.println(".");

      if (feed.publish(0))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
  else if (server.arg("status") == "1")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(1);
      Serial.println(".");

      if (feed.publish(1))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
  else if (server.arg("status") == "2")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(2);
      Serial.println(".");

      if (feed.publish(2))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
 else if (server.arg("status") == "3")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(3);
      Serial.println(".");

      if (feed.publish(3))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
  else if (server.arg("status") == "4")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(4);
      Serial.println(".");

      if (feed.publish(4))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
  else if (server.arg("status") == "5")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(5);
      Serial.println(".");

      if (feed.publish(5))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
if (server.arg("status") == "6")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(6);
      Serial.println(".");

      if (feed.publish(6))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
  else if (server.arg("status") == "8")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(8);
      Serial.println(".");

      if (feed.publish(8))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
  }
  else if (server.arg("status") == "9")
  {
    if (mqtt.connected())
    {
      Serial.println("\nsending val");
      Serial.println(9);
      Serial.println(".");

      if (feed.publish(9))
        Serial.println("Success");
      else
        Serial.println("Fail");

    }
  delay(1000);
}
}



















