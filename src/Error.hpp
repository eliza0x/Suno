#pragma once

class Error{
  int errorPin;
  int warningPin;
  protected:
    void clearWarning(void){
      digitalWrite(warningPin, LOW); 
    }
    void putWarning(void){
      digitalWrite(warningPin, HIGH); 
    }
    void putError(void){
      digitalWrite(errorPin, HIGH);
    }
  public: 
    void setErrorPin(const int wPin, const int ePin){
      warningPin = wPin;
      errorPin = ePin;
      pinMode(wPin,OUTPUT);
      pinMode(ePin,OUTPUT);
    }
};
