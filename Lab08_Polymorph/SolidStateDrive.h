
#include <iostream>
using namespace std;

#include "Disk.h"

#ifndef SSD_H
#define SSD_H

class SolidStateDrive : public Disk{
public:
  SolidStateDrive();

  void moveBlock(int spaces);
  void cleanCache();
  int getUUID();
};

int SolidStateDrive::getUUID(){
  return 2;
}

SolidStateDrive::SolidStateDrive(){
  cout << "From the SSD class\n";
  cout << "Creating a new drive of type SSD\n";
  currentBlock = 0;
  value = 0;
}

void SolidStateDrive::moveBlock(int spaces){
  cout << "From the SSD class\n";
  currentBlock += spaces;
}

void SolidStateDrive::cleanCache(){
  cout << "From the SSD class\n";
  cout << ">>Solid states don't have cache\n";
}

#endif
