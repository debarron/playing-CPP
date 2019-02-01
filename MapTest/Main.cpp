#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "Animal.h"

int main(){
  ifstream inputFile("inputAnimal.txt");

  string command, name;
  int id, age;
  map<int,Animal> animalMap;

  if(inputFile.fail()){
    cout << "There was an error while opening the file\n";
    return 1;
  }

  while(!inputFile.eof()){
    inputFile >> command;

    if(command == "NEW"){
      // Lets create a new Animal
      // acording to the data in the
      // input file
      inputFile >> id;
      inputFile >> name;
      inputFile >> age;

      Animal myAnimal(name, age);
      cout << "The name is: " << myAnimal.getName() << "\n";

      // Add the element in the map
      animalMap[id] = myAnimal;

    }else if(command == "GET_OLD"){
      // Lets look in the map for the Animal
      // with $id = id, and add more age to it.

      inputFile >> id;
      inputFile >> age;

      animalMap[id].getOld(age);

    }else if(command == "DIE"){
      // Lets kill the animal in the map,
      // look for it using the id

      inputFile >> id;
      animalMap[id].die();

    }else if(command == "END"){
      // We reached the end of the file,
      // nothing else to do, lets move on!
      break;
    }
  }

  // Since we don't want to remove elements from
  // the map, lets just print those animls that are
  // alive.
  map<int,Animal>::iterator it;
  for (it = animalMap.begin(); it != animalMap.end(); it++){
    Animal x = (*it).second;

    if(x.isAlive()){
      cout << "The pet: " << x.getName();
      cout << " is " << x.getAge() << " years old\n";
    }
  }

  return 0;
}
