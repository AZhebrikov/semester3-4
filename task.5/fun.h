#pragma once

struct Point
{
	int x;
	int y;

	Point(){x=0;y=0;}
	Point(int x,int y){this->x=x;this->y=y;}

};

class SPoint
{
	Point * mass;
    int Number;
    int Maxmass;
public:
	SPoint(int a){Maxmass=a;mass = new Point [Maxmass];Number=0;}
	~SPoint(){delete [] mass;Number=0;Maxmass=0;}

	class iterator
	  {
       	  int i;
       	  int Number;
   	   public:
   	   	  iterator(int i,int Number){this->i=i;this->Number=Number;}
  	      iterator(const iterator & b){i=b.i;Number=b.Number;}

  	      int operator++(){return( (i+1)%Number );}
  	      int operator++(int){return( (i+1)%Number );}
  	      int operator+=(int a){return( i=( (i+a)%Number) );}
  	      int operator--(){ if(i==0){return Number-1;}else{return i-1;} }
  	      int operator--(int){ if(i==0){return Number-1;}else{return i-1;} }
  	      int operator-=(int a){ if(i<a){return i=Number-1-(a-1);}else{return i-=a;} }
	  	  int operator*(){return i;}
	  	  int operator!=(const iterator & b){return i!=b.i;}
	  	  iterator & operator=(const iterator & b){i=b.i;Number=b.Number;return *this;}
	  	  iterator & operator=(int a){i=a;return *this;}
	  
	  	  friend class SPoint;
  	      
	  };
	  iterator Begin(){return iterator(0,Number);}

      int Affiliation(const Point a,const Point b,const Point c);
      int Granic(const Point & c);
      int ProvAffiliation(const Point & c);
      int Dobavit(int a,int b);
      Point & operator[](int i){return mass[i];}
      int operator++(int){return ++Number;}
      int UvelichOb();
      int DeleteAll();
      int DobavinK(int k,const Point & b);
	friend class iterator;
    friend std::istream & operator>>(std::istream & cin,SPoint & b);
    friend std::ostream & operator<<(std::ostream & cout,SPoint & b);
};

std::istream & operator>>(std::istream & cin,SPoint & b);
std::ostream & operator<<(std::ostream & cout,Point & b);
std::ostream & operator<<(std::ostream & cout,SPoint & b);
int DET(int a1,int a2,int b1,int b2);
