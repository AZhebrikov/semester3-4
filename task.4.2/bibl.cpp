#include <cstddef>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "bibl.h"

//---------------------------------------CComplexNumber

void CComplexNumber::Show()
  {
    std::cout<<"("<<Re<<","<<Im<<")";
  }

void CComplexNumber::Show(std::ofstream& f)
  {
    f<<"("<<Re<<","<<Im<<")";
  }

//---------------------------------------CComplexVector

void CComplexVector::emplase_new()
  {
    if(MAX==0)
    {
      V=reinterpret_cast<CComplexNumber*>(new char[(MAX=10)*sizeof(CComplexNumber)]);
      for(size_t i=0;i<MAX;i++)new(V+i) CComplexNumber();
    }
    else
    {
      CComplexNumber* V_=reinterpret_cast<CComplexNumber*>(new char[(MAX*2)*sizeof(CComplexNumber)]);
      for(size_t i=0;i<MAX;i++)new(V_+i) CComplexNumber(V[i]);
      for(size_t i=MAX;i<MAX*2;i++)new (V_+i) CComplexNumber();
    MAX*=2;
      delete [] reinterpret_cast<char*>(V);V=V_;
    }
  }

void CComplexVector::Clean()
  {
    delete [] reinterpret_cast<char*>(V);SetZero();
  }

CComplexVector& CComplexVector::CopyOnly(const CComplexVector & b)
  {
    if(this == &b){}
    else if(b.ReturN()== 0 )
      {
        if(MAX==0) emplase_new();
        else for(size_t i=0;i<N;i++)V[i].SetZero();
      }
    else if( MAX<b.ReturN() )
      {
        Clean();
            if( b.ReturN()>10 )MAX=size_t(int(b.ReturN())*1.4);
            else MAX=10;
          V=reinterpret_cast<CComplexNumber*>(new char[MAX*sizeof(CComplexNumber)]);
          for(size_t i=0;i<b.ReturN();i++)new(V+i) CComplexNumber(b.ReturV()[i]);
          for(size_t i=b.ReturN();i<MAX;i++)new(V+i) CComplexNumber();
      }
    else
      {
        for(size_t i=0;i<b.ReturN();i++)V[i]=b.ReturV()[i];
        for(size_t i=b.ReturN();i<MAX;i++)V[i].SetZero();
      }
    N=b.ReturN();
  return *this;
  }

CComplexVector& CComplexVector::move_CopyOnly(CComplexVector &b)
  {
    V=b.ReturV();
    N=b.ReturN();
    MAX=b.ReturMAX();
    b.SetZero();
  return *this;
  }

CComplexVector::CComplexVector(const CComplexNumber & a)
  {
    SetZero();
    emplase_new();
    N++;
    V[0]=a;
  }

CComplexVector::CComplexVector(const CComplexVector & b)
  {
    SetZero();
    CopyOnly(b);
  }

CComplexVector::CComplexVector(CComplexVector && b)
  {
    move_CopyOnly(b);
  }

CComplexVector& CComplexVector::operator=(const CComplexVector& b)
  {
    return CopyOnly(b);
  }

CComplexVector& CComplexVector::operator=(const CComplexNumber& b)
  {
    if(MAX==0){emplase_new();V[0]=b;N++;}
    else{for(size_t i=0;i<N;i++)V[i].SetZero();V[0]=b;N=1;}
  return *this;
  }

CComplexVector& CComplexVector::operator=(CComplexVector && b)
  {
    return move_CopyOnly(b);
  }

/**/
CComplexVector::CComplexVector(size_t N,size_t MAX,CComplexNumber* V)
  {
    this->V=new CComplexNumber [(this->MAX=MAX)];
    size_t i;this->N=N;
    for(i=0;i<N;i++)this->V[i]=V[i];
    for(i=N;i<MAX;i++)this->V[i]=CComplexNumber();
  }

CComplexVector CComplexVector::operator+(const CComplexVector& b)
  {
    size_t MAX_=(MAX>b.ReturMAX())?MAX:(b.ReturMAX());
      CComplexNumber* V_=reinterpret_cast<CComplexNumber*>(new char[sizeof(CComplexNumber)*MAX_]);
        size_t N_=(N>b.ReturN())?N:(b.ReturN());
        for(size_t i=N_;i<MAX_;i++)V_[i].SetZero();
        for(size_t i=0;i<N_;i++)V_[i]=V[i]+b.ReturV()[i];
          CComplexVector tmp(N_,MAX_,V_);
  return tmp;
  }

