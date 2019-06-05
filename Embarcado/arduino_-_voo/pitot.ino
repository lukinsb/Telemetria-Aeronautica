void pitotInit() {

  for (int x = 0; x < 10; x++) {
    cont[x] = analogRead(pitotPin);
    Vout = (3.3 * cont[x]) / 4095;
    Vout = Vout - 2.5;
    Vout = Vout * 1000;
    offset = offset + Vout;
    //Serial.println(P);
  }
  offset = (offset / 10) * 1.015 - 2;
  //Serial.println(offset);
  for (int x = 0; x < 5; x++) {
    getVel();
    offsetv += Vel;
    //Serial.print(offsetv);
  }
  //Serial.print(offsetv);
}

void getVel() {

  somaVel = 0;
  for (int x = 0; x < 3; x++) {

    sensorValue = analogRead(pitotPin);
    Vout = (3.3 * sensorValue) / 4095;
    Vout = Vout - 2.5;
    Vout = Vout * 1000;
    Vel = (sqrt((abs(Vout - offset)) * 2 / 1.225));
    if (Vel <= offsetv) {
      Vel = 0;
    }
    somaVel += Vel;
  }

  Vel = somaVel / 3;


}
