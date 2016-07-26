/* Error クラス */
class Error{
  int errorPin; /* エラーピンの番号を表す */
  
  protected:
    void putError(void){
      digitalWrite(errorPin, HIGH); 
    }
  public:
    /* エラーLEDのピンを設定する関数 */
    void setErrorPin(const int pin){
      errorPin = pin;
      pinMode(pin,OUTPUT);
    }
};
