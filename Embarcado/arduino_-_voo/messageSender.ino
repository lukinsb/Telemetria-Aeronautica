void sendTelemetryStatus() {
  datamsg = "t";
  datamsg += ",";
  datamsg += String(millis());
  datamsg += ",";
  datamsg += bat_tension;
  datamsg += ",";
  datamsg += bat_gauge;
  datamsg += ",";
  datamsg += sd_enabled;
  datamsg += ",";
  datamsg += cont_alt;


  Serial1.println(datamsg);
  Serial.println(datamsg);

}

void sendPlaneStatus() {


  datamsg = "p";
  datamsg += ",";
  datamsg += String(millis());
  datamsg += ",";
  datamsg += outbat_gauge;
  datamsg += ",";
  datamsg += outbat_tension;
  datamsg += ",";
  datamsg += Amps;


  //Serial.println(datamsg);
  Serial1.println(datamsg);
  SDsend(datamsg, "mqttData.txt");


}

void sendGPS() {

  datamsg = "g";
  datamsg += ",";
  datamsg += String(millis());
  datamsg += ",";
  datamsg += String(latitude, 6);
  datamsg += ",";
  datamsg += String(longitude, 6);
  datamsg += ",";
  datamsg += calendar;
  datamsg += ",";
  datamsg += hour_clock;
  datamsg += ",";
  datamsg += gps_speed;
  datamsg += ",";
  datamsg += gps_course;
  datamsg += ",";
  datamsg += gps_alt;
  datamsg += ",";
  datamsg += satelites;
  datamsg += ",";
  datamsg += precision;


  //Serial.println(datamsg);
  Serial1.println(datamsg);
  Serial.println(datamsg);
  SDsend(datamsg, "mqttData.txt");

}

void sendFlightData() {

  datamsg = "f";
  datamsg += ",";
  datamsg += String(millis());
  datamsg += ",";
  datamsg += Vel;
  datamsg += ",";
  datamsg += temp;
  datamsg += ",";
  datamsg += pressure;
  datamsg += ",";
  datamsg += alt;
  datamsg += ",";
  datamsg += distance;
  datamsg += ",";
  datamsg += OrientX;
  datamsg += ",";
  datamsg += OrientY;
  datamsg += ",";
  datamsg += OrientZ;
  datamsg += ",";
  datamsg += alt_den;


  //Serial.println(datamsg);
  Serial1.println(datamsg);
  Serial.println(datamsg);
  SDsend(datamsg, "mqttData.txt");

}

void sendAccel() {
  if (readacc == true) {
    tic = millis();

    File dataFile = SD.open("mqttData.txt", FILE_WRITE);

    if (dataFile && sd_enabled == 1) {
      while (millis() - tic < 250) {

        if ((millis() - tic) % 10 == 0) {

          getOrientation();
          getAccel();
          getLin();
          getEuler();
          getGravity();

          datamsg = "a";
          datamsg += ",";
          datamsg += String(millis());
          datamsg += ",";
          datamsg += accelX;
          datamsg += ",";
          datamsg += accelY;
          datamsg += ",";
          datamsg += accelZ;
          datamsg += ",";
          datamsg += linX;
          datamsg += ",";
          datamsg += linY;
          datamsg += ",";
          datamsg += linZ;
          datamsg += ",";
          datamsg += linX;
          datamsg += ",";
          datamsg += gravityX;
          datamsg += ",";
          datamsg += gravityY;
          datamsg += ",";
          datamsg += gravityZ;
          datamsg += ",";
          datamsg += gyroX;
          datamsg += ",";
          datamsg += gyroY;
          datamsg += ",";
          datamsg += gyroZ;
          datamsg += ",";
          datamsg += eulerX;
          datamsg += ",";
          datamsg += eulerY;
          datamsg += ",";
          datamsg += eulerZ;
          datamsg += ",";
          datamsg += OrientX;
          datamsg += ",";
          datamsg += OrientY;
          datamsg += ",";
          datamsg += OrientZ;

          dataFile.println(datamsg);
        }
      }

    }

    dataFile.close();
    readacc = false;
  }

}



void readtoSD() {
  readacc = true;

}

void sendtotel() {
  sendtel = true;

}
