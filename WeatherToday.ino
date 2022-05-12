#include "DHT.h"
DHT dht;
#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>

#define dht_apin A0 
#define LINE_TOKEN  "i7cVyIoWGgDN0sh5KnkdCwnV58CxlmwxTNd0vvyclsg"

const char* ssid = "Odepearl_2.4G";
const char* pass = "itkmitls";

uint32_t ts, ts1, ts2;
void setup()
{
  Serial.begin(9600);
  dht.setup(2); // data pin 2
  
  WiFi.begin(ssid, pass); 
  delay(1000);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.print("\nPleas wait"); 
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(300);
  }
  
  Serial.print("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);  // กำหนด Line Token
  LINE.notify("เชื่อมต่อกับ WeatherToday สำเร็จเเล้ว");

  ts = ts1 = millis();
}

void loop(){
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  ts = millis();
  //DHT.read11(dht_apin);
 if ((ts - ts1 >= 10000) && (WiFi.status() == WL_CONNECTED))
 { 
  LINE.notify("Temperature : " + String(temperature) + " °C" +"\n" + "Humidity : " + String(humidity)) + " %";
  return;
 } 
}
