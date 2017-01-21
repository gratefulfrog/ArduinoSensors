#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>


class Config{
  private:
    const unsigned int  id;
  // an example class to be used in initializing a sensor
  public:
    Config(int);
    void init();
};


class Sensor{
  // abstract class defines a sensor Interface 
  // as having a pin and a vector of values, 
  // and methods to reset & access the values
  
  protected:
    // index to lookup values
    static const int curInd  = 0,
                     prevInd = 1;
    const int pinID;
    
    unsigned int values[2];
    void updateValues(unsigned int);
    
  public:
    const String name;
    Sensor(int pi, String name);
    void reset();
    unsigned int getVal(int ind=curInd) const;
    
    // following abstract methods must be defined in child class
    void init(Config&) const;
    virtual boolean read() = 0;
};

class LightSensor : public Sensor{
  private:
    // all light sensors have this value as their lower limit, 
    // i.e. if the analog read is less than this it is noise
    static const unsigned int minVal = 200;   
  public:
    LightSensor(int pi,String name);
    boolean read();
};

class StupiditySensor : public Sensor{
  private:
    static const unsigned int humanStupidty = 65535;       
  public:
    StupiditySensor(int pi,String name);
    boolean read();
};

#endif

