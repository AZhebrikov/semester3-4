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


for(int i=0;i<15;i++)
{
 cout<<"FS.AddBlockMemory====================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl; 
}

cout<<FS;

FileSystem::iterator it=FS.Begin(0);
cout<<"(int)it= "<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;

cout<<"(int)it++= ";
it++;
cout<<(int)it<<endl;


cout<<"-00-00--0-0-0"<<endl;

cout<<"Sblock[0]: ";FS.printf(cout,0);
cout<<"Sblock[1]: ";FS.printf(cout,1);
cout<<"Sblock[2]: ";FS.printf(cout,2);
cout<<"Sblock[18]: ";FS.printf(cout,18);
cout<<"Sblock[25]: ";FS.printf(cout,25);
cout<<"Sblock[27]: ";FS.printf(cout,27);
cout<<"Sblock[28]: ";FS.printf(cout,28);
cout<<"Sblock[36]: ";FS.printf(cout,36);
cout<<"Sblock[34]: ";FS.printf(cout,34);

cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;


cout<<FS<<endl;

FS.DeleteFileAll(0);
cout<<FS<<endl;
FS.ErrorChek(3);

 cout<<"Sblock[0]: ";FS.printf(cout,0);
 cout<<"Sblock[1]: ";FS.printf(cout,1);
 cout<<"Sblock[2]: ";FS.printf(cout,2);
 cout<<"Sblock[3]: ";FS.printf(cout,3);
 cout<<"Sblock[4]: ";FS.printf(cout,4);
 cout<<"Sblock[5]: ";FS.printf(cout,5);
 cout<<"Sblock[6]: ";FS.printf(cout,6);
 cout<<"Sblock[7]: ";FS.printf(cout,7);
 cout<<"Sblock[8]: ";FS.printf(cout,8);

cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;

cout<<FS<<endl;

 cout<<"FS.CreateFiles(\"t1.txt\");"<<endl;
 cout<<"New_Block= "<<FS.New_Block()<<endl;
 cout<<"New_INode= "<<FS.New_INode()<<endl;

 FS.CreateFiles("t1.txt");

 cout<<"New_Block= "<<FS.New_Block()<<endl;
 cout<<"New_INode= "<<FS.New_INode()<<endl;
 
 cout<<FS<<endl;

 for(int i=0;i<15;i++)
 {
  cout<<"FS.AddBlockMemory====================="<<endl;
  FS.AddBlockMemory(0);
  cout<<FS<<endl; 
 }

 for(int i=0;i<40;i++)
 {
  cout<<"Sblock["<<i<<"]: ";FS.printf(cout,i);
 }
 

cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;
cout<<"+++++++++++++++++++++"<<endl;



/*
FS.VivodAll(0,cout);
cout<<"++++++++++++++++++++"<<endl;

char mass1[BLOCK_SIZE]="qwer@###%###@";
cout<<"mass1= "<<mass1<<endl;

cout<<"FS.InWriteEndBlock(0,mass1);"<<endl;
FS.InWriteEndBlock(0,mass1);
cout<<"FS.VivodAll(0,cout);"<<endl;
FS.VivodAll(0,cout);



//char mass2[BLOCK_SIZE]=
//char mass3[BLOCK_SIZE]=
//char mass4[BLOCK_SIZE]=
//char mass5[BLOCK_SIZE]=
//char mass6[BLOCK_SIZE]=
//char mass7[BLOCK_SIZE]=
//char mass8[BLOCK_SIZE]=
*/
}