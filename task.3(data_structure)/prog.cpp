
#include <iostream>
#include "fun.h"

int main(void)
{
 using std::endl;
 using std::cout;

 cout<<"---------------------------------------1"<<endl;
try{
 		O("Проверка конструктора и деструктора CList,Cell");
 CList r1;
 cout<<"r1 = "<<r1<<endl;
 		O("Проверка AddAfter()");r1.AddAfter("123");r1.AddBefore("321");
 cout<<"r1 = "<<r1<<endl;
 		O("Проверка операторов << и >> для CList");
 r1>>"ABC"<<"YUI";
 cout<<"r1 = "<<r1<<endl;
 		O("Проверка операторов [] и ()");
 cout<<"r1[1] ="<<r1[1]<<endl;
 cout<<"(int) cur ="<<r1()<<endl;
 cout<<"r1[0] ="<<r1[0]<<endl;
 cout<<"(int) cur ="<<r1()<<endl;
 cout<<"r1[2] ="<<r1[2]<<endl;
 cout<<"(int) cur ="<<r1()<<endl;
 		O("Проверка функций AddBegin() и AddEnd() с сохранением указателя cur");
 cout<<"(int) cur ="<<r1()<<endl;
 r1.AddBegin("koi"); cout<<"r1 = "<<r1<<endl;
 cout<<"(int) cur ="<<r1()<<endl;
 r1.AddBegin("poi"); cout<<"r1 = "<<r1<<endl;
 cout<<"(int) cur ="<<r1()<<endl;
 r1.AddEnd("iok"); cout<<"r1 = "<<r1<<endl;
 cout<<"(int) cur ="<<r1()<<endl;
		O("Проверка функции SizeList();");
 cout<<"SizeList r1 ="<<r1.SizeList()<<endl;;
		O("Проверка работы сортировки Sort()");
 cout<<"r1 = "<<r1<<endl;
 cout<<"Выполняется сортировка."<<endl;r1.Sort();
 cout<<"r1 = "<<r1<<endl;

  		O("Проверка выделения памяти под строку");
 {
  const char * word="JDD";
  r1.AddBegin(word);
 }
 cout<<" r1 = "<<r1<<endl;
		O("Проверка класса Cell");
 Cell a("123");cout<<"a= "<<a<<endl;
 Cell b("234");cout<<"b= "<<b<<endl;
 a.Swap(b);
 cout<<"a= "<<a<<endl;
 cout<<"b= "<<b<<endl;
 cout<<"a>b "<<(a>b)<<endl;
 cout<<"a<b "<<(a<b)<<endl;
 cout<<"a= "<<a<<endl;
 cout<<"b= "<<b<<endl;
 a.Swap(b);
 Cell c("123");
 cout<<"c= "<<c<<endl;
 cout<<"a>=c "<<(a>=c)<<endl;
 cout<<"a<=c "<<(a<=c)<<endl;
 cout<<"a>c "<<(a>c)<<endl;
 Cell k("124");
 cout<<"k= "<<k<<endl;
 cout<<"a>=k "<<(a>=k)<<endl;
 cout<<"a<=k "<<(a<=k)<<endl;
 cout<<"a>k "<<(a>k)<<endl;
		O("Проверим функции DelNumber(),DelList()");
 cout<<"r1 = "<<r1<<endl;
 cout<<"r1[3]= "<<r1[3]<<endl;
 r1.DelNumber(3);
 cout<<"r1 = "<<r1<<endl;
 cout<<"r1[3]= "<<r1[3]<<endl;
 r1.DelList();
 cout<<"r1 = "<<r1<<endl;

 CList r2;
 r2<<"123"<<"234">>"klo">>"hgu"<<"dyrhf">>"afsjha";
 CList r3;
 r3>>"456">>"1f4">>"2vx"<<"12334546"<<"aSx"<<"bgnhmj";
 cout<<"r2= "<<r2<<endl;
 cout<<"r3= "<<r3<<endl;
 cout<<"r2[3]= "<<r2[3]<<endl;
 r2.AddNumber(3,"JOH");
 cout<<"r2= "<<r2<<endl;
 r3.AddCList(r2);
 cout<<"r3= "<<r3<<endl;
 cout<<"r2= "<<r2<<endl;
		O("Проверка работы конструктора CList(const CList& b)");
 CList r4(r2);
 cout<<"r4= "<<r4<<endl;
 cout<<"r2= "<<r2<<endl;
}catch(int err){cout<<"Error = "<<err<<endl;}
 return 0;
}
