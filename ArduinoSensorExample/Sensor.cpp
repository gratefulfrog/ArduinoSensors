#include "Sensor.h"



/////////////////////// Config Class Methods ////////////////////////
/* These methods are all just stubs,
 * real code will have to go here...
 */

Config::Config(int i): id(i){
}

void Config::init(){
  // do stuff here
  Serial.print("Config: ");
  Serial.print(id);
  Serial.println(" initialized!");
}

/////////////////////// END of Config Class Methods ////////////////////////


/////////////////// Sensor class methods  //////////////////////////
/* Thes Sensor class  is an abstract class serving as an itnerface for all sensors
 */


// constructor assigns pin and name
Sensor::Sensor(int pi,String n): pinID(pi),name(n){
  reset();
}

// resets values vector to (zero,zero)
void Sensor::reset(){
  values[curInd]=values[prevInd]=0;
}

// previous value is assigned current value,
// current value is assigned argument value
void Sensor::updateValues(unsigned int v){
  values[prevInd] = values[curInd];
  values[curInd] = v;
}

// return the value referred by the ind argument, defaults to current
unsigned int Sensor::getVal(int ind = Sensor::curInd) const{
  return values[ind];
}

// this is a stub
// it just calls the argument's init() method
void Sensor::init(Config& cr) const{
  cr.init();
}

/////////////////////// END of Sensor Class Methods ////////////////////////

/////////////////// LightSensor class methods  //////////////////////////// 
// constructor, just invokes parent
LightSensor::LightSensor(int p,String n) : Sensor(p,n){
}

// read method:
// reads the sensor
// compares value read to current value and minimum value
// if greater than min and different from current then update value vector and return TRUE
// otherwise do not update and return FALSE
boolean LightSensor::read(){
  bool newVal = false;
  // in real life this would be called
  // int valueRead = analogRead(pinID);

  // just for testing
  unsigned int valueRead = random(0,1000);
  // end of just for testing!
  
  if ((valueRead > LightSensor::minVal) && (valueRead  != values[curInd])){
    // if the value we read is greater than the min and different from the last value,
    // then we got a new valid value
    updateValues(valueRead);
    newVal=true;
  }
  return newVal;
}


////////////////  STUPIDITY SENSOR EXAMPLE only (stupidity is so omnipresnet, its detection is impossible)!!!!!  /////////////////////
/////////////////////// END of Sensor Class Methods ////////////////////////

/////////////////// StupiditySensor class methods  (stupidity is maxed out...)!!!!!   //////////////////////////// 
// constructor, invokes parent, and updates current values to humanStupidity class const
StupiditySensor::StupiditySensor(int p,String n) : Sensor(p,n){
  updateValues(humanStupidty);
}

boolean StupiditySensor::read(){
  return true; // there is always more human stupidty available! 
}

