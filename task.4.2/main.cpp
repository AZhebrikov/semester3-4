#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

#include "bibl.h"
#include "my_bibl.h"

int main()
{ try{
  std::cout<<"Начало работы."<<std::endl<<std::endl;
  ListName LN;
  Fabric_1 FB;
  Vec_ VC(FB.Retur_Fabric(),LN,"t.txt");
  std::cout<<"Вывод данных на экран:"<<std::endl;
  for(size_t i=0;i<VC.Retur_Vec().size();i++){VC.Retur_Vec()[i]->Show();std::cout<<std::endl;}
  std::cout<<"Вывод данных по файлам:"<<std::endl;
  for(size_t i=0;i<VC.Retur_Vec().size();i++){VC.Retur_Vec()[i]->Output();}
  std::cout<<"Вывод окончен!"<<std::endl;

  std::cout<<"Начало проверки работы операторов."<<std::endl;

   std::cout<<"vec1= ";(*(VC.Retur_Vec()[0])).Show();std::cout<<std::endl;
   std::cout<<"vec2= ";(*(VC.Retur_Vec()[1])).Show();std::cout<<std::endl;
   std::cout<<"vec1+vec1= ";(*(VC.Retur_Vec()[0])+*(VC.Retur_Vec()[0])).Show();std::cout<<std::endl;
   std::cout<<"vec1+vec2= ";(*(VC.Retur_Vec()[0])+*(VC.Retur_Vec()[1])).Show();std::cout<<std::endl;

   CComplexVector v1;
   v1.Add_push_back(2,-3);
   v1.Add_push_back(1,5);
   v1.Add_push_back(2,2);

   CComplexVector v2;
   v2.Add_push_back(-2,1);
   v2.Add_push_back(1,2);
   v2.Add_push_back(0,-1);


   std::cout<<"v1= ";v1.Show();std::cout<<std::endl;
   std::cout<<"v2= ";v2.Show();std::cout<<std::endl;
   std::cout<<"v1*v2=  ";(v1*v2).Show();std::cout<<std::endl;

   CComplexVector v3;
   std::cout<<"v3=v1;\nv3= ";v3=v1;v3.Show();std::cout<<std::endl;
   std::cout<<"~v3= ";(~v3).Show();std::cout<<std::endl;
   std::cout<<"v2= "<<v2<<std::endl;
   std::cout<<"v2[1]= "<<v2[1]<<std::endl;
   v2[1]=CComplexNumber(7,7);
   std::cout<<"v2[1]= "<<v2[1]<<std::endl;

 }catch(const char* err){std::cout<<err<<std::endl;}

return 0;
}
