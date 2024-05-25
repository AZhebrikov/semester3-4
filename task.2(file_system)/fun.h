#pragma once

#define BLOCK_SIZE 4*4*N+4
#define N 2
#define NBLOCKS 100000
#define MAX_FILES 1000
#define O(a) std::cout<<a<<std::endl;

union BLOCK;
class INode;
class FileSystem;


struct Tint
{
  int sz;
  int numb;
  int pz;

  Tint(){sz=numb=pz=0;}
  Tint(int i){sz=i;numb=0;pz=0;}
  Tint(int a,int b,int c){sz=a;numb=b;pz=c;}
  Tint(const Tint & b){sz=b.sz;numb=b.numb;pz=b.pz;}

  Tint & operator=(const Tint & b){sz=b.sz;numb=b.numb;pz=b.pz;return *this;}
  void XY(int & numberblock,int & pozic){numberblock=numb;pozic=pz;}
  operator int()const{return sz;}

};

union BLOCK
{
 private:
      int State;
   struct PN_{
      int State;
         int Number;
         int Peak[2*N-1];
         int Next[2*N];
         int prevBlock;
         int prevBranch;
     }PN;
   struct SD_{
      int State;
         char Data[BLOCK_SIZE];
     }SD;

 public:

   BLOCK (){State=-2;}

   void Vivod(std::ostream & cout);
   friend class FileSystem;
   friend std::ostream & operator<<(std::ostream & cout, FileSystem & FS);
   friend int main(void);
};

class INode
{
 char FileName[128];
 int Size;
 int FirstBlock;
  public:

 INode (){FileName[0]='\0';Size=0;FirstBlock=-2;}

 friend class FileSystem;
 friend std::ostream & operator<<(std::ostream & cout, FileSystem & FS);
 friend int main(void);
};

extern BLOCK _SBLOCK_[NBLOCKS];
extern INode _Node_[MAX_FILES];


 class FileSystem
 {
    BLOCK * Sblock;
    INode * Node;
    int ErrBlock;
    int ErrFile;
    int ErrWrite;
    int ErrSystem;
    int ErrRead;
 public:

 FileSystem (){ErrSystem=ErrWrite=ErrFile=ErrBlock=ErrRead=0;Sblock=_SBLOCK_;Node=_Node_;}

  class iterator
  {    BLOCK * Sblock;
       INode * Node;
       int numberblock;
       int filenumber;
    public:
       iterator(int filenumber,BLOCK * Sblock,INode * Node);/*{if(Node[filenumber].FirstBlock==-2)throw -1;
                                                            if(Sblock[Node[filenumber].FirstBlock].State==2)throw -2;
                                                              this->filenumber=filenumber;numberblock=-1;
                                                                     this->Sblock=Sblock;this->Node=Node;}*/
       iterator(const iterator & b);/*{filenumber=b.filenumber;numberblock=b.numberblock;
                                                                     Sblock=b.Sblock;Node=b.Node;}*/
       int operator!=(const iterator &b){return numberblock!=b.numberblock;}
       int operator==(const iterator &b){return numberblock==b.numberblock;}
       void operator++();/*
                    {  bool A=true;
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
                    }*/
       void operator++(int);/*
                    {  bool A=true;
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
                    }*/
       int operator*()const{return numberblock;}

       iterator & operator=(const iterator & b);/*
          {
            Sblock=b.Sblock;
            Node=b.Node;
            numberblock=b.numberblock;
            filenumber=b.filenumber;
            return *this;
          }*/

        iterator & operator=(int j){numberblock=j;return *this;}

       iterator End();/*
            {
              iterator it(filenumber,Sblock,Node);
              it.numberblock=Node[filenumber].FirstBlock;
              while(Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number]!=-1)
                                    it.numberblock=Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number];
              return it;
            }*/

      iterator Begin();/*
            {
              iterator it(filenumber,Sblock,Node);
              it.numberblock=Node[filenumber].FirstBlock;
              while(Sblock[it.numberblock].PN.Next[0]!=-1)it.numberblock=Sblock[it.numberblock].PN.Next[0];
              return it;
            }*/


      operator int()const{return numberblock;}

       friend class FileSystem;
       friend iterator Begin(int filenumber);
       friend iterator End(int filenumber);
//       friend std::ostream & operator<<(std::ostream & cout, FileSystem::iterator & it);

};
       iterator Begin(int filenumber);/*
                        {if(Node[filenumber].FirstBlock==-2)throw -1;
                         if(Sblock[Node[filenumber].FirstBlock].State==2)throw -2;
                         iterator it(filenumber,Sblock,Node);
                         it.numberblock=Node[filenumber].FirstBlock;
                         while(Sblock[it.numberblock].PN.Next[0]!=-1)it.numberblock=Sblock[it.numberblock].PN.Next[0];
                         return it;
                        }*/

       iterator End(int filenumber);/*
                      {if(Node[filenumber].FirstBlock==-2)throw -1;
                       if(Sblock[Node[filenumber].FirstBlock].State==2)throw -2;
                       iterator it(filenumber,Sblock,Node);
                       it.numberblock=Node[filenumber].FirstBlock;
                       while(Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number]!=-1)
                                    it.numberblock=Sblock[it.numberblock].PN.Next[Sblock[it.numberblock].PN.Number];
                       return it;
                      }*/



  int New_Block();
  int New_INode();
  int CreateFiles(const char * filename);
  int BrokenBlock(int brkblock);
  int expansion(int brkblock);
  int levelup(int filenumber);
  int AddBlockMemory(int filenumber);
  int DeleteFileAll(int filenumber);
  int EmptyFile(int filenumber);

  Tint InWriteBlock(int filenumber,const char * WR,int Kd=0,int pozic=0);
  Tint InCleanWriteBlock(int filenumber,const char * WR, int Kd=0,int pozic=0);

  int SearchNumberBloc(int k,int filenumber);
  int SeachPozic(int filenumber,int poz,int & pozic_, int & block_);
  int SeachFiles(const char *fname);

  int VivodAll(int filenumber,std::ostream & cout);
  int VivodAllNameFiles(std::ostream & cout);
  void VivodFile(int filenumber,std::ostream & cout);


  int SaveDisk();
  int ReadDisk();

  int printf(std::ostream & cout,int i){if(i<0||i>=NBLOCKS){return -1;}Sblock[i].Vivod(cout);return 0;}
  int ErrorChek(int a=0);

  friend iterator;
  friend std::ostream & operator<<(std::ostream & cout, FileSystem & FS);
  friend int main(void);
 };


std::ostream & operator<<(std::ostream & cout, FileSystem & FS);
