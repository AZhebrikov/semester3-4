#pragma once

int gcd (int a, int b);


class CRat
{
 int m;
 unsigned int n;   // m/n
public:

 CRat(int m=0,int n=1){if(n==0)throw -1;if(n>0){this->m=m;this->n=(unsigned int)n;}
                                        else{this->m=(-1)*m;this->n=(unsigned int)((-1)*n);}
                                           }
 CRat(const int * b){if(b[1]==0)throw -1;if(b[1]>0){m=b[0];n=(unsigned int)b[1];}
                                         else{m=b[0]*(-1);n=(unsigned int)((-1)*b[1]);}
                    }
 CRat(const CRat & b){m=b.m;n=b.n;}


 CRat & operator=(const CRat & b){m=b.m;n=b.n;return *this;}
 CRat & operator=(int a){m=a;n=(unsigned int)1;return *this;}
 CRat & operator=(const int * b){if(b[1]==0)throw -2;if(b[1]>0){m=b[0];n=(unsigned int)b[1];return *this;}
                                                     else{m=(-1)*b[0];n=(unsigned int)((-1)*b[1]);return *this;}
                                }


 CRat operator+(const CRat & b)const{CRat r(m*((int)b.n)+((int)n)*b.m,n*b.n);return r;}
 CRat operator+(int a)const{CRat r(m+((int)n)*a,n);return r;}
/* CRat operator+(const int * b)const{if(b[1]==0)throw -3;
                                        if(b[1]>0){CRat r(m*b[1]+((int)n)*b[0],n*(unsigned int)b[1]);return r;}
                                        else{CRat r;r.m=(-1)*(m*b[1]+((int)n)*b[0]);r.n=n*(unsigned int)(b[1]*(-1));return r;}
                                   }*/


 CRat operator-(const CRat & b)const{CRat r(m*((int)b.n)-((int)n)*b.m,n*b.n);return r;}
 CRat operator-(int a)const{CRat r(m-((int)n)*a,n);return r;}
/* CRat operator-(const int * b)const{if(b[1]==0)throw -3;
                                        if(b[1]>0){CRat r(m*b[1]-((int)n)*b[0],n*(unsigned int)b[1]);return r;}
                                        else{CRat r;r.m=(-1)*(m*b[1]-((int)n)*b[0]);r.n=n*(unsigned int)(b[1]*(-1));return r;}
                                   }*/


 CRat operator*(const CRat & b)const{CRat r(m*b.m,n*b.n);return r;}
 CRat operator*(int a)const{CRat r(m*a,n);return r;}
 CRat operator*(const int * b)const{if(b[1]==0)throw -3;
                                                if(b[1]>0){CRat r(m*b[0],n*(unsigned int)b[1]);return r;}
                                                else{CRat r;r.m=(-1)*m*b[0];r.n=n*(unsigned int)((-1)*b[1]);return r;}
                                   }



 CRat operator/(const CRat & b)const{if(b.m==0)throw -3;
                                            if(b.m>0){CRat r(m*((int)b.n),n*(unsigned int)b.m);return r;}
                                            else{CRat r;r.m=(-1)*m*((int)b.n);r.n=n*(unsigned int)((-1)*b.m);return r;}
                                   }
 CRat operator/(int a)const{if(a==0)throw -3;
                                        if(a<0){CRat r((-1)*m,n*(unsigned int)((-1)*a));return r;}
                                        else{CRat r(m,n*(unsigned int)a);return r;}
                           }
 CRat operator/(const int * b)const{CRat B(b);return *this/B;}

 void operator()(int a,int b){if(b==0)throw -3;if(b>0){m=a;n=(unsigned int)b;}
                                               else{m=(-1)*a;n=(unsigned int)((-1)*b);}
                             }
 int num()const{return m;}
 void Num(int a){m=a;}
 unsigned int den()const{return n;}
 void Den(int a){if(a==0)throw -5;if(a>0){n=(unsigned int)a;}
                                  else{m=m*(-1);n=(unsigned int)((-1)*a);}
                }
 bool operator>(const CRat & b)const{if(  (m*((int)b.n)-((int)n)*b.m) >0  )return true;
                                     else return false;
                                    }

 bool operator<(const CRat & b)const{if(  (m*((int)b.n)-((int)n)*b.m) <0  )return true;
                                     else return false;
                                    }

 void Krt(){int a;
                   if(m>=0){a=gcd(m,(int)n);m=m/a;n=n/(unsigned int)a;}
                   else{a=gcd((-1)*m,(int)n);m=m/a;n=n/(unsigned int)a;}
               }


};

std::ostream & operator<<(std::ostream & cout,const CRat &b);
