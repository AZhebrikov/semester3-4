


#include <iostream>
#include "fun.h"

   bool Cell::operator>(const Cell &b)const
        {bool A;
         int i=0;
         do{
            if(v[i]==b.v[i]){
                           if(v[i]!='\0')continue;
                           else{A=false;break;}
                          }
            if(v[i]>b.v[i]){A=true;break;}
            else{A=false;break;}
           }while(++i);
        return A;
        }
   bool Cell::operator>=(const Cell &b)const
        {bool A;
         int i=0;
         do{
            if(v[i]==b.v[i]){
                           if(v[i]!='\0')continue;
                           else{A=true;break;}
                          }
            if(v[i]>=b.v[i]){A=true;break;}
            else{A=false;break;}
         }while(++i);
        return A;
        }
   bool Cell::operator<(const Cell &b)const
        {bool A;
         int i=0;
         do
           {if(v[i]==b.v[i]){
                           if(v[i]!='\0')continue;
                           else{A=false;break;}
                          }
            if(v[i]<b.v[i]){A=true;break;}
            else{A=false;break;}
           }while(++i);
        return A;
        }
   bool Cell::operator<=(const Cell &b)const
        {bool A;
         int i=0;
         do{
            if(v[i]==b.v[i]){
                           if(v[i]!='\0')continue;
                           else{A=true;break;}
                          }
            if(v[i]<=b.v[i]){A=true;break;}
            else{A=false;break;}
         }while(++i);
        return A;
        }


void CList::AddAfter( const char* x)
 {
  Cell *n =new Cell ;n->v= new char [strlen(x)+1];memcpy(const_cast<char *>(n->v),x,strlen(x)+1);
  if(IsEmpty()){cur=begin=end=n;}
  else
   {
    n->next=cur->next;
    n->prev=cur;
    cur->next=n;
    if(n->next)n->next->prev=n;
    else end=n;
   }
 }

 void CList::AddBefore( const char* x)
 {
  Cell *n =new Cell();n->v= new char [strlen(x)+1];memcpy(const_cast<char *>(n->v),x,strlen(x)+1);
  if(IsEmpty()){cur=begin=end=n;}
  else
   {
    n->prev=cur->prev;
    n->next=cur;
    cur->prev=n;
    if(n->prev)n->prev->next=n;
    else begin=n;
   }
 }

 int CList::DelCur()
 {/*O("DelCur()");*/
  if(IsEmpty())return -1;

  if(cur->prev)cur->prev->next=cur->next;
  else begin=cur->next;

  if(cur->next)cur->next->prev=cur->prev;
  else end=cur->prev;

   //O("Cell* r");
   Cell* r=cur;

  if(cur->prev)cur=cur->prev; else cur=cur->next;

   //O("delete r:");
   delete r;

return 0;
}

 int CList::Sort()
{
 if(IsEmpty())return -1;
 else
  {const char *tmp;
   int intbegin=0;
   int intend=SizeList()-1;
   GoToBegin();
   while(intbegin<intend)
     {
      for(;cur->next;cur=cur->next)
         if( *(cur) > *(cur->next)  ){tmp=cur->v;cur->v=cur->next->v;cur->next->v=tmp;}
      intend--;cur=cur->prev;
      for(;cur->prev;cur=cur->prev)
         if( *(cur) < *(cur->prev)  ){tmp=cur->v;cur->v=cur->prev->v;cur->prev->v=tmp;}
      intbegin++;cur=cur->next;
     }
  }
return 0;
}

std::ostream & operator<<(std::ostream & cout,const CList & b)
{
 if(b.IsEmpty())cout<<"<Список пуст>";
 else
  {
   cout<<std::endl<<" < "<<std::endl;;
   for(CList::iterator it=b.first();it!=b.last();++it)cout<<"   "<<*it<<" "<<std::endl;
   cout<<" > ";
  }
return cout;
}

 CList & CList::operator<<(const char * x)
 {
  Cell *n =new Cell ;n->v= new char [strlen(x)+1];memcpy(const_cast<char *>(n->v),x,strlen(x)+1);
  if(IsEmpty()){cur=begin=end=n;}
  else
   {
    n->next=cur->next;
    n->prev=cur;
    cur->next=n;
    if(n->next)n->next->prev=n;
    else end=n;
   }
 return *this;
 }


 CList & CList::operator>>(const char * x)
 {
  Cell *n =new Cell();n->v= new char [strlen(x)+1];memcpy(const_cast<char *>(n->v),x,strlen(x)+1);
  if(IsEmpty()){cur=begin=end=n;}
  else
   {
    n->prev=cur->prev;
    n->next=cur;
    cur->prev=n;
    if(n->prev)n->prev->next=n;
    else begin=n;
   }
 return *this;
 }


