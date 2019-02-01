#include <string>

using namespace std;

class Animal{
private:
string name;
int age;
bool alive;

public:
Animal();
Animal(string _name, int _age);
string getName();
int getAge();
void getOld(int _newAge);
void die();
bool isAlive();
};
Animal::Animal(){
  name = "";
  age = 0;
  alive = false;
}

Animal::Animal(string _name, int _age){
  name = _name;
  age = _age;
  alive = true;
}
string Animal::getName(){
  return name;
}

int Animal::getAge(){
  return age;
}
void Animal::getOld(int _newAge){
  age += _newAge;
}

bool Animal::isAlive(){
  return alive;
}
void Animal::die(){
  alive = false;
}