CComplexVector CComplexVector::operator-(const CComplexVector& b)
  {
    size_t MAX_=(MAX>b.ReturMAX())?MAX:(b.ReturMAX());
      CComplexNumber* V_=reinterpret_cast<CComplexNumber*>(new char[sizeof(CComplexNumber)*MAX_]);
        size_t N_=(N>b.ReturN())?N:(b.ReturN());
        for(size_t i=N_;i<MAX_;i++)V_[i].SetZero();
        for(size_t i=0;i<N_;i++)V_[i]=V[i]-b.ReturV()[i];
          CComplexVector tmp(N_,MAX_,V_);
  return tmp;
  }

CComplexNumber_bas CComplexVector::operator[](int i)
  {
    if(i>int(N) || i<0)throw "ERROR!!!Выход за границу массива.";
    return CComplexNumber_bas (V[i],i,this);
  }

CComplexNumber CComplexVector::operator*(const CComplexVector& b)
  {
    if(N!=b.ReturN())throw "ERROR!!!Вектора имеют разную длинну.";
      CComplexNumber tmp;
      for(size_t i=0;i<N;i++){tmp+=(V[i]*b.V[i]);}
  return tmp;
  }

CComplexVector  CComplexVector::operator~()
  {
    CComplexVector tmp;
    tmp.ReturMAX_()=MAX;
    tmp.ReturV_() = reinterpret_cast<CComplexNumber*>(new char[sizeof(CComplexNumber)*MAX]);
    tmp.ReturN_()=N;
    for(size_t i=0;i<MAX;i++){(tmp.ReturV())[i]=(~V[i]);}
  return tmp;
  }

int CComplexVector::Add_push_back(double Re,double Im)
  {
    if(N>=MAX)emplase_new();
    V[N]=CComplexNumber(Re,Im);
    N++;
  return 0;
  }

int CComplexVector::Add_push_back(CComplexNumber& b)
  {
    if(N>=MAX)emplase_new();
    V[N]=b;
    N++;
  return 0;
  }

int CComplexVector::Del_pop_back()
  {
    if(N<=0)return -1;
    N--;
  return 0;
  }

int CComplexVector::Input(std::vector<CComplexVector*>& Vec,
                          std::vector<FabricCComplexVector* >& Fabric,
                          ListName& vecname,
                          const char* filename){

      std::ifstream f(filename);
      if(!f)return -2;
      std::string str;
      while(getline(f,str))
          {
            std::stringstream ss(str);
            int a=-1;ss>>a;
              char Filename[256];Filename[0]='\0';ss>>Filename;
              size_t i;
              i=vecname.AddFile(Filename);
              CComplexVector* W=Fabric[a-1]->Create(0,0,NULL,i,&(vecname.vecfname));
                double Re,Im;
                while(ss>>Re>>Im)
                {
                  W->Add_push_back(Re,Im);
                }
              Vec.push_back(W);
          }
       return 0;
       }

void CComplexVector::Show()
  {
    std::cout<<"{";
    for(size_t i=0;i<N;i++)V[i].Show();
    std::cout<<"}";
  }

void CComplexVector::Output()
  {
    std::cout<<"{";
    for(size_t i=0;i<N;i++)V[i].Show();
    std::cout<<"}";
  }
//------------------------------CComplexNumber_bas
CComplexNumber_bas::CComplexNumber_bas(const CComplexNumber& b,size_t i,CComplexVector* V_):CComplexNumber(b)
  {
    this->i=i;this->V_=V_;
  }

CComplexNumber_bas& CComplexNumber_bas::operator=(const CComplexNumber& b)
  {
    *( ((*V_).ReturV()) +i )=b;
    return *this;
  }

//----------------------------------------------ListName
size_t ListName::AddFile(const char *filename)
  {
    size_t i;
    for(i=0;i<vecfname.size();i++)if(vecfname[i]==filename)return i;
    vecfname.push_back(filename);
  return i;
  }

//----------------------------------------------Vec_
Vec_::Vec_(std::vector<FabricCComplexVector* >& Fabric,ListName& vecname,const char* filename)
  {
    CComplexVector::Input(Vec,Fabric,vecname,filename);
  }

//----------------------------------------------global function

std::ostream& operator<<(std::ostream& cout,const CComplexNumber& b)
  {
    cout<<"("<<b.Re<<","<<b.Im<<")";
  return cout;
  }

std::ostream& operator<<(std::ostream& cout,const CComplexVector& b)
  {
    cout<<"{";
    for(size_t i=0;i<b.ReturN();i++)cout<<b.ReturV()[i];
    cout<<"}";
  return cout;
  }
