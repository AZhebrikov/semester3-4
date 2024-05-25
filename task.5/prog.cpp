#include <iostream>
#include <string.h>
#include <stdio.h>
#include "fun.h"


int main(void)
{
 	using std::cout;
 	using std::cin;
 	using std::endl;

 SPoint FS(30);
 cout<<FS<<endl;
 FS.Dobavit(1,1);
 cout<<FS<<endl;
 
 cout<<"FS.ProvAffiliation(Point(1,2))= "<<FS.ProvAffiliation(Point(1,2))<<endl;
 cout<<"FS.ProvAffiliation(Point(1,1))= "<<FS.ProvAffiliation(Point(1,1))<<endl;

 FS.Dobavit(3,3);
 cout<<FS<<endl;
 
 cout<<"FS.ProvAffiliation(Point(1,2))= "<<FS.ProvAffiliation(Point(1,2))<<endl;
 cout<<"FS.ProvAffiliation(Point(2,1))= "<<FS.ProvAffiliation(Point(2,1))<<endl;
 cout<<"FS.ProvAffiliation(Point(2,2))= "<<FS.ProvAffiliation(Point(2,2))<<endl;
 cout<<"FS.ProvAffiliation(Point(3,3))= "<<FS.ProvAffiliation(Point(3,3))<<endl;

 FS.Dobavit(7,7);
 cout<<FS<<endl;
 FS.Dobavit(-4,-4);
 cout<<FS<<endl;

 cout<<"FS.ProvAffiliation(Point(-1,2))= "<<FS.ProvAffiliation(Point(-1,2))<<endl;
 cout<<"FS.ProvAffiliation(Point(2,4))= "<<FS.ProvAffiliation(Point(2,4))<<endl;
 cout<<"FS.ProvAffiliation(Point(3,2))= "<<FS.ProvAffiliation(Point(3,2))<<endl;
 cout<<"FS.ProvAffiliation(Point(-2,-2))= "<<FS.ProvAffiliation(Point(-2,-2))<<endl;
 

 FS[3]=Point(4,0);
 cout<<FS<<endl;
 FS[4]=Point(-4,-4);
 FS++;
 cout<<FS<<endl;
 FS.Dobavit(3,7);
 cout<<FS<<endl;
 
 cout<<"FS.ProvAffiliation(Point(4,0))= \n"<<FS.ProvAffiliation(Point(4,0))<<endl;
 cout<<"FS.ProvAffiliation(Point(0,-2))= \n"<<FS.ProvAffiliation(Point(0,-2))<<endl;
 cout<<"FS.ProvAffiliation(Point(5,7))= \n"<<FS.ProvAffiliation(Point(5,7))<<endl;
 cout<<"FS.ProvAffiliation(Point(0,1))= \n"<<FS.ProvAffiliation(Point(0,1))<<endl;
 cout<<"FS.ProvAffiliation(Point(1,0))= \n"<<FS.ProvAffiliation(Point(1,0))<<"||"<<endl;
 
 FS[5]=Point(-4,4); 
 FS[6]=Point(1,3);FS++;
 cout<<FS<<endl;
  
 cout<<"FS.ProvAffiliation(Point(1,0))= \n"<<FS.ProvAffiliation(Point(1,0))<<"||"<<endl;

 FS[6]=Point(1,5);
 FS[7]=Point(1,3);FS++;
 cout<<FS<<endl;

 cout<<"FS.ProvAffiliation(Point(1,0))= \n"<<FS.ProvAffiliation(Point(1,0))<<"||"<<endl;
 cout<<"FS.ProvAffiliation(Point(-2,0))= \n"<<FS.ProvAffiliation(Point(-2,0))<<"||"<<endl;
 cout<<"FS.ProvAffiliation(Point(0,3))= \n"<<FS.ProvAffiliation(Point(0,3))<<"||"<<endl;
 
 SPoint FH(30);
 cout<<FH<<endl;
 FH.Dobavit(1,1);
 FH.Dobavit(5,4);
 FH.Dobavit(8,4);
 FH.Dobavit(9,5);
 FH.Dobavit(9,-1);
 FH.Dobavit(5,2);
 FH.Dobavit(1,-5);
 FH.Dobavit(6,-3);
 FH.Dobavit(6,-7);
 FH.Dobavit(4,-5);
 FH.Dobavit(-4,-8);
 FH.Dobavit(-1,-2);
 FH.Dobavit(-5,-2);
 FH.Dobavit(-5,1);
 FH.Dobavit(-4,-1);
 FH.Dobavit(-2,-1);
 FH.Dobavit(0,0);
 FH.Dobavit(0,2);
 FH.Dobavit(-3,2);
 FH.Dobavit(-3,7);
 FH.Dobavit(2,7);
 FH.Dobavit(2,6);
 FH.Dobavit(-2,6);
 FH.Dobavit(-2,5);
 FH.Dobavit(1,5);
 FH.Dobavit(1,4);
 FH.Dobavit(-2,4);
 FH.Dobavit(-2,3);
 FH.Dobavit(1,3);

 cout<<FH<<endl;
  
 cout<<"FH.ProvAffiliation(Point(1,1))= \n"<<FH.ProvAffiliation(Point(1,1))<<"||"<<endl;
 cout<<"FH.ProvAffiliation(Point(0,-3))= \n"<<FH.ProvAffiliation(Point(0,-3))<<"||"<<endl;
 
 
 int i,j,k;
 while(cin>>i>>j)//точка прекращения 100 -100
    {
    	if(i==100 && j==-100){while(cin.get()!='\n');break;}
    	cout<<"FH.ProvAffiliation(Point("<<i<<","<<j<<"))= "<<FH.ProvAffiliation(Point(i,j))<<"||"<<endl;
    }
 
 SPoint FJ(30);
 cout<<FJ<<endl;

 while(cin>>k>>i>>j)//точка прекращения 0 100 -100
    {
    	if(k==0 && i==100 && j==-100){while(cin.get()!='\n');break;}
    	cout<<"FJ.DobavinK(int k,const Point & b)"<<FJ.DobavinK(k,Point(i,j))<<endl;
    	cout<<FJ<<endl;
    }

 

 return 0;
}
