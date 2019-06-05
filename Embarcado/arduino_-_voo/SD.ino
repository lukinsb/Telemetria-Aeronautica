void SDinit() {
  Serial.print("Initializing SD card...");


  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("SD Card failed");
    sd_enabled = 0;
    delay(2000);
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

}

void SDsend(String data, String archive) {
  File dataFile = SD.open(archive, FILE_WRITE);
  if (dataFile && sd_enabled == 1) {
    dataFile.println(data);
    dataFile.close();
  }
  else if (sd_enabled == 1) {
    Serial.print("error opening");
    Serial.println(archive);
    sd_enabled = 0;

  }

}


void retrieveSD(String archive) {

  File dataFile = SD.open(archive);
  if (dataFile) {
    Serial.println(archive);

    // read from the file until there's nothing else in it:
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    // close the file:
    dataFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.print ("error opening ");
    Serial.println(archive);
  }
}


void printDirectory(File dir, int numTabs) {
  dir.seek(0);
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }

}
