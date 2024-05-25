#include <iostream>
#include <math.h>
#include "fun.h"

#define O(a) std::cout<<a<<std::endl;
std::istream & operator>>(std::istream & cin,SPoint & b)
    {
    	int x,y;
    	cin>>x>>y;
    	if(cin.fail()){
    		      cin.clear();
    		      while(cin.get()!='\n'){};
    		      return cin;
    		           }
        if(b.Number==b.Maxmass)
        	        {std::cout<<"\n Произошло переполнение! Увеличение объема происходит вручную.\n";return cin;}
    	b.mass[b.Number].x=x;
    	b.mass[b.Number].y=y;
    	b.Number++;
    	return cin;
    }


int SPoint::Affiliation(const Point a,const Point b,const Point c)
    {if(Number<=1)return -1;
    	int A=a.x-b.x;
    	int B=b.y-a.y;
    	int C=a.y*b.x-a.x*b.y;
    	if(a.x<b.x && a.x<=c.x && c.x<= b.x && A*c.y+B*c.x+C==0)return 1;
    	if(a.x>b.x && a.x>=c.x && c.x>= b.x && A*c.y+B*c.x+C==0)return 1;
    	if(a.x==b.x && a.y<b.y && c.x==a.x && a.y<=c.y && c.y<=b.y)return 1;
    	if(a.x==b.x && a.y>b.y && c.x==a.x && a.y>=c.y && c.y>=b.y)return 1;
    return 0;
    }


int SPoint::Granic(const Point & c)
    {   if(Number<=1)return -1;
        iterator it=Begin();
        for(;(it++)!=0;it+=1)
           {
           	if(Affiliation(mass[*it],mass[it++],c)==1)return 1;
           }if(Affiliation(mass[*it],mass[it++],c)==1)return 1;
    return 0;
    }

int DET(int a1,int a2,int b1,int b2)
    {
        return (a1*b2 - a2*b1);
    }

int SPoint::ProvAffiliation(const Point & c)
	{
     if(Number==0)return -1;
     if(Number==1){
     	           if(mass[0].x==c.x && mass[0].y==c.y){return 1;}
     	           else{return 3;} 
     	          }
     bool K=false;
     iterator it1=Begin();
     for(it1+=1;*it1!=0;it1+=1)
       {
        if(  DET(mass[1].x-mass[0].x,mass[1].y-mass[0].y,mass[*it1].x-mass[0].x,mass[*it1].y-mass[0].y)!=0)K=true;        	
       }

     if(Granic(c)==1)return 1;
     if(K==false)return 3;

     it1=Begin();
     iterator it2=Begin();
     int PER;
     

 do{
    PER=0;
    it2=it1;
       do{   
             if(
                    (  
                        DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)==0
                        && DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                    )
               )
                {
                    iterator tmp(it2);

                    while(DET(mass[*tmp].x-c.x,mass[*tmp].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)==0){tmp=(tmp--);}   
                    if(
                       ( DET(mass[*tmp].x-c.x,mass[*tmp].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )*
                       ( DET(mass[*it1].x-c.x,mass[*it1].y-c.y,mass[(it2++)].x-c.x,mass[(it2++)].y-c.y) )>0
                      )PER+=1;

                }
             else if(
                        (   
                            DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                            && DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                        )
                     &&
                        (
                            ( DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )*
                            ( DET(mass[*it1].x-c.x,mass[*it1].y-c.y,mass[(it2++)].x-c.x,mass[(it2++)].y-c.y) )>0
                        )
                    &&
                        (
                            (
                                ( DET(c.x-mass[*it2].x,c.y-mass[*it2].y,mass[(it2++)].x-mass[*it2].x,mass[(it2++)].y-mass[*it2].y) )*
                                ( DET(mass[(it2++)].x-mass[*it2].x,mass[(it2++)].y-mass[*it2].y,mass[*it1].x-mass[*it2].x,mass[*it1].y-mass[*it2].y) )>0                   
                            )
                        ||
                            (
                                abs(DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it2].x-c.x,mass[*it2].y-c.y))>
                                abs(DET(mass[(it2++)].x-mass[*it1].x,mass[(it2++)].y-mass[*it1].y,mass[*it2].x-mass[*it1].x,mass[*it2].y-mass[*it1].y))
                            )
                        )
                   )
                   {
                        PER+=1;
                   }
           }while( (it2+=1)!=*it1);
        if(PER%2==0){K=false;break;}    

        }while( (it1+=1)!=0 );


	 if(K==true)return 2;
	 else return 3;
	}


std::ostream & operator<<(std::ostream & cout,Point & b)
{
    cout<<"{"<<b.x<<", "<<b.y<<"}";
return cout;
}

