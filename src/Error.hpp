class Error{
  int errorPin;
   void setErrorPin(const int pin){
    errorPin = pin;
    pinMode(pin,OUTPUT);
  }
 
  protected:
    void putError(void){
      digitalWrite(errorPin, HIGH); 
    }
};
