#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "fun.h"

//Глобальные функции программы...
std::ostream & operator<<(std::ostream & cout, FileSystem & FS)
  {
    cout<<"Файлы:"<<std::endl;
      for(int i=0;i< MAX_FILES;i++)if(FS.Node[i].FirstBlock!=-2)
         {cout<<"Имя файла["<<i<<"]:"<<FS.Node[i].FileName<<" ,Размер файла:"
              <<FS.Node[i].Size<<" ,Номер 1-ого блока:"<<FS.Node[i].FirstBlock<<std::endl;}
    cout<<"Блоки памяти:"<<std::endl;
      for(int i=0;(i<NBLOCKS)&&(FS.Sblock[i].State!=-2);i++)
      {
        cout<<"Сост["<<i<<"]:"<<FS.Sblock[i].State;
        if(FS.Sblock[i].PN.State!=2){    cout<<" ,Количество элементов:"<<FS.Sblock[i].PN.Number<<" ,PrevBlock:"<<
                                         FS.Sblock[i].PN.prevBlock<<" ,prevBranch:"<<FS.Sblock[i].PN.prevBranch<<"\n      ";
        for(int k=0;(k<FS.Sblock[i].PN.Number)&&(k<2*N-1);k++){cout<<"["<<FS.Sblock[i].PN.Peak[k]<<"] ";}cout<<"|| ";
        for(int k=0;k<2*N;k++){cout<<"{"<<FS.Sblock[i].PN.Next[k]<<"} ";}
        }cout<<std::endl;  
      }
  return cout;
  }
 

//Функции, относящиеся к классу FileSystem...

int FileSystem::New_Block()
  {
   if(ErrSystem!=0)return -1;
   int i;
   for(i=0;i<NBLOCKS;i++)if(Sblock[i].State==-2)break;
   if(NBLOCKS==i){ErrBlock=ErrWrite=-1;return -1;}
   else return i;
  }

int FileSystem::New_INode()
  {
   if(ErrSystem!=0)return -1;
   int i;
   for(i=0;i<MAX_FILES;i++)if(Node[i].FirstBlock==-2)break;
   if(MAX_FILES==i){ErrWrite=ErrFile=-1;return -1;}
   else return i;
  }
  
int FileSystem::CreateFiles(const char * filename)
  {
    int filenumber;
    int firstblock;
    if( ( filenumber=New_INode() )==-1)return -2;
    if( ( firstblock=New_Block() )==-1)return -1;
    
      strncpy(Node[filenumber].FileName,filename,128);
      Node[filenumber].Size=0;
      Node[filenumber].FirstBlock=firstblock;

      Sblock[firstblock].State=2;
      memset(Sblock[firstblock].SD.Data,'\0',2);
      
   return 0;
  }

int FileSystem::BrokenBlock(int brkblock)
  {
    if( (Sblock[brkblock].State!=1) || (Sblock[brkblock].PN.Number <(2*N-1) ) ) return -1;
    int tmpblock1;
    int tmpblock2;
    if( ( tmpblock1=New_Block() )==-1)return -1;
    if( (tmpblock2=tmpblock1+1) == NBLOCKS )return -1;
    
        Sblock[tmpblock1].PN.prevBlock=brkblock;
        Sblock[tmpblock1].PN.prevBranch = 0;
        Sblock[tmpblock1].PN.Number = N;
        Sblock[tmpblock1].PN.State=1;
        for(int i=0;i< N;i++){Sblock[tmpblock1].PN.Peak[i]=Sblock[brkblock].PN.Peak[i];}
        for(int i=0;i<2*N;i++){Sblock[tmpblock1].PN.Next[i]=-1;}

        Sblock[tmpblock2].PN.prevBlock=brkblock;
        Sblock[tmpblock2].PN.prevBranch = 1;
        Sblock[tmpblock2].PN.Number = N-1;
        Sblock[tmpblock2].PN.State=1;
        for(int i=N;i<(2*N-1);i++){Sblock[tmpblock2].PN.Peak[i-N]=Sblock[brkblock].PN.Peak[i];}
        for(int i=0;i<2*N;i++){Sblock[tmpblock2].PN.Next[i]=-1;}

        Sblock[brkblock].PN.Number = 1;
        Sblock[brkblock].PN.State = 0;
     
             if(Sblock[brkblock].PN.prevBranch==-1){Sblock[brkblock].PN.Peak[0] = N;}
        else if(Sblock[brkblock].PN.prevBranch==0){Sblock[brkblock].PN.Peak[0] =
                Sblock[Sblock[brkblock].PN.prevBlock].PN.Peak[0]-(N-1);}
        else{Sblock[brkblock].PN.Peak[0] = 
             Sblock[Sblock[brkblock].PN.prevBlock].PN.Peak[(Sblock[brkblock].PN.prevBranch)-1]+N;}
     
        Sblock[brkblock].PN.Next[0] = tmpblock1;
        Sblock[brkblock].PN.Next[1] = tmpblock2;
        
  return 0;
  }


