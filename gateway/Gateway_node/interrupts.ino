void inicializa() {
  telainicial();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  reconnect();
  verifica_serial_radio();
  verifica_serial_USB();
}

void menuMais() {

  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounceInterval) //declare the debounce/block out interval in setup
  {
    if (menu < 4) {
      menu = menu + 1;
    }
    else {
      menu = 0;
    }

  }
  last_interrupt_time = interrupt_time;

 // Serial.print(menu);
}

void menuMenos() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > debounceInterval) //declare the debounce/block out interval in setup
  {
    if (menu > 0) {
      menu = menu - 1;
    }
    else {
      menu = 4;
    }

  }
  last_interrupt_time = interrupt_time;

//Serial.print(menu);

}
