#include <iostream>
#include "fun.h"



int CList::StartNext()
    {
     if(ListEmpty())return -2;
     if(t[start].next==EMPTY)return -1; 
     start=t[start].next;
     t[start].prev=EMPTY;
    return 0;
    } 


 int CList::new_CPoint()
 {
  int i;
  if(ListEmpty())
    {
     t = new CPoint [Size];
     if(t==NULL){return -1;}
       begin=end=cur=EMPTY;
         start=0;finish=Size-1;
         t[0].prev=EMPTY;t[0].next=1;
         for(i = 1;i<finish;i++){t[i].prev=i-1;t[i].next=i+1;}
         t[finish].next=EMPTY;t[finish].prev=i-1;
    }
   else if(start==finish)
    {
     CPoint * p =new CPoint [Size*2];
     if(p==NULL)return -1;
       for(i=0;i<Size;i++)
        {
         p[i]=t[i];
         p[i].next=t[i].next;
         p[i].prev=t[i].prev;
        }
       Size=Size*2;
       finish=Size-1;p[start].next=i;
       for(;i<finish;i++){p[i].prev=i-1;p[i].next=i+1;}
       p[finish].next=EMPTY;p[finish].prev=i-1;
         delete [] t;t=p;
    }
   i=start;
   StartNext();
 return i;
 }


 int CList::AddAfter(const CPoint & b)
 {
  int tmp;
  if((tmp=new_CPoint())<0)return -1;
  if(begin==EMPTY)
   {
    t[tmp]=b;
    begin=cur=end=tmp;
    t[tmp].next=t[tmp].prev=EMPTY;
   } 
  else if(begin==end)
   {
    end=tmp;
    t[end]=b;t[end].next=EMPTY;t[end].prev=begin;
    t[begin].next=end; 
   }
  else
   {
    t[tmp]=b;
    if(cur!=end)
     {
      t[tmp].next=t[cur].next;t[tmp].prev=cur;
      t[t[cur].next].prev=tmp;t[cur].next=tmp;
     }
    else
     {
      t[tmp].next=EMPTY;t[tmp].prev=cur;
      t[cur].next=tmp;
      end=tmp;
     }
   }
 return 0;
 }




 int CList::DeleteAfter()
 {
  if(ListEmpty())return -3;
  if(begin==EMPTY)return -2;
  if(t[cur].next==EMPTY)return -1;
  if(t[t[cur].next].next==EMPTY)
   {
    t[start].prev=t[cur].next;
    t[t[cur].next].next=start;
    t[t[cur].next].prev=EMPTY;
    start=t[cur].next;
    end=cur;t[cur].next=EMPTY;
   }
  else
   {
    int tmp=t[cur].next;
    t[cur].next=t[tmp].next;
    t[t[tmp].next].prev=cur;
    t[start].prev=tmp;
    t[tmp].next=start;
    start=tmp;
   } 
 return 0; 
 }

 int CList::DeleteCur()
 {
  if(ListEmpty())return -3;
  if(begin==EMPTY)return -2;
  if(t[cur].next==EMPTY)
     {
    	if(t[cur].prev==EMPTY)
     	{
     	 t[cur].next=start;
     	 t[start].prev=cur;
      	 start=cur;t[start].prev=EMPTY;
     	 begin=cur=end=EMPTY;
     	}
   	else
    	{
     	 t[cur].next=start;
     	 t[start].prev=cur;
     	 end=t[cur].prev;
     	 t[end].next=EMPTY;
     	 start=cur;
     	 t[start].prev=EMPTY;
     	 cur=end;     
    	}
   }
  else
   {
    	if(t[cur].prev==EMPTY)
    	{
    	 begin=t[cur].next;
    	 t[begin].prev=EMPTY;
    	 t[start].prev=cur;
    	 t[cur].next=start;
    	 start=cur;
    	 t[start].prev=EMPTY;
    	 cur=begin;
    	}
    	else
    	{
    	 t[t[cur].prev].next=t[cur].next;
    	 t[t[cur].next].prev=t[cur].prev;
    	 t[cur].next=start;
    	 t[start].prev=cur;
    	 start=cur;
    	 cur=t[cur].prev;
    	 t[start].prev=EMPTY;
    	}
   } 
 return 0; 
 }

