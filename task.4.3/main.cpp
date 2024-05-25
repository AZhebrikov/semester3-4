#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>


#include "bibl.h"
#include "my_bibl.h"

int main()
{ try{
  time_t t1,t2;
  unsigned int time_start;
  unsigned int time_end;
  ListName LN;
  Fabric_1 FB;
  std::cout<<"Начало работы."<<std::endl<<"Заполнение исходного файла данными."<<std::endl;
  Out_Put_Info("t.txt",2000,100,30,2);
  std::cout<<"Происходит заполнение вектора векторов CComplexVector."<<std::endl;
  Vec_ VC(FB.Retur_Fabric(),LN,"t.txt");

  std::cout<<"Вывод без OpenMP данных в файл с доп функционалом:"<<std::endl;
  time(&t1);
    time_start=clock();
  for(size_t i=0;i<VC.Retur_Vec().size();i++){VC.Retur_Vec()[i]->Output_file("txt_sav1.txt");}
    time_end=clock();
  time(&t2);
  std::cout<<"Вывод окончен!"<<std::endl;
  std::cout<<"Время выполнения ="<<(int)(t2-t1)<<std::endl;
  std::cout<<"Время выполнения ="<<time_end-time_start<<std::endl;


  std::cout<<"Вывод данных с доп вычислениями по временным файлам с помощью OpenMP + их слияние в один файл :"<<std::endl;
  time(&t1);
    time_start=clock();
  Output_OPM_senterFile(VC,"txt_sav2.txt");
    time_end=clock();
  time(&t2);
  std::cout<<"Вывод окончен!"<<std::endl;
  std::cout<<"Время выполнения ="<<(int)(t2-t1)<<std::endl;
  std::cout<<"Время выполнения ="<<time_end-time_start<<std::endl;

  }catch(const char* err){std::cout<<err<<std::endl;}

return 0;
}
