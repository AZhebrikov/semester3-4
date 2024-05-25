#include <iostream>
#include <string.h>
#include <stdio.h>
#include "fun.h"

BLOCK _SBLOCK_[NBLOCKS];
INode _Node_[MAX_FILES];

int main(void)
{
 using std::cout;
 using std::cin;
 using std::endl;

FileSystem FS;

cout<<FS<<endl;

cout<<"++++++++++++++++++\n";
cout<<"FS.ReadDisk()= "<<(FS.ReadDisk())<<endl;
cout<<"++++++++++++++++++\n";
cout<<FS<<endl;

 return 0;
}