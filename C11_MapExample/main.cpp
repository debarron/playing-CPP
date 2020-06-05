#include <iostream>
#include <map>
#include <string>

int main ()
{
  std::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];
  mymap['d'] = "Daniel";

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  auto aName = mymap.find('d');
  std::cout << "Name is: " << aName->second.c_str() << "\n";

  auto searchElement = mymap.find('x');
  if(searchElement == mymap.end())
    std::cout << "'x' is not there\n";

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  return 0;
}
