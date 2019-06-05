void gaugeSens() {
  digitalWrite(batSign, HIGH);
  if (bat_gauge < 21) {
    digitalWrite(batSign, LOW);
  }
    in_bat = analogRead(sensorPin);
  //in_bat = in_bat - 1;
  bat_tension = (in_bat / 1023.0) * 3.215;
  bat_tension = bat_tension * 2.88888888889;

  if (bat_tension >= 6.8) {

    bat_gauge = 1;
  }

  else if (bat_tension >= 6.5) {

    bat_gauge = (1.126761 * (bat_tension - 6.8)) + 1;

  }

  else if (bat_tension <= 6) {
    bat_gauge = 0;
    count++;
    // if(count>1){
    //   rstc_start_software_reset(RSTC);
    // }
  }

  else {
    bat_gauge = (-(0.4242 * pow(bat_tension, 6)) + (13.327 * pow(bat_tension, 5)) - (173.5 * pow(bat_tension, 4)) + (1198.2 * pow(bat_tension, 3)) - (4630.1 * pow(bat_tension, 2)) + (9493 * bat_tension) - 8068.7);
  }

  bat_gauge = bat_gauge * 100;


  //Serial << "Porcentagem Bateria: " << _FLOAT(bat_gauge, 0) << " " << "Tensão Bateria: " << _FLOAT(bat_tension, 2) << "\n";
  //radioSerial << "Porcentagem Bateria: " << _FLOAT(bat_gauge, 0) << " " << "Tensão Bateria: " << _FLOAT(bat_tension, 2) << "\n";
  //Serial.print("  ");
  //Serial.print("Tensão Bateria: ");
  //Serial.println(bat_tension, 3);
  //delay(1000);
}
