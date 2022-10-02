//PT 1 Filter
 ///////////////////////////////////////////////////////////
// this function is a diskrete PT1 filter, its exact, as long uk0 konstant over one timestep
// the matimatical function would be: y[k+1] = u[k] * (1 - exp(-timestep * fknick)) + exp(-timestep * fknick) * y[k]
// inputs:
// yk0 - y[k] the last value of this function, or start value
// uk0 - input signal (from adc) 
// timestep - timestep between two adc measurements
// fknick - kink (german knick) frequency where the transfere function knicks down

int PT1_val(int yk0, int uk0, float timestep, float fknick){
  float e = 2.71828;
  double a = pow(e, -timestep*fknick);
  int yk1 = (int) uk0 * (1-a) + a * yk0;
  return yk1;
}

//PT 1 Filter
 ///////////////////////////////////////////////////////////
// this function is a diskrete PT1 filter, its exact, as long uk0 konstant over one timestep
// the matimatical function would be: y[k+1] = u[k] * (1 - exp(-timestep * fknick)) + exp(-timestep * fknick) * y[k]
// inputs:
// yk0 - y[k] the last value of this function, or start value
// uk0 - input signal (from adc) 
// timestep - timestep between two adc measurements
// fknick - kink (german knick) frequency where the transfere function knicks down

//alternativ 1/n if timestep=constant 

int PT1_val(int yk0, int uk0, float n){
  float e = 2.71828;
  double a = pow(e, -1/n);
  int yk1 = (int) uk0 * (1-a) + a * yk0;
  return yk1;
}