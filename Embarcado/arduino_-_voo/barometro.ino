void baroInit() {
  if (!bme.begin()) {
    Serial.println("Barometer Error");
    delay(2000);
    //while (1);
  }

}

void getBaro() {
  temp = bme.readTemperature();
  pressure = bme.readPressure();
  alt = bme.readAltitude(cont_alt); // this should be adjusted to your local forcase
  alt_den = pressure*0.0002953;
  tk = temp+273.15;
  alt_den=44330.7*(1-pow((alt_den/(cont_alt/33.864))/(tk/288.15),0.234969));
   
  
}
