#include <iostream>
using namespace std;

#ifndef DISK_H
#define DISK_H

class Disk{
public:
  int currentBlock;
  int value;
public:
  Disk();
  int readData();
  void writeData(int _value);

  virtual void cleanCache();
  virtual void moveBlock(int spaces);

  // Forcing re-definition
  virtual int getUUID() = 0;

};


void Disk::cleanCache(){
  cout << "From the Disk class\n";
}

void Disk::moveBlock(int spaces){
  cout << "From the Disk class\n";
}

Disk::Disk(){
  cout << "From the Disk class CONSTRUCTOR\n";
  currentBlock = 0;
  value = 0;
}

int Disk::readData(){
  return value;
}

void Disk::writeData(int _value){
  value = _value;
}

#endif
