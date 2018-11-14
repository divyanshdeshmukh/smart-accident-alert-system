#include "TinyGPS++.h"
#include "SoftwareSerial.h"

SoftwareSerial serial_connection(10, 11); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data

int buzzerPin = 12; 
int swtch = 13; 
void setup() 
{
  Serial.begin(9600);
  pinMode(swtch, INPUT);
  pinMode(buzzerPin, OUTPUT);
  //serial_connection.begin(9600);//This opens up communications to the GPS
}

void loop()
{
  
  while (serial_connection.available()) //While there are characters to come from the GPS
  {
    gps.encode(serial_connection.read());//This feeds the serial NMEA data into the library one char at a time
  }
  if (gps.location.isUpdated()) //This will pretty much be fired all the time anyway but will at least reduce it to only after a package of NMEA data comes in
  {
    //Get the latest info from the gps object which it derived from the data sent by the GPS unit
    delay(5000);
    //Serial.println("Satellite Count:");
    //Serial.println(gps.satellites.value());
    //Serial.println("Latitude:");
    //Serial.println(gps.location.lat(), 6);
    //Serial.println("Longitude:");
    //Serial.println(gps.location.lng(), 6);
    //Serial.println("Speed MPH:");
    //Serial.println(gps.speed.mph());
    //Serial.println("Altitude Feet:");
    //Serial.println(gps.altitude.feet());
    //Serial.println("");
    Serial.println(gps.location.lat(),6);
    Serial.println(gps.location.lng(),6);
  }
  if(debounce(swtch)== LOW)
  {
    tone(buzzerPin, 500);
    Serial.println("detected");
    delay(500);
    noTone(buzzerPin);
    delay(1000);
  }
}
int debounce(int pin)
{
  int state, previous_state;
  previous_state = digitalRead(pin); 
  for(int i = 0; i < 25; i++)
  {
    delay(1);                       
    state = digitalRead(pin);       
    if( state != previous_state)
    {
      i = 0;                  
      previous_state = state;       
    }
  }
  return state;
}
