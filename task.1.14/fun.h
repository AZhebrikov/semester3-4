#pragma once

#define O(a) std::cout<<a<<std::endl;


class CPoint
{
 int x,y,prev,next;
public:
 CPoint(){x=y=next=prev=0;}
 CPoint(int x,int y){this->x=x;this->y=y;prev=next=0;}
 CPoint(const CPoint &b){x=b.x;y=b.y;prev=next=0;}

 CPoint & operator=(const CPoint & b){x=b.x;y=b.y;return *this;}
  
 friend class CList;
 friend class CListShell;
 friend std::ostream & operator<<(std::ostream & cout,const CPoint &b);
 friend double TanTwoCPoint(const CPoint & first,const CPoint & second);
 int operator==(const CPoint & b){ return (x==b.x)&&(y==b.y); }
};

/*
struct twoint
{
 int end;
 int flag;
 tvoint(){end=0;flag=0;}
 tvoint(int a){end=a;flag=0;}
 operator int(){return end;}
};
*/






#define EMPTY -1

class CList
{
 CPoint * t;
 int begin,cur,end,start,finish,Size=5;
public:
 CList(){SetZero();}
 CList(const CPoint & b){SetZero();AddAfter(b);}
 CList(const CList & b){SetZero();CopeOnly(b);}
 CList(const CPoint * b,int n){if(n<=0)throw -4;SetZero();for(int i=0;i<n;i++){AddAfter(b[i]);} }
 CList(CList && b){ t=b.t; begin=b.begin; cur=b.cur; end=b.end; start=b.start; finish=b.finish;b.SetZero(); }
 ~CList(){Clean();}

// CPoint * GetMassConvexHull();
// CPoint * GetMassAllPoints();
// CPoint * GetMassInternalPoints();

 void SetZero(){t=NULL;begin=cur=end=start=finish=EMPTY;}
 void Clean();
 int CopeOnly(const CList &b);
 
 	    class iterator
 	    {
    	 const CList *n;
    	 int Pointer;
      public:
    	 iterator(){Pointer=EMPTY;n=NULL;}
    	 iterator(const CList * n,int Pointer){this->n=n;this->Pointer=Pointer;}
    	 iterator(const iterator & b){n=b.n;Pointer=b.Pointer;}
   
   	   void operator++(){Pointer=n->t[Pointer].next;}
   	   void operator++(int){Pointer=n->t[Pointer].next;}
   	   int operator==(const iterator & b)const{return Pointer==b.Pointer;}
  	   int operator!=(const iterator & b)const{return Pointer!=b.Pointer;}
  	   const CPoint & operator*()const{return n->t[Pointer];}
  	   operator int()const{return Pointer;}
      };

 	    iterator it_begin()const{return iterator(this,begin);}
 	    iterator it_end()const{return iterator(this,EMPTY);}
 	    iterator it_end_()const{return iterator(this,end);}

 CList & operator=(const CList & b){CopeOnly(b);return *this;}
 CList & operator=(CList && b){if(t!=NULL){delete [] t;}t=b.t; begin=b.begin; cur=b.cur; end=b.end;
                                start=b.start; finish=b.finish;b.SetZero(); return *this;}
 CList & operator<<(const CPoint & b){GoToEnd();AddAfter(b);GoToEnd();return *this;}
 CList & operator>>(const CPoint & b){AddBeginPrev(b);GoToBegin();return *this;}
 int NumberPoints()const;
 int Begin()const{return begin;}
 int End()const{return end;}
 int ListEmpty()const{return t==NULL;}
 void GoToBegin(){cur=begin;}
 void GoToEnd(){cur=end;}

 int CurNext(){if(t==NULL)return -3;if(cur==EMPTY)return -2;if(t[cur].next==EMPTY)return EMPTY;return cur=t[cur].next;}
 int CurPrev(){if(t==NULL)return -3;if(cur==EMPTY)return -2;if(t[cur].prev==EMPTY)return EMPTY;return cur=t[cur].prev;}
 int GetCurPrev()const{if(t[cur].prev==EMPTY)return EMPTY;return t[cur].prev;}
 int GetCurNext()const{if(t[cur].next==EMPTY)return EMPTY;return t[cur].next;}
 int StartNext(); 
 int SearchCPoint(const CPoint & b);
 int SwapCurNext();
 int SwapCurPrev();


 int Delete();
 int DeleteCur();
 int new_CPoint();
 int AddAfter(const CPoint & b);
 int DeleteAfter();
 int AddBeginPrev(const CPoint & b);
 //int AddAfterMass(const CPoint * b,int n);
 int DeleteCPoint(const CPoint & b);
 int DeleteCopyCPoint();

 void SortX();
 void SortY();
 int AllSortXY();

 double TanCurNext()const{
                          if(t[cur].next==EMPTY)return 0;
                          if(t[cur].x==t[t[cur].next].x)throw -1;
                          return ((double)(t[t[cur].next].y-t[cur].y))/(t[t[cur].next].x-t[cur].x);
                         }
  

 int Chek(int mod=0)const;
 int massChek()const;
 int massError(); 
 friend class CListShell;
};











# define ALLOCATE_MEMORY_and_ALLOCATE_MEMORY           0
# define NOT_ALLOCATE_MEMORY_and_ALLOCATE_MEMORY       1
# define ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY       2
# define NOT_ALLOCATE_MEMORY_and_NOT_ALLOCATE_MEMORY   3
 
class CListShell
{
 CList ConvexHull;
 CList InnerSet;
public:
 CListShell(){}
 CListShell(CList & innerset,CList & convexhull,int modification=0);
 
 int ConvexHull_Move_InnerSet();
 int ShellBuiling();
 int ConvexHull_OneMove_InnerSet();
 int InnerSet_OneMove_ConvexHull();
 
 void ConvexHullChek(int mod = 0){ConvexHull.Chek(mod);}
 void InnerSetChek(int mod = 0){InnerSet.Chek(mod);}
 CList& operator[](int i){
                          if(i<0||i>1)throw -1;
                          if(i==0){return ConvexHull;}
                          if(i==1){return InnerSet;}
                          throw -2;
                         } 





 friend std::ostream & operator<<(std::ostream & cout,const CListShell &b);
 int DeleteCPointInnerSet(const CPoint & b);
 int DeleteCPointConvexHull(const CPoint & b);
 int DeleteCPointSet(const CPoint & b); 
 int InnerSetNumber()const;
 int ConvexHullNumber()const;
 int AddCPoint(const CPoint & b);
};










double TanTwoCPoint(const CPoint & first,const CPoint & second);
std::ostream & operator<<(std::ostream & cout,const CPoint &b);
std::ostream & operator<<(std::ostream & cout,const CList &b);
std::ostream & operator<<(std::ostream & cout,const CListShell &b);





