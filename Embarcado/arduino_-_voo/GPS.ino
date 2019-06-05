void getGPS() {

  while (Serial2.available() > 0) {
    if (gps.encode(Serial2.read())) {

      latitude = gps.location.lat(); // Latitude in degrees (double)
      longitude = gps.location.lng(); // Longitude in degrees (double)
      calendar = gps.date.value(); // Raw date in DDMMYY format (u32)
      hour_clock = gps.time.value(); // Raw time in HHMMSSCC format (u32)
      gps_speed = gps.speed.mps(); // Speed in meters per second (double)
      gps_course = gps.course.deg(); // Course in degrees (double)
      gps_alt = gps.altitude.meters(); // Altitude in meters (double)
      satelites = gps.satellites.value(); // Number of satellites in use (u32)
      precision = gps.hdop.value(); // Horizontal Dim. of Precision (100ths-i32)


    }


  }


  //Serial.print(gps.location.rawLat().negative ? "-" : "+");
  //Serial.println(gps.location.rawLat().deg); // Raw latitude in whole degrees
  //Serial.println(gps.location.rawLat().billionths);// ... and billionths (u16/u32)
  //Serial.print(gps.location.rawLng().negative ? "-" : "+");
  //Serial.println(gps.location.rawLng().deg); // Raw longitude in whole degrees
  //Serial.println(gps.location.rawLng().billionths);// ... and billionths (u16/u32)
  //Serial.println(gps.date.year()); // Year (2000+) (u16)
  //Serial.println(gps.date.month()); // Month (1-12) (u8)
  //Serial.println(gps.date.day()); // Day (1-31) (u8)
  //Serial.println(gps.time.hour()); // Hour (0-23) (u8)
  //Serial.println(gps.time.minute()); // Minute (0-59) (u8)
  //Serial.println(gps.time.second()); // Second (0-59) (u8)
  //Serial.println(gps.time.centisecond()); // 100ths of a second (0-99) (u8)
  //Serial.println(gps.speed.value()); // Raw speed in 100ths of a knot (i32)
  //Serial.println(gps.speed.knots()); // Speed in knots (double)
  //Serial.println(gps.speed.mph()); // Speed in miles per hour (double)
  //Serial.println(gps.speed.kmph()); // Speed in kilometers per hour (double)
  //Serial.println(gps.course.value()); // Raw course in 100ths of a degree (i32)
  //Serial.println(gps.altitude.value()); // Raw altitude in centimeters (i32)
  //Serial.println(gps.altitude.miles()); // Altitude in miles (double)
  //Serial.println(gps.altitude.kilometers()); // Altitude in kilometers (double)
  //Serial.println(gps.altitude.feet()); // Altitude in feet (double)


}
