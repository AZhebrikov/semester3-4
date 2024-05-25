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


/*
 int CList::AddAfterMass(const CPoint * b,int n)
 {O("AddAfterMass");
  int tmp,i=0;
  if(begin==EMPTY)
   {
    if((tmp=new_CPoint())<0)return -1;
    t[tmp]=b[i++];
    begin=cur=end=tmp;
    t[tmp].next=t[tmp].prev=EMPTY;
   }
  if(begin==end&&i<n)
   {
    if((tmp=new_CPoint())<0)return -1;
    end=tmp;
    t[end]=b[i++];t[end].next=EMPTY;t[end].prev=begin;
    t[begin].next=end; 
   }      
  for(;i<n;i++)
  {
   if((tmp=new_CPoint())<0)return -1;
   t[tmp]=b[i];
   t[tmp].next=t[cur].next;t[tmp].prev=cur;
   t[t[cur].next].prev=tmp;t[cur].next=tmp;
  } 
 return 0;
 }
*/


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
 
 int CList::NumberPoints()const
 {
 if( ListEmpty()||Begin()==EMPTY )return 0;
  	int number=0;
  	auto end=it_end();
  	auto it=it_begin();
  	for(;it!=end;++number,++it);
 return number;
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
  tmp=t[cur].x;t[cur].x=t[t[cur].next].x;t[t[cur].next].x=tmp;
  tmp=t[cur].y;t[cur].y=t[t[cur].next].y;t[t[cur].next].y=tmp;
 return 0;
 }
 
 int CList::SwapCurPrev()
 {
  if(t==NULL||begin==EMPTY||t[cur].prev==EMPTY)return -1;
  int tmp;
  tmp=t[cur].x;t[cur].x=t[t[cur].prev].x;t[t[cur].prev].x=tmp;
  tmp=t[cur].y;t[cur].y=t[t[cur].prev].y;t[t[cur].prev].y=tmp;
 return 0;
 }
 
 void CList::SortX()
 {
  if(t==NULL||begin==EMPTY||begin==end)return;
  int start=begin;
  int finish=end;
  cur=start;
   while(1)
   {
    for(;t[cur].next!=EMPTY;cur=t[cur].next)
         if(t[cur].x>t[t[cur].next].x)SwapCurNext();
    cur=t[finish].prev;finish=t[finish].prev;if(start==finish)break;
    for(;t[cur].prev!=EMPTY;cur=t[cur].prev)
         if(t[cur].x<t[t[cur].prev].x)SwapCurPrev();
    cur=t[start].next;start=t[start].next;if(start==finish)break;         
   }
 }
 
 
 void CList::SortY()
 {
  if(t==NULL||begin==EMPTY||begin==end)return;
  int start=begin;
  int finish=end;
  cur=start;
   while(1)
   {
    for(;t[cur].next!=EMPTY;cur=t[cur].next)
         if(t[cur].y>t[t[cur].next].y)SwapCurNext();
    cur=t[finish].prev;finish=t[finish].prev;if(start==finish)break;
    for(;t[cur].prev!=EMPTY;cur=t[cur].prev)
         if(t[cur].y<t[t[cur].prev].y)SwapCurPrev();
    cur=t[start].next;start=t[start].next;if(start==finish)break;         
   }
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


/* 
 twoint DeleteCopyCPointMax()
 {
  twoint err;
  if(t=NULL)return -2;
  if(begin==EMPTY||begin==end)return -1;
  int max;
  int tmp;
  SortX();
  for(GoToEnd();;)
   {
    max=cur;
    while(t[cur].prev!=begin&&t[t[cur].prev].x==t[cur].x){CurPrev();if(t[cur].y>t[max].y)max=cur;}
    if(t[cur].prev==begin)
     {
      if(t[t[cur].prev].x==t[begin].x)
       {
        if(t[begin].y>t[max].y)
         {
           if(t[begin].prev==EMPTY)
           {
           	err.flag=t[begin].next;
            err.end=end;
            t[begin].next=EMPTY;
            end=cur=begin;
           }
           else
           {
           	AddBeginPrev(t[begin]);
           	err.flag=t[begin].next;
           	cur=begin;
           	DeleteCur();
           	err.end=end;
           	end=cur;
           	t[end].next=EMPTY;
           }
         }
        else
         { 
          AddBeginPrev(t[max]);
          if(cur==max)
          { 
          	DeleteCur();
          }
          else
          {
          	tmp=cur;
          	cur=max;
          	DeleteCur();
          	cur=tmp;
          }
           	err.flag=begin;
           	err.end=end;
           	cur=t[begin].prev;
           	end=cur;
           	t[end].next=EMPTY;
         }      
       }
       else
       {
        AddBeginPrev(t[max]);
          if(cur==max)
          { 
          	DeleteCur();
          }
          else
          {
          	tmp=cur;
          	cur=max;
          	DeleteCur();
          	cur=tmp;
          }
          AddBeginPrev(t[begin]);
          err.flag=t[begin].next;
          cur=begin;  
          DeleteCur();
          err.end=end;
          end=cur;
          t[end].next=EMPTY;
       }
     }
    else{
    	AddBeginPrev(t[max]);
    	if(cur==max)
         {
         	DeleteCur();
         }
        else
         {
         	tmp=cur;
         	cur=max;
         	DeleteCur();
         	cur=tmp;
         }	
         CurPrev();}  
  }
 }
*/ 

 int CList::DeleteCopyCPoint()
 {
  if(t==NULL||begin==EMPTY||begin==end)return -1;
  GoToBegin();
  while(GetCurNext()!=EMPTY)
      {
       if(
         t[cur].x==t[t[cur].next].x
                                  &&
         t[cur].y==t[t[cur].next].y
         )DeleteAfter();
       else CurNext();
      }
 return 0;
 }
     
 int CList::AllSortXY()
 {
  if(t==NULL||begin==EMPTY||begin==end)return -1;
  GoToBegin();
  SortX();
  int start;
  int tmp_begin,tmp_end,tmp_start_prev,tmp_cur_next;
  tmp_begin=tmp_end=tmp_start_prev=tmp_cur_next=EMPTY;
  for(start=cur;;)
    {
     	if(GetCurNext()!=EMPTY)
    	  {
       	  if( t[GetCurNext()].x != t[start].x)
         	{
         	 if(start==cur){start=CurNext();continue;}
          	 tmp_begin=begin;
          	 tmp_end=end;
          	 tmp_start_prev=t[start].prev;
          	 tmp_cur_next=t[cur].next;
                    begin=start;t[begin].prev=EMPTY;
                    end=cur;t[end].next=EMPTY;
                    SortY();
                    GoToEnd();
                begin=tmp_begin;
                end=tmp_end;
                t[start].prev=tmp_start_prev;
                t[cur].next=tmp_cur_next;
                start=CurNext();
         	}
       	else 
       	 {
          CurNext();
       	 } 
        }
        else
          {
               if(cur!=start)
                {
                 tmp_begin=begin;
          	     tmp_start_prev=t[start].prev;
          	     begin=start;t[begin].prev=EMPTY;
                     SortY();
                     GoToEnd();
                 begin=tmp_begin;
                 t[start].prev=tmp_start_prev;
                }
            break;
          } 
    }  
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
             <<t[i].next<<"  x= "<<t[i].x<<"  y= "<<t[i].y<<std::endl; 
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


int CList::SearchCPoint(const CPoint & b)
{
  if(ListEmpty())return -3;
  if(begin==EMPTY)return -2;
  GoToBegin();
  do{
     if(t[cur]==b)return 0;
  }while(CurNext()!=EMPTY);
 return -1;
}

int CList::DeleteCPoint(const CPoint & b)
{
  if(ListEmpty())return -3;
  if(begin==EMPTY)return -2;
  if(SearchCPoint(b)==-1)return -1;
  DeleteCur();
  return 0;
}
