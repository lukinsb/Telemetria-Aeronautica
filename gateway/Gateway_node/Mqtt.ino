void callback(char* topic, byte* payload, unsigned int length) {
  //Serial.print("Message arrived [");
  //Serial.print(topic);
  //Serial.print("] ");
  for (int i = 0; i < length; i++) {
    onemsg += (char)payload[i];
  }
  radioSerial.println(onemsg);
  Serial.println(onemsg);
  twomessage = onemsg;
  onemsg = "";

  //Serial.println();


  // Switch on the LED if an 1 was received as first character
  if (char(payload[0] == '1')) {

    value = LOW;


    // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else if (payload[0] == '0') {
    digitalWrite(ledPin, HIGH);
    value = HIGH;

    // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {

  // Loop until we're reconnected
  if (!client.connected()) {

    while (WiFi.status() != WL_CONNECTED) {
      setup_wifi();
    }
    Serial.println("l,Attempting MQTT connection...");
    verifica_serial_radio();
    verifica_serial_USB();
    if (millis() - time1 > 1000) {
      gaugeSens();
      display.clear();
      atualizaDisplay();
      display.display();

      time1 = millis();
    }
    // Create a random client ID
    String clientId = "HT-";
    clientId += String(random(0xffff), HEX);
    Serial.println("l," + clientId);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("l,connected");
      digitalWrite(ledPin, LOW);
      // Once connected, publish an announcement...
      client.publish("harpiaDataSend", "NodeMCU connected");
      // ... and resubscribe
      client.subscribe("harpiaDataSend");
      mqttStatus = true;

    } else {
      Serial.print("l,failed, rc=");
      digitalWrite(ledPin, HIGH);
      Serial.print("l," + client.state());
      Serial.println("l,try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(1000);
      //gaugeSens();
      //atualizaDisplay();
      mqttStatus = false;

    }
  }

}
