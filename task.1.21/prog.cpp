#include <iostream>
#include "fun.h"

int main(void)
{
 using std::cout;
 using std::cin;
 using std::endl;
 
 

 try{
 cout<<"Проверка конструкторов."<<endl;
 {
 	int m1=10,n1=10;
 	SparseMatrix hil(m1,n1);
 	for(int i=0;i<m1;i++)
 	{
 		cout<<"hil["<<i<<"]= "<<hil[i]<<endl;
 	}	
    cout<<"Проверка выводва:"<<endl;
    cout<<"hil:\n"<<hil;
    SparseMatrix Matr1;
    cout<<"Matr1:\n"<<Matr1; 
 
    try{Matr1.SwapLine(0,1);}catch(int err){printf("Error = %d\n",err);}
 	try{Matr1.SwapLine(0,0);}catch(int err){printf("Error = %d\n",err);}
 	try{cout<<Matr1[0]<<endl;}catch(int err){printf("Error = %d\n",err);}
 
    SparseMatrix Matr2(m1,n1);
    cout<<"Matr2:\n"<<Matr2;
    Matr2.AddElement(5,CPoint(0,0));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
    Matr2.AddElement(5,CPoint(-2,0));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
	Matr2.AddElement(5,CPoint(5,3));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(7,6));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(-13,9));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(4,1));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(-5,4));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(10,8));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
    Matr2.AddElement(5,CPoint(3,2));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(3,5));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(3,7));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
    Matr2.AddElement(5,CPoint(3,6));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(4,9));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	Matr2.AddElement(5,CPoint(5,3));cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
    
    cout<<"Попытка вылезти за границу матрицы:"<<endl;
    cout<<"["<<(Matr2.AddElement(-1,CPoint(10,8)))<<"] ";cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	cout<<"["<<(Matr2.AddElement(10,CPoint(10,8)))<<"] ";cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	cout<<"["<<(Matr2.AddElement(5,CPoint(10,-1)))<<"] ";cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 	cout<<"["<<(Matr2.AddElement(5,CPoint(10,10)))<<"] ";cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[5]Error= "<<( (CList&)Matr2[5] ).massError()<<endl;
 
    cout<<"Проверка работы SwapLine():"<<endl;
    cout<<"Matr2:\n"<<Matr2;
    Matr2.SwapLine(5,2);
    cout<<"Matr2:\n"<<Matr2;

    cout<<"Проверка создания с помощью AddElement():"<<endl;
    cout<<"Matr1:\n"<<Matr1;
    Matr1.AddElement(5,CPoint(0,0));cout<<"Matr1:\n"<<Matr1;
    Matr1.AddElement(5,CPoint(5,0));cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[5] ).massError()<<"[]"<<endl;
    Matr1.AddElement(4,CPoint(1,0));cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[4] ).massError()<<"[]"<<endl;
	Matr1.AddElement(3,CPoint(2,0));cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[3] ).massError()<<"[]"<<endl;
	Matr1.AddElement(2,CPoint(3,0));cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[2] ).massError()<<"[]"<<endl;
	Matr1.AddElement(1,CPoint(4,0));cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[1] ).massError()<<"[]"<<endl;
	
	cout<<"["<<(Matr1.AddElement(-1,CPoint(10,8)))<<"] ";cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[5] ).massError()<<endl;
 	cout<<"["<<(Matr1.AddElement(6,CPoint(10,8)))<<"] ";cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[5] ).massError()<<endl;
 	cout<<"["<<(Matr1.AddElement(4,CPoint(10,-1)))<<"] ";cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[5] ).massError()<<endl;
 	cout<<"["<<(Matr1.AddElement(4,CPoint(10,1)))<<"] ";cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[5]Error= "<<( (CList&)Matr1[5] ).massError()<<endl;
 		
    cout<<"Matr1:\n"<<Matr1;
    Matr1.SwapLine(5,2);
    cout<<"Matr1:\n"<<Matr1;
    
 }

}catch(int err){printf("ERROR1 = %d\n",err);}


