#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "fun.h"

BLOCK _SBLOCK_[NBLOCKS];
INode _Node_[MAX_FILES];

int main(void)
{
 using std::cout;
 using std::cin;
 using std::endl;
 cout<<"Создается виртуальный диск...\n"<<endl;
 FileSystem FS;
 cout<<"Проверка на наличие данных в системе...\n"<<endl;

    if(FS.ReadDisk()==0)cout<<"Данные были найдены, синхронизация системы...\n"<<endl;
    else cout<<"Данные не были найдены.\n"<<endl;

 int vb;
 int tkf=-1;
 char fname[128];fname[0]='\0';
 char err;
 char tmpfile[128];tmpfile[0]='\0';

 cout<<"Диск готов к работе.\n";
 cout<<"Mожем предложить следующий функционал:\n";
 
 METKA1:
 
 cout<<"\n[1] Просмотреть  набор имеющихся файлов.\n"
        "[2] Создать файл.\n"
        "[3] Перезаписать данные в файл.\n"
        "[4] Дописать данные в файле.\n"
        "[5] Посмотреть содержимые файла.\n"
        "[6] Удалить  файл.\n"
        "[7] Закончить работу.\n"
        "Выберете номер команды.\n";
      while(1)
      {
       cin>>vb;
       if(cin.fail()){cin.clear();while(cin.get()!='\n'){};
                          cout<<"Ввод был совершен неверно, повторите ввод номера действия."<<endl;continue;}
       while(cin.get()!='\n');
       if(vb<=0||vb>=8){
       					cout<<"Ввод был совершен неверно, повторите ввод номера действия."<<endl;continue;
                       }
       break;
      }

      if(vb==1)
         {
          if(FS.VivodAllNameFiles(cout)==-1){cout<<"Действие выполнено, желаете что-нибудь еще?\n";goto METKA1;}
 		  if(tkf==-1)cout<<"На данный момент вами не выбран никакой файл.\n";
          else 
           {
           	 cout<<"На данный момент вами выбран следующий файл:\n";
             FS.VivodFile(tkf,cout);
             cout<<endl;
           } 
          cout<<"Желаете выбрать новый файл<y/n>?\n";
          while(1)
            {
             cin>>err;
             if(cin.fail()){cin.clear();while(cin.get()!='\n'){};
                          cout<<"Ввод был совершен неверно, повторите попытку ввода."<<endl;continue;}
       		 while(cin.get()!='\n');
             if(err=='y'||err=='n')break;
             cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            }
          if(err=='y')
            {
             cout<<"Введите номер выбранного вами файла.\n";
              while(1)
              {
               cin>>tkf;
               if(cin.fail()){cin.clear();while(cin.get()!='\n'){};
                          cout<<"Ввод был совершен неверно, повторите попытку ввода."<<endl;continue;}
       		   while(cin.get()!='\n');
               if(!FS.EmptyFile(tkf))break;
               cout<<"Выбанного вами файла не существует, повторите попытку.\n";
              }
            }
          cout<<"Действие выполнено, желаете что-нибудь еще?\n";
          goto METKA1;
         }
         //=======================================================
      else if(vb==2)
      	 {
      	 	cout<<"Для создания файла необходимо задать его имя.\n";
        	 	do{
                    cout<<"Введите имя файла: "<<endl;
          			cin>>fname;
          			while(cin.get(err))
            		{
              		 if(err==' '|| err=='\t')continue;
              	     if(err=='\n')break;
              		  else
                		{
                         while(cin.get(err))if(err=='\n')break;
                         cout<<"Ввод неверен, необходимо ввести одно слово: ";
                         cin>>fname;continue;
                        }
                    } 
          			 cout<<"То есть cоздать файл  "<<fname<<" <y/n>?"<<endl;
          			 cin>>err;
  				  }while(err!='y');
  				  while(cin.get()!='\n');
  			if( (tkf=FS.SeachFiles(fname))==-1 )
  			  {
               FS.CreateFiles(fname);
               cout<<"Файл был успешно создан\n"
                      "Перехожу на меню действий.\n";
  			  }
  			else cout<<"Файл, с таким именем уже существует,вам придется удалить его вручную.\n"
  				        "Перехожу на меню действий.\n"; 
  		 	goto METKA1;

      	 }
      	 //=======================================================================
      else if(vb==3)
      	{
      	 	if(FS.EmptyFile(tkf)==-1)
      	 		{
      	 			cout<<"На данный момент вами не выбран никакой файл,поэтому запись невозможна.\n"
      	 			"Перехожу на меню действий.\n";
      	 			goto METKA1;
      	 	    }
      	 	cout<<"На данный момент вами выбран следующий файл:\n";
            FS.VivodFile(tkf,cout);cout<<endl;  

            cout<<"Желаете выбрать новый файл<y/n>?\n";
            while(1)
            {
               cin>>err;
               while(cin.get()!='\n');
               if(err=='y'||err=='n')break;
               cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            }
            if(err=='y')
            {
             cout<<"Перехожу на меню действий для дальнейшего выбора нового файла в действии [1].\n";
             goto METKA1;
            }
            
                        	bool A;
                        	int pozic=0;
                        	int block=0;
            				cout<<"Желаете произвести ввод с клаdиатуры<y/n>(ответ \"нет\" будет подрузомевать ввод из файла)?\n";
            				while(1)
            				{
               					cin>>err;
               					while(cin.get()!='\n');
               					if(err=='y'||err=='n')break;
               					cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            				}
            				
            				if(err=='y'){cout<<"Вами выбран ввод с клавиатуры.\n";A=false;}
            				else
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
  				  					A=true;
            				 }	

            									cout<<"Желаете произвести ввод с определенной позиции<y/n>"
            									      "(ответ \"нет\" подрузомевает, что по умолчанию стоит 0)?\n";
            									while(1)
            									{
               										cin>>err;
               										while(cin.get()!='\n');
               										if(err=='y'||err=='n')break;
               										cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            									} 	
            									if(err=='y')
            									  {
            									  	cout<<"Введите номер выбранной вами позиции.\n";
              										while(1)
              										{
               										 	cin>>pozic;
               										 	if(cin.fail()){cin.clear();while(cin.get()!='\n');
                          									cout<<"Ввод был совершен неверно, повторите попытку ввода."<<endl;continue;}
       		 											while(cin.get()!='\n');
       		 											break;
              										}

            									  }
            									else
            									  {
 												    cout<<"Может вы желаете ввести блок, в который осуществить "
 												          "ввод(ответ \"нет\" подрузомевает, что по умолчанию стоит 0)<y/n>?\n";

 													while(1)
            										{
               										 	cin>>err;
               											while(cin.get()!='\n');
               											if(err=='y'||err=='n')break;
               											cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            										}
            										
            										if(err=='y')
            										{
            											cout<<"Введите номер выбранного вами блока.\n";
              											while(1)
              											{
               										 		cin>>block;
               										 		if(cin.fail()){cin.clear();while(cin.get()!='\n');
                          										cout<<"Ввод был совершен неверно, повторите попытку ввода."<<endl;continue;}
       		 												while(cin.get()!='\n');
       		 												break;
              											}
            										}
            									  }				

                cout<<"Вы выбрали перезапись информации.\n"
                      "ВНИМАНИЕ!!!  Учтите, что в блоках было возможно хранение разного количество байт \n"
                      "информации, поэтому может произойти ситуация, что вы перезаписали не весь\n"
                      "блок информации,видемый вам, а лишь ту ее часть, которая находится в соответсвующем блоке.\n\n"

                       "Итоговая информация: \n";
                           cout<<"Ввод совершается ";
                                         if (A)cout<<"из файла "<<tmpfile<<" в файл: "<<endl;
                                          else cout<<"с клавиатуры в файл: "<<endl;
                           FS.VivodFile(tkf,cout);cout<<endl;
                           if(pozic!=0)cout<<"Ввод в позицию "<<pozic<<endl;
                           else if(block!=0)cout<<"Ввод в блок "<<block<<endl;
                           else cout<<"Ввод с начала файла."<<endl;
            if(A)
               {
               	    std::ifstream f;
                	Tint Mg;
                	f.open(tmpfile);
                	if(f.is_open()==false)
               			{
                		 cout<<"В ходе открытия файла произошла ошибка,перехожу в меню действий.\n";
                		 goto METKA1;
                		}
           
                				    cout<<"Начался ввод из файла.\n"<<endl;
                				    A=false;
               	 					char mass[BLOCK_SIZE];mass[0]='\0';
                	 				int i=0;
                	 				if(pozic!=0)block=FS.SeachPozic(tkf,pozic,pozic,block);	
                	 				while(f.get(err) )
                	  				{
                	  					if(A && err=='\n'){i--;break;}
                	  			        A=false;
                	  			        if(err=='\n')A=true;
                        				if( i<(BLOCK_SIZE-1) ){mass[i]=err;i++;}
                        				else
                          				{
                          			 	  mass[i]='\0';
                          			 	  Mg=FS.InCleanWriteBlock(tkf,mass,block,pozic);
                                          Mg.XY(block,pozic);
                                          mass[0]=err;
                                          i=1;
                          				}
                	  				}mass[i]='\0';
                          			 Mg=FS.InCleanWriteBlock(tkf,mass,block,pozic);
                                     Mg.XY(block,pozic);
                            cout<<"Происходит закрыие файла\n";
                            f.close();
                	   		cout<<"Запись данных в файл окончена.\n";		
 			   }
 			else
 			   {
		 			   			Tint Mg;
		 			   			cout<<"Введи текст записи(последовательность символов \\n\\n будет расценена, \n"
		 			   			       "как конец текста и заменен на символ \'\\0\'):\n"<<endl;

               	 					char mass[BLOCK_SIZE];mass[0]='\0';
                	 				int i=0;
                	 				if(pozic!=0)block=FS.SeachPozic(tkf,pozic,pozic,block);	
                	 				
                	 				A=false;
                	 				while( cin.get(err) )
                	  				{
                	  			        if(A && err=='\n'){i--;break;}
                	  			        A=false;
                	  			        if(err=='\n')A=true;
                        				if( i<(BLOCK_SIZE-1) ){mass[i]=err;i++;}
                        				else
                          				{ 
                          			 	  mass[i]='\0';
                          			 	  Mg=FS.InCleanWriteBlock(tkf,mass,block,pozic);
                                          Mg.XY(block,pozic);
                                          mass[0]=err;
                                          i=1;
                          				}
                	  				}mass[i]='\0';
                          			 Mg=FS.InCleanWriteBlock(tkf,mass,block,pozic);
                                     Mg.XY(block,pozic);
                            
                	   		cout<<"Запись данных в файл окончена.\n";		
                	
 			   }

                goto METKA1;
               
      	 }
      //=============================================================
      else if(vb==4)
      	{
      	 	if(FS.EmptyFile(tkf)==-1)
      	 		{
      	 			cout<<"На данный момент вами не выбран никакой файл,поэтому запись невозможна.\n"
      	 			"Перехожу на меню действий.\n";
      	 			goto METKA1;
      	 	    }
      	 	cout<<"На данный момент вами выбран следующий файл:\n";
            FS.VivodFile(tkf,cout);cout<<endl;  

            cout<<"Желаете выбрать новый файл<y/n>?\n";
            while(1)
            {
               cin>>err;
               while(cin.get()!='\n');
               if(err=='y'||err=='n')break;
               cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            }
            if(err=='y')
            {
             cout<<"Перехожу на меню действий для дальнейшего выбора нового файла в действии [1].\n";
             goto METKA1;
            }
            
                        	bool A;
                        	int pozic=0;
                        	int block=0;
            				cout<<"Желаете произвести ввод с клаdиатуры<y/n>(ответ \"нет\" будет подрузомевать ввод из файла)?\n";
            				while(1)
            				{
               					cin>>err;
               					while(cin.get()!='\n');
               					if(err=='y'||err=='n')break;
               					cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            				}
            				
            				if(err=='y'){cout<<"Вами выбран ввод с клавиатуры.\n";A=false;}
            				else
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
  				  					A=true;
            				 }	

            									cout<<"Желаете произвести ввод с определенной позиции<y/n>"
            									      "(ответ \"нет\" подрузомевает, что по умолчанию стоит 0)?\n";
            									while(1)
            									{
               										cin>>err;
               										while(cin.get()!='\n');
               										if(err=='y'||err=='n')break;
               										cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            									} 	
            									if(err=='y')
            									  {
            									  	cout<<"Введите номер выбранной вами позиции.\n";
              										while(1)
              										{
               										 	cin>>pozic;
               										 	if(cin.fail()){cin.clear();while(cin.get()!='\n');
                          									cout<<"Ввод был совершен неверно, повторите попытку ввода."<<endl;continue;}
       		 											while(cin.get()!='\n');
       		 											break;
              										}

            									  }
            									else
            									  {
 												    cout<<"Может вы желаете ввести блок, в который осуществить "
 												          "ввод(ответ \"нет\" подрузомевает, что по умолчанию стоит 0)<y/n>?\n";

 													while(1)
            										{
               										 	cin>>err;
               											while(cin.get()!='\n');
               											if(err=='y'||err=='n')break;
               											cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            										}
            										
            										if(err=='y')
            										{
            											cout<<"Введите номер выбранного вами блока.\n";
              											while(1)
              											{
               										 		cin>>block;
               										 		if(cin.fail()){cin.clear();while(cin.get()!='\n');
                          										cout<<"Ввод был совершен неверно, повторите попытку ввода."<<endl;continue;}
       		 												while(cin.get()!='\n');
       		 												break;
              											}
            										}
            									  }				

                cout<<"Вы выбрали дописать  информации.\n"
                      "ВНИМАНИЕ!!!  Учтите, что добавление информации может изменить местоположение иной \n"
                      "информации в файле.\n\n"
                      
                       "Итоговая информация: \n";
                           cout<<"Ввод совершается ";
                                         if (A)cout<<"из файла "<<tmpfile<<" в файл: "<<endl;
                                          else cout<<"с клавиатуры в файл: "<<endl;
                           FS.VivodFile(tkf,cout);cout<<endl;
                           if(pozic!=0)cout<<"Ввод в позицию "<<pozic<<endl;
                           else if(block!=0)cout<<"Ввод в блок "<<block<<endl;
                           else cout<<"Ввод с начала файла."<<endl;
            if(A)
               {
               	    std::ifstream f;
                	Tint Mg;
                	f.open(tmpfile);
                	if(f.is_open()==false)
               			{
                		 cout<<"В ходе открытия файла произошла ошибка,перехожу в меню действий.\n";
                		 goto METKA1;
                		}
           
                				    cout<<"Начался ввод из файла.\n"<<endl;
                				    A=false;
               	 					char mass[BLOCK_SIZE];mass[0]='\0';
                	 				int i=0;
                	 				if(pozic!=0)block=FS.SeachPozic(tkf,pozic,pozic,block);	
                	 				while(f.get(err))
                	  				{
                	  					if(A && err=='\n'){i--;break;}
                	  			        A=false;
                	  			        if(err=='\n')A=true;
                        				if( i<(BLOCK_SIZE-1) ){mass[i]=err;i++;}
                        				else
                          				{
                          			 	  mass[i]='\0';
                          			 	  Mg=FS.InWriteBlock(tkf,mass,block,pozic);
                                          Mg.XY(block,pozic);
                                          mass[0]=err;
                                          i=1;
                          				}
                	  				}mass[i]='\0';
                          			 Mg=FS.InWriteBlock(tkf,mass,block,pozic);
                                     Mg.XY(block,pozic);
                            cout<<"Происходит закрыие файла\n";
                            f.close();
                	   		cout<<"Запись данных в файл окончена.\n";		
 			   }
 			else
 			   {
		 			   			Tint Mg;
		 			   			cout<<"Введи текст записи(последовательность символов \\n\\n будет расценена, \n"
		 			   			       "как конец текста и заменен на символ \'\\0\'):\n"<<endl;

               	 					char mass[BLOCK_SIZE];mass[0]='\0';
                	 				int i=0;
                	 				if(pozic!=0)block=FS.SeachPozic(tkf,pozic,pozic,block);	
                	 				
                	 				A=false;
                	 				while( cin.get(err) )
                	  				{
                	  			        if(A && err=='\n'){i--;break;}
                	  			        A=false;
                	  			        if(err=='\n')A=true;
                        				
                        				if( i<(BLOCK_SIZE-1) ){mass[i]=err;i++;}
                        				else
                          				{ 
                          			 	  mass[i]='\0';
                          			 	  Mg=FS.InWriteBlock(tkf,mass,block,pozic);
                                          Mg.XY(block,pozic);
                                          mass[0]=err;
                                          i=1;
                          				}
                	  				}
                	  				 mass[i]='\0';
                          			 Mg=FS.InWriteBlock(tkf,mass,block,pozic);
                                     Mg.XY(block,pozic);
                            
                	   		cout<<"Запись данных в файл окончена.\n";		
                	
 			   }

                goto METKA1;
               
      	 }
      	 //===============================================================
      else if(vb==5)
         {
         	if(FS.EmptyFile(tkf)==-1)
      	 		{
      	 			cout<<"На данный момент вами не выбран никакой файл,поэтому просмор содержимого  невозможен.\n"
      	 			"Перехожу на меню действий.\n";
      	 			goto METKA1;
      	 	    }
      	 	cout<<"На данный момент вами выбран следующий файл:\n";
            FS.VivodFile(tkf,cout);cout<<endl;  

            cout<<"Желаете выбрать новый файл<y/n>?\n";
            while(1)
            {
               cin>>err;
               while(cin.get()!='\n');
               if(err=='y'||err=='n')break;
               cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            }
            if(err=='y')
            {
             cout<<"Перехожу на меню действий для дальнейшего выбора нового файла в действии [1].\n";
             goto METKA1;
            }

            cout<<"Произвожу вывод содержимого файла:\n";
            FS.VivodAll(tkf,cout);
            cout<<"Вывод окончен, перевожу в меню дейтсвий.\n";
      	  goto METKA1;
      	 }
      	 //====================================================================
      else if(vb==6)
      {
      		if(FS.EmptyFile(tkf)==-1)
      	 	{
      	 		cout<<"На данный момент вами не выбран никакой файл,поэтому удаление файла  невозможно.\n"
      	 		"Перехожу на меню действий.\n";
      	 	    goto METKA1;
      	    }
      	 	cout<<"На данный момент вами выбран следующий файл:\n";
            FS.VivodFile(tkf,cout);cout<<endl;  

            cout<<"Желаете выбрать новый файл<y/n>?\n";
            while(1)
            {
               cin>>err;
               while(cin.get()!='\n');
               if(err=='y'||err=='n')break;
               cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            }
            if(err=='y')
            {
             cout<<"Перехожу на меню действий для дальнейшего выбора нового файла в действии [1].\n";
             goto METKA1;
            }

            cout<<"Произвожу удаление файла:\n";
            if(FS.DeleteFileAll(tkf)==0)cout<<"Удаление завершено успешно, перевожу в меню дейтсвий.\n";
            else cout<<"Во время удаления возникли проблемы, перевожу в меню дейтсвий.\n";
          goto METKA1;
      }
      //===============================================================================
      else if(vb==7)
      {
      	cout<<"Желаете ли вы сохранить изменения, произошедшие в процессе работы<y/n>?\n";
        while(1)
            {
               cin>>err;
               while(cin.get()!='\n');
               if(err=='y'||err=='n')break;
               cout<<"Ввод был совершен некорректо, повторите попытку.\n";
            }
            if(err=='y')
            {
             cout<<"Происходит сохранение данных...\n";
             FS.SaveDisk();
             cout<<"Сохранение данных заверешно, прекращение работы с диском...\n";
            }
            else cout<<"Отмена сохранения данных, прекращение работы с диском...\n";
      }
      //==============================================================================
 return 0;
}