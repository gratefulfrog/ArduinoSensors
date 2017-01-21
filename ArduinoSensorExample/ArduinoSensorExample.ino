#include "Sensor.h"

const int lightSensorPin = A3,
          stupiditySensorPin = 0;

unsigned int loopCount = 0;

const String lightSensorName = "Frank the light sensor",
             stupidityDetectorName = "John the all seeing stupidity detector, overlaoded with work";

const int nbSensors = 2; 

// here we have a vector of pointers to concrete instances inheriting from an anstract class!
// this is a key concept in object programming!
const Sensor* sensorVec[nbSensors] = {new LightSensor(lightSensorPin,lightSensorName),
                                      new StupiditySensor(stupiditySensorPin,stupidityDetectorName)
                                     };
    
void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println();

  // just for tests..
  randomSeed(analogRead(0));
  // end of just for tests

  loopCount = 0;
  // initalize the sensors!
  for(int i=0;i<nbSensors;i++){
    Config conf = Config(i);
    sensorVec[i]->init(conf);
  }
}

// little helper function to do Serial output
void output(int i, boolean valueFound){
  Serial.print("Sensor: ");
  Serial.print(i);
  Serial.print(" ");
  Serial.print(sensorVec[i]->name);
  Serial.print(" detected: ");
  Serial.println(valueFound ? String(sensorVec[i]->getVal()) : "nothing...");
}

void loop() {
  Serial.print("Cycle : ");
  Serial.println(loopCount++);
  for(int i=0;i<nbSensors;i++){
    output(i, sensorVec[i]->read());
  }
  delay(2000);
} 



