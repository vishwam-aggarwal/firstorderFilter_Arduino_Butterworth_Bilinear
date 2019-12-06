#include "firstorderFilter.h"
#include "math.h"

firstorderFilter myFilter;

uint32_t loopTimer; //Declaring the time-keeping variable
float F = 10, y, filtered_y; // Signal Frequency set to 10 radians/sec (10/2/pi ~ 1.6 Hz)
float Ts = 0.01; //Sample Time

void setup() {

  Serial.begin(38400); // Serial Baudrate, Use Serial Plotter to visualize the filtering effect

  myFilter.setup(F/4, Ts); // Cutoff Frequency of Filter set to 10/4 = 2.5 radians/sec ~ 0.4 Hz

  loopTimer = micros(); // Initializing Time-Keeping Variable to to current micros() clock
}

void loop() {

  y = sin(F*loopTimer/float(1000000)); // creating signal for filtering
  filtered_y = myFilter.filteredValue(y); //receiving filtered value from the filter for input y

  Serial.print(y); Serial.print(", "); Serial.println(filtered_y);
  
  while(micros() - loopTimer < Ts*1000000); //Waiting for the remaining sample time pass
  loopTimer = micros(); // Resetting the Time-Keeping Variable to the current micros() clock for next sample time execution
}