int  FileSystem::expansion(int brkblock)
  {
    if( (Sblock[brkblock].State!=1) || (Sblock[brkblock].PN.Number <(2*N-1) ) ) return -2;
    if(  Sblock[brkblock].PN.prevBlock==-1 )return -1;
    int tmpblock;
    if( ( tmpblock=New_Block() )==-1)return -1;
    
    if(  Sblock[Sblock[brkblock].PN.prevBlock].PN.Number==Sblock[brkblock].PN.prevBranch &&
         Sblock[Sblock[brkblock].PN.prevBlock].PN.Number < (2*N-1) ) 
            {
             Sblock[Sblock[brkblock].PN.prevBlock].PN.Peak[Sblock[Sblock[brkblock].PN.prevBlock].PN.Number]
             = Sblock[Sblock[brkblock].PN.prevBlock].PN.Peak[(Sblock[Sblock[brkblock].PN.prevBlock].PN.Number)-1]+N;
             Sblock[Sblock[brkblock].PN.prevBlock].PN.Number++;
             Sblock[Sblock[brkblock].PN.prevBlock].PN.Next[Sblock[Sblock[brkblock].PN.prevBlock].PN.Number]=tmpblock;
                  Sblock[tmpblock].PN.State=1;
                  Sblock[tmpblock].PN.prevBlock=Sblock[brkblock].PN.prevBlock;
                  Sblock[tmpblock].PN.prevBranch=Sblock[Sblock[brkblock].PN.prevBlock].PN.Number;
                  Sblock[tmpblock].PN.Number=N-1;
                  for(int i=N;i<(2*N-1);i++){Sblock[tmpblock].PN.Peak[i-N]=Sblock[brkblock].PN.Peak[i];}
                  for(int i=0;i<2*N;i++){Sblock[tmpblock].PN.Next[i]=-1;}
             Sblock[brkblock].PN.Number=N;
             
             return 0;
            }
    return -1;
  }


  int FileSystem::levelup(int filenumber)
  {
    
    int i=Node[filenumber].FirstBlock;while(Sblock[i].PN.Next[0]!=-1)i=Sblock[i].PN.Next[0];
    int end=Node[filenumber].FirstBlock;while(Sblock[end].PN.Next[Sblock[end].PN.Number]!=-1)end=Sblock[end].PN.Next[Sblock[end].PN.Number];
    int tmpj;
    
      do{
          BrokenBlock(i);
          tmpj=0;
          while(Sblock[i].PN.prevBlock!=-1)
            {
              tmpj=Sblock[i].PN.prevBranch;
              i=Sblock[i].PN.prevBlock;
              if(Sblock[i].PN.Number>tmpj)break;
            }
          i=Sblock[i].PN.Next[tmpj+1];   
          while(Sblock[i].PN.Next[0]!=-1)i=Sblock[i].PN.Next[0];
        }while(i!=end);
        BrokenBlock(i);

  return 0;
  }

