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

 cout<<"FS.CreateFiles(\"t1.txt\");"<<endl;
 FS.CreateFiles("t1.txt");
 cout<<FS<<endl;

cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;


for(int i=0;i<15;i++)FS.AddBlockMemory(0);
 
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass1[BLOCK_SIZE]="qwer@###%###@[1]";
cout<<"mass1= "<<mass1<<endl;

cout<<"FS.InWriteBlock(0,mass1);"<<endl;
FS.InWriteBlock(0,mass1);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass2[BLOCK_SIZE]="ghjk[2]";
cout<<"mass2= "<<mass2<<endl;

cout<<"FS.InWriteBlock(0,mass2);"<<endl;
FS.InWriteBlock(0,mass2);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass3[BLOCK_SIZE]="123456789123456789[3]";
cout<<"mass3= "<<mass3<<endl;

cout<<"FS.InWriteBlock(0,mass3);"<<endl;
FS.InWriteBlock(0,mass3);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass4[BLOCK_SIZE]="aaaabbbbccccdddd123456789[4]";
cout<<"mass4= "<<mass4<<endl;

cout<<"FS.InWriteBlock(0,mass4);"<<endl;
FS.InWriteBlock(0,mass4);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass5[BLOCK_SIZE]="hhhhtttthhhh[5]";
cout<<"mass5= "<<mass5<<endl;

cout<<"FS.InWriteBlock(0,mass5);"<<endl;
FS.InWriteBlock(0,mass5,3);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass6[BLOCK_SIZE]="|uuuuppppuuuu5555|";
cout<<"mass6= "<<mass6<<endl;

cout<<"FS.InWriteBlock(0,mass6);"<<endl;
FS.InWriteBlock(0,mass6,2);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);


cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass7[BLOCK_SIZE]="|uuuuppppuuuu5555|";
cout<<"mass7= "<<mass7<<endl;

cout<<"FS.InWriteBlock(0,mass7);"<<endl;
FS.InWriteBlock(0,mass7,100);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);

cout<<"\n+++++++++++++++++++++\n"<<endl;

char mass8[BLOCK_SIZE]="|uuuuppppuuuu5555|";
cout<<"mass8= "<<mass8<<endl;

cout<<"FS.InWriteBlock(0,mass7);"<<endl;
FS.InWriteBlock(0,mass8,15);

cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);


cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;


 
 cout<<"FS.CreateFiles(\"t2.txt\");"<<endl;
 FS.CreateFiles("t2.txt");
 FS.VivodAll(1,cout);

 FS.InWriteBlock(1,mass8);
 FS.VivodAll(1,cout);

 FS.InWriteBlock(1,mass5);
 FS.VivodAll(1,cout);

 FS.InWriteBlock(1,mass8);
 FS.VivodAll(1,cout);

cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;

cout<<"FS.CreateFiles(\"t3.txt\");"<<endl;
FS.CreateFiles("t3.txt");
FS.VivodAll(2,cout);

char mass10[BLOCK_SIZE]="11112222";
cout<<"mass10= "<<mass10<<endl;

FS.InWriteBlock(2,mass10);
FS.VivodAll(2,cout);

char mass11[BLOCK_SIZE]="M";
cout<<"mass11= "<<mass11<<endl;

FS.InWriteBlock(2,mass11);
FS.VivodAll(2,cout);

FS.AddBlockMemory(2);
FS.AddBlockMemory(2);

FS.VivodAll(2,cout);

FS.InWriteBlock(2,mass10,2);
FS.VivodAll(2,cout);

cout<<"FS.InWriteBlock(2,mass10,1,3);"<<endl;
FS.InWriteBlock(2,mass10,1,3);
FS.VivodAll(2,cout);

char mass12[BLOCK_SIZE]="R";
cout<<"mass12= "<<mass12<<endl;

cout<<"FS.InWriteBlock(2,mass12,1,3);"<<endl;
FS.InWriteBlock(2,mass12,1,3);
FS.VivodAll(2,cout);

cout<<"FS.InWriteBlock(2,mass12,1,330);"<<endl;
FS.InWriteBlock(2,mass12,1,330);
FS.VivodAll(2,cout);

char mass13[BLOCK_SIZE]="RRttYYttRRttYYttRRttYYttRRttYYtt";
cout<<"mass13= "<<mass13<<endl;

FS.InWriteBlock(2,mass13,0,8);
FS.VivodAll(2,cout);

return 0;
}
