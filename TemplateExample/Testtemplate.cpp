// debarron
// 4/21/2017
// An example of templates

#include <string>
#include <iostream>

#define SIZE 5
using namespace std;
// TODO: get the minimum element in all the arrays, using a function

template <class G>
G getMin(G arr[]){
  G value = arr[0];

  for (int i = 1; i < SIZE; i++) {
    if(arr[i] < value){
      value = arr[i];
    }
  }
  return value;
}

int getMinInt(int arr[]){
  int value = arr[0];
  for (int i = 1; i < SIZE; i++) {
    if(arr[i] < value){
      value = arr[i];
    }
  }
  return value;
}

double getMinDbl(double arr[]){
  double value = arr[0];
  for (int i = 1; i < SIZE; i++) {
    if(arr[i] < value){
      value = arr[i];
    }
  }
  return value;
}

int main(){
  int arrInt[SIZE] = {2, 4, 6, 1, 9};
  double arrDbl[SIZE] = {2.0, 4.0, 6.0, 1.0, 9.0};
  string arrStr[SIZE] = {"helo", "world", "I", "passed", "away"};

  // for ints => getMinInt
  cout << "The minimum integer is: " << getMinInt(arrInt) << "\n";
  cout << "The minimum double is: " << getMinDbl(arrDbl) << "\n\n";

  cout << "The minimum element in [strings]: " << getMin(arrStr) << "\n";
  cout << "The minimum element in [int]: " << getMin(arrInt) << "\n";
  cout << "The minimum element in [double]: " << getMin(arrDbl) << "\n";

}