int FileSystem::AddBlockMemory(int filenumber)
  {
    if(Node[filenumber].FirstBlock==-2)return -2;
    int addblock;
    if( ( addblock=New_Block() )==-1)return -1;
    Sblock[addblock].State=-1;
    
      if(Sblock[Node[filenumber].FirstBlock].State==2)
          {
            int tmpblock=Node[filenumber].FirstBlock;
              Node[filenumber].FirstBlock=addblock;
              Sblock[addblock].PN.State=1;
              Sblock[addblock].PN.prevBlock=-1;
              Sblock[addblock].PN.prevBranch=-1;
              for(int k=0;k<2*N;k++){Sblock[addblock].PN.Next[k]=-1;}
              Sblock[addblock].PN.Number=1;
              Sblock[addblock].PN.Peak[0]=tmpblock;
              addblock=AddBlockMemory(filenumber);

       }
      else if(  (Sblock[Node[filenumber].FirstBlock].State==1) && (Sblock[Node[filenumber].FirstBlock].PN.Number < 2*N-1)  ) 
       {
        Sblock[Node[filenumber].FirstBlock].PN.Peak[Sblock[Node[filenumber].FirstBlock].PN.Number]=addblock;
              Sblock[addblock].State=2;
              memset(Sblock[addblock].SD.Data,'\0',2);
        Sblock[Node[filenumber].FirstBlock].PN.Number++; 
       }
      else if(  (Sblock[Node[filenumber].FirstBlock].State==1) && (Sblock[Node[filenumber].FirstBlock].PN.Number == 2*N-1)  )
       {
        int i;
        BrokenBlock(Node[filenumber].FirstBlock);
        
        i=Node[filenumber].FirstBlock;while(Sblock[i].PN.Next[Sblock[i].PN.Number]!=-1)i=Sblock[i].PN.Next[Sblock[i].PN.Number];
        Sblock[i].PN.Peak[Sblock[i].PN.Number]=addblock;Sblock[i].PN.Number++;
              Sblock[addblock].State=2;
              memset(Sblock[addblock].SD.Data,'\0',2);
          
       }
      else if( Sblock[Node[filenumber].FirstBlock].State == 0)
       {
          int i=Node[filenumber].FirstBlock;while(Sblock[i].PN.Next[0]!=-1)i=Sblock[i].PN.Next[0];
          if( Sblock[i].PN.Number== (2*N-1) )levelup(filenumber);
          else
          {
            int end=Node[filenumber].FirstBlock;while(Sblock[end].PN.Next[Sblock[end].PN.Number]!=-1)
                                                                             end=Sblock[end].PN.Next[Sblock[end].PN.Number];
            int tmpi,tmpj,j;
             while(i!=end)
                {
                  tmpi=i;
                  tmpj=0;
                  while(Sblock[tmpi].PN.prevBlock!=-1)
                     {
                      tmpj=Sblock[tmpi].PN.prevBranch;
                      tmpi=Sblock[tmpi].PN.prevBlock;
                      if(Sblock[tmpi].PN.Number>tmpj)break;
                     }
                  j=Sblock[tmpi].PN.Next[tmpj+1];   
                  while(Sblock[j].PN.Next[0]!=-1)j=Sblock[j].PN.Next[0];

                    if(  Sblock[j].PN.Number==(2*N-1))
                       {  if( expansion(j)==0 )continue;
                          int tmpk=Sblock[j].PN.Peak[0];
                          for(int k=0;k<Sblock[j].PN.Number-1;k++){Sblock[j].PN.Peak[k]=Sblock[j].PN.Peak[k+1];}
                          Sblock[j].PN.Number--;
                          Sblock[i].PN.Peak[Sblock[i].PN.Number]=tmpk;Sblock[i].PN.Number++;
                          Sblock[tmpi].PN.Peak[tmpj]+=1;
                       }
                 i=j;

                }
          }
          i=Node[filenumber].FirstBlock;while(Sblock[i].PN.Next[Sblock[i].PN.Number]!=-1)i=Sblock[i].PN.Next[Sblock[i].PN.Number];
          Sblock[i].PN.Peak[Sblock[i].PN.Number]=addblock;Sblock[i].PN.Number++;
              Sblock[addblock].State=2;
              memset(Sblock[addblock].SD.Data,'\0',2);
          
       }
   if(Sblock[addblock].State==-1){Sblock[addblock].State=-2;}
   return addblock;    
  }


