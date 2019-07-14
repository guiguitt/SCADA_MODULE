#ifndef LEDIND_H_INCLUDED
#define LEDIND_H_INCLUDED
#include <arduino.h>

#define LED_ON 0
#define LED_WIFI 1
#define LED_FAIL 2


class LedIndicator_Module {
  public:
    LedIndicator_Module();
    void ON(bool statue);
    void ON();
    void WIFI(bool statue);
    void WIFI();
    void FAIL(bool statue);
    void FAIL();
  private:
    int on;
    int wifi;
    int fail;

};
#endif  //LEDIND