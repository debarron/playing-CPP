#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main(){
  tuple<char, int, string> simple_tuple;
  simple_tuple = make_tuple('b', 20, "something longer than a char");

  cout << "## EXAMPLE 1" << endl
       << "Value 1: " << get<0>(simple_tuple) << endl
       << "Value 2: " << get<1>(simple_tuple) << endl
       << "Value 3: " << get<2>(simple_tuple) << endl << endl;
 

  // Example with a pointer
  tuple<char*,int,string> tuple_with_pointer;
  char *a_pointer;
  int a_pointer_length;
  string a_pointer_key;

  a_pointer_key = "Yup, just a key";
  a_pointer_length = 10;
  a_pointer = (char *)malloc(sizeof(char) * a_pointer_length);
  memset(a_pointer, '*', a_pointer_length);

  // Pack and unpack
  tuple_with_pointer = make_tuple(a_pointer, a_pointer_length, a_pointer_key);
  cout << "## EXAMPLE 2 " << endl
       << "Value 1: " << get<0>(tuple_with_pointer) << endl
       << "Value 2: " << get<1>(tuple_with_pointer) << endl
       << "Value 3: " << get<2>(tuple_with_pointer) << endl << endl;

  return 0;
}
