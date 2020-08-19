#include <iostream>
#include <vector>

using namespace std;

vector<int> getSimpleVector(){
  return vector<int>();
}

vector<int> *getSimpleVectorPointer(){
  return new vector<int>();
}

void testVector(vector<int> t){
  t.push_back(6);
  t.push_back(6);
  t.push_back(6);

  for (int i = 0; i < t.size(); i++)
    cout << "\t from function " << t[i] << "\n";
}

void testVectorReference(vector<int> &t){
  t.push_back(6);
  t.push_back(6);
  t.push_back(6);

  for (int i = 0; i < t.size(); i++)
    cout << "\t from function " << t[i] << "\n";
}




int main(){
  cout << " -- TESTING HOW TO CREATE VECTOR\n";
  // Regular vector
  vector<int> test = getSimpleVector();
  test.push_back(1);
  test.push_back(1);
  test.push_back(1);
  for (int i = 0; i < test.size(); i++)
    cout << "normal " << test[i] << "\n";

  // Pointer vector
  vector<int> *pvector = getSimpleVectorPointer();
  pvector->push_back(2);
  pvector->push_back(2);
  pvector->push_back(2);
  for (int i = 0; i < pvector->size(); i++)
    cout << "pointer " << (*pvector)[i] << "\n";

  // Reference vectpr
  vector<int> &cvector = *getSimpleVectorPointer();
  cvector.push_back(3);
  cvector.push_back(3);
  cvector.push_back(3);
  for (int i = 0; i < cvector.size(); i++)
    cout << "constant " << cvector[i] << "\n";


  cout << "\n -- TESTING FUNCTIONS\n";
  cout << " \t * PASS BY VALUE\n";
  testVector(test);
  for (int i = 0; i < test.size(); i++)
    cout << "normal at " << test[i] << "\n";

  testVector(*pvector);
  for (int i = 0; i < pvector->size(); i++)
    cout << "pointer at " << (*pvector)[i] << "\n";

  testVector(cvector);
  for (int i = 0; i < cvector.size(); i++)
    cout << "constant at " << cvector[i] << "\n";


  cout << "\n \t * PASS BY REFERENCE\n";
  testVectorReference(test);
  for (int i = 0; i < test.size(); i++)
    cout << "normal Ref " << test[i] << "\n";

  testVectorReference(*pvector);
  for (int i = 0; i < pvector->size(); i++)
    cout << "pointer Ref " << (*pvector)[i] << "\n";

  testVectorReference(cvector);
  for (int i = 0; i < cvector.size(); i++)
    cout << "constant Ref " << cvector[i] << "\n";





  return 0;
}