try{

  cout<<"Тестируем класс CListTmp:"<<endl;
  {
   SparseMatrix Matr1(4,5);
    cout<<"Matr1:\n"<<Matr1;
    Matr1.AddElement(0,CPoint(1,0));
    Matr1.AddElement(0,CPoint(2,1));
    Matr1.AddElement(0,CPoint(3,2));
    Matr1.AddElement(0,CPoint(4,3));
    Matr1.AddElement(0,CPoint(5,4));
    Matr1.AddElement(1,CPoint(2,0));
    Matr1.AddElement(1,CPoint(3,1));
    Matr1.AddElement(1,CPoint(4,2));
    Matr1.AddElement(1,CPoint(5,3));
    Matr1.AddElement(1,CPoint(6,4));
    Matr1.AddElement(2,CPoint(3,0));
    Matr1.AddElement(2,CPoint(4,1));
    Matr1.AddElement(2,CPoint(5,2));
    Matr1.AddElement(2,CPoint(6,3));
    Matr1.AddElement(2,CPoint(7,4));
    Matr1.AddElement(3,CPoint(4,0));
    Matr1.AddElement(3,CPoint(5,1));
    Matr1.AddElement(3,CPoint(6,2));
    Matr1.AddElement(3,CPoint(7,3));
    Matr1.AddElement(3,CPoint(8,4));
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;
    Matr1[1]*=2;
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;
    cout<<"Matr1[0]*2= "<<Matr1[0]*2<<endl;
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;
    cout<<"Matr1[0]="<<Matr1[0]<<endl;
    cout<<"Matr1[2]="<<Matr1[2]<<endl;
    cout<<"Matr1[0]+=Matr1[2]"<<endl;
    Matr1[0]+=Matr1[2];
    cout<<"Matr1[0]="<<Matr1[0]<<endl;
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;
    Matr1[1]*=0;
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;


    SparseMatrix Matr2(8,8);
    cout<<"Matr2:\n"<<Matr2;
    Matr2.AddElement(0,CPoint(5,0));
    Matr2.AddElement(0,CPoint(3,6));
    Matr2.AddElement(1,CPoint(4,3));
    Matr2.AddElement(2,CPoint(3,0));
    Matr2.AddElement(2,CPoint(2,7));
    Matr2.AddElement(3,CPoint(5,1));
    Matr2.AddElement(3,CPoint(2,5));
    Matr2.AddElement(4,CPoint(2,3));
    Matr2.AddElement(5,CPoint(1,1));
    Matr2.AddElement(5,CPoint(1,6));
    Matr2.AddElement(6,CPoint(3,2));
    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;
    cout<<"Matr2[0]*2= "<<Matr2[0]*2<<endl;
    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;
    cout<<"Matr2[0]="<<Matr2[0]<<endl;
    cout<<"Matr2[2]="<<Matr2[2]<<endl;
    cout<<"Matr2[0]+=Matr2[2]"<<endl;
    Matr2[0]+=Matr2[2];
    cout<<"Matr2[0]="<<Matr2[0]<<endl;
    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;
    Matr2[1]*=0;
    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;
    ((CList &)Matr2[0]).massChek();
    cout<<"Matr2[0]="<<Matr2[0]<<endl;
    cout<<"Matr2[7]="<<Matr2[7]<<endl;
    cout<<"Matr1[3]="<<Matr1[3]<<endl;
    cout<<"Matr1[3]+=Matr2[0];"<<endl;
    Matr1[3]+=Matr2[0];
    cout<<"Matr2[0]="<<Matr2[0]<<endl;
    cout<<"Matr1[3]="<<Matr1[3]<<endl;
    cout<<"Matr2[0]+=Matr1[3];"<<endl;
    Matr2[0]+=Matr1[3];
    cout<<"Matr2[0]="<<Matr2[0]<<endl;
    cout<<"Matr1[3]="<<Matr1[3]<<endl;

    

 }
}catch(int err){printf("ERROR1 = %d\n",err);}


