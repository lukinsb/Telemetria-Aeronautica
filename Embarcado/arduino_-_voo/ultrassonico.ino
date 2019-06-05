void getDist() {
  // Clears the trigPin

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH, 11000);

  // Calculating the distance
  SoundSpeed = 331 + 0.6 * temp;
  distance = duration * (SoundSpeed / 10000) / 2;

  if (distance == 0 || distance > 400) {
    distance = -1.0 ;

  }
}
