#include <iostream>
#include "fun.h"

std::ostream & operator<<(std::ostream & cout,const CPoint &b)
{
 cout<<"("<<b.x<<", "<<b.y<<")";
return cout;
}

std::ostream & operator<<(std::ostream & cout,const CList &b)
{
 if(b.ListEmpty()){cout<<"<Лист не существует.>";}
 else if(b.Begin()==EMPTY){cout<<"<Лист пуст>";}
 else
     {
      cout<<"{ ";
  	  auto end=b.it_end_();
  	  auto it=b.it_begin();
  	  for(;it!=end;++it){cout<<*it<<", ";}
      cout<<*it<<" }";
     }
 return cout;
}

double TanTwoCPoint(const CPoint & first,const CPoint & second)
{
 return ((double)(second.y-first.y))/(second.x-first.x);
}

 std::ostream & operator<<(std::ostream & cout,const CListShell &b)
 {
  cout<<"ConvexHull= "<<b.ConvexHull<<std::endl;
  cout<<"InnerSet= "<<b.InnerSet;
  return cout;
 }
