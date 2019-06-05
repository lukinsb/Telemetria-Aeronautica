void getTens() {


  out_bat = analogRead(outBat_pin);
  outbat_tension = (out_bat / 4095.0) * 3.3;
  outbat_tension = outbat_tension * 2.88888888889;

  if (outbat_tension >= 7.2) {

    outbat_gauge = 1;
  }

  else if (outbat_tension >= 6.5) {

    outbat_gauge = (1.126761 * (outbat_tension - 7.2)) + 1;

  }

  else if (outbat_tension <= 6) {
    outbat_gauge = 0;
  }

  else {
    outbat_gauge = (-(0.4242 * pow(outbat_tension, 6)) + (13.327 * pow(outbat_tension, 5)) - (173.5 * pow(outbat_tension, 4)) + (1198.2 * pow(outbat_tension, 3)) - (4630.1 * pow(outbat_tension, 2)) + (9493 * outbat_tension) - 8068.7);
  }


  outbat_gauge = outbat_gauge * 100;



}



void getCurr() {
  RawValue = analogRead(corrente_pin);
  Amps = (RawValue / 4095.0) * 5000; // Gets you mV
  Amps = ((Amps - 2500) / 66);

}
