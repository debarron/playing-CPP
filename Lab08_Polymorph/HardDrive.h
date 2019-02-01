

#include <iostream>
using namespace std;

#include "Disk.h"
#ifndef HDD_H
#define HDD_H



class HardDrive : public Disk{
public:
  HardDrive();
  void cleanCache();
  void moveBlock(int spaces);
  int getUUID();
};

int HardDrive::getUUID(){
  return 1;
}

HardDrive::HardDrive(){
  cout << "From the HDD class\n";
  cout << "Creating a new drive of type HDD\n\n";
  currentBlock = 0;
  value = 0;
}

void HardDrive::cleanCache(){
  cout << "From the HDD class\n";
  cout << "Cleaning the cache of an HDD\n\n";
}

void HardDrive::moveBlock(int spaces){
  cout << "From the HDD class\n";
  currentBlock += spaces * 8;
}


#endif