try{

  cout<<"Тестируем класс CListTmp:"<<endl;
  {
   SparseMatrix Matr1(4,5);
    cout<<"Matr1:\n"<<Matr1;
    Matr1.AddElement(0,CPoint(1,0));
    Matr1.AddElement(0,CPoint(2,1));
    Matr1.AddElement(0,CPoint(3,2));
    Matr1.AddElement(0,CPoint(4,3));
    Matr1.AddElement(0,CPoint(5,4));
    Matr1.AddElement(1,CPoint(2,0));
    Matr1.AddElement(1,CPoint(3,1));
    Matr1.AddElement(1,CPoint(4,2));
    Matr1.AddElement(1,CPoint(5,3));
    Matr1.AddElement(1,CPoint(6,4));
    Matr1.AddElement(2,CPoint(3,0));
    Matr1.AddElement(2,CPoint(4,1));
    Matr1.AddElement(2,CPoint(5,2));
    Matr1.AddElement(2,CPoint(6,3));
    Matr1.AddElement(2,CPoint(7,4));
    Matr1.AddElement(3,CPoint(4,0));
    Matr1.AddElement(3,CPoint(5,1));
    Matr1.AddElement(3,CPoint(6,2));
    Matr1.AddElement(3,CPoint(7,3));
    Matr1.AddElement(3,CPoint(8,4));
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;

    cout<<"Matr1[0][2]= "<<(int)Matr1[0][2]<<endl;
	cout<<"Matr1[1][3]= "<<(int)Matr1[1][3]<<endl;
	cout<<"Matr1[3][4]= "<<(int)Matr1[3][4]<<endl;
	cout<<"Matr1[0][4]= "<<(int)Matr1[0][4]<<endl;
	cout<<"Matr1[2][2]= "<<(int)Matr1[2][2]<<endl;

    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;

    cout<<"Matr1[0][2]= "<<(int)Matr1[0][2];cout<<"  Matr1[0][2]= 21";Matr1[0][2]=21;cout<<"  Matr1[0][2]= "<<(int)Matr1[0][2]<<endl;
	cout<<"Matr1[1][3]= "<<(int)Matr1[1][3];cout<<"  Matr1[1][3]= 22";Matr1[1][3]=22;cout<<"  Matr1[1][3]= "<<(int)Matr1[1][3]<<endl;
	cout<<"Matr1[3][4]= "<<(int)Matr1[3][4];cout<<"  Matr1[3][4]= 23";Matr1[3][4]=23;cout<<"  Matr1[3][4]= "<<(int)Matr1[3][4]<<endl;
	cout<<"Matr1[0][4]= "<<(int)Matr1[0][4];cout<<"  Matr1[0][4]= 24";Matr1[0][4]=24;cout<<"  Matr1[0][4]= "<<(int)Matr1[0][4]<<endl;
	cout<<"Matr1[2][2]= "<<(int)Matr1[2][2];cout<<"  Matr1[2][2]= 25";Matr1[2][2]=25;cout<<"  Matr1[2][2]= "<<(int)Matr1[2][2]<<endl;
        
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;


    SparseMatrix Matr2(8,8);
    cout<<"Matr2:\n"<<Matr2;
    Matr2.AddElement(0,CPoint(5,0));
    Matr2.AddElement(0,CPoint(3,6));
    Matr2.AddElement(1,CPoint(4,3));
    Matr2.AddElement(2,CPoint(3,0));
    Matr2.AddElement(2,CPoint(2,7));
    Matr2.AddElement(3,CPoint(5,1));
    Matr2.AddElement(3,CPoint(2,5));
    Matr2.AddElement(4,CPoint(2,3));
    Matr2.AddElement(5,CPoint(1,1));
    Matr2.AddElement(5,CPoint(1,6));
    Matr2.AddElement(6,CPoint(3,2));
    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;

    cout<<"Matr2[0][2]= "<<(int)Matr2[0][2]<<endl;
	cout<<"Matr2[1][3]= "<<(int)Matr2[1][3]<<endl;
	cout<<"Matr2[3][4]= "<<(int)Matr2[3][4]<<endl;
	cout<<"Matr2[0][4]= "<<(int)Matr2[0][4]<<endl;
	cout<<"Matr2[2][2]= "<<(int)Matr2[2][2]<<endl;
    cout<<"Matr2[6][2]= "<<(int)Matr2[6][2]<<endl;
	cout<<"Matr2[6][1]= "<<(int)Matr2[6][1]<<endl;
	cout<<"Matr2[6][3]= "<<(int)Matr2[6][3]<<endl;
	cout<<"Matr2[5][2]= "<<(int)Matr2[5][2]<<endl;
	cout<<"Matr2[7][2]= "<<(int)Matr2[7][2]<<endl;
    

    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;

    cout<<"Matr2[0][2]= "<<(int)Matr2[0][2];cout<<"   Matr2[0][2]=21 ";Matr2[0][2]=21;cout<<"  Matr2[0][2]= "<<(int)Matr2[0][2]<<endl;
	cout<<"Matr2[1][3]= "<<(int)Matr2[1][3];cout<<"   Matr2[1][3]=22 ";Matr2[1][3]=22;cout<<"  Matr2[1][3]= "<<(int)Matr2[1][3]<<endl;
	cout<<"Matr2[3][4]= "<<(int)Matr2[3][4];cout<<"   Matr2[3][4]=23 ";Matr2[3][4]=23;cout<<"  Matr2[3][4]= "<<(int)Matr2[3][4]<<endl;
	cout<<"Matr2[0][4]= "<<(int)Matr2[0][4];cout<<"   Matr2[0][4]=24 ";Matr2[0][4]=24;cout<<"  Matr2[0][4]= "<<(int)Matr2[0][4]<<endl;
	cout<<"Matr2[2][2]= "<<(int)Matr2[2][2];cout<<"   Matr2[2][2]=25 ";Matr2[2][2]=25;cout<<"  Matr2[2][2]= "<<(int)Matr2[2][2]<<endl;
    cout<<"Matr2[6][2]= "<<(int)Matr2[6][2];cout<<"   Matr2[6][2]=26 ";Matr2[6][2]=26;cout<<"  Matr2[6][2]= "<<(int)Matr2[6][2]<<endl;
	cout<<"Matr2[6][1]= "<<(int)Matr2[6][1];cout<<"   Matr2[6][1]=27 ";Matr2[6][1]=27;cout<<"  Matr2[6][1]= "<<(int)Matr2[6][1]<<endl;
	cout<<"Matr2[6][3]= "<<(int)Matr2[6][3];cout<<"   Matr2[6][3]=28 ";Matr2[6][3]=28;cout<<"  Matr2[6][3]= "<<(int)Matr2[6][3]<<endl;
	cout<<"Matr2[5][2]= "<<(int)Matr2[5][2];cout<<"   Matr2[5][2]=29 ";Matr2[5][2]=29;cout<<"  Matr2[5][2]= "<<(int)Matr2[5][2]<<endl;
	cout<<"Matr2[7][2]= "<<(int)Matr2[7][2];cout<<"   Matr2[7][2]=30 ";Matr2[7][2]=30;cout<<"  Matr2[7][2]= "<<(int)Matr2[7][2]<<endl;
    
    cout<<"Matr2:\n"<<Matr2;cout<<"Matr2[1]Error= "<<( (CList&)Matr2[1] ).massError()<<endl;


 }
}catch(int err){printf("ERROR1 = %d\n",err);}