int  FileSystem::ErrorChek(int a)
 {
  if(a==0)
    {
     for(int i=0;i<NBLOCKS;i++)if(Sblock[i].State==2)
            {
             std::cout<<"Sblock["<<i<<"]:";
             if((Sblock[i].SD.Data[0]=='\0')&&(Sblock[i].SD.Data[1]=='\0'))std::cout<<"YES"<<std::endl;
             else std::cout<<"NO"<<std::endl;
            }
    }
  else if(a==1)
    {
     for(int i=0;i<MAX_FILES;i++)if(Node[i].FirstBlock!=-2)std::cout<<"ERROR1"<<std::endl;
    }
  else if(a==2)
    {
     for(int i=0;i<NBLOCKS;i++)if(Sblock[i].State!=-2)std::cout<<"ERROR2"<<std::endl; 
    } 
  return 0;
 }


 int FileSystem::DeleteFileAll(int filenumber)
 {
  if(Node[filenumber].FirstBlock==-2)return -1;
  
  int i=Node[filenumber].FirstBlock;
  if(Sblock[i].State==2)
    {
     Sblock[i].SD.State=-2;
     memset(Sblock[i].SD.Data,'\0',2); 
    }
  else
  {
      int k; 
      while(i!=-1)
      {
        if(Sblock[i].State==0)
        {
         for(k=0;k<2*N;k++)if(Sblock[i].PN.Next[k]!=-1){i=Sblock[i].PN.Next[k];break;}
         if(k==2*N && Sblock[i].PN.prevBlock==-1)
             {
               Sblock[i].State=-2;
               memset(Sblock[i].SD.Data,'\0',2);
               i=-1;
             }
         else if(k==2*N && Sblock[i].PN.prevBlock!=-1)
             {
              int tmpi=Sblock[i].PN.prevBlock;
              Sblock[tmpi].PN.Next[Sblock[i].PN.prevBranch]=-1;
              Sblock[i].State=-2;
              i=tmpi;
             }
         
        }
        else if(Sblock[i].State==1)
        {
          for(k=0;k<Sblock[i].PN.Number;k++)
            {
             Sblock[Sblock[i].PN.Peak[k]].State=-2;
             memset(Sblock[Sblock[i].PN.Peak[k]].SD.Data,'\0',2);
            }
            
          int tmpi=Sblock[i].PN.prevBlock;
          if(tmpi!=-1){Sblock[tmpi].PN.Next[Sblock[i].PN.prevBranch]=-1;}
          Sblock[i].State=-2;
          i=tmpi;
          
        }
      }
  }
  Node[filenumber].FirstBlock=-2;
  Node[filenumber].Size=0;
  Node[filenumber].FileName[0]='\0';
  return 0;
 }

 int FileSystem::SearchNumberBloc(int k,int filenumber)
  {
   if(k<0)k=0;
   int i=Node[filenumber].FirstBlock;
   if(Sblock[i].State==2)return i;
   while( (Sblock[i].State==1)||(Sblock[i].State==0) ) 
   {
      if(Sblock[i].PN.State==1)
      {
        if(  (Sblock[i].PN.prevBlock==-1) && (k>=Sblock[i].PN.Number) )return Sblock[i].PN.Peak[Sblock[i].PN.Number-1];
        
        if(  (Sblock[i].PN.prevBlock==-1) && (k<Sblock[i].PN.Number)  )return Sblock[i].PN.Peak[k];
        else
          {
           if(Sblock[i].PN.prevBranch == 0)
           {
            return Sblock[i].PN.Peak[(Sblock[i].PN.Number-Sblock[Sblock[i].PN.prevBlock].PN.Peak[0]+k)];
           }
           else
           {
            if(  (k-Sblock[Sblock[i].PN.prevBlock].PN.Peak[Sblock[i].PN.prevBranch-1]) > Sblock[i].PN.Number )
                                                                        return Sblock[i].PN.Peak[Sblock[i].PN.Number-1];
            else return Sblock[i].PN.Peak[(k-Sblock[Sblock[i].PN.prevBlock].PN.Peak[Sblock[i].PN.prevBranch-1])];
           }
          }
      }
      else if(Sblock[i].PN.State==0)
      {int j=0;
        if(k<Sblock[i].PN.Peak[0]){i=Sblock[i].PN.Next[0];continue;}
        for(j=0;j+1<Sblock[i].PN.Number;j++)
             {
               if(  (Sblock[i].PN.Peak[j]<=k) && (Sblock[i].PN.Peak[j+1]>k) )
                    {
                      i=Sblock[i].PN.Next[j+1];
                    }
             }
        if( (j+1)==Sblock[i].PN.Number && (Sblock[i].PN.Peak[j]<=k) )
           {
             i=Sblock[i].PN.Next[j+1];
           } 
        }
   }
   return -1;
  }




  int FileSystem::SeachPozic(int filenumber,int poz,int & pozic_, int & block_)
   {
      if(Node[filenumber].FirstBlock==-2)return -2;
      int i;
      int insize=0;
      int pozic = 0;
      int block = 0;
      int numberblock=0;
     
      if(Sblock[Node[filenumber].FirstBlock].State==2)
        {
         if(poz<0)pozic=0;
         else 
          {
            for(i=0;(Sblock[Node[filenumber].FirstBlock].SD.Data[i]!='\0');)
                             {insize++;i++;
                              if(insize==poz )break;
                             }pozic=insize;
          } 
         pozic_=pozic;block_=Node[filenumber].FirstBlock; return numberblock;
        }

      
      iterator begin = Begin(filenumber);
      iterator end = End(filenumber);
      
      bool A=true;
      int tmp;
      int k=0;
      i=0;

      if(poz<=0)
        {
          pozic_=0;
          block_= Sblock[(*begin)].PN.Peak[0];
        return 0;
        }

      if(poz>=Node[filenumber].Size)
         {
            for(;begin!=end;begin++)
            {
               for(tmp=0;tmp<Sblock[(*begin)].PN.Number;tmp++,k++)
                       {
                        if(Sblock[Sblock[(*begin)].PN.Peak[tmp]].SD.Data[0]!='\0'){block=Sblock[(*begin)].PN.Peak[tmp];
                                                                                                        numberblock=k;}
                       }
            }     for(tmp=0;tmp<Sblock[(*begin)].PN.Number;tmp++,k++)
                       {
                        if(Sblock[Sblock[(*begin)].PN.Peak[tmp]].SD.Data[0]!='\0'){block=Sblock[(*begin)].PN.Peak[tmp];
                                                                                                        numberblock=k;}
                       }
            for(tmp=0;Sblock[block].SD.Data[tmp]!='\0';tmp++){;}
              pozic=tmp;
              block_=block;
              pozic_=pozic;
              return numberblock;
         }
      else
         {

          for(;begin!=end;begin++)
            {
               for(tmp=0;tmp<Sblock[(*begin)].PN.Number;tmp++,k++)
                       {for(i=0;(Sblock[Sblock[(*begin)].PN.Peak[tmp]].SD.Data[i]!='\0');)
                             {insize++;i++;
                              if(insize==poz && (Sblock[Sblock[(*begin)].PN.Peak[tmp]].SD.Data[i]!='\0'))
                                                            {A=false;pozic=i;block=Sblock[(*begin)].PN.Peak[tmp];numberblock=k;}
                              if(insize==poz+1 && A){pozic=i-1;block=Sblock[(*begin)].PN.Peak[tmp];numberblock=k;}
                             }
                       }
            }     for(tmp=0;tmp<Sblock[(*begin)].PN.Number;tmp++,k++)
                       {for(i=0;(Sblock[Sblock[(*begin)].PN.Peak[tmp]].SD.Data[i]!='\0');)
                             {insize++;i++;
                              if(insize==poz && (Sblock[Sblock[(*begin)].PN.Peak[tmp]].SD.Data[i]!='\0'))
                                                            {A=false;pozic=i;block=Sblock[(*begin)].PN.Peak[tmp];numberblock=k;}
                              if(insize==poz+1 && A){pozic=i-1;block=Sblock[(*begin)].PN.Peak[tmp];numberblock=k;}
                             }
                       }
           block_=block;
           pozic_=pozic;
           return numberblock;
         }
   }


  Tint FileSystem::InWriteBlock(int filenumber,const char * WR, int  Kd,int  pozic)
    { 
     int twr=0;
     if(Node[filenumber].FirstBlock==-2)return -1;
        int insize=0;
        char tmpblock[3*BLOCK_SIZE];memset(tmpblock,'\0',2);int tmi1=0;
        bool A=true;
        Tint Rt(0,Kd,0);
        int pmass=Kd;
        int p;
        int tmp;
        int end=SearchNumberBloc(NBLOCKS,filenumber);


     if(Sblock[Node[filenumber].FirstBlock].State==2)
        {pmass=0;
         p=Node[filenumber].FirstBlock;
            for(tmp=0;tmp<pozic;tmp++)if(Sblock[p].SD.Data[tmp]=='\0')pozic=tmp;
            for(tmp=pozic;Sblock[p].SD.Data[tmp]!='\0';tmp++)
               {
                  tmpblock[tmi1]=Sblock[p].SD.Data[tmp];
                  tmi1++;
               }tmpblock[tmi1]='\0';
            
              for(tmp=pozic;tmp<(BLOCK_SIZE-1) && WR[twr]!='\0';twr++,tmp++)
                 {
                    Sblock[p].SD.Data[tmp]=WR[twr];
                    insize++;
                 }Sblock[p].SD.Data[tmp]='\0';Rt.pz=tmp;
            
              
              if(tmp==(BLOCK_SIZE-1) && WR[twr]!='\0')
                        { pmass++;
                          p=AddBlockMemory(filenumber);
                          for(tmp=0; WR[twr]!='\0';twr++,tmp++)
                            {
                             Sblock[p].SD.Data[tmp]=WR[twr];
                             insize++;
                            }Sblock[p].SD.Data[tmp]='\0';
                        }Rt.numb=pmass;Rt.pz=tmp;               

            for(twr=0; (tmp<(BLOCK_SIZE-1) )&&(tmpblock[twr]!='\0');tmp++,twr++ )
                       {
                        Sblock[p].SD.Data[tmp]=tmpblock[twr];
                       }Sblock[p].SD.Data[tmp]='\0';
         
           if(tmp==(BLOCK_SIZE-1) && tmpblock[twr]!='\0')
           { pmass++;
             p=AddBlockMemory(filenumber);
             for(tmp=0; (tmp<(BLOCK_SIZE-1) )&&(tmpblock[twr]!='\0');tmp++,twr++ )
                       {
                        Sblock[p].SD.Data[tmp]=tmpblock[twr];
                       }Sblock[p].SD.Data[tmp]='\0';
           }

          Node[filenumber].Size+=insize;Rt.sz=insize;  
        return Rt;        
        }
     
       p=SearchNumberBloc(pmass,filenumber);
       if(p==end){end=AddBlockMemory(filenumber);}
       for(tmp=0;tmp<pozic;tmp++)if(Sblock[p].SD.Data[tmp]=='\0')pozic=tmp;
       for(tmp=pozic;Sblock[p].SD.Data[tmp]!='\0';tmp++)
         {
          tmpblock[tmi1]=Sblock[p].SD.Data[tmp];
          tmi1++;
         }tmpblock[tmi1]='\0';
              for(tmp=pozic;tmp<(BLOCK_SIZE-1) && WR[twr]!='\0';twr++,tmp++)
                {
                  Sblock[p].SD.Data[tmp]=WR[twr];
                  insize++;
                }Sblock[p].SD.Data[tmp]='\0';

                     if(tmp==(BLOCK_SIZE-1))
                        {
                          pmass++;
                          p=SearchNumberBloc(pmass,filenumber);
                          if(p==end){end=AddBlockMemory(filenumber);}
                          
                          for(tmp=0;Sblock[p].SD.Data[tmp]!='\0';tmp++)
                             {
                              tmpblock[tmi1]=Sblock[p].SD.Data[tmp];
                              tmi1++;
                             }tmpblock[tmi1]='\0';
                          
                          for(tmp=0; WR[twr]!='\0';twr++,tmp++)
                            {
                             Sblock[p].SD.Data[tmp]=WR[twr];
                             insize++;
                            }Sblock[p].SD.Data[tmp]='\0';
                        }Rt.numb=pmass;Rt.pz=tmp;

                     for(twr=0; (tmp<(BLOCK_SIZE-1) )&&(tmpblock[twr]!='\0');tmp++,twr++ )
                       {
                        Sblock[p].SD.Data[tmp]=tmpblock[twr];
                       }Sblock[p].SD.Data[tmp]='\0';      
        if(tmpblock[twr]=='\0')A=false;
        else pmass++;
        
        while(A)
        {
          p=SearchNumberBloc(pmass,filenumber);
          if(p==end){end=AddBlockMemory(filenumber);}
       
          for(tmi1=0;tmpblock[twr]!=0;tmi1++,twr++)
            {
              tmpblock[tmi1]=tmpblock[twr];
            }tmpblock[tmi1]='\0';

          for(tmp=0;Sblock[p].SD.Data[tmp]!='\0';tmp++,tmi1++)
            {
             tmpblock[tmi1]=Sblock[p].SD.Data[tmp];
            }tmpblock[tmi1]='\0';
          
          for(twr=0,tmp=0;(tmp<(BLOCK_SIZE-1) )&&(tmpblock[twr]!='\0');tmp++,twr++ )
            {
              Sblock[p].SD.Data[tmp]=tmpblock[twr];
            }Sblock[p].SD.Data[tmp]='\0'; 
          
          if(tmpblock[twr]=='\0')A=false;
          else pmass++;
        }
      
      Node[filenumber].Size+=insize;Rt.sz=insize;  
  return Rt;
  }

         



