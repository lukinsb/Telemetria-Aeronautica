

void telainicial() {

  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 15, "Harpia");
  display.setFont(ArialMT_Plain_10);
  display.drawString(63, 35, "Gateway Local");
  display.drawString(63, 45, "Conectando Wi-Fi");
  display.display();
}


void atualizaDisplay() {


  String ip = WiFi.localIP().toString();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  // display.clear();
  display.drawString(5, 0, "IP: ");
  display.drawString(20, 0, ip);
  // display.display();

  if (mqttStatus == true) {
    display.fillCircle(120, 8, 3);
    //display.display();
  }
  else if (mqttStatus == false) {
    display.drawCircle(120, 8, 3);
    // display.display();
  }

  if (menu == 0) {
    imprimeTexto(63, 15, "Voltage In: ");
    imprimeTexto(63, 35, String(bat_tension) + " v");
    display.fillCircle(43, 60, 2);
    display.drawCircle(53, 60, 2);
    display.drawCircle(63, 60, 2);
    display.drawCircle(73, 60, 2);
    display.drawCircle(83, 60, 2);
    //display.display();


  }

  else if (menu == 1) {
    if (bat_tension < 8 && bat_tension >= 6) {
      imprimeTexto(63, 15, "Battery Life: ");
      imprimeTexto(63, 35, String(bat_gauge) + " %");
    }
    else if (bat_tension < 6) {

      imprimeTexto(63, 15, "Warning - Low Bat");
      imprimeTexto(63, 35, "Plug in Source");

    }
    else {
      imprimeTexto(63, 15, "Battery Status: ");
      imprimeTexto(63, 35, "Plugged In");

    }
    display.drawCircle(43, 60, 2);
    display.fillCircle(53, 60, 2);
    display.drawCircle(63, 60, 2);
    display.drawCircle(73, 60, 2);
    display.drawCircle(83, 60, 2);
    // display.display();

  }
  else if (menu == 2) {
    imprimeTexto(63, 15, "Radio Payload: ");
    imprimeTexto(63, 35, stringComando);
    display.drawCircle(43, 60, 2);
    display.drawCircle(53, 60, 2);
    display.fillCircle(63, 60, 2);
    display.drawCircle(73, 60, 2);
    display.drawCircle(83, 60, 2);
    //display.display();


  }
  else if (menu == 4) {
    if (millis() - time2 > 500 &&  messageStatus == false) {
      imprimeTexto(63, 15, "Data Status");
      imprimeTexto(63, 35, "Waiting");
    }

    if (messageStatus == true) {
      time2 = millis();
      messageStatus = false;
      imprimeTexto(63, 15, "Data Status");
      imprimeTexto(63, 35, "Receiving");
    }
    display.drawCircle(43, 60, 2);
    display.drawCircle(53, 60, 2);
    display.drawCircle(63, 60, 2);
    display.drawCircle(73, 60, 2);
    display.fillCircle(83, 60, 2);
    //display.display();
  }

  else if (menu == 3) {
    imprimeTexto(63, 15, "MQTT Payload: ");
    imprimeTexto(63, 35, twomessage);
    display.drawCircle(43, 60, 2);
    display.drawCircle(53, 60, 2);
    display.drawCircle(63, 60, 2);
    display.fillCircle(73, 60, 2);
    display.drawCircle(83, 60, 2);
    //display.display();

  }
}


void imprimeTexto(int x, int y, String txt) {
  //Apaga o display
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_10);
  display.drawString(x, y, txt);
  // display.display();
}
