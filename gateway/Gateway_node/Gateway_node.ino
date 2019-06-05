#include <Streaming.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "SSD1306Wire.h"
#include <SoftwareSerial.h>



// Inicializa o display Oled
SSD1306Wire display(0x3c, D2, D1);
WiFiClient espClient;
PubSubClient client(espClient);
SoftwareSerial radioSerial(D7, D8); // RX, TX  (cria interface serial por software nas portas digitais 8 e 7 do ATMEGA para comunicar com ESP8266)

#define sensorPin A0 
#define ledPin D4
#define batSign D0
#define botesq D6
#define botdir D5 

int count = 0, ver = 0, value = 0, menu = 0, debounceInterval = 150;   
float sensorValue = 0, in_bat = 2700, bat_tension = 0, bat_gauge = 0, time1 = 0, time2 = 0;
boolean mqttStatus = false, messageStatus = false, stringComandoCompleta = false;;
//char* ssid = "Iot_Deal";
//char* password = "iotadmin@2017";
char* ssid = "Rosangela2G";
char* password = "robaiao72";
const char* mqtt_server = "iot.eclipse.org";
long lastMsg = 0;
byte qtdeBytesComandoRecebido = 0;    
char comandoRecebido[250], msg[250];        
String onemsg = "", twomessage = "", stringComando = "";




void setup() {


  Serial.begin(115200);
  radioSerial.begin(19200);
  delay(100);
  
  display.init();
  display.flipScreenVertically();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  pinMode(batSign, OUTPUT);
  digitalWrite(batSign, HIGH);
  pinMode(botesq, INPUT_PULLUP);
  pinMode(botdir, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(botesq), menuMenos, FALLING);
  attachInterrupt(digitalPinToInterrupt(botdir), menuMais, FALLING);
  inicializa();
  delay(300);



}

void loop() {
  client.loop();
  verifica_serial_radio();
  verifica_serial_USB();
  if (millis() - time1 > 1000) {
    gaugeSens();
    display.clear();
    atualizaDisplay();
    display.display();
  
    time1 = millis();
  }

  if (!client.connected()) {
    reconnect();
  }

}
