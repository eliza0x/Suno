class Error{
  int errorPin;
  
  protected:
    void putError(void){
      digitalWrite(errorPin, HIGH); 
    }
  public:
    void setErrorPin(const int pin){
      errorPin = pin;
      pinMode(pin,OUTPUT);
    }
};
