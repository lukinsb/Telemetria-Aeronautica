void verifica_serial_radio() {                // esta funcao e responsavel por receber os comandos enviados pelo Arduino via interface serial

  if (Serial1.available() > 0) {         // verifica se existem comandos na interface serial provenientes do ESP8266
    qtdeBytesComandoRecebido = Serial1.readBytesUntil(10, comandoRecebido, 150);  // le os dados da serial ate receber o LINE FEED "\n" ASCII=10,com um limite de 100 caracteres e tambem conta quantos caracteres foram recebidos armazenando em "qtdeBytesComandoRecebido"
    comandoRecebido[qtdeBytesComandoRecebido] = 0;    // adicionamos um 0 no final do Array de caracteres recebidos. Isto ira parar a transmissao de dados que tiverem permanecido no buffer
    stringComandoCompleta = true;                     // indica que os dados do comando foram recebidos corretamente
    stringComando = String(comandoRecebido);          // converte os dados recebidos para String e armazena em "stringComando"

  }

  if (stringComandoCompleta == true) {               // verifica se o comando foi recebido corretamente

 
    Serial.println(comandoRecebido);
    
     if (stringComando == "qnh") {
      send_if = false;
      Serial.println("Digite o qnh");
      while (!Serial.available()) {}
      stringComando = leSerial();
      cont_alt = stringComando.toFloat();

    }

        if (stringComando == "stop") {
      send_if = false;
      Serial.println("Stopping");
    }

    if (stringComando == "continue") {
      send_if = true;
      Serial.println("Continuing");

    }
   


    for (int i = 0 ; i < 150 ; i++) {                // limpa array comandoRecebido
      comandoRecebido[i] = ' ';
    }

    stringComandoCompleta = false;                   // reseta a variavel que indica que o comando foi recebido corretamente preparando para receber proximo comando
  }
}
