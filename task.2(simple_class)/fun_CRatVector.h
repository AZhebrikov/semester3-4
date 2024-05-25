#pragma once

//#include "fun_CRat.h"

class CRatVector
{
 int n;CRat * vec;
 void SetZero(){n=0;vec=NULL;}
 void Clean(){delete [] vec;SetZero(); }
 void CopyOnly(const CRatVector & b){if(b.n>0){vec = new CRat [n=b.n];for(int i=0;i<n;i++)vec[i]=b.vec[i];}}
 void CopyOnly(int a,const CRat * b){if(a>0){vec = new CRat [n=a];for(int i=0;i<n;i++)vec[i]=b[i];}}
public:
 CRatVector(){SetZero();}
 CRatVector(int a){if(a<=0)throw -16;vec=new CRat [n=a];}
 CRatVector(const CRatVector & b){CopyOnly(b);}
 CRatVector(int a,const CRat *b){CopyOnly(a,b);}
 CRatVector( CRatVector && b){n=b.n;vec=b.vec;SetZero();}
 ~CRatVector(){Clean();SetZero();}

 CRatVector & operator=(const CRatVector &b){if(&b!=this){Clean();CopyOnly(b);}return (*this);}
 CRatVector & operator=(CRatVector &&b){if(&b!=this){Clean();n=b.n;vec=b.vec;b.SetZero();}return(*this);}

 CRatVector operator+(const CRatVector &b)const;
 CRatVector operator-(const CRatVector &b)const;
 CRat operator*(const CRatVector &b)const;
 CRatVector operator*(int a)const;
 CRatVector operator/(int a)const;
 CRat & operator[](int i){if(i<0||i>=n)throw -17;return vec[i];}
 CRat cor(int i)const{if(i<0||i>=n)throw -14;return vec[i];}
 void Cor(int i,const CRat & a){if(i<0||i>=n)throw -15;vec[i]=a;}
 int Kol()const{return n;}
 void Krtr();
};

std::ostream & operator<<(std::ostream & cout,const CRatVector & b);
