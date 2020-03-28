#include <vector>
#include <iostream>

using namespace std;

int main(){
  vector<int> simpleVector;

  // Add elements to a vector
  simpleVector.push_back(1);
  simpleVector.push_back(3);
  simpleVector.push_back(5);

  // Retrieve elements from vector
  for(int i = 0; i < simpleVector.size(); i++)
    cout << "Position: " << i << " Value: " << simpleVector[i] << "\n";
  
  return 0;
}
