#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "fun.h"


int main(void)
{
 	using std::cout;
 	using std::cin;
 	using std::endl;

 	SPoint FS(30);

 	cout<<"Введите набор точек для того, чтобы задать прямоугольник,\n"
 	      "заметим, что стороны прямоугольника будут соединены в соответсвующем порядке и \n"
 	      "запрещают пересечение(ответственность за это лежит на Вас!).\n"
 	      "Возможен следующий функционал(введите целое число.):\n";
 	      METKA1:

 	cout<<"[1] Ввод из файла.\n"
 	      "[2] Ввод с клавиатуры.\n"
 	      "[3] Повторить попытку заполнения(Все данные будут удалены).\n"
 	      "[4] Вывести точки многоугольника.\n"
 	      "[5] Узнать о нахождении точки внутри или на границе прямоугольника.\n"
 	      "[6] Закончить работу. \n";

 	int vb;
 	char err;
	char tmpfile[128];tmpfile[0]='\0';

 	  while(1)
      {
       cin>>vb;
       if(cin.fail()){cin.clear();while(cin.get()!='\n'){};
                          cout<<"Ввод был совершен неверно, повторите ввод номера действия."<<endl;continue;}
       while(cin.get()!='\n');
       if(vb<=0||vb>=7){
       					cout<<"Ввод был совершен неверно, повторите ввод номера действия."<<endl;continue;
                       }
       break;
      }

      if(vb==1)
      {
      		cout<<"Для  чтения файла необходимо задать его имя.\n";
        	 				  do{
                    				cout<<"Введите имя файла: "<<endl;
          							cin>>tmpfile;
          							while(cin.get(err))
            						{
              		 					if(err==' '|| err=='\t')continue;
              	     					if(err=='\n')break;
              		  					else
                							{
                       	  				 while(cin.get(err))if(err=='\n')break;
                       	  				 cout<<"Ввод неверен, необходимо ввести одно слово: ";
                       	  				 cin>>tmpfile;continue;
                       	 				}
                    				} 
          			 				
          			 				cout<<"То есть на чтение открыть докуент "<<tmpfile<<" <y/n>?"<<endl;
          			 				cin>>err;
  				  					}while(err!='y');
  				  					while(cin.get()!='\n');
  				  
  			std::ifstream f;
  			f.open(tmpfile);
  			if(f.is_open()==false)
               			{
                		 cout<<"В ходе открытия файла произошла ошибка,перехожу в меню действий.\n";
                		 goto METKA1;
                		}

            int k,x,y;
            while(f>>k>>x>>y)
       		{
       		 FS.DobavinK(k,Point(x,y));
       		}
       		f.close();
       	goto METKA1;
      }
      else if(vb==2)
      {
       		cout<<"Производится ввод с клафиатуры,поэтому вводите три целых числа,\n"
            	 "первое число - номер позиции записи, вторые два - координаты точки.\n"
            	 "Заполение будет сопровождаться выводом.(для прекращения введите -1 -1 -1)\n";
       		int k,x,y;
       		while(cin>>k>>x>>y)
       		{
       		if(cin.fail()){cin.clear();while(cin.get()!='\n'){};
         	                 cout<<"Ввод был совершен неверно, повторите ввод номера действия."<<endl;continue;}
        	if(k==-1 && x==-1 && y==-1){while(cin.get()!='\n'){};cout<<"Ввод окончен.\n";break;}
        	FS.DobavinK(k,Point(x,y));
       		}
      	goto METKA1;
      }
      else if(vb==3)
      {
        	cout<<"Удаление всех данных.\n";
        	FS.DeleteAll();
        goto METKA1;	
      }
      else if(vb==4)
      {
        	cout<<"Вывожу точки многоугольника:\n";
        	cout<<FS<<endl;
        goto METKA1;
      }
      else if(vb==5)
      {
       	 cout<<"Введите точку:\n";
       	 int x,y;
       		while(1)
      		{
       			cin>>x>>y;
       			if(cin.fail()){cin.clear();while(cin.get()!='\n'){};
            		              cout<<"Ввод был совершен неверно, повторите ввод номера действия."<<endl;continue;}
       			while(cin.get()!='\n');
       			break;
      		}
          int p;
          p=FS.ProvAffiliation(Point(x,y));
          if(p==1)cout<<"Точка лежит на границе.\n";
          else if(p==2)cout<<"Точка лежит внутри прямоугольника.\n";
          else if(p==3)cout<<"Точка лежит вне прямоугольника.\n";
 		 goto METKA1;
       }	
      else
        cout<<"Работа закончилась, зачтите пожалуйста программу ;)\n";
return 0;
}
