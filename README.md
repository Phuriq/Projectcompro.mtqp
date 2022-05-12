![](https://i.pinimg.com/originals/62/bd/cc/62bdcce8c60574d8dc39f343a21c587b.gif)
# Temp & Humid notification <img src=https://pa1.narvii.com/7608/9ef8bdeaa513398af8b27e2bd7bd1bf02870a881r1-444-480_hq.gif  width="50">
> This __Temp & Humid notification__  project is part of Computer Programming Project, KMITL Semester 2/2021 1st Year
 ## บทคัดย่อ 📝
> *  โครงงานชิ้นงาน __Temp & Humid notification__  ทีใช้ C เป็น Microcontroller
> *ทีทำให้เรารู้ถึงอุณหภูมิและความชื้นในที่ๆ Microcontroller ตั้งอยู่ โดยเราได้ใช้พื้นฐานการต่อวงจรจากวิชา Computer Programming มาใช้ในการพัฒนา Microcontroller ตัวนี้
> * โดยในการทำโปรเจคนี้เราได้นำ Source Code ในการวัดอุณหภูมิมาทำการแสดงผลผ่าน notification ของ Application LINE เพื่อความสะดวกในการรับรู้ อุณหภูมิ ณ จุดๆนั้น
## วัตถุประสงค์ 
> * 1.เพื่อศึกษาและพัฒาการต่อวงจร Arduino และ NodeMCU
> * 2.เพื่อนำความรู้ภาษา C ที่ได้ศึกษาจากรายวิชา Computer Programming มาประยุกต์ใช้กับ IOT เพื่อส่งโปรเจคอาจารย์
> * 3.เพื่อวัดอุณหภูมิและความชื้น เพื่อใช้ประโยชน์ตามจุดประสงค์ในแต่ละวัน
## ข้อดี 💚
> * สามารถวัดอุณหภูมิเพื่อใช้ในห้องสำหรับเก็บเซิร์ฟเวอร์หรือเหมืองคริปโต
> * สามารถวัดปริมาณความชื้นเพื่อประกอบการทำกิจการได้ เช่น ถ้าเรารู้ว่าถ้าชื้นเกินก็ยังไม่ควรตากผ้า
> * ใช้งานง่าย เข้าถึงทุกคน และ สะดวกสะบาย
## อุปกรณ์ 🛠
> * Breadboard
> * Nodemcu esp8266
> * Dht11
> * สายไฟจั้มเปอร์
## โปสเตอร์
> ![poster (download)](https://media.discordapp.net/attachments/865671142626033694/974339698401116220/poster_compro.jpg?width=496&height=702)
## ชิ้นงาน
> >  ![microcontroller (download)](https://media.discordapp.net/attachments/865671142626033694/974340163226456105/279963943_378952927534906_8536625025542008159_n.jpg?width=526&height=701)
## Code การเชื่อมต่อตัว Microcontroller กับ LINE
```C
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
```
## Code การส่งข้อความวัดค่าอุณหภูมิและความชื้นจาก Microcontroller ไปที่ LINE
```C
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
```
## ตัวอย่างการส่งข้อความผ่านไลน์
> >  ![Line (download)](https://media.discordapp.net/attachments/865671142626033694/974340163775905892/279510677_733612044304531_965625920282107422_n.png?width=324&height=701)
## วิดีโอนำเสนอชิ้นงาน
> * [Youtube](https://www.youtube.com/watch?v=g0TveA3Xgcw)
---
# Members <img src="https://www.iwlconsulting.com/wp-content/uploads/2020/09/teamwork-icon-200x200-1.gif"  width="50">

| Student ID | ชื่อ - นามสกุล |
| :--------  | :-------- |
|   64070195 |   พรพินิต หนองนา |
|   64070152 |   ติณณภูมิ เกิดอินทร์   |
|   64070212 |   ภูริ ศิริภูล  |
|   64070233 |   นายวีระวิทธ์ มนต์เหลา |
