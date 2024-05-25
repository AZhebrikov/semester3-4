#include <cstddef>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <ctime>
#include "omp.h"


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

CComplexVector1::CComplexVector1(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    ReturN_()=N;
    ReturMAX_()=MAX;
    ReturV_()=V;
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

void CComplexVector1::Show_()
  {
    std::cout<<"File: "<<(*fname)[i]<<"  "<<"[";
    for(size_t i=0;i<ReturN();i++)ReturV()[i].Show();
    std::cout<<"]  "
       <<func1()<<"  "
       <<func2()<<"  "
       <<func3()<<"  "
       <<func4()<<"  "
       <<func5()<<"  "
       <<func6()<<"  "
       <<func7()<<"  "
       <<func8()<<"  ";
  }

void CComplexVector1::Output_file(const char* filename)
{
      time_t t1,t2;time(&t1);time(&t2);
      while((int)(t2-t1)<1)time(&t2);
  std::ofstream f;
  f.open(filename,std::ios::app);
  if(!f.is_open())throw "ERROR!!! Ошибка вывода CComplexVector1;";
  f<<1<<" "<<(*fname)[i]<<" ";
  for(size_t i=0;i<ReturN();i++){ReturV()[i].Show(f);f<<" ";}
    f<<func1()<<"  "
     <<func2()<<"  "
     <<func3()<<"  "
     <<func4()<<"  "
     <<func5()<<"  "
     <<func6()<<"  "
     <<func7()<<"  "
     <<func8()<<"  ";
  f<<std::endl;
}

void CComplexVector1::Output_()
    {
            time_t t1,t2;time(&t1);time(&t2);
            while((int)(t2-t1)<1)time(&t2);
      std::ofstream f;
      f.open((*fname)[i],std::ios::app);
      if(!f.is_open())throw "ERROR!!! Ошибка вывода CComplexVector1;";
      f<<1<<" "<<(*fname)[i]<<" ";
      for(size_t i=0;i<ReturN();i++){ReturV()[i].Show(f);f<<" ";}
      f<<func1()<<"  "
       <<func2()<<"  "
       <<func3()<<"  "
       <<func4()<<"  "
       <<func5()<<"  "
       <<func6()<<"  "
       <<func7()<<"  "
       <<func8()<<"  ";
       f<<std::endl;
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

double CComplexVector1::func1()const//сумма первых координат
    {
      double SumX=0;
      for(size_t i=0;i<ReturN();i++)SumX+=ReturV()[i].Re;
    return SumX;
    }

double CComplexVector1::func2()const//сумма вторых координат
    {
      double SumY=0;
      for(size_t i=0;i<ReturN();i++)SumY+=ReturV()[i].Im;
    return SumY;
    }

double CComplexVector1::func3()const//попарная сумма координат
    {
      double Sum=0;
      for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Re+ReturV()[i].Im);
    return Sum;
    }

double CComplexVector1::func4()const//сумма разностей первой и второй координаты
    {
      double Sum=0;
      for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Re-ReturV()[i].Im);
    return Sum;
    }
double CComplexVector1::func5()const//сумма разностей второй и первой
    {
      double Sum=0;
      for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Im-ReturV()[i].Re);
    return Sum;
    }
double CComplexVector1::func6()const//сумма квадратов первых координат
    {
      double Sum=0;
      for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Re*ReturV()[i].Re);
    return Sum;
    }

double CComplexVector1::func7()const//сумма квадратов вторых координат
    {
      double Sum=0;
      for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Im*ReturV()[i].Im);
    return Sum;
    }

