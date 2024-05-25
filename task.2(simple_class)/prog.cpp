#include <iostream>
#include <string.h>
#include "fun_CRat.h"
#include "fun_CRatVector.h"
int main(void)
{try{
 using std::cout;
 using std::endl;
 using std::cin;

 CRat a,b(1),c(-1,2);
 CRat k(c);
 int mass[2]={1,3};
 CRat r(mass);
 cout<<"--------------------------------------------------------1\n";
      cout<<"a= "<<a<<endl
          <<"b= "<<b<<endl
          <<"c= "<<c<<endl
          <<"k= "<<k<<endl
          <<"r= "<<r<<endl;
 cout<<"-------------------------------------------------------1+\n";
 cout<<"sizeof(CRat)=";
 cout<<sizeof(CRat)<<endl;
 cout<<"--------------------------------------------------------2\n";

 int err[2]={3,-7};
 r=err;
  cout<<"int err[2]={3,-7};\n"
        "r=err;\n";
  cout<<"r= "<<r<<endl;

 cout<<"--------------------------------------------------------2+\n";
  int A=5;

    cout<<"a= "<<a<<"r= "<<r<<" ,||a=(const CRat &)r|| ";a=r;cout<<"a= "<<r<<endl;
    cout<<"b= "<<b<<"A= "<<A<<" ,||b=(int)A|| ";b=A;cout<<"b= "<<b<<endl;
    cout<<"c= "<<c<<"mass={1,3}  ,||c=r|| ";c=mass;cout<<"c= "<<c<<endl;
 cout<<"--------------------------------------------------------3\n";

    cout<<"a= "<<a<<" ,b= "<<b<<" a+b= "<<a+b<<endl;
    cout<<"a= "<<a<<" ,A= "<<A<<" a+A= "<<a+A<<endl;
    cout<<"a= "<<a<<" ,mass= {1,3} , a+b= "<<a+mass<<endl;
 cout<<"--------------------------------------------------------4\n";

    cout<<"a= "<<a<<" ,A= "<<A<<" a-A= "<<a-A<<endl;
    cout<<"a= "<<a<<" ,b= "<<b<<" a-b= "<<a-b<<endl;
    cout<<"a= "<<a<<" ,mass= {1,3} , a-mass= "<<a-mass<<endl;
 cout<<"--------------------------------------------------------5\n";

  mass[1]=-2;
     cout<<"a= "<<a<<" ,r= "<<r<<" a*r= "<<a*r<<endl;
     cout<<"a= "<<a<<" ,mass= {1,-2} , a*mass= "<<a*mass<<endl;
     cout<<"a= "<<a<<" ,A= "<<A<<" a*A= "<<a*A<<endl;
 cout<<"--------------------------------------------------------6\n";
    cout<<"a= "<<a<<" ,r= "<<r<<" a/r= "<<a/r<<endl;
    cout<<"a= "<<a<<" ,mass= {1,-2} , a/mass= "<<a/mass<<endl;
    cout<<"a= "<<a<<" ,A= "<<A<<" a/A= "<<a/A<<endl;
 cout<<"--------------------------------------------------------7\n";
  a(2,-3);
  cout<<"a(2,-3); -> a= "<<a<<endl;
 cout<<"--------------------------------------------------------8\n";

  cout<<"a= "<<a<<" , a.num()= "<<a.num()<<" , a.ded()= "<<a.den()<<endl;
  a.Num(5);a.Den(-2);
  cout<<"a.Num(5);a,Den(-2);\n"
       "a= "<<a<<endl;
 cout<<"--------------------------------------------------------9\n";
  a(1,2);b(-2,3);c(1,5);
  cout<<  (int)(a>b)  <<"    "
     <<  (int)(a>c)  <<"    "
     <<  (int)(c>b)  <<"    "
     <<  (int)(c>a)  <<"    "
     <<  (int)(b>a)  <<"    "
     <<  (int)(b>c)  <<"    "
     <<  (int)(b>b)  <<"    "
     <<  (int)(b<b)  <<endl;
 cout<<"--------------------------------------------------------10\n";
  b(15,25);a(28,7);c(15,13);
   cout<<"a= "<<a;a.Krt();cout<<"a= "<<a<<endl;
   cout<<"b= "<<b;b.Krt();cout<<"b= "<<b<<endl;
   cout<<"c= "<<c;c.Krt();cout<<"c= "<<c<<endl;
 cout<<"--------------------------------------------------------11\n";

  CRat w[4]={CRat(1,2),CRat(3,-4),CRat(2,6),CRat(1,7)};
  cout<<"CRat w[4]={CRat(1,2),CRat(3,-4),CRat(2,6),CRat(1,7)};"<<endl;
  for(int i=0;i<4;i++)cout<<"w["<<i<<"]= "<<w[i]<<endl;

 cout<<"--------------------------------------------------------12\n";

  CRatVector z;cout<<z<<endl;
  CRatVector x(3);cout<<x<<endl;
  CRatVector s(4,w);cout<<s<<endl;
  CRatVector m(s);cout<<m<<endl;
 cout<<"--------------------------------------------------------13\n";

  z=m;cout<<"z=m;"<<endl
          <<"z= "<<z<<endl<<"m= "<<m<<endl;
 cout<<"--------------------------------------------------------14\n";

  z[0](1,2);z[1](1,-1);z[2](3,2);z[3](2,-4);
  cout<<"z[0](1,2);z[1](1,-1);z[2](3,2);z[3](2,-4);"<<endl;
  cout<<"z= "<<z<<endl;

 cout<<"--------------------------------------------------------15\n";

  cout<<"z-m= "<<z-m<<" ,"<<"z= "<<z<<endl<<"m= "<<m<<endl;
  cout<<"z+m= "<<z+m<<" ,"<<"z= "<<z<<endl<<"m= "<<m<<endl;
  int h=-2;
  cout<<"m*k= "<<m*h<<" ,"<<"k= "<<h<<endl<<"m= "<<m<<endl;
  cout<<"z/k= "<<z/h<<" ,"<<"k= "<<h<<endl<<"z= "<<z<<endl;
  cout<<"z*m= "<<z*m<<" ,"<<"z= "<<z<<endl<<"m= "<<m<<endl;
 cout<<"---------------------------------------------------------16\n";
  k=z*m;k.Krt();cout<<"k ="<<k<<endl;

  cout<<"z[0]= "<<z.cor(0)<<endl;
  z.Cor(0,k);cout<<"z[0]= "<<z.cor(0)<<endl;
 cout<<"---------------------------------------------------------17\n";
  z[0](-6,2);z[1](120,84);z[2](32,8);z[3](75,-30);
  cout<<"z[0](-6,2);z[1](120,84);z[2](32,8);z[3](75,-30);"<<endl;
  cout<<"z= "<<z<<endl;
  z.Krtr();
  cout<<"z= "<<z<<endl;
 cout<<"---------------------------------------------------------18\n";
}catch(int err){
                if(err>-10)printf("Error = %d  \n",err);
                else printf("Error = %d \n",err); 
               }
return 0;
}








