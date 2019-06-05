 void accelInit() {

  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.println("Accelerometer Error");
    delay(2000);
    // while (1);
  }

  bno.setExtCrystalUse(true);

}

void accelcalib() {

  int8_t temp = bno.getTemp();

  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);

}

void getOrientation() {
  sensors_event_t event;
  bno.getEvent(&event);
  OrientX = event.orientation.x;
  OrientY = event.orientation.y;
  OrientZ = event.orientation.z;
}


void getEuler() {
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  eulerX = euler.x();
  eulerY = euler.y();
  eulerZ = euler.z();
  }

void getGravity() {
  imu::Vector<3> gravity = bno.getVector(Adafruit_BNO055::VECTOR_GRAVITY);
  gravityX = gravity.x();
  gravityY = gravity.y();
  gravityZ = gravity.z();
  }

void getAccel() {
  imu::Vector<3> accelerometer = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  accelX = accelerometer.x();
  accelY = accelerometer.y();
  accelZ = accelerometer.z();
}

void getMag() {
  imu::Vector<3> magnetometer = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
  magX = magnetometer.x();
  magY = magnetometer.y();
  magZ = magnetometer.z();
  }

void getGyro() {
  imu::Vector<3> gyroscope = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  gyroX = gyroscope.x();
  gyroY = gyroscope.y();
  gyroZ = gyroscope.z();
  }

void getLin() {
  imu::Vector<3> linearaccel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
  linX = linearaccel.x();
  linY = linearaccel.y();
  linZ = linearaccel.z();


}