double CComplexVector1::func8()const//сумма квадратов всех координат
    {
      double Sum=0;
      for(size_t i=0;i<ReturN();i++)Sum+=((ReturV()[i].Im*ReturV()[i].Im)+(ReturV()[i].Re*ReturV()[i].Re));
    return Sum;
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

CComplexVector2::CComplexVector2(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname)
  {
    this->i=i;
    this->fname=fname;
    ReturN_()=N;
    ReturMAX_()=MAX;
    ReturV_()=V;
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


  void CComplexVector2::Show_()
    {
      std::cout<<"File: "<<(*fname)[i]<<"  "<<"<";
      for(size_t i=0;i<ReturN();i++)ReturV()[i].Show();
      std::cout<<">  "
         <<func1()<<"  "
         <<func2()<<"  "
         <<func3()<<"  "
         <<func4()<<"  "
         <<func5()<<"  "
         <<func6()<<"  "
         <<func7()<<"  "
         <<func8()<<"  ";
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

  void CComplexVector2::Output_()
      {
            time_t t1,t2;time(&t1);time(&t2);
            while((int)(t2-t1)<1)time(&t2);
        std::ofstream f;
        f.open((*fname)[i],std::ios::app);
        if(!f.is_open())throw "ERROR!!! Ошибка вывода CComplexVector2;";
        f<<2<<" "<<(*fname)[i]<<" ";
        for(size_t i=0;i<ReturN();i++){ReturV()[i].Show(f);f<<" ";}
        f<<func1()<<"  "
         <<func2()<<"  "
         <<func3()<<"  "
         <<func4()<<"  "
         <<func5()<<"  "
         <<func6()<<"  "
         <<func7()<<"  "
         <<func8()<<"  ";
         f<<std::endl;
      }

  void CComplexVector2::Output_file(const char* filename)
  {
        time_t t1,t2;time(&t1);time(&t2);
        while((int)(t2-t1)<1)time(&t2);
    std::ofstream f;
    f.open(filename,std::ios::app);
    if(!f.is_open())throw "ERROR!!! Ошибка вывода CComplexVector1;";
    f<<2<<" "<<(*fname)[i]<<" ";
    for(size_t i=0;i<ReturN();i++){ReturV()[i].Show(f);f<<" ";}
      f<<func1()<<"  "
       <<func2()<<"  "
       <<func3()<<"  "
       <<func4()<<"  "
       <<func5()<<"  "
       <<func6()<<"  "
       <<func7()<<"  "
       <<func8()<<"  ";
       f<<std::endl;
  }



  double CComplexVector2::func1()const//сумма первых координат
      {
        double SumX=0;
        for(size_t i=0;i<ReturN();i++)SumX+=ReturV()[i].Re;
      return SumX;
      }

  double CComplexVector2::func2()const//сумма вторых координат
      {
        double SumY=0;
        for(size_t i=0;i<ReturN();i++)SumY+=ReturV()[i].Im;
      return SumY;
      }

  double CComplexVector2::func3()const//попарная сумма координат
      {
        double Sum=0;
        for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Re+ReturV()[i].Im);
      return Sum;
      }

  double CComplexVector2::func4()const//сумма разностей первой и второй координаты
      {
        double Sum=0;
        for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Re-ReturV()[i].Im);
      return Sum;
      }
  double CComplexVector2::func5()const//сумма разностей второй и первой
      {
        double Sum=0;
        for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Im-ReturV()[i].Re);
      return Sum;
      }
  double CComplexVector2::func6()const//сумма квадратов первых координат
      {
        double Sum=0;
        for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Re*ReturV()[i].Re);
      return Sum;
      }

  double CComplexVector2::func7()const//сумма квадратов вторых координат
      {
        double Sum=0;
        for(size_t i=0;i<ReturN();i++)Sum+=(ReturV()[i].Im*ReturV()[i].Im);
      return Sum;
      }

  double CComplexVector2::func8()const//сумма квадратов всех координат
      {
        double Sum=0;
        for(size_t i=0;i<ReturN();i++)Sum+=((ReturV()[i].Im*ReturV()[i].Im)+(ReturV()[i].Re*ReturV()[i].Re));
      return Sum;
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
//-----------------------------------------------Глобальные функции
void Out_Put_Info(const char* filename,size_t MAX,int MAX_Number,size_t MAX_Dlin,int MAX_clas)
{
  std::ofstream f;
  f.open(filename);
  if(!f.is_open())throw "ERROR!!! Ошибка задания файлов.;";
  char word[5][40];
      strcpy(word[0],"t1.txt");
      strcpy(word[1],"t2.txt");
      strcpy(word[2],"t3.txt");
      strcpy(word[3],"t4.txt");
      strcpy(word[4],"t5.txt");
  for(size_t j=0;j<MAX;j++)
  {
    f<<(1+(rand()%MAX_clas))<<" "<<word[rand()%3]<<" ";
    for(size_t i=0;i<2*MAX_Dlin;i++)f<<(rand()%MAX_Number)<<" ";
    f<<std::endl;
  }
}

void Output_OPM_senterFile(Vec_& VC,const char* filename)
{
  #pragma omp parallel num_threads(4) shared(VC)
  {
    #pragma omp sections
    {
      #pragma omp section
       { for(size_t i1=0;i1<(VC.Retur_Vec().size())/4;i1++){VC.Retur_Vec()[i1]->Output_file("txt_TMP1.txt");} }
      #pragma omp section
       { for(size_t i2=(VC.Retur_Vec().size())/4;i2<(VC.Retur_Vec().size())/2;i2++){VC.Retur_Vec()[i2]->Output_file("txt_TMP2.txt");} }
      #pragma omp section
       { for(size_t i3=(VC.Retur_Vec().size())/2;i3<(VC.Retur_Vec().size())*3/4;i3++){VC.Retur_Vec()[i3]->Output_file("txt_TMP3.txt");} }
      #pragma omp section
       { for(size_t i4=(VC.Retur_Vec().size())*3/4;i4<(VC.Retur_Vec().size());i4++){VC.Retur_Vec()[i4]->Output_file("txt_TMP4.txt");} }
    }
  }
 std::ofstream f;f.open(filename);
 std::ifstream f1,f2,f3,f4;std::string str;
 f1.open("txt_TMP1.txt");while(getline(f1,str))f<<str;
 f2.open("txt_TMP2.txt");while(getline(f2,str))f<<str;
 f3.open("txt_TMP3.txt");while(getline(f3,str))f<<str;
 f4.open("txt_TMP4.txt");while(getline(f4,str))f<<str;
 return;
}

void Output_OPM(Vec_& VC)
{
  #pragma omp parallel num_threads(4) shared(VC)
  {
    #pragma omp sections
    {
      #pragma omp section
       { for(size_t i1=0;i1<(VC.Retur_Vec().size())/4;i1++){VC.Retur_Vec()[i1]->Output_();} }
      #pragma omp section
       { for(size_t i2=(VC.Retur_Vec().size())/4;i2<(VC.Retur_Vec().size())/2;i2++){VC.Retur_Vec()[i2]->Output_();} }
      #pragma omp section
       { for(size_t i3=(VC.Retur_Vec().size())/2;i3<(VC.Retur_Vec().size())*3/4;i3++){VC.Retur_Vec()[i3]->Output_();} }
      #pragma omp section
       { for(size_t i4=(VC.Retur_Vec().size())*3/4;i4<(VC.Retur_Vec().size());i4++){VC.Retur_Vec()[i4]->Output_();} }
    }
  }
 return;
}
