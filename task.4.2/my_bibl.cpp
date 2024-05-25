#include <cstddef>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "bibl.h"
#include "my_bibl.h"
//---------------------------CComplexVector1
CComplexVector1::CComplexVector1(const CComplexNumber & a,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    SetZero();
    emplase_new();
    ReturN_()++;
    ReturV()[0]=a;
  }

CComplexVector1::CComplexVector1(const CComplexVector & b,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    SetZero();
    CopyOnly(b);
  }

CComplexVector1::CComplexVector1(CComplexVector && b,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    move_CopyOnly(b);
  }

/**/
CComplexVector1::CComplexVector1(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    ReturV_()=new CComplexNumber [(ReturMAX_()=MAX)];
    ReturN_()=N;size_t j;
    for(j=0;j<N;j++)ReturV_()[j]=V[j];
    for(j=N;j<MAX;j++)ReturV_()[j]=CComplexNumber();
  }

CComplexVector1::CComplexVector1(const CComplexVector1 & b):CComplexVector(b){i=b.i;fname=b.fname;}
CComplexVector1::CComplexVector1(CComplexVector1 && b):CComplexVector(reinterpret_cast<CComplexVector &&>(reinterpret_cast<CComplexVector&>(b))){i=b.i;fname=b.fname;}
CComplexVector1::CComplexVector1(const CComplexVector2 & b):CComplexVector(b){i=b.i;fname=b.fname;}
CComplexVector1::CComplexVector1(CComplexVector2 && b):CComplexVector(reinterpret_cast<CComplexVector &&>(reinterpret_cast<CComplexVector&>(b))){i=b.i;fname=b.fname;}

void CComplexVector1::Show()
  {
    std::cout<<"File: "<<(*fname)[i]<<"  "<<"[";
    for(size_t i=0;i<ReturN();i++)ReturV()[i].Show();
    std::cout<<"]";
  }

  void CComplexVector1::Output()
    {
      std::ofstream f;
      f.open((*fname)[i],std::ios::app);
      if(!f.is_open())throw "ERROR!!! Ошибка вывода CComplexVector1;";
      f<<1<<" "<<(*fname)[i]<<" ";
      for(size_t i=0;i<ReturN();i++){ReturV()[i].Show(f);f<<" ";}
      f<<std::endl;
    }
//-----------------------------------CComplexVector2

CComplexVector2::CComplexVector2(const CComplexNumber & a,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    SetZero();
    emplase_new();
    ReturN_()++;
    ReturV()[0]=a;
  }

CComplexVector2::CComplexVector2(const CComplexVector & b,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    SetZero();
    CopyOnly(b);
  }

CComplexVector2::CComplexVector2(CComplexVector && b,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    move_CopyOnly(b);
  }


/**/
CComplexVector2::CComplexVector2(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    ReturV_()=new CComplexNumber [(ReturMAX_()=MAX)];
    ReturN_()=N;size_t j;
    for(j=0;j<N;j++)ReturV_()[j]=V[j];
    for(j=N;j<MAX;j++)ReturV_()[j]=CComplexNumber();
  }

CComplexVector2::CComplexVector2(const CComplexVector1 & b):CComplexVector(b){i=b.i;fname=b.fname;}
CComplexVector2::CComplexVector2(CComplexVector1 && b):CComplexVector(reinterpret_cast<CComplexVector &&>(reinterpret_cast<CComplexVector&>(b))){i=b.i;fname=b.fname;}
CComplexVector2::CComplexVector2(const CComplexVector2 & b):CComplexVector(b){i=b.i;fname=b.fname;}
CComplexVector2::CComplexVector2(CComplexVector2 && b):CComplexVector(reinterpret_cast<CComplexVector &&>(reinterpret_cast<CComplexVector&>(b))){i=b.i;fname=b.fname;}

void CComplexVector2::Show()
  {
    std::cout<<"File: "<<(*fname)[i]<<"  "<<"<";
    for(size_t i=0;i<ReturN();i++)ReturV()[i].Show();
    std::cout<<">";
  }

void CComplexVector2::Output()
  {
    std::ofstream f;
    f.open((*fname)[i],std::ios::app);
    if(!f.is_open())throw "ERROR!!! Ошибка вывода CComplexVector2;";
    f<<2<<" "<<(*fname)[i]<<" ";
    for(size_t i=0;i<ReturN();i++){ReturV()[i].Show(f);f<<" ";}
    f<<std::endl;
  }

//----------------------------------------------FabricCComplexVector1

CComplexVector* FabricCComplexVector1::Create(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname)
  {
    return new CComplexVector1(N,MAX,V,i,fname);
  }
//----------------------------------------------FabricCComplexVector2
CComplexVector* FabricCComplexVector2::Create(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname)
  {
    return new CComplexVector2(N,MAX,V,i,fname);
  }
