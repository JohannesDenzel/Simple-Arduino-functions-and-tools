

/* this method doesnt work

//shifts all elements in array to position = last position + 1, write vallu to position 0
//arrayPointer is pointer to first element of array  
void Array_FirstIn_FirstOut(uint16_t * arrayAdress, uint16_t arraySize, long value){

  //shift elements
  for(uint16_t arrPosition = 0; arrPosition < arraySize - 1; arrPosition++){
    //arrayAdress is the adress of the first element array in the RAM, the next element is at the adress arrayAdress + 1.
    //*arrayAdress is the value at this address. *(arrayAdress + 1) is the next value (second value in array)
    //So (arrayAdress + arrPosition) is the adress to the value at arrPosition in the Array. (arrayAdress + arrPosition + 1) is the adress to the value next to it.
    *(arrayAdress + arrPosition + 1) = *(arrPosition + arrPosition);
  }

  *arrayPointer[0] = value;
  
}

*/
//shifts all elements in array to position = last position + 1, write vallu to position 0
//arrayPointer is pointer to first element of array  
void Array_FirstIn_FirstOut(uint16_t arr[], uint16_t arraySize, long value){

  //shift elements
  for(uint16_t arrPosition = arraySize - 1; arrPosition > 0; arrPosition--){
    //arrayAdress is the adress of the first element array in the RAM, the next element is at the adress arrayAdress + 1.
    //*arrayAdress is the value at this address. *(arrayAdress + 1) is the next value (second value in array)
    //So (arrayAdress + arrPosition) is the adress to the value at arrPosition in the Array. (arrayAdress + arrPosition + 1) is the adress to the value next to it.
    arr[arrPosition] = arr[arrPosition - 1];
  }

  arr[0] = value;
  
}



void setup() {
  Serial.begin(115200);

}

void loop() {
  static uint16_t testArray[10] = {1,2,3,4,5,6,7,8,9,10};
  static uint16_t i = 0;
  const uint16_t arrTestSize = 5; //test with size that is smaller than actual size to see if function really only writes at the positions it should. the values 6,7,8,9,10 should not change.

  Array_FirstIn_FirstOut(testArray, arrTestSize, i);

  //print whole array:
  for(uint16_t k = 0; k < 10; k++){
    Serial.print(String(testArray[k]) + " ");
  }
  Serial.println();

  i++;
  delay(500);
}
