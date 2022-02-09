#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
DHT my_sensor(4,DHT11);
DHT sensor2(5,DHT11);

float Humedad,Temeratura;
float Humedad2,Temeratura2;
unsigned int envio=1000,tactual,tanterior;



void setup() {
  Serial.begin(9600);
  my_sensor.begin();

}

void loop() {
  tactual=millis();

  if(tactual-tanterior>envio){
      tanterior=tactual;
      Humedad=my_sensor.readHumidity();
      Temeratura=my_sensor.readTemperature();

        Serial.print("Humedad++");
        Serial.print(Humedad);
        Serial.print("%");
        Serial.print("Temperatura--");
      Serial.println(Temeratura);
       Humedad2=sensor2.readHumidity();
      Temeratura2=sensor2.readTemperature();
        
        Serial.print("");
        Serial.print("********");
        Serial.print("__Humedad__2-:");
        Serial.print(Humedad2);
        Serial.print("%");
        Serial.print("__Temperatura__2-:");
      Serial.println(Temeratura2);

  }
}