std::ostream & operator<<(std::ostream & cout,SPoint & b)
{
    if(b.Number==0){cout<<"Набор точек пуст."<<std::endl;return cout;}
    for(int i=0;i<b.Number;i++)cout<<"["<<i<<"]"<<b.mass[i]<<std::endl;
return cout;
}


int SPoint::Dobavit(int a,int b)
    {
        if(Number==Maxmass)
                    std::cout<<"\n Произошло переполнение! Увеличение объема происходит вручную.\n";
        mass[Number].x=a;
        mass[Number].y=b;
        Number++;
        return 0;
    }

int SPoint::UvelichOb()
    {
        Maxmass*=2;
        Point * tmp = new Point [Maxmass];
        for(int i=0;i<Number;i++)tmp[i]=mass[i];
        delete [] mass;
        mass = tmp;
        return 0;
    }

int SPoint::DeleteAll()
    {
        Number=0;
        return 0;
    }

int SPoint::DobavinK(int k,const Point & b)
    {
        if(k<0)k=0;
        if(Number==Maxmass)UvelichOb();
        if(Number<=k)
        {
            mass[Number]=b;
            Number++;     
        }
        else
        {
           int i;
           for(i=Number-1;i!=k-1;i--)
           {
            mass[i+1]=mass[i];
           }mass[k]=b;Number++; 
        }
     return 0;
    }



//**********************
/*do{PER=0;

        if(
                    ( DET(mass[it1--].x-c.x,mass[it1--].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )*
                    ( DET(mass[it1++].x-c.x,mass[it1++].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )<=0
                ){PER=1;}

        for(it2=(it1++);it2!=it1;it2+=1)
            {
             if(
                (  DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)==0
                   && DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                )
                &&( (it2--)!=(*it1) )&&
                (
                    ( DET(mass[it2--].x-c.x,mass[it2--].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )*
                    ( DET(mass[*it1].x-c.x,mass[*it1].y-c.y,mass[(it2++)].x-c.x,mass[(it2++)].y-c.y) )>0
                )
                &&
                (
                  (
                    ( DET(c.x-mass[it2--].x,c.y-mass[it2--].y,mass[(it2++)].x-mass[it2--].x,mass[(it2++)].y-mass[it2--].y) )*
                    ( DET(mass[(it2++)].x-mass[it2--].x,mass[(it2++)].y-mass[it2--].y,
                                                     mass[*it1].x-mass[it2--].x,mass[*it1].y-mass[it2--].y) )>0                     
                  )
                  ||
                  (
                    abs(DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[it2--].x-c.x,mass[it2--].y-c.y))>
                    abs(DET(mass[(it2++)].x-mass[*it1].x,mass[(it2++)].y-mass[*it1].y,mass[it2--].x-mass[*it1].x,mass[it2--].y-mass[*it1].y))
                  )
                )
            ){O("1");PER+=1;}
             else if(DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                && DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)==0){
                                                    O("2  "<<DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)
                                                        <<"  "<<DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y));}
             else if(
                     (  DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                        && DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)!=0
                     )
                     &&
                    (
                        ( DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )*
                        ( DET(mass[*it1].x-c.x,mass[*it1].y-c.y,mass[(it2++)].x-c.x,mass[(it2++)].y-c.y) )>0
                    )
                    &&
                    (
                        (
                            ( DET(c.x-mass[*it2].x,c.y-mass[*it2].y,mass[(it2++)].x-mass[*it2].x,mass[(it2++)].y-mass[*it2].y) )*
                            ( DET(mass[(it2++)].x-mass[*it2].x,mass[(it2++)].y-mass[*it2].y,
                                                     mass[*it1].x-mass[*it2].x,mass[*it1].y-mass[*it2].y) )>0                   
                        )
                        ||
                        (
                            abs(DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it2].x-c.x,mass[*it2].y-c.y))>
                            abs(DET(mass[(it2++)].x-mass[*it1].x,mass[(it2++)].y-mass[*it1].y,mass[*it2].x-mass[*it1].x,mass[*it2].y-mass[*it1].y))
                        )
                    )
                   ){O("3  "<<( DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y) )*
                        ( DET(mass[*it1].x-c.x,mass[*it1].y-c.y,mass[(it2++)].x-c.x,mass[(it2++)].y-c.y) )
                     );
                        PER+=1;}
             else if( ((it2++)!=(*it1) )&&
                       DET(mass[*it2].x-c.x,mass[*it2].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)==0
                       && DET(mass[(it2++)].x-c.x,mass[(it2++)].y-c.y,mass[*it1].x-c.x,mass[*it1].y-c.y)==0
                     )
               {O("4");PER+=2;}
           O("---*it2= "<<*it2<<"  *it2++= "<<it2++<<"  PER= "<<PER);
           }
        O("*it1= "<<*it1<<"  PER= "<<PER);
        if(PER%2==0){K=false;break;}    
        }while( (it1+=1)!=0 );*/