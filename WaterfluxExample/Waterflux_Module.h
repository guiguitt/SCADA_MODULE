#ifndef WATERFLUX_H_INCLUDED
#define WATERFLUX_H_INCLUDED
#include <arduino.h>

void WF_Init(int p);
double WF_GetFreq();
void WF_Rising();
void WF_Rising2();
double WF_Debit(float coef);
#endif  //wATERFLUX