#include <TinyGPS++.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_BMP280.h>
#include <DueTimer.h>


#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55);
Adafruit_BMP280 bme;
TinyGPSPlus gps;


#define chipSelect 4
#define trigPin 12
#define echoPin 13
#define pitotPin A0
#define corrente_pin A2
#define inBat_pin A9
#define outBat_pin A3
#define analogIn A0


String datamsg = "", stringComando = "";
long duration;
unsigned long tic, toc;
int distance, sensorValue = 0, RawValue = 0, cont[10], precision;
double Amps = 0, latitude = 0, longitude = 0, gps_speed = 0, gps_course = 0, gps_alt = 0;
float Vout = 0, Vel = 0, somaVel = 0, offset = 0, offsetv = 0, tensao = 0, tk = 0, alt_den = 0;
float cont_alt = 1013.25, temp, pressure, alt, alt_livre;
float OrientX, OrientY, OrientZ, accelX, accelY, accelZ, linX, linY, linZ;
float magX, magY, magZ, gravityX, gravityY, gravityZ, gyroX, gyroY, gyroZ, eulerX, eulerY, eulerZ;
float in_bat = 2700, bat_tension = 0, bat_gauge = 0;
float out_bat = 2700, outbat_tension = 0, outbat_gauge = 0, SoundSpeed = 0;
boolean sd_enabled = 1, send_if = false, stringComandoCompleta = false, readacc = false, sendtel = false;
byte qtdeBytesComandoRecebido = 0;      // variavel que armazena a quantidade de bytes que compoem o comando recebido
char comandoRecebido[150];              // array de 100 bytes para armazenar o comando recebido do ESP8266 via serial
uint32_t calendar, hour_clock, satelites;



void setup() {

  Serial.begin(115200);
  Serial1.begin(19200);
  Serial2.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  analogReadResolution(12);



  SDinit();
  accelInit();
  accelcalib();
  pitotInit();
  baroInit();

  SDsend("Novo Registro", "mqttData.txt");

  Timer3.attachInterrupt(readtoSD);
  Timer3.start(1000000); // Calls every 50ms
  delay(50);
  Timer4.attachInterrupt(sendtotel);
  Timer4.start(1000000); // Calls every 50ms

}

void loop() {


  getDist();
  getOrientation();
  getAccel();
  getLin();
  getEuler();
  getVel();
  getBaro();
  getTens();
  getCurr();
  getBat();
  getGPS();
  verifica_serial_USB();
  verifica_serial_radio();
 


  if (send_if == true) {
    sendFlightData();
    sendPlaneStatus();
    sendAccel();
  }
  if (sendtel == true) {
     sendTelemetryStatus();
     sendGPS();
     //sendFlightData();
     sendtel = false;
  }

}
