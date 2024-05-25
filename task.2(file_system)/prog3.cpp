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

 char ms[BLOCK_SIZE];ms[0]='\0';
 cout<<"ms= "<<ms<<endl;

 cout<<"FS.InWriteBlock(0,ms);"<<endl;
 FS.InWriteBlock(0,ms);

 FS.VivodAll(0,cout);

 char mass1[BLOCK_SIZE]="qwer@###%###@[1]";
 cout<<"mass1= "<<mass1<<endl;

 cout<<"FS.InWriteBlock(0,mass1);"<<endl;
 FS.InWriteBlock(0,mass1);

 FS.VivodAll(0,cout);

 cout<<"=-=-=-=-=-="<<endl;
 
 char mass2[BLOCK_SIZE]="RRttYYttRRtYYtt";
 cout<<"mass2= "<<mass2<<endl;

 cout<<"FS.InWriteBlock(0,mass2);"<<endl;
 FS.InWriteBlock(0,mass2,0,8);

 FS.VivodAll(0,cout);

 cout<<"=-=-=-=-=-="<<endl;

 char mass3[BLOCK_SIZE]="11111";
 cout<<"mass3= "<<mass3<<endl;

 cout<<"FS.InCleanWriteBlock(0,mass3);"<<endl;
 FS.InCleanWriteBlock(0,mass3,0,3);

 FS.VivodAll(0,cout);

 char mass4[BLOCK_SIZE]="444446666688888";
 cout<<"mass4= "<<mass4<<endl;

 cout<<"FS.InCleanWriteBlock(0,mass4);"<<endl;
 FS.InCleanWriteBlock(0,mass4,0,26);

 FS.VivodAll(0,cout);

   cout<<"=-=-=-=-=-="<<endl;
   cout<<"+++++++++++"<<endl;
   cout<<"=-=-=-=-=-="<<endl;


 cout<<"FS.CreateFiles(\"t2.txt\");"<<endl;
 FS.CreateFiles("t2.txt");
 cout<<FS<<endl;
 
 for(int i=0;i<15;i++)FS.AddBlockMemory(1);

 FS.VivodAll(1,cout);
 FS.InWriteBlock(1,"hhhhyyyyttttrrrr",1,0);
 FS.InWriteBlock(1,"aaaaeeeewwwwcccc",3,0);
 FS.InWriteBlock(1,"ppppooooiiiiuuuu",4,0);
 FS.InWriteBlock(1,"nnnnbbbbvvvvxxxx",5,0);
 FS.InWriteBlock(1,"ddddffffggggqqqq",7,0);
 FS.InWriteBlock(1,"llllkkkkssssdddd",9,0);
 FS.InWriteBlock(1,"11112222333344445555666677778888OOO",13,0);
 FS.InWriteBlock(1,"M",12,0);
 FS.InWriteBlock(1,"TTTTUUUUPPPPVVVV",14,0);
 FS.InWriteBlock(1,"M",13,35);
 FS.VivodAll(1,cout);
 int pozic,block;
 cout<<"SeachPozic(1,0,pozic,block) ="<<(FS.SeachPozic(1,0,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,1,pozic,block) ="<<(FS.SeachPozic(1,1,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,2,pozic,block) ="<<(FS.SeachPozic(1,2,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,10,pozic,block) ="<<(FS.SeachPozic(1,10,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,20,pozic,block) ="<<(FS.SeachPozic(1,20,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,30,pozic,block) ="<<(FS.SeachPozic(1,30,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,40,pozic,block) ="<<(FS.SeachPozic(1,40,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*3,pozic,block) ="<<(FS.SeachPozic(1,4*4*3,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*6,pozic,block) ="<<(FS.SeachPozic(1,4*4*6,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*6+1,pozic,block) ="<<(FS.SeachPozic(1,(4*4*6+1),pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*8+1,pozic,block) ="<<(FS.SeachPozic(1,(4*4*8+1),pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*8+2,pozic,block) ="<<(FS.SeachPozic(1,(4*4*8+2),pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*8+3,pozic,block) ="<<(FS.SeachPozic(1,(4*4*8+3),pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,4*4*8+4,pozic,block) ="<<(FS.SeachPozic(1,(4*4*8+4),pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,500,pozic,block) ="<<(FS.SeachPozic(1,500,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;
cout<<"SeachPozic(1,-2,pozic,block) ="<<(FS.SeachPozic(1,-2,pozic,block))<<" pozic= "<<pozic<<"  block= "<<block<<endl;

   cout<<"=-=-=-=-=-="<<endl;
   cout<<"+++++++++++"<<endl;
   cout<<"=-=-=-=-=-="<<endl;

cout<<FS<<endl;

FS.SaveDisk();

FS.VivodFile(0,cout);cout<<endl;
FS.VivodFile(1,cout);cout<<endl;
FS.VivodFile(2,cout);cout<<endl;

return 0;
}