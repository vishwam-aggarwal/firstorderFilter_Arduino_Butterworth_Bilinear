/******************************************************************************
 * Includes
 ******************************************************************************/

#include "Arduino.h"
#include "firstorderFilter.h"
/***********************************************************************************************
The setup function needs to be called first 
cutOff - cutoff frequency in rad/sec
Ts- Sampling time

Discrete time Transfer Function of filter [tustin] is y = a*[u + prev_u] - b*prev_y

where

a = Ts*cutOff/(Ts*cutOff + 2)
b = (Ts*cutOff - 2)/(Ts*cutOff + 2)
  
************************************************************************************************/
void firstorderFilter::setup(float cutOff, float Ts)
{
this->cutOff = cutOff;
this->Ts = Ts;
_a = Ts*cutOff/(Ts*cutOff + 2);
_b = (Ts*cutOff - 2)/(Ts*cutOff + 2);
_prev_u = 0;
_prev_y = 0;
}
/************************************************************************************
This function computes the low pass filtered value of the input at cutOff rad/sec

**************************************************************************************/
float firstorderFilter::filteredValue(float u)
{
 _y = _a*(u + _prev_u) - _b*(_prev_y);
 
 _prev_u = u;
 _prev_y = _y;
 
 return _y;
}