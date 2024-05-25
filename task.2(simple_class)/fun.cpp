#include <string.h>
#include <iostream>
#include "fun_CRat.h"
#include "fun_CRatVector.h"
CRatVector CRatVector::operator+(const CRatVector &b)const
{
 if(n!=b.n)throw -10;
 CRatVector r(b);
 for(int i=0;i<n;i++){r.vec[i]=r.vec[i]+vec[i];}
return r;
}

CRatVector CRatVector::operator-(const CRatVector &b)const
{
 if(n!=b.n)throw -11;
 CRatVector r(*this);
 for(int i=0;i<n;i++){r.vec[i]=r.vec[i]-vec[i];}
return r;
}

CRat CRatVector::operator*(const CRatVector &b)const
{
 if(n!=b.n)throw -12;
 CRat r;
 for(int i=0;i<n;i++)r=r+vec[i]*b.vec[i];
return r;
}

CRatVector CRatVector::operator*(int a)const
{
 CRatVector r(*this);
 for(int i=0;i<n;i++){r.vec[i]=r.vec[i]*a;}
return r;
}

CRatVector CRatVector::operator/(int a)const
{
 CRatVector r(*this);
 for(int i=0;i<n;i++){r.vec[i]=r.vec[i]/a;}
return r;
}

std::ostream & operator<<(std::ostream & cout,const CRatVector & b)
{
 if(b.Kol()==0)
  {
   cout<<"[-]";
   return cout;
  }
 else
  {
   cout<<"[";
   for(int i=0;i<b.Kol()-1;i++)
    {
     cout<<b.cor(i)<<",";
    }
    cout<<b.cor(b.Kol()-1)<<"]";
   return cout;
  }
}

int gcd (int a, int b)
{
	return b ? gcd (b, a % b) : a;
}

std::ostream & operator<<(std::ostream & cout,const CRat &b)
{
 cout<<"("<<b.num()<<"/"<<b.den()<<")";
 return cout;
}

 void CRatVector::Krtr()
 {
  for(int i =0;i<n;i++)vec[i].Krt();
 } 



