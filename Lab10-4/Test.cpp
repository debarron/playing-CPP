#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
  vector<int> p;
  p.push_back(10);
  p.push_back(10);
  p.push_back(10);
  p.push_back(10);
  p.push_back(10);
  p.push_back(10);
  p.push_back(10);
  p.push_back(10);

  cout << "Size: " << p.size() << endl;
  cout << "Capacity: " << p.capacity() << endl;
  cout << "Max size: " << p.max_size() << endl;
  cout << "\n\n";

  vector<int>::iterator it;
  for(it = p.begin(); it != p.end(); it++){
    cout << "Value : " << *it << endl;
  }

  return 0;
}
