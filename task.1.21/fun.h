#pragma once

#define O(a) std::cout<<a<<std::endl;

 class CList;
 class SparseMatrix;
 class CListTmp;
 class CListTmp1;
 class CPoint;

class CListTmp
{
  int j; 
  CList * list;
 public:
  CListTmp(){throw -1;}
  CListTmp(int j,CList * list){this->j=j;this->list=list;}
  int  operator=(int M);
     
  operator int()const;
  operator CPoint()const;

 friend class CList;
 friend class SparseMatrix;
 friend class CListTmp1;

};


class CListTmp1
{
 CList * List;
 int n;
public:
 CListTmp1(){throw -1;}
 CListTmp1(int n,CList * List){this->List=List;this->n=n;} 
 CListTmp  operator[](int j){if(j>=n||j<0)throw -1;return CListTmp(j,List);} 
 CListTmp1  operator*=(int M);
 CList   operator*(int M)const;
 operator CList &(){return *List;}
CListTmp1  operator+=(CList & b);

 friend class CList;
 friend class SparseMatrix;
 friend class CListTmp;

};



class CPoint
{
 int element;
 int j;
 int prev,next;
public:
 CPoint(){element=j=next=prev=0;}
 CPoint(int element){this->element=element;j=prev=next=0;}
 CPoint(int element,int j){this->element=element;this->j=j;prev=next=0;}
 CPoint(const CPoint &b){element=b.element;j=b.j;prev=next=0;}

 CPoint & operator=(const CPoint & b){element=b.element;j=b.j;return *this;}
 operator int(){return element;}
 friend class CList;
 friend class SparseMatrix;
 friend class CListTmp;
 friend class CListTmp1;

 friend std::ostream & operator<<(std::ostream & cout,const CPoint &b);
 int operator==(const CPoint & b){ return element==b.element; }
};




#define EMPTY -1

class CList
{ 
 CPoint * t;
 int begin,cur,end,start,finish,Size=5;
public:
 CList(){SetZero();}
 CList(const CPoint & b){SetZero();AddAfter(b);}
 CList(const CList & b){SetZero();CopeOnly(b);}
 CList(CList && b){ t=b.t; begin=b.begin; cur=b.cur; end=b.end; start=b.start; finish=b.finish;b.SetZero(); }
 ~CList(){Clean();}

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

 int SearchNumber(int je);
 int SwapCurNext();
 int SwapCurPrev();

 int Delete();
 int DeleteCur();
 int new_CPoint();
 int AddAfter(const CPoint & b);
 int DeleteAfter();
 int AddBeginPrev(const CPoint & b);

 int Chek(int mod=0)const;
 int massChek()const;
 int massError(); 


friend class SparseMatrix;
friend class CListTmp;
friend class CListTmp1;
};


class SparseMatrix
{
 int m;
 int n;
 CList * Matrix;

 void CopeOnly(const SparseMatrix &b){Generate(b.m,b.n);for(int k=0;k<m;k++)Matrix[k]=b.Matrix[k];}
 void Clean(){delete [] Matrix;Matrix=NULL;m=n=0;}
 void SetZero(){m=n=0;Matrix=NULL;}

 void Generate(int m,int n){if(m<=0||n<=0)throw -1;this->m=m;this->n=n;Matrix = new CList [m];}

public:
 SparseMatrix(){SetZero();}
 SparseMatrix(int m,int n){Generate(m,n);}
 SparseMatrix(int i,int j,int a){if(i<=0||j<=0)throw -1;Generate(i+1,j+1); Matrix[i].AddAfter(CPoint(a,j));}
 SparseMatrix(const SparseMatrix &b){O("=&");CopeOnly(b);}
 SparseMatrix(SparseMatrix && b){O("=&&");n=b.n;m=b.m;Matrix=b.Matrix;b.SetZero();}
 ~SparseMatrix(){O("~");Clean();}
 
 int SwapLine(int i,int j);

 int LineOutPut(int i);
 int ColumnOutPut(int j);
 int MatrixOutPut();

 int AddElement(int i,const CPoint & b);
 CListTmp1  operator[](int i){if(i>=m||i<0)throw -1;return CListTmp1(n,Matrix+i);}

friend std::ostream & operator<<(std::ostream & cout,SparseMatrix &b);

};




std::ostream & operator<<(std::ostream & cout,const CPoint &b);
std::ostream & operator<<(std::ostream & cout,const CList &b);
std::ostream & operator<<(std::ostream & cout,SparseMatrix &b);





