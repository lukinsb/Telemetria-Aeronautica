void verifica_serial_radio() {                // esta funcao e responsavel por receber os comandos enviados pelo Arduino via interface serial

  if (radioSerial.available() > 0) {         // verifica se existem comandos na interface serial provenientes do ESP8266
    qtdeBytesComandoRecebido = radioSerial.readBytesUntil(10, comandoRecebido, 250);  // le os dados da serial ate receber o LINE FEED "\n" ASCII=10,com um limite de 100 caracteres e tambem conta quantos caracteres foram recebidos armazenando em "qtdeBytesComandoRecebido"
    comandoRecebido[qtdeBytesComandoRecebido] = 0;    // adicionamos um 0 no final do Array de caracteres recebidos. Isto ira parar a transmissao de dados que tiverem permanecido no buffer
    stringComandoCompleta = true;                     // indica que os dados do comando foram recebidos corretamente
    stringComando = String(comandoRecebido);          // converte os dados recebidos para String e armazena em "stringComando"
    //Serial.println(stringComando);
  }

  if (stringComandoCompleta == true) {               // verifica se o comando foi recebido corretamente

    client.publish("harpiaData", comandoRecebido);
    Serial.println(stringComando);
    messageStatus = true;
   


    for (int i = 0 ; i < 250 ; i++) {                // limpa array comandoRecebido
      comandoRecebido[i] = ' ';
    }

    stringComandoCompleta = false;                   // reseta a variavel que indica que o comando foi recebido corretamente preparando para receber proximo comando
  }
}