int FileSystem::VivodAll(int filenumber,std::ostream & cout)
  {if(Node[filenumber].FirstBlock==-2)return -1;
    cout<<"FileName: "<<Node[filenumber].FileName<<" ,Size:"<<Node[filenumber].Size<<std::endl;
   if(Sblock[Node[filenumber].FirstBlock].State==2)
      {
        Sblock[Node[filenumber].FirstBlock].Vivod(cout);
        return 0; 
      }
    iterator begin = Begin(filenumber);
    iterator end = End(filenumber);
    for(;begin!=end;begin++)
      {
       for(int k=0;k<Sblock[((int)begin)].PN.Number;k++){cout<<"Sblock["<<Sblock[((int)begin)].PN.Peak[k]<<"]: ";
                                                         Sblock[Sblock[((int)begin)].PN.Peak[k]].Vivod(cout);}
      }for(int k=0;k<Sblock[((int)begin)].PN.Number;k++){cout<<"Sblock["<<Sblock[((int)begin)].PN.Peak[k]<<"]: ";
                                                         Sblock[Sblock[((int)begin)].PN.Peak[k]].Vivod(cout);}

   return 0;
  }


void BLOCK::Vivod(std::ostream & cout)
  {
   if(State==-2)cout<<"Ячейка пуста."<<std::endl;
   if(State==1||State==0)
   {
    cout<<"State: "<<State<<" ,Number: "<<PN.Number<<" ,prevBlock: "<<PN.prevBlock<<" ,prevBranch: "<<PN.prevBranch<<std::endl
        <<"          ";
        for(int i=0;i<PN.Number;i++){cout<<"["<<PN.Peak[i]<<"]";}cout<<" || ";
        for(int i=0;i<2*N;i++){cout<<"{"<<PN.Next[i]<<"}";}cout<<std::endl;  
   }
   if(State==2)
   {cout<<"State: "<<State<<" ||";
    for(int k=0;(k<NBLOCKS)&&(SD.Data[k]!='\0');k++){cout<<((char)SD.Data[k]);}
    cout<<std::endl;
   }
  }



  Tint FileSystem::InCleanWriteBlock(int filenumber,const char * WR, int Kd,int pozic)
    {
     int twr=0;
     if(Node[filenumber].FirstBlock==-2)return -1;
        int insize=0;
        bool A=false;
        int pmass=Kd;
        int p;
        int tmp;
        int end=SearchNumberBloc(NBLOCKS,filenumber);


if(Sblock[Node[filenumber].FirstBlock].State==2)
        {pmass=0;
         p=Node[filenumber].FirstBlock;
            for(tmp=0;tmp<pozic;tmp++)if(Sblock[p].SD.Data[tmp]=='\0'){pozic=tmp;A=true;}
              
            for(tmp=pozic;tmp<(BLOCK_SIZE-1) && WR[twr]!='\0';twr++,tmp++)
                {   if(Sblock[p].SD.Data[tmp]=='\0')A=true;
                    Sblock[p].SD.Data[tmp]=WR[twr];
                    if(A)insize++;
                }if( (tmp==(BLOCK_SIZE-1))||A  )Sblock[p].SD.Data[tmp]='\0';
            
              if(tmp==(BLOCK_SIZE-1) && WR[twr]!='\0')
                        {pmass++;
                          p=AddBlockMemory(filenumber);
                          for(tmp=0; WR[twr]!='\0';twr++,tmp++)
                            {if(Sblock[p].SD.Data[tmp]=='\0')A=true;
                             Sblock[p].SD.Data[tmp]=WR[twr];
                             if(A)insize++;
                            }if( (tmp==(BLOCK_SIZE-1))||A  )Sblock[p].SD.Data[tmp]='\0';
                        }               

          Node[filenumber].Size+=insize;  
        return Tint(insize,pmass,tmp);        
        }
     
       p=SearchNumberBloc(pmass,filenumber);
       if(p==end){end=AddBlockMemory(filenumber);}
       for(tmp=0;tmp<pozic;tmp++)if(Sblock[p].SD.Data[tmp]=='\0'){pozic=tmp;A=true;}
              for(tmp=pozic;tmp<(BLOCK_SIZE-1) && WR[twr]!='\0';twr++,tmp++)
                {
                  if(Sblock[p].SD.Data[tmp]=='\0')A=true;
                  Sblock[p].SD.Data[tmp]=WR[twr];
                  if(A)insize++;
                }if( (tmp==(BLOCK_SIZE-1))||A  )Sblock[p].SD.Data[tmp]='\0';

                     if(tmp==(BLOCK_SIZE-1))
                        {
                          pmass++;
                          p=SearchNumberBloc(pmass,filenumber);
                          if(p==end){end=AddBlockMemory(filenumber);}                    
                          
                          for(tmp=0; WR[twr]!='\0';twr++,tmp++)
                            {if(Sblock[p].SD.Data[tmp]=='\0')A=true;
                             Sblock[p].SD.Data[tmp]=WR[twr];
                             if(A)insize++;
                            }if( (tmp==(BLOCK_SIZE-1))||A  )Sblock[p].SD.Data[tmp]='\0';
                        }

      Node[filenumber].Size+=insize;  
  return Tint(insize,pmass,tmp);
  }

 int FileSystem::SaveDisk()
  {
    std::ofstream file;
    file.open("MEMORY_DISK.txt",std::ios::trunc);
    for(int i=0;i<(NBLOCKS*(4*N+2)*4);i++)file<<((char *)Sblock)[i];
    for(int i=0;i<(2*4+128)*MAX_FILES;i++)file<<((char *)Node)[i];  
    return 0;
  }

  int FileSystem::ReadDisk()
  {
    FILE * file;
    file=fopen("MEMORY_DISK.txt","r");
    if(file==NULL)return -1;
    
    for(int i=0;i<(NBLOCKS*(4*N+2)*4);i++){((char*)Sblock)[i]=((char)fgetc(file));}
    for(int i=0;i<(2*4+128)*MAX_FILES;i++){((char*)Node)[i]=((char)fgetc(file));}  
    return 0;
  }

  int FileSystem::VivodAllNameFiles(std::ostream & cout)
  {
    int files=0;
    for(int i=0;i< MAX_FILES;i++)if(Node[i].FirstBlock!=-2)
         {cout<<"Имя файла["<<i<<"]:"<<Node[i].FileName<<" ,Размер файла:"
              <<Node[i].Size<<" ,Номер 1-ого блока:"<<Node[i].FirstBlock<<std::endl;files++;}
    if(files==0){cout<<"Файлов нет."<<std::endl;return -1;}
        cout<<"Имеется "<<files<<" файлов на данный момент."<<std::endl;
  return 0;          
  }

  void FileSystem::VivodFile(int filenumber,std::ostream & cout)
   {
    if(filenumber<0||filenumber>=MAX_FILES||Node[filenumber].FirstBlock==-2)cout<<"Файл с таким номером не сущестует.";
    else cout<<"Имя файла["<<filenumber<<"]:"<<Node[filenumber].FileName<<" ,Размер файла:"
              <<Node[filenumber].Size<<" ,Номер 1-ого блока:"<<Node[filenumber].FirstBlock;
   }

   int FileSystem::EmptyFile(int filenumber)
   {
    if(filenumber<0||filenumber>=MAX_FILES||Node[filenumber].FirstBlock==-2)return -1;
    return 0;
   }

  int FileSystem::SeachFiles(const char *fname)
   {
     for(int i=0;(i< MAX_FILES);i++)if(Node[i].FirstBlock!=-2)
       {
        if(strcmp(fname,Node[i].FileName)==0)return i;
       }  
    return -1;
   }

   //функции класс iterator

  FileSystem::iterator::iterator(int filenumber,BLOCK * Sblock,INode * Node)
                    {
                      if(Node[filenumber].FirstBlock==-2)throw -1;
                      if(Sblock[Node[filenumber].FirstBlock].State==2)throw -2;
                      this->filenumber=filenumber;numberblock=-1;
                      this->Sblock=Sblock;
                      this->Node=Node;
                    }

  FileSystem::iterator::iterator(const FileSystem::iterator & b)
                    {
                      filenumber=b.filenumber;
                      numberblock=b.numberblock;
                      Sblock=b.Sblock;Node=b.Node;
                    }

  void FileSystem::iterator::operator++()
                    {  
                       bool A=true;
                       int tmpj=0;
                       while(Sblock[numberblock].PN.prevBlock!=-1)
                       {
                         tmpj=Sblock[numberblock].PN.prevBranch;
                         numberblock=Sblock[numberblock].PN.prevBlock;
                         if(Sblock[numberblock].PN.Number>tmpj){A=false;break;}
                       }
                       if(A){while(Sblock[numberblock].PN.Next[Sblock[numberblock].PN.Number]!=-1)
                                    numberblock=Sblock[numberblock].PN.Next[Sblock[numberblock].PN.Number];}
                       else{
                            numberblock=Sblock[numberblock].PN.Next[tmpj+1];   
                            while(Sblock[numberblock].PN.Next[0]!=-1)numberblock=Sblock[numberblock].PN.Next[0];
                           }
                    }
  void FileSystem::iterator::operator++(int)
                    {
                       bool A=true;
                       int tmpj=0;
                       while(Sblock[numberblock].PN.prevBlock!=-1)
                       {
                         tmpj=Sblock[numberblock].PN.prevBranch;
                         numberblock=Sblock[numberblock].PN.prevBlock;
                         if(Sblock[numberblock].PN.Number>tmpj){A=false;break;}
                       }
                       if(A){while(Sblock[numberblock].PN.Next[Sblock[numberblock].PN.Number]!=-1)
                                    numberblock=Sblock[numberblock].PN.Next[Sblock[numberblock].PN.Number];}
                       else{
                            numberblock=Sblock[numberblock].PN.Next[tmpj+1];   
                            while(Sblock[numberblock].PN.Next[0]!=-1)numberblock=Sblock[numberblock].PN.Next[0];
                           }
                    }

