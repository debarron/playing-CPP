#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef tuple<string, int, const char*> Data;

void modify_int(int *v){
  *v = *v * 2;
}

int main(int argc, char **argv){
  // create a vector of objects
  // Keep a pointer to an element
  // Modified the element
  // Check results

  vector<Data> d;
  d.push_back(make_tuple(string("Hello1"), 20, string("world1").data()));
  d.push_back(make_tuple(string("Hello2"), 20, string("world2").data()));
  d.push_back(make_tuple(string("Hello3"), 20, string("world3").data()));
  d.push_back(make_tuple(string("Hello4"), 20, string("world4").data()));
  d.push_back(make_tuple(string("Hello5"), 20, string("world5").data()));

  vector<Data>::iterator it;
  for(it = d.begin(); it != d.end(); ++it){
    Data &d_i = *it;
    modify_int(&get<1>(d_i));

    cout << "RES: " << get<0>(d_i) << " " << get<1>(d_i) << endl;
  }

  return 0;

}
