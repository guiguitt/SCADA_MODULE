#ifndef ULTRASON_H_INCLUDED
#define ULTRASON_H_INCLUDED

#include <arduino.h>
class Ultrason_Module {
  public:
    Ultrason_Module(int trigger, int echo);
    Ultrason_Module(int trigger, int echo, int minRange, int maxRange);
    unsigned int echoInms();
    float distance();
    float mesure(int nbre, int timing, bool debug);
    float etalonnage(float distance, int nbre, int timing, bool debug);
  private:
    float Speed = 0.344;
    int _trigger;
    int _echo;
    int _minRange;
    int _maxRange;
};
#endif  //ULTRASON