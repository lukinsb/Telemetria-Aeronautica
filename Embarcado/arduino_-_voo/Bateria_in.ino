void getBat() {


  in_bat = analogRead(inBat_pin);
  bat_tension = (in_bat / 4096.0) * 3.3;
  bat_tension = bat_tension * 2.888888889;

  if (bat_tension >= 7.2) {
    bat_gauge = 1;
  }

  else if (bat_tension >= 6.5) {

    bat_gauge = (1.126761 * (bat_tension - 7.2)) + 1;

  }

  else if (bat_tension <= 6) {
    bat_gauge = 0;
  }

  else {
    bat_gauge = (-(0.4242 * pow(bat_tension, 6)) + (13.327 * pow(bat_tension, 5)) - (173.5 * pow(bat_tension, 4)) + (1198.2 * pow(bat_tension, 3)) - (4630.1 * pow(bat_tension, 2)) + (9493 * bat_tension) - 8068.7);
  }

  bat_gauge = bat_gauge * 100;


}
