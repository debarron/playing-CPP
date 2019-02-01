



#include <iostream>
#include <string>

#include "Disk.h"
#include "HardDrive.h"
#include "SolidStateDrive.h"

using namespace std;

void printInfo(Disk *disk){
  disk->moveBlock(8);
  cout << "Current block is: " << disk->currentBlock << "\n";
  cout << "The UUID is: " << disk->getUUID() << "\n";
}

int main(){
  cout << ">> Polymorphism practice\n\n";

  Disk *myDisk;

  myDisk = new HardDrive();
  printInfo(myDisk);

  myDisk = new SolidStateDrive();
  printInfo(myDisk);

  return 0;

}
