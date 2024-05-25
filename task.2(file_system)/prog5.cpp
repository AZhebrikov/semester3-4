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
 
cout<<FS;

Tint MG;
int block=0;
int pozic=0;

 cout<<"FS.CreateFiles(\"t1.txt\");"<<endl;
 FS.CreateFiles("t1.txt");
 cout<<FS<<endl;

 char mass1[BLOCK_SIZE]="qqqqwwwweeeerrrrttttyyyyuuuuiiii";cout<<"mass1= "<<mass1<<endl;
 char mass2[BLOCK_SIZE]="LLLLKKKKIIIIOOOORRRREEEE";cout<<"mass2= "<<mass2<<endl;
 char mass3[BLOCK_SIZE]="111122223333666677778888";cout<<"mass3= "<<mass3<<endl;
 char mass4[BLOCK_SIZE]="11117777666644449999";cout<<"mass4= "<<mass4<<endl;

cout<<"FS.InWriteBlock(0,ms);"<<endl;
MG=FS.InWriteBlock(0,mass1,block,pozic);MG.XY(block,pozic);

cout<<"block= "<<block<<"  pozic= "<<pozic<<endl;
FS.VivodAll(0,cout);cout<<endl;

cout<<"FS.InWriteBlock(0,ms);"<<endl;
MG=FS.InWriteBlock(0,mass2,block,pozic);MG.XY(block,pozic);

cout<<"block= "<<block<<"  pozic= "<<pozic<<endl;
FS.VivodAll(0,cout);cout<<endl;

cout<<"FS.InWriteBlock(0,ms);"<<endl;
MG=FS.InWriteBlock(0,mass3,block,pozic);MG.XY(block,pozic);

cout<<"block= "<<block<<"  pozic= "<<pozic<<endl;
FS.VivodAll(0,cout);cout<<endl;

cout<<"FS.InWriteBlock(0,ms);"<<endl;
MG=FS.InWriteBlock(0,mass4,block,pozic);MG.XY(block,pozic);

cout<<"block= "<<block<<"  pozic= "<<pozic<<endl;
FS.VivodAll(0,cout);cout<<endl;

return 0;
}