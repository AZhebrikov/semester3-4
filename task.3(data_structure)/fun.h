#pragma once
#include <cstring>
# define O(a) std::cout<<a<<std::endl;

  class Cell
  {
     void Clean(){delete [] v;SetZero();}
     void SetZero(){prev=next=NULL;v=NULL;}
   public:
     Cell *prev,*next;
     const char * v;

     Cell(){/*O("Cell()");*/SetZero();}
     Cell(const char * s){v=new char [strlen(s)+1];memcpy(const_cast<char *>(v),s,strlen(s)+1);prev=next=NULL;}
     ~Cell(){/*O("~Cell()");*/Clean();}

     bool operator>(const Cell &b)const;
     bool operator>=(const Cell &b)const;
     bool operator<(const Cell &b)const;
     bool operator<=(const Cell &b)const;

     void Swap(Cell & b){const char * tmp=v;v=b.v;b.v=tmp;}

     operator const char*(){return v;}
  };




  class CList
{
   Cell  *cur,*begin,*end;

   void SetZero(){cur=begin=end=NULL;}
   void Clean(){GoToBegin();while(DelCur()==0);SetZero();}
   void CopyOnly(const CList & b){if(!b.IsEmpty())
                                               {for(iterator it=b.first();it!=b.last();++it){GoToEnd();AddAfter(*it);}  GoToEnd();}}
 public:

  class iterator
  {
    Cell *cur;
    public:
    iterator(){cur=NULL;}
    iterator(Cell *cur){this->cur=cur;}
    int operator!=(const iterator &b){return cur!=b.cur;}
    int operator==(const iterator &b){return cur==b.cur;}
    Cell * operator++(){if(cur){return cur=cur->next;}throw -3;}
    Cell * operator++(int){if(cur){Cell *r=cur;cur=cur->next;return r;}throw -3;}
    const char* operator*(){return cur->v;}
   };

   iterator first()const{return iterator(begin);}
   iterator last()const{return iterator(NULL);}

   CList(){/*O("CList()");*/SetZero();}
   CList(const CList & b){CopyOnly(b);}
   ~CList(){/*O("~CList()");*/Clean();}

   void GoToBegin(){cur=begin;}
   void GoToEnd(){cur=end;}
   int GoToNext(){if(IsEmpty())return -1;if(cur->next==NULL)return -2;cur=cur->next;return 0;}
   int GoToPrev(){if(IsEmpty())return -1;if(cur->prev==NULL)return -2;cur=cur->prev;return 0;}

   int IsEmpty()const{return cur==NULL;}
   int SizeList(){int q;GoToBegin();for(q=1;GoToNext()==0;q++);return q;}
   int Sort();

   int DelCur();
   int DelNumber(int i){ (*this)[i];return DelCur(); }
   void DelList(){Clean();}

   void AddEnd(const char * x){Cell *r=cur;GoToEnd();AddAfter(x);cur=r;}
   void AddBegin( const char * x){Cell *r=cur;GoToBegin();AddBefore(x);cur=r;}
   void AddAfter( const char* x);
   void AddBefore( const char* x);
   void AddCList(const CList & b){CopyOnly(b);}
   void AddNumber(int i, const char * x){if(i<=0)throw -2;(*this)[i-1];AddAfter(x);}

   CList & operator<<(const char * x);
   CList & operator>>(const char * x);
   Cell & operator[](int i){GoToBegin();for(;i>0&&!GoToNext();i--);if(i!=0)throw -1;return *cur;}
   int   operator()(){if(cur==begin)return 0;int q;Cell * r=cur;GoToBegin();for(q=0;cur->next!=r;q++){GoToNext();} GoToNext();q++;return q;}
};

std::ostream & operator<<(std::ostream & cout,const CList & b);




