#ifndef firstorderFilter_h
#define firstorderFilter_h

#include "Arduino.h"

class firstorderFilter
{
  public:
	void setup(float cutOff, float Ts);
    float filteredValue(float u);
  private:
   /************************
   Filter Parameters
   ************************/
   float cutOff;
   float Ts;
   float _a;
   float _b;
   /************************
   Filter states
   ************************/
	float _prev_u;
	float _prev_y;
	float _y;
};

#endif
