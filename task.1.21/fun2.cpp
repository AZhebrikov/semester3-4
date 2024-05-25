#include<iostream>
#include"fun.h"



int SparseMatrix::AddElement(int i,const CPoint & b)
{
 if(b.element==0)return -1;
 if(Matrix==NULL){Generate(i+1,b.j+1);Matrix[i].AddAfter(b);return 0;}
 if(i>=m||i<0||b.j>=n||b.j<0)return -2;
 int tmp=Matrix[i].SearchNumber(b.j);
      if(tmp==-3||tmp==-2)
         {
          Matrix[i].AddAfter(b);
         } 
 else if(tmp==-1){throw -1;}
 else if(tmp==0)
         {
          Matrix[i].AddBeginPrev(b);
         }
 else if(tmp==1)
         {
          Matrix[i].t[Matrix[i].cur].element=b.element;
         }
 else if(tmp==2) 
         {
          Matrix[i].AddAfter(b);
         }
return 0;
}

int SparseMatrix::SwapLine(int i,int j)
                          {
                           if(i>=m||j>=m||i<0||j<0)throw -1;
                           if(i==j)return 0;
                           CPoint * listtmp;int tmp;
                           listtmp=Matrix[i].t;Matrix[i].t=Matrix[j].t;Matrix[j].t=listtmp;
                           tmp=Matrix[i].begin;Matrix[i].begin=Matrix[j].begin;Matrix[j].begin=tmp;
                           tmp=Matrix[i].cur;Matrix[i].cur=Matrix[j].cur;Matrix[j].cur=tmp;
                           tmp=Matrix[i].end;Matrix[i].end=Matrix[j].end;Matrix[j].end=tmp;
                           tmp=Matrix[i].start;Matrix[i].start=Matrix[j].start;Matrix[j].start=tmp;
                           tmp=Matrix[i].finish;Matrix[i].finish=Matrix[j].finish;Matrix[j].finish=tmp;
                           tmp=Matrix[i].Size;Matrix[i].Size=Matrix[j].Size;Matrix[j].Size=tmp;
                          return 0;
                          }

CListTmp1 CListTmp1::operator*=(int M)
                          {
                           if(M==0){(*List).Delete();}
                           else
                             {
                              (*List).GoToBegin();
                              if((*List).begin==EMPTY)return (*this);
                              do{
                                  (*List).t[(*List).cur].element=((*List).t[(*List).cur].element)*M;
                              }while((*List).CurNext()!=EMPTY);
                             }
                           return (*this);  
                          }

CList  CListTmp1::operator*(int M)const
                          {
                           CList tmp;
                           if(M!=0)
                             {
                              tmp = (*List);
                              tmp.GoToBegin();
                              if(tmp.begin==EMPTY)return tmp;
                                do{
                                   tmp.t[tmp.cur].element=(tmp.t[tmp.cur].element)*M;
                                }while(tmp.CurNext()!=EMPTY);
                             }
                           return tmp;  
                          }



CListTmp1  CListTmp1::operator+=( CList &  b )
{
 if(b.begin==EMPTY)return *this;
 b.GoToEnd();if(b.t[b.cur].j>=n)return *this;
 if((*List).begin==EMPTY){(*List)=b;return *this;}
 b.GoToBegin();      int t1=b.t[b.cur].j;
 (*List).GoToBegin();int t2=(*List).t[(*List).cur].j;
   if(t1<t2)
   {
    (*List).AddBeginPrev(b.t[b.cur]);
     if(b.CurNext()==EMPTY)return *this;
     t2=t1;
     t1=b.t[b.cur].j;
   }
 
 do{
    if(t2<t1)
      {
        if((*List).CurNext()==EMPTY)
        {
         do{
            (*List).AddAfter(b.t[b.cur]);
         }while(b.CurNext()!=EMPTY);
         break;
        }
        t2=(*List).t[(*List).cur].j;      
      }
    else if(t1==t2)
      {
       (*List).t[(*List).cur].element=(*List).t[(*List).cur].element+b.t[b.cur].element;
       if(b.CurNext()==EMPTY)return *this;
       t1=b.t[b.cur].j;
       if((*List).CurNext()==EMPTY)
        {
         do{
            (*List).AddAfter(b.t[b.cur]);
         }while(b.CurNext()!=EMPTY);
         break;
        }
       t2=(*List).t[(*List).cur].j; 
      }
    else
      {
       (*List).CurPrev();
       (*List).AddAfter(b.t[b.cur]);
       if(b.CurNext()==EMPTY)return *this;
       t1=b.t[b.cur].j;
       t2=(*List).t[(*List).cur].j;
      } 
   
 }while(1);
return *this;
}


  int  CListTmp::operator=(int M)
     {if(M!=0)
      {
         CPoint b(M,j);
         int tmp=(*list).SearchNumber(j);
         if(tmp==-3||tmp==-2)
            {
             (*list).AddAfter(b);
            } 
        else if(tmp==-1){throw -1;}
        else if(tmp==0)
            {
              (*list).AddBeginPrev(b);
            }
        else if(tmp==1)
            {
              (*list).t[(*list).cur].element=M;
            }
        else if(tmp==2) 
            {
              (*list).AddAfter(b);
            }
       return M;
      }      
      else
      {
       if( (*list).SearchNumber(j)==1)(*list).DeleteCur();
       return 0; 
      }
    }
   
    CListTmp::operator int()const
    {
      if((*list).SearchNumber(j)==1)return (*list).t[(*list).cur].element;
      return 0;
     }

    CListTmp::operator CPoint()const
    {
      if((*list).SearchNumber(j)==1)return (*list).t[(*list).cur];
      return CPoint(0,0);
     }


int SparseMatrix::ColumnOutPut(int j)
{
  if(j>=n||j<0)throw -1;
  for(int k=0;k<m;k++)
  {
    if(Matrix[k].SearchNumber(j)==1)std::cout<<Matrix[k].t[Matrix[k].cur].element<<std::endl;
    else std::cout<< 0 <<std::endl;
  }
  return 0;
}

int SparseMatrix::LineOutPut(int i)
  {
    if(i>=m||i<0)throw -1;
    if(Matrix[i].begin==EMPTY)
     {
      std::cout<<"{ ";
      for(int k=0;k<n;k++)std::cout<<0<<"  ";
      std::cout<<"}";
      return 0;        
     }
    Matrix[i].GoToBegin();
    int jtmp=0;
    std::cout<<"{ ";
    do{
       if(jtmp < Matrix[i].t[Matrix[i].cur].j)
       do{std::cout<<0<<"  ";jtmp++;}while(jtmp!=Matrix[i].t[Matrix[i].cur].j);
       std::cout<<Matrix[i].t[Matrix[i].cur].element<<"  ";jtmp++;
    }while(Matrix[i].CurNext()!=EMPTY);
    
    if(jtmp<n){do{std::cout<<0<<"  ";jtmp++;}while(jtmp!=n);}

    std::cout<<"}";

  return 0;
  }

int SparseMatrix::MatrixOutPut()
{
  for(int k=0;k<m;k++)
  {
    LineOutPut(k);std::cout<<std::endl;
  }
  return 0;
}