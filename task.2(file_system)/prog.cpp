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
 cout<<FS.New_Block()<<endl;
 cout<<FS.New_INode()<<endl;

 cout<<"FS.CreateFiles(\"t1.txt\");"<<endl;
 FS.CreateFiles("t1.txt");
 cout<<FS<<endl;
 
 cout<<"New_Block= "<<FS.New_Block()<<endl;
 cout<<"New_INode= "<<FS.New_INode()<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(FS.Node[0].FirstBlock);
 cout<<FS<<endl;

 cout<<"New_Block= "<<FS.New_Block()<<endl;
 cout<<"New_INode= "<<FS.New_INode()<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"----------1---------"<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory"<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"----------2---------"<<endl;
 
 cout<<"FS.AddBlockMemory==============="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory==================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory====================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;

 cout<<"----------3---------"<<endl;
 
 cout<<"FS.AddBlockMemory==============="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory==================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory====================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;

 cout<<"----------4---------"<<endl;
 
 cout<<"FS.AddBlockMemory==============="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory==================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;
 
 cout<<"FS.AddBlockMemory====================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl;

 cout<<"----------5---------"<<endl;

for(int i=0;i<2;i++)
{
 cout<<"FS.AddBlockMemory====================="<<endl;
 FS.AddBlockMemory(0);
 cout<<FS<<endl; 
}

cout<<FS<<endl;


cout<<"SearchNumberBloc(0,0)"<<endl;
cout<<FS.SearchNumberBloc(0,0)<<endl<<endl;

cout<<"SearchNumberBloc(5,0)"<<endl;
cout<<FS.SearchNumberBloc(5,0)<<endl<<endl;

cout<<"SearchNumberBloc(8,0)"<<endl;
cout<<FS.SearchNumberBloc(8,0)<<endl<<endl;

cout<<"SearchNumberBloc(9,0)"<<endl;
cout<<FS.SearchNumberBloc(9,0)<<endl<<endl;

cout<<"SearchNumberBloc(10,0)"<<endl;
cout<<FS.SearchNumberBloc(10,0)<<endl<<endl;

cout<<"SearchNumberBloc(11,0)"<<endl;
cout<<FS.SearchNumberBloc(11,0)<<endl<<endl;

cout<<"SearchNumberBloc(12,0)"<<endl;
cout<<FS.SearchNumberBloc(12,0)<<endl<<endl;

cout<<"SearchNumberBloc(13,0)"<<endl;
cout<<FS.SearchNumberBloc(13,0)<<endl<<endl;

cout<<"SearchNumberBloc(14,0)"<<endl;
cout<<FS.SearchNumberBloc(14,0)<<endl<<endl;

cout<<"SearchNumberBloc(15,0)"<<endl;
cout<<FS.SearchNumberBloc(15,0)<<endl<<endl;

cout<<"SearchNumberBloc(16,0)"<<endl;
cout<<FS.SearchNumberBloc(16,0)<<endl<<endl;

cout<<"SearchNumberBloc(22,0)"<<endl;
cout<<FS.SearchNumberBloc(22,0)<<endl<<endl;

cout<<"SearchNumberBloc(26,0)"<<endl;
cout<<FS.SearchNumberBloc(26,0)<<endl<<endl;

cout<<"SearchNumberBloc(28,0)"<<endl;
cout<<FS.SearchNumberBloc(28,0)<<endl<<endl;

cout<<"SearchNumberBloc(30,0)"<<endl;
cout<<FS.SearchNumberBloc(30,0)<<endl<<endl;

cout<<"SearchNumberBloc(-2,0)"<<endl;
cout<<FS.SearchNumberBloc(-2,0)<<endl<<endl;
 
 
 cout<<"----------6---------"<<endl;
 FS.ErrorChek();

 cout<<"----------7---------"<<endl;
 
 cout<<"DeleteFileAll(0)"<<endl;
 FS.DeleteFileAll(0);
 cout<<FS<<endl;  

 FS.ErrorChek(1);
 FS.ErrorChek(2);
 
 
return 0;
}
