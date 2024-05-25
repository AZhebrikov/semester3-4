#include <iostream>
#include "fun.h"

std::ostream & operator<<(std::ostream & cout,const CPoint &b)
{
 cout<<b.element;
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

std::ostream & operator<<(std::ostream & cout, SparseMatrix &b)
{
	if(b.m==0){cout<<"Матрица пуста."<<std::endl;}
	else
	    {
	    	cout<<"Матрица:"<<std::endl;
	    	for(int i=0;i<b.m;i++)cout<<"["<<i<<"]: "<<b[i]<<std::endl;
	    }
 return cout;
}


