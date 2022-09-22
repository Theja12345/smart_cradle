#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 14   
#define DHTTYPE    DHT11     
//#define DHTTYPE    DHT22     
//#define DHTTYPE    DHT21    

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
int buzzer= 6;
int sensorPin=7;
boolean val=0;
int out1 = 10;
int out2 = 12;


void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  delayMS = sensor.min_delay / 1000;
   pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(sensorPin,INPUT);
  pinMode(A0,INPUT);
  pinMode(5,OUTPUT);
  
}

void loop() {
 
  delay(delayMS);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  if (event.temperature >= 35){
    digitalWrite(buzzer, HIGH);
    }
    else{
      digitalWrite(buzzer, LOW);
    }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
  val=digitalRead(7);
  Serial.println(val);
  if(val==0)
  {  
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
 delay(30000);
}
  else
  {
   digitalWrite(out1, LOW);
   digitalWrite(out2, LOW);
  }
int value = analogRead(A0);
  Serial.println(value);
  if(val<6000)
  {
    digitalWrite(5,LOW);
  }
  else
  {
    digitalWrite(5,HIGH);
   
  }
}
 
