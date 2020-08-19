#include <vector>
#include <string>
#include <iostream>

using namespace std;

class SimpleOb {
  public:
    int num;
    float fnum;
    string name;

    SimpleOb(){
      num = 0;
      fnum = 0.0;
      name = "N/A";
    }
    SimpleOb(int _num, float _fnum, string _name){
      num = _num;
      fnum = _fnum;
      name = _name;
    }
};

ostream& operator<<(ostream &strm, const SimpleOb &a){
  return strm << "SimpleOb(num:" << a.num <<
                          ",fnum:" << a.fnum << 
                          ",name:" << a.name;
}

template <typename T>
vector<T> genericVector(T a){
  vector<T> myVector;
  myVector.push_back(a);

  return myVector;
}

void testString(){
  cout << "## Generic STRING \n";
  string name = "Daniel";
  
  vector<string> myStrings = genericVector<string>(name);
  myStrings.push_back("Ernesto");
  myStrings.push_back("Betania");

  for (int i = 0; i < myStrings.size(); i++)
    cout << " Pos " << i << " = " << myStrings[i] << " \n";

  cout << "## End STRING\n";
}

void testInt(){
  cout << "Generci INT\n";
  vector<int> vec = genericVector<int>(3);
  vec.push_back(4);
  vec.push_back(5);

  for(int i = 0; i < vec.size(); i++)
    cout << "Pos " << i << " = " << vec[i] << " \n";

  cout << "# End INT\n";
}

void testObjects(){
  cout << "Generic Obj\n";
  SimpleOb obj;
  obj.num = 3;
  obj.fnum = 3.5;
  obj.name = "simple";

  vector<SimpleOb> vec = genericVector<SimpleOb>(obj);
  vec.push_back(SimpleOb (5, 3.4, "Daniel"));
  vec.push_back(SimpleOb (4, 4.3, "Ernesto"));

  for(int i = 0; i < vec.size(); i++)
    cout << "Pos " << i << " = " << vec[i] << " \n";

  cout << "# End INT\n";
}

int main(){

  testString();
  testInt();
  testObjects();
  return 0;
}



