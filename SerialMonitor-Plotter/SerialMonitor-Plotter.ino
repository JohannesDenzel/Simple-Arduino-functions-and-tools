//Licence: MIT
//Autor: Johannes Denzel, 21.09.2022
//If no Serial Plotter is Available this sketch can be used to use the monitor as a simple plotter

//const uint16_t maxPoints = 256; //Number of points used to draw a line

//can only draw a positive axis
//maxPoints - maximum length of line
void DrawLine(uint16_t maxPoints, uint16_t maxValue, uint16_t minValue, uint16_t value){
  uint16_t nPoints_uint = 0;
  float nPoints_float = 0;
  if(value > maxValue){
    value = maxValue;
  }

  if(value < minValue){
    value = minValue;
  }

  nPoints_float = (float) ((value - minValue) * (maxPoints * 1.0/maxValue));
  //nPoints_uint = (uint16_t) nPoints_float; //0.9999 -> 0.0  
  nPoints_uint = (uint16_t) nPoints_float + 0.5; //0.499 -> 0.0, 0.5 -> 1

  for(uint16_t point = 0; point < nPoints_uint; point++){
    Serial.print('.');
  }
  Serial.println();
  //Serial.println(nPoints_float);
}

void setup() {
  Serial.begin(115200);

}

void loop() {
  static uint16_t val = 0;
  const uint16_t maxVal = 500;
  const uint16_t minVal = 200;
  const uint16_t maxPoints = 150;
  val+=10;
  if(val > maxVal){
    val = 300;
  }

  //Serial.println(val);
  DrawLine(maxPoints, maxVal, minVal, val);

delay(10);
}
