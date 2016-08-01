#pragma once

class Error{
  int errorPin;
  int safePin;
  protected:
    void clearError(void){
      digitalWrite(errorPin, LOW); 
      digitalWrite(safePin, HIGH); 
    }
    void putError(void){
      digitalWrite(errorPin, HIGH);
      digitalWrite(safePin, LOW);
    }
  public: 
    void setErrorPin(const int sPin, const int ePin){
      safePin = sPin;
      errorPin = ePin;
      pinMode(sPin,OUTPUT);
      pinMode(ePin,OUTPUT);
      digitalWrite(safePin, LOW);
    }
};
