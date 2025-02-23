#pragma once
#include <systemobject.h>



class CBaseDrive:public CSystemObject{
  bool bOn=false;
  int _motor=0;
  float _mspeed=0.0;
  int _mdir=1;
  float _setSpeed=1.0;
  int _PWMSpeed=0;



 

  unsigned long _driveStartTime=0;
  unsigned long _maxRunTime=10000;
  unsigned long _driveInterval=0;
  unsigned long _modifiedTime=0;
  unsigned long _duration=0;
  unsigned long _changedOn=0;
protected: 
  const int freq = 10000;
  const int resolution = 12;

  PinName PIN_SIGNAL;
  PinName PIN_DIR;
  PinName PIN_FG;  //Feedback
 
  static int channel;
  int _channel;
public:
  CBaseDrive();

  void init();

  void Forward(float s=1.0,unsigned long dur=0);
  void Backward(float s=1.0,unsigned long dur=0);
  void Reverse();

  bool isForward();
  
  virtual void Speed(float s=1.0,unsigned long dur=0);
  
  virtual void activateDrive(float val){}
  virtual void runOnce(CMsg &m){};
  
  void sendPWM(int nVal);

  int Speed(){return _mspeed;};
  void TestMotor(); 
  void loop();
  void stopActuator();

  float getSetSpeed(){return _setSpeed;}
  void setSetSpeed(float tmp){_setSpeed=tmp;}

  int getPWMSpeed(){return _PWMSpeed;};
  void setPWMSpeed(float tmp){_PWMSpeed=tmp;};

  int getMSpeed(){return _mspeed;};
  void setMSpeed(float tmp){_mspeed=tmp;};
 

  unsigned long getDuration(){return _duration;};
  void setDuration(unsigned long tmp){_duration=tmp;}
  

  unsigned long getMaxRunTime(){return _maxRunTime;};
  void setMaxRunTime(unsigned long tmp){_maxRunTime=tmp;}
  
  unsigned long getModifiedTime(){return _modifiedTime;};
  void setModifiedTime(unsigned long tmp){_modifiedTime=tmp;}
  
  unsigned long getDriveInterval(){return _driveInterval;};
  void setDriveInterval(unsigned long tmp){_driveInterval=tmp;}
 
  void setDir(int tmp=0){_mdir=tmp;};
  int getDir(){return _mdir;};

  unsigned long getDriveStartTime(){return _driveStartTime;};
  void setDriveStartTime(unsigned long tmp){_driveStartTime=tmp;}

  void setMotor(int tmp){_motor=tmp;};
  int getMotor(){return _motor;};

  void callNewFunction(CMsg &msg);  
};
