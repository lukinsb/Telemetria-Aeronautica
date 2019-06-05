
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network

  Serial.print("l,Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("l,.");
    //gaugeSens();
    //atualizaDisplay();
    verifica_serial_radio();
    verifica_serial_USB();
    if (millis() - time1 > 1000) {
      gaugeSens();
      display.clear();
      atualizaDisplay();
      display.display();

      time1 = millis();
    }

  }



  randomSeed(micros());


}