try{

  cout<<"Тестируем последние функции:"<<endl;
  {
   SparseMatrix Matr1(4,5);
    cout<<"Matr1:\n"<<Matr1;
    Matr1.AddElement(0,CPoint(1,0));
    Matr1.AddElement(0,CPoint(2,1));
    Matr1.AddElement(0,CPoint(3,2));
    Matr1.AddElement(0,CPoint(4,3));
    Matr1.AddElement(0,CPoint(5,4));
    Matr1.AddElement(1,CPoint(2,0));
    Matr1.AddElement(1,CPoint(3,1));
    Matr1.AddElement(1,CPoint(4,2));
    Matr1.AddElement(1,CPoint(5,3));
    Matr1.AddElement(1,CPoint(6,4));
    Matr1.AddElement(2,CPoint(3,0));
    Matr1.AddElement(2,CPoint(4,1));
    Matr1.AddElement(2,CPoint(5,2));
    Matr1.AddElement(2,CPoint(6,3));
    Matr1.AddElement(2,CPoint(7,4));
    Matr1.AddElement(3,CPoint(4,0));
    Matr1.AddElement(3,CPoint(5,1));
    Matr1.AddElement(3,CPoint(6,2));
    Matr1.AddElement(3,CPoint(7,3));
    Matr1.AddElement(3,CPoint(8,4));
    cout<<"Matr1:\n"<<Matr1;cout<<"Matr1[1]Error= "<<( (CList&)Matr1[1] ).massError()<<endl;

    SparseMatrix Matr2(Matr1);
    cout<<"Matr1:\n"<<Matr1;
    cout<<"Matr2:\n"<<Matr2;
    
    SparseMatrix Matr3(1,1,5);
    Matr3.AddElement(0,CPoint(1,0));
    Matr3.AddElement(0,CPoint(2,1));
    Matr3.AddElement(0,CPoint(3,2));
    Matr3.AddElement(1,CPoint(4,0));
    Matr3.AddElement(1,CPoint(5,1));
    Matr3.AddElement(1,CPoint(6,2));
    Matr3.AddElement(2,CPoint(7,0));
    Matr3.AddElement(2,CPoint(8,1));
    Matr3.AddElement(2,CPoint(9,2));
    cout<<"Matr3:\n"<<Matr3;
    
    cout<<"Matr1:\n"<<Matr1;
    
    try{Matr1.LineOutPut(-1);cout<<endl;}catch(int err){printf("Error = %d\n",err);}
    try{Matr1.LineOutPut(2);cout<<endl;}catch(int err){printf("Error = %d\n",err);}
    try{Matr1.LineOutPut(4);cout<<endl;}catch(int err){printf("Error = %d\n",err);}
 
 
    try{Matr1.ColumnOutPut(-1);cout<<endl;}catch(int err){printf("Error = %d\n",err);}
    try{Matr1.ColumnOutPut(2);cout<<endl;}catch(int err){printf("Error = %d\n",err);}
    try{Matr1.ColumnOutPut(5);cout<<endl;}catch(int err){printf("Error = %d\n",err);}
 
    SparseMatrix Matr4(8,8);
    cout<<"Matr4:\n"<<Matr4;
    Matr4.AddElement(0,CPoint(5,0));
    Matr4.AddElement(0,CPoint(3,6));
    Matr4.AddElement(1,CPoint(4,3));
    Matr4.AddElement(2,CPoint(3,0));
    Matr4.AddElement(2,CPoint(2,7));
    Matr4.AddElement(3,CPoint(5,1));
    Matr4.AddElement(3,CPoint(2,5));
    Matr4.AddElement(4,CPoint(2,3));
    Matr4.AddElement(5,CPoint(1,1));
    Matr4.AddElement(5,CPoint(1,6));
    Matr4.AddElement(6,CPoint(3,2));

    cout<<"Matr4:\n"<<Matr4;

    Matr4.MatrixOutPut();
    

 }
}catch(int err){printf("ERROR1 = %d\n",err);}


 return 0;
}
