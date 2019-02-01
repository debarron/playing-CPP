#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define SIZE 5

template <class T>
T retrieveMin(T arr[]){
  T value = arr[0];

  for(int i = 1; i < SIZE; i++){
    if(value > arr[i]){
      value = arr[i];
    }
  }
  return value;
}

int main(){
  int valuesInt[SIZE] = {2, 5, 1, 0, 10};
  string valuesString[SIZE] = {"hello", "world", "this", "is", "theEnd"};
  double valuesDouble[SIZE] = {2.0, 5.0, 1.0, 0.0, 10.0};

  cout << "The min int is: " << retrieveMin(valuesInt) << endl;
  cout << "The min string is: " << retrieveMin(valuesString) << endl;
  cout << "The min double is: " << retrieveMin(valuesDouble) << endl;
  return 0;
}


int retrieveMinInt(int arr[]){
  int value = arr[0];
  for(int i = 1; i < SIZE; i++){
    if(value > arr[i]){
      value = arr[i];
    }
  }
  return value;
}