FileSystem::iterator & FileSystem::iterator::operator=(const FileSystem::iterator & b)
                    {
                      Sblock=b.Sblock;
                      Node=b.Node;
                      numberblock=b.numberblock;
                      filenumber=b.filenumber;
                    return *this;
                    }

FileSystem::iterator FileSystem::iterator::End()
                    {
                      iterator it(filenumber,Sblock,Node);
                      it.numberblock=Node[filenumber].FirstBlock;
                      while(Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number]!=-1)
                                    it.numberblock=Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number];
                    return it;
                    }

FileSystem::iterator FileSystem::iterator::Begin()
                    {
                      iterator it(filenumber,Sblock,Node);
                      it.numberblock=Node[filenumber].FirstBlock;
                      while(Sblock[it.numberblock].PN.Next[0]!=-1)it.numberblock=Sblock[it.numberblock].PN.Next[0];
                    return it;
                    }


FileSystem::iterator FileSystem::Begin(int filenumber)
                        {
                          if(Node[filenumber].FirstBlock==-2)throw -1;
                          if(Sblock[Node[filenumber].FirstBlock].State==2)throw -2;
                          iterator it(filenumber,Sblock,Node);
                          it.numberblock=Node[filenumber].FirstBlock;
                          while(Sblock[it.numberblock].PN.Next[0]!=-1)it.numberblock=Sblock[it.numberblock].PN.Next[0];
                        return it;
                        }

FileSystem::iterator FileSystem::End(int filenumber)
                      {
                        if(Node[filenumber].FirstBlock==-2)throw -1;
                        if(Sblock[Node[filenumber].FirstBlock].State==2)throw -2;
                        iterator it(filenumber,Sblock,Node);
                        it.numberblock=Node[filenumber].FirstBlock;
                        while(Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number]!=-1)
                                        it.numberblock=Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number];
                      return it;
                      }

