// @debarron
// 04/26/2017
// A list example
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
  list<char> listOfChars;
  list<char>::iterator lcIt;

  string m = "Dear Students";
  string::iterator strIt;

  char lchar[3] = {'a', 'u', 'i'};
  for(int i = 0; i < 3; i++){
    listOfChars.remove(lchar[i]);
  }
  for(strIt = m.begin(); strIt != m.end(); strIt++){
    listOfChars.push_back(*strIt);
  }

  for(lcIt = listOfChars.begin(); lcIt != listOfChars.end(); lcIt++){
    if(*lcIt == 'a'){
      listOfChars.remove(*lcIt); // AVOID! @_@
    }
  }


  cout << 0 << "\n";
}
