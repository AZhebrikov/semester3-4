#include <iostream>
#include "fun.h"

int main(void)
{
 using std::cout;
 using std::endl;
 using std::cin; 
/*
 cout<<"Проверка класса CPoint:"<<endl;
 {
 CPoint a;
 cout<<"a= ";cout<<a<<endl;
 CPoint b(-3,5);
 cout<<"b= "<<b<<endl;
 CPoint c(b);
 cout<<"c= "<<c<<endl;
 a=b;
 cout<<"a= "<<a<<endl;
 }
 cout<<"==========================================================================Проверка класса CList:\n"
       "Проверка функций, связанных с заполнением,\n инициализацией и выделением памяти:"<<endl;
 {
 int i;
 CPoint mass[3];
 mass[0]=CPoint(2,6);
 mass[1]=CPoint(-1,4);
 mass[2]=CPoint(-4,3);
 cout<<"mass = {";for(i=0;i<2;i++)cout<<mass[i]<<", ";cout<<mass[i]<<"}"<<endl;
 CPoint b(-3,5);
 cout<<"b= "<<b<<endl;
  cout<<"================================"<<endl;
  CList a;
  cout<<"a: ";a.Chek();
  cout<<"a= "<<a<<endl;
  
  cout<<"================================"<<endl;
  CList c(b);
  cout<<"c: ";c.Chek();
  cout<<"c= "<<c<<endl;
  
  cout<<"================================"<<endl;
  CList d(mass,3);
  cout<<"d: ";d.Chek();
  cout<<"d= "<<d<<endl;
  
  cout<<"================================"<<endl;
  cout<<"d: ";d.Chek();
  cout<<"d= "<<d<<endl;
  d.massChek();
  d.AddAfter(CPoint (6,-3)); 
  d.AddAfter(CPoint (8,8)); 
  d.AddAfter(CPoint (4,-3)); 
  d.AddAfter(CPoint (12,-14)); 
  d.AddAfter(CPoint (5,-8)); 
  d.AddAfter(CPoint (9,-8)); 
  d.AddAfter(CPoint (13,7)); 
  d.AddAfter(CPoint (81,6)); 
  d.AddAfter(CPoint (3,-3)); 
  d.AddAfter(CPoint (14,-5));
  cout<<"d= "<<d<<endl;
  cout<<"d: ";d.Chek();   
  CList g(d);
  cout<<"g= "<<g<<endl;
  cout<<"g: ";g.Chek();   
  cout<<"CpointNumber(g)= "<<g.NumberPoints()<<endl;
  cout<<"CpointNumber(c)= "<<c.NumberPoints()<<endl;
 }

 {
  cout<<"Проверка работы функций, связанных с работой с индексами:"<<endl;
  CList a;
  cout<<"add"<<endl;a.AddAfter(CPoint (1,1));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(1);
  cout<<"add"<<endl;a.AddAfter(CPoint (2,2));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(1);
  cout<<"add"<<endl;a.AddAfter(CPoint (3,3));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"add"<<endl;a.AddAfter(CPoint (4,4));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;  
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(1);
  a.CurPrev();cout<<"a.CurPrev();"<<endl;a.Chek(1);
  a.CurPrev();cout<<"a.CurPrev();"<<endl;a.Chek(1);
  a.massChek();a.Chek(1);a.Chek(0);
  cout<<"add"<<endl;a.AddAfter(CPoint (5,5));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"GetCurNext()= "<<a.GetCurNext()<<"  ,GetCutPrev()= "<<a.GetCurPrev()<<endl;a.Chek(1);a.Chek(0); 
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(1);a.Chek(0); 
  cout<<"GetCurNext()= "<<a.GetCurNext()<<"  ,GetCutPrev()= "<<a.GetCurPrev()<<endl;a.Chek(1);a.Chek(0); 
 
  cout<<"Проверка работы функций, связанных с работой с индексами:"<<endl;
  a.Chek(1);a.massChek();
  a.Chek(0);cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0); 
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(1);a.Chek(0);   
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(1);a.Chek(0);   
  a.Chek(1);a.massChek();
  a.CurNext();cout<<"a.CurNext();"<<endl;a.Chek(0); 
  cout<<"add"<<endl;a.AddAfter(CPoint (6,6));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;
  a.Chek(0);a.massChek();cout<<"a.DeleteAfter();";a.DeleteAfter();a.Chek(0);a.massChek();
  cout<<"a= "<<a<<endl;
  cout<<"add"<<endl;a.AddAfter(CPoint (7,7));a.massChek();a.Chek(1);a.Chek(0);cout<<"a= "<<a<<endl;
  a.Chek(0);
  cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"a.DeleteCur();";a.DeleteCur();a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"-------"<<endl;
  cout<<"add"<<endl;a.AddAfter(CPoint (1,1));a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"add"<<endl;a.AddAfter(CPoint (2,2));a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"add"<<endl;a.AddAfter(CPoint (3,3));a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"add"<<endl;a.AddAfter(CPoint (4,4));a.Chek(0);cout<<"a= "<<a<<endl;
  cout<<"a.Delete();";a.Delete();a.Chek(0);cout<<"a= "<<a<<endl;  
 }

 {
  cout<<"Проверка операторов класса CList,связанных с копированием и добавлением элементов:"<<endl;
  CList a;
  a<<CPoint(1,1)<<CPoint(2,2)<<CPoint(3,3);
  cout<<"a= "<<a<<endl;
  a>>CPoint(-1,-1)>>CPoint(-2,-2)>>CPoint(-3,-3);
  cout<<"a= "<<a<<endl;
  CList b=a;
  cout<<"b= "<<b<<endl;
  CList c=CList(CPoint(10,10));
  cout<<"c= "<<c<<endl;
  CList k,l;
  cout<<"k= "<<k<<endl;
  cout<<"l= "<<l<<endl;
  k=c;
  cout<<"k= "<<k<<endl;
  l=CList(CPoint(5,5));
  cout<<"l= "<<l<<endl;
  c=a;
  cout<<"c= "<<c<<endl;
 }
 
 {
  cout<<"Проверка функций сортировки."<<endl;
  CList a;
  a<<CPoint(1,1)<<CPoint(2,2)<<CPoint(3,3);
  cout<<"a= "<<a<<endl;
  a.GoToBegin();a.SwapCurPrev();cout<<"a.GoToBegin();a.SwapCurPrev();  a= "<<a<<endl;
  a.SwapCurNext();cout<<"a.SwapCurNext();  a= "<<a<<endl;
  a.CurNext();a.SwapCurNext();cout<<"a.CurNext();a.SwapCurNext();  a= "<<a<<endl;
  a.CurNext();a.SwapCurPrev();cout<<"a.CurNext();a.SwapCurPrev();  a= "<<a<<endl;
  a.CurNext();a.SwapCurNext();cout<<"a.CurNext();a.SwapCurNext();  a= "<<a<<endl;

  CList b;
  b<<CPoint(1,1)
   <<CPoint(1,-7)
   <<CPoint(1,20)
   <<CPoint(1,0)
   <<CPoint(1,-20)
   <<CPoint(1,-3)
   <<CPoint(1,7)
   <<CPoint(1,5)
   <<CPoint(1,6)
   <<CPoint(1,1)
   <<CPoint(1,-17)
   <<CPoint(1,0)
   <<CPoint(1,8);
 cout<<"b= "<<b<<endl;
 b.SortX();
 cout<<"b= "<<b<<endl;
 b.SortY();
 cout<<"b= "<<b<<endl;
 CList c;
  c<<CPoint(-1,1)
   <<CPoint(-2,1)
   <<CPoint(19,1)
   <<CPoint(8,1)
   <<CPoint(4,1)
   <<CPoint(-6,1)
   <<CPoint(7,1)
   <<CPoint(-2,1)
   <<CPoint(3,1)
   <<CPoint(5,1)
   <<CPoint(8,1)
   <<CPoint(-4,1)
   <<CPoint(-2,1);
 cout<<"c= "<<c<<endl;
 c.SortX();
 cout<<"c= "<<c<<endl;
 c.SortY();
 cout<<"c= "<<c<<endl;


 }
 
 {
  cout<<"Проверка второстепенных функций:"<<endl;
  CList c;
  c<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  c.Chek();c.Chek(1);
  cout<<"c= "<<c<<endl;
  c.AddBeginPrev(CPoint(6,6));
  c.Chek();c.Chek(1);
  cout<<"c= "<<c<<endl;
  CList b;
  cout<<"b= "<<b<<endl;
  b.AddBeginPrev(CPoint(1,1));b.Chek();b.Chek(1);cout<<"b= "<<b<<endl;
  b.AddBeginPrev(CPoint(2,2));b.Chek();b.Chek(1);cout<<"b= "<<b<<endl;
  b.AddBeginPrev(CPoint(3,3));b.Chek();b.Chek(1);cout<<"b= "<<b<<endl;
  cout<<"b= "<<b<<endl;


 }
 
 {
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,8))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,8)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,7))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,7)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,6))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,6)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,5))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,5)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,4))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,4)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,2))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,2)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,0))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,0)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,-1))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,-1)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,-2))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,-2)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,-3))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,-3)<<endl;
  cout<<"angle= "<<TanTwoCPoint(CPoint(2,2),CPoint(4,-4))<<"   Cpoint1= "<<CPoint(2,2)<<"   Cpoint2= "<<CPoint(4,-4)<<endl; 
 }
 
 {
 cout<<"____________________________"<<endl;
 {CList a;
  a<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"a= "<<a<<endl;   
 CList b;
  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"b= "<<b<<endl;
   
  cout<<"CListShell rt1;"<<endl;
  CListShell rt1;
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"rt1.ConvexHull_Move_InnerSet();"<<endl;
  rt1.ConvexHull_Move_InnerSet();
  cout<<"rt1:\n"<<rt1<<endl;
 }
 cout<<"____________________________"<<endl;
 {CList a;
  a<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"a= "<<a<<endl;   
 CList b;
  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"b= "<<b<<endl;
   
  cout<<"CListShell rt1(a,b,ALLOCATE_MEMORY_and_ALLICATE_MEMORY);"<<endl;
  CListShell rt1(a,b,ALLOCATE_MEMORY_and_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"rt1.ConvexHull_Move_InnerSet();"<<endl;
  rt1.ConvexHull_Move_InnerSet();
  cout<<"rt1:\n"<<rt1<<endl;
 }
 cout<<"____________________________"<<endl;
 {CList a;
  a<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"a= "<<a<<endl;   
 CList b;
  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"b= "<<b<<endl;
   
  cout<<"CListShell rt1(a,b,ALLOCATE_MEMORY_and_NOT_ALLICATE_MEMORY);"<<endl;
  CListShell rt1(a,b,ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"rt1.ConvexHull_Move_InnerSet();"<<endl;
  rt1.ConvexHull_Move_InnerSet();
  cout<<"rt1:\n"<<rt1<<endl;
 }
 cout<<"____________________________"<<endl;
 {CList a;
  a<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"a= "<<a<<endl;   
 CList b;
  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"b= "<<b<<endl;
   
   
  cout<<"CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_ALLOCATE_MEMORY);"<<endl;
  CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"rt1.ConvexHull_Move_InnerSet();"<<endl;
  rt1.ConvexHull_Move_InnerSet();
  cout<<"rt1:\n"<<rt1<<endl;
 }
 cout<<"____________________________"<<endl;
 {CList a;
  a<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"a= "<<a<<endl;   
 CList b;
  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);
  cout<<"b= "<<b<<endl;
   
  cout<<"CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);"<<endl;
  CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"rt1.ConvexHull_Move_InnerSet();"<<endl;
  rt1.ConvexHull_Move_InnerSet();
  cout<<"rt1:\n"<<rt1<<endl;
  }
 }


 {
  cout<<"Проверка добавочных функций:"<<endl;
    CList a;
  a<<CPoint(1,1)
   <<CPoint(4,-7)
   <<CPoint(-3,20)
   <<CPoint(5,0)
   <<CPoint(2,-20)
   <<CPoint(-3,-3)
   <<CPoint(-2,7)
   <<CPoint(6,5)
   <<CPoint(5,0)
   <<CPoint(-7,1)
   <<CPoint(4,-7)
   <<CPoint(3,0)
   <<CPoint(1,1)
   <<CPoint(-1,5)
   <<CPoint(-2,-3)
   <<CPoint(19,2)
   <<CPoint(8,-6)
   <<CPoint(5,0)
   <<CPoint(3,4)
   <<CPoint(7,-3)
   <<CPoint(-2,1)
   <<CPoint(3,4)
   <<CPoint(5,0)
   <<CPoint(7,-3)
   <<CPoint(-4,5)
   <<CPoint(-2,3);
   cout<<"a= "<<a<<endl;
   cout<<"a.AllSortXY();"<<endl;
   a.AllSortXY();
   cout<<"a= "<<a<<endl;
  }
  
  {
     CList a;
  a<<CPoint(1,3)
   <<CPoint(2,1)
   <<CPoint(3,2)
   <<CPoint(1,4)
   <<CPoint(2,2)
   <<CPoint(3,1)
   <<CPoint(1,2)
   <<CPoint(2,3)
   <<CPoint(3,2)
   <<CPoint(1,4)
   <<CPoint(2,4)
   <<CPoint(3,4)
   <<CPoint(1,0)
   <<CPoint(2,0)
   <<CPoint(3,3)
   <<CPoint(1,2)
   <<CPoint(2,1)
   <<CPoint(3,0)
   <<CPoint(1,4)
   <<CPoint(2,2)
   <<CPoint(3,1)
   <<CPoint(1,4)
   <<CPoint(2,0)
   <<CPoint(3,3)
   <<CPoint(1,2)
   <<CPoint(2,3);
   cout<<"a= "<<a<<"   aError= "<<a.massError()<<endl;
   a.SortY();cout<<"SortY();"<<endl;
   cout<<"a= "<<a<<"   aError= "<<a.massError()<<endl;
   a.SortX();cout<<"SortX();"<<endl;
   cout<<"a= "<<a<<"   aError= "<<a.massError()<<endl;
   cout<<"a.AllSortXY();"<<endl;
   a.AllSortXY();
   cout<<"a= "<<a<<"   aError= "<<a.massError()<<endl;
   cout<<"DeleteCopyCPoint()"<<endl;
   a.DeleteCopyCPoint();
   cout<<"a= "<<a<<endl; 
  }
 */
 
 /*
 {
  cout<<"Углубленная проверка операторов:"<<endl;
  CList a; a.massChek();a.Chek(1);
  cout<<"1<<"<<endl;a<<CPoint(1,1);a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"2>>"<<endl;a>>CPoint(2,2);a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"3<<"<<endl;a<<CPoint(3,3);a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"4<<"<<endl;a<<CPoint(4,4);a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"5<-"<<endl;a.CurPrev();a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"6()"<<endl;a.DeleteCur();a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"7<<"<<endl;a<<CPoint(3,3);a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"8()"<<endl;a.DeleteCur();a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"9<--"<<endl;a.GoToBegin();a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;
  cout<<"10>>"<<endl;a>>CPoint(5,5);a.massChek();a.Chek(0);cout<<"aError= "<<a.massError()<<endl;cout<<"a= "<<a<<endl;

 }
 */
 
 /*
 {
  CList a;
  a<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4);   
  CList b;
  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4);
   
  cout<<"b= "<<b<<endl;
   
  cout<<"CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);"<<endl;
  CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;

  cout<<"rt1[0]:"<<endl;rt1[0].massChek();rt1[0].Chek();cout<<"rt1[0]Error= "<<rt1[0].massError()<<endl;
  cout<<"rt1[1]:"<<endl;rt1[1].massChek();rt1[1].Chek();cout<<"rt1[1]Error= "<<rt1[1].massError()<<endl;

  cout<<"rt1.ConvexHull_OneMove_InnerSet();"<<endl;
  rt1.ConvexHull_OneMove_InnerSet();

  cout<<"rt1[0]:"<<endl;rt1[0].massChek();rt1[0].Chek();cout<<"rt1[0]Error= "<<rt1[0].massError()<<endl;
  cout<<"rt1[1]:"<<endl;rt1[1].massChek();rt1[1].Chek();cout<<"rt1[1]Error= "<<rt1[1].massError()<<endl;

  cout<<"rt1.ConvexHull_OneMove_InnerSet();"<<endl;
  rt1.ConvexHull_OneMove_InnerSet();

  cout<<"rt1[0]:"<<endl;rt1[0].massChek();rt1[0].Chek();cout<<"rt1[0]Error= "<<rt1[0].massError()<<endl;
  cout<<"rt1[1]:"<<endl;rt1[1].massChek();rt1[1].Chek();cout<<"rt1[1]Error= "<<rt1[1].massError()<<endl;
  
  cout<<"rt1.ConvexHull_OneMove_InnerSet();"<<endl;
  rt1.ConvexHull_OneMove_InnerSet();

  cout<<"rt1[0]:"<<endl;rt1[0].massChek();rt1[0].Chek();cout<<"rt1[0]Error= "<<rt1[0].massError()<<endl;
  cout<<"rt1[1]:"<<endl;rt1[1].massChek();rt1[1].Chek();cout<<"rt1[1]Error= "<<rt1[1].massError()<<endl;

  cout<<"rt1.ConvexHull_OneMove_InnerSet();"<<endl;
  rt1.ConvexHull_OneMove_InnerSet();

  cout<<"rt1[0]:"<<endl;rt1[0].massChek();rt1[0].Chek();cout<<"rt1[0]Error= "<<rt1[0].massError()<<endl;
  cout<<"rt1[1]:"<<endl;rt1[1].massChek();rt1[1].Chek();cout<<"rt1[1]Error= "<<rt1[1].massError()<<endl;

  rt1[1].AllSortXY();
  rt1[1].DeleteCopyCPoint();

  cout<<"rt1[0]:"<<endl;rt1[0].massChek();rt1[0].Chek();cout<<"rt1[0]Error= "<<rt1[0].massError()<<endl;
  cout<<"rt1[1]:"<<endl;rt1[1].massChek();rt1[1].Chek();cout<<"rt1[1]Error= "<<rt1[1].massError()<<endl;
  
 }
 */
 /*
 {
  cout<<"Проверка остатка работы функций"<<endl;
  CList a;
  CList b; 

  b<<CPoint(5,1)
   <<CPoint(-2,3)
   <<CPoint(3,-2)
   <<CPoint(6,1)
   <<CPoint(-4,6)
   <<CPoint(5,8)
   <<CPoint(7,8)
   <<CPoint(8,9)
   <<CPoint(12,12)
   <<CPoint(1,3)
   <<CPoint(6,2)
   <<CPoint(-3,11)
   <<CPoint(2,6);
    
   cout<<"a= "<<a<<endl;
   cout<<"b= "<<b<<endl;

  
  cout<<"CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);"<<endl;
  CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"---"<<endl;
  rt1[0].CurPrev();rt1.ConvexHullChek(1);
  cout<<"---"<<endl;
  rt1[1].CurPrev();rt1.InnerSetChek(1);
  cout<<"---"<<endl;
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"rt1.ConvexHull_OneMore_InnerSet();"<<endl;
  rt1.ConvexHull_OneMove_InnerSet();
  rt1.ConvexHullChek(1);
  rt1.InnerSetChek(1);
  cout<<"rt1:\n"<<rt1<<endl;
  rt1.ConvexHull_OneMove_InnerSet();
  rt1.ConvexHullChek(1);
  rt1.InnerSetChek(1);
  cout<<"rt1:\n"<<rt1<<endl;
  }
  */
  {
   CList a;
   CList b; 

  b<<CPoint(-3,-4)
   <<CPoint(-4,-1)
   <<CPoint(-2,-2)
   <<CPoint(-3,2)
   <<CPoint(-1,2)
   <<CPoint(-2,4)
   <<CPoint(1,-5)
   <<CPoint(1,-1)
   <<CPoint(1,1)
   <<CPoint(1,3)
   <<CPoint(1,5)
   <<CPoint(2,-2)
   <<CPoint(2,4)
   <<CPoint(4,-1)
   <<CPoint(4,1)
   <<CPoint(4,5)
   <<CPoint(5,2)
   <<CPoint(5,-2)
   <<CPoint(-4,1)
   <<CPoint(-4,3)
   <<CPoint(-4,5)
   <<CPoint(-2,8)
   <<CPoint(0,7)
   <<CPoint(2,6)
   <<CPoint(2,-5)
   <<CPoint(3,-4)
   <<CPoint(4,-3)
   <<CPoint(5,0)
   <<CPoint(5,1);
    
   cout<<"a= "<<a<<endl;
   cout<<"b= "<<b<<endl;

  
  cout<<"CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);"<<endl;
  CListShell rt1(b,a,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;
  cout<<"---"<<endl;


  cout<<"ShellBuiling();==============="<<endl;
  rt1.ShellBuiling();
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"ConvexHullNumber= "<<rt1.ConvexHullNumber()<<endl;
  cout<<"InnerSetNumber= "<<rt1.InnerSetNumber()<<endl;
  cout<<"CHdelete(10,10)"<<rt1.DeleteCPointConvexHull(CPoint(10,10))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"CHdelete(-3,-4)"<<rt1.DeleteCPointConvexHull(CPoint(-3,-4))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"ISdelete(10,10)"<<rt1.DeleteCPointInnerSet(CPoint(10,10))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"ISdelete(-1,2)"<<rt1.DeleteCPointInnerSet(CPoint(-1,2))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"delete(10,10)"<<rt1.DeleteCPointSet(CPoint(10,10))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"delete(-2,8)"<<rt1.DeleteCPointSet(CPoint(-2,8))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"Add(3,7)"<<endl;
  rt1.AddCPoint(CPoint(3,7));
  cout<<"rt1:\n"<<rt1<<endl; 
  

 }
 
 
 {
  cout<<"====="<<endl;
  CList a;
  CList b;

  b<<CPoint(1,1)
   <<CPoint(2,2)
   <<CPoint(3,3)
   <<CPoint(4,4)
   <<CPoint(5,5);

  CListShell rt1(a,b,NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY);
  cout<<"rt1:\n"<<rt1<<endl;
  cout<<"a= "<<a<<endl;   
  cout<<"b= "<<b<<endl;

  rt1.ShellBuiling();
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"ConvexHullNumber= "<<rt1.ConvexHullNumber()<<endl;
  cout<<"InnerSetNumber= "<<rt1.InnerSetNumber()<<endl;
  cout<<"CHdelete(10,10)"<<rt1.DeleteCPointConvexHull(CPoint(10,10))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"CHdelete(1,1)"<<rt1.DeleteCPointConvexHull(CPoint(1,1))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"ISdelete(10,10)"<<rt1.DeleteCPointInnerSet(CPoint(10,10))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"ISdelete(-1,2)"<<rt1.DeleteCPointInnerSet(CPoint(-1,2))<<endl;
  cout<<"rt1:\n"<<rt1<<endl; 
  cout<<"Add(7,4)"<<endl;
  rt1.AddCPoint(CPoint(7,4));
  cout<<"rt1:\n"<<rt1<<endl; 
  
 }
 
 cout<<"Работает."<<endl;
return 0;
}