int CList::Delete()
 {int i;
  if(ListEmpty())return -1;
  if(begin==EMPTY)return 0;
  begin=cur=end=EMPTY;
  start=0;
  t[start].prev=EMPTY;t[start].next=start+1;
  for(i=1;i<Size-1;i++)
   {
    t[i].prev=i-1;t[i].next=i+1;
   }
  t[i].prev=i-1;t[i].next=EMPTY;
 return 0;
 }
 

 int CList::CopeOnly(const CList & b)
 {
  if( t==NULL||Size<b.Size )
   {
    delete [] t;
    t=new CPoint [Size=b.Size];
    if(t==NULL)return -1;
   }
  int i; 
  for(i=0;i<Size;i++)
   {
    t[i]=b.t[i];
    t[i].next=b.t[i].next;
    t[i].prev=b.t[i].prev;
   }    
  begin=b.begin;cur=b.cur;end=b.end;
  start=b.start;finish=b.finish;
  if(Size>b.Size)
   {
    for(t[finish].next=i;i<Size-1;i++)
     {
      t[i].prev=i-1;
      t[i].next=i+1;
     }
     finish=i;
     t[finish].next=EMPTY;
   }
  return 0;
 }

 void CList::Clean()
 {
  delete [] t;t=NULL;
  begin=cur=end=start=finish=EMPTY;
 }



 int CList::SwapCurNext()
 {
  if(t==NULL||begin==EMPTY||t[cur].next==EMPTY)return -1;
  int tmp;
  tmp=t[cur].element;t[cur].element=t[t[cur].next].element;t[t[cur].next].element=tmp;
 return 0;
 }
 
 int CList::SwapCurPrev()
 {
  if(t==NULL||begin==EMPTY||t[cur].prev==EMPTY)return -1;
  int tmp;
  tmp=t[cur].element;t[cur].element=t[t[cur].prev].element;t[t[cur].prev].element=tmp;
 return 0;
 }
 
 

 
 
 
  int CList::Chek(int mod)const
     {
      if(t==NULL)return -1;
      if(mod==0)
               {
                std::cout<<"bedin= "<<begin<<std::endl
                         <<"cur= "<<cur<<std::endl
                         <<"end= "<<end<<std::endl
                         <<"start= "<<start<<std::endl
                         <<"finish= "<<finish<<std::endl
                         <<"Size= "<<Size<<std::endl;
                if(t==NULL)std::cout<<"t=NULL"<<std::endl;
                else std::cout<<"t!=NULL"<<std::endl;
               }
      if(mod==1)
               {
                std::cout<<"cur = "<<cur<<std::endl
                         <<"next = "<<t[cur].next<<std::endl
                         <<"prev = "<<t[cur].prev<<std::endl;
               }
     return 0;
    }
 
 

 int CList::massChek()const
            {
             if(t==NULL)return -1;
             for(int i =0;i<Size;i++)std::cout<<"t["<<i<<"]:"<<"  prev= "<<t[i].prev<<"  next= "
             <<t[i].next<<"  element= "<<t[i].element<<"  j= "<<t[i].j<<std::endl; 
             return 0;
            }    

 int CList::massError()
            {
             int TMP_cur=cur;
             if(t==NULL)return -3;
             if(begin==EMPTY)return -2;
             cur=begin;
             while(GetCurNext()!=EMPTY)
             {
              if( (cur) != (t[t[cur].next].prev) ){return -1;}
              CurNext();
             }
             cur=TMP_cur;
            return 0;
            }


int CList::SearchNumber(int je)
{
	if(ListEmpty())return -3;
    if(begin==EMPTY)return -2;
  if(begin==end)
       {
        if(t[cur].j<je)return 2;
        if(t[cur].j==je)return 1;
        if(t[cur].j>je)return 0;
       }
  GoToBegin();
  if(t[cur].j==je)return 1;
  if(t[cur].j>je)return 0;
  do{
     if(t[cur].j==je)return 1;
     if(t[cur].j>je){CurPrev();return 2;}
  }while(CurNext()!=EMPTY);
 return 2;
}


int CList::AddBeginPrev(const CPoint & b)
 {
  int tmp;
  if((tmp=new_CPoint())<0)return -1;    
   
  if(begin==EMPTY)
   {
    t[tmp]=b;
    begin=cur=end=tmp;
    t[tmp].next=t[tmp].prev=EMPTY;
   }
  else if(t[begin].next==EMPTY)
   {
    t[tmp]=b;
    t[tmp].next=begin;
    t[tmp].prev=EMPTY;
    t[begin].next=EMPTY;
    t[begin].prev=tmp;
    begin=tmp;
   }
  else
   {
    t[tmp]=b;
    t[tmp].prev=EMPTY;
    t[tmp].next=begin;
    t[begin].prev=tmp;
    begin=tmp;
   }
  return 0;
 }

