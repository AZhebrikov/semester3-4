#include <iostream>
#include "fun.h"

 CListShell::CListShell( CList & innerset, CList & convexhull,int modification)
 {O("CListShell");
  if(modification==0||modification==2)
      InnerSet=innerset;
  else{
       InnerSet.t=innerset.t;
       InnerSet.begin=innerset.begin;
       InnerSet.cur=innerset.cur; 
       InnerSet.end=innerset.end; 
       InnerSet.start=innerset.start; 
       InnerSet.finish=innerset.finish;
       InnerSet.Size=innerset.Size;
       innerset.SetZero();
      }
  if(modification==0||modification==1)
      ConvexHull=convexhull;
  else
      {
       ConvexHull.t=convexhull.t;
       ConvexHull.begin=convexhull.begin;
       ConvexHull.cur=convexhull.cur; 
       ConvexHull.end=convexhull.end; 
       ConvexHull.start=convexhull.start; 
       ConvexHull.finish=convexhull.finish;
       ConvexHull.Size=convexhull.Size;
       convexhull.SetZero();
      }
  
  ConvexHull.AllSortXY();
  ConvexHull.DeleteCopyCPoint();
  InnerSet.AllSortXY();
  InnerSet.DeleteCopyCPoint();
 }
 
 int CListShell::ConvexHull_Move_InnerSet()
 {
  if(ConvexHull.t==NULL||ConvexHull.begin==EMPTY)return -1;
  ConvexHull.GoToEnd();
  for(ConvexHull.GoToEnd();ConvexHull.cur!=EMPTY;ConvexHull.DeleteCur())InnerSet>>ConvexHull.t[ConvexHull.cur];
  InnerSet.AllSortXY();
  InnerSet.DeleteCopyCPoint();
 return 0;
 }
 

 int CListShell::ConvexHull_OneMove_InnerSet()
  {
   if(ConvexHull.t==NULL||ConvexHull.begin==EMPTY)return -1;
   InnerSet.AddBeginPrev(ConvexHull.t[ConvexHull.cur]);
   ConvexHull.DeleteCur();
   return 0;
  }
  
 int CListShell::InnerSet_OneMove_ConvexHull()
 {
  if(InnerSet.t==NULL||InnerSet.begin==EMPTY)return -1;
  ConvexHull.AddBeginPrev(InnerSet.t[InnerSet.cur]);
  InnerSet.DeleteCur();
  return 0;
 }

 int CListShell::DeleteCPointInnerSet(const CPoint & b)
 {
  if(InnerSet.t==NULL||InnerSet.begin==EMPTY)return -2;
  if(InnerSet.SearchCPoint(b)==-1)return -1;
  InnerSet.DeleteCur();
 return 0;
 }

 int CListShell::DeleteCPointConvexHull(const CPoint & b)
 {
  if(ConvexHull.t==NULL||ConvexHull.begin==EMPTY)return -2;
  if(ConvexHull.SearchCPoint(b)==-1)return -1;
  ConvexHull.DeleteCur();
  ShellBuiling();
  return 0;
 }
 
 int CListShell::DeleteCPointSet(const CPoint & b)
 {
  if(InnerSet.t==NULL||InnerSet.begin==EMPTY)return -2;
  if(ConvexHull.t==NULL||ConvexHull.begin==EMPTY)return -2;	
  if(DeleteCPointInnerSet(b)==-1)return DeleteCPointConvexHull(b);
  return 0;
 }

int CListShell::InnerSetNumber()const
{

 return InnerSet.NumberPoints(); 
}

int CListShell::ConvexHullNumber()const
{
 return ConvexHull.NumberPoints(); 
}

int CListShell::AddCPoint(const CPoint & b)
{
 if(InnerSet.SearchCPoint(b)==0||ConvexHull.SearchCPoint(b)==0)return -1;
 InnerSet>>(b);
 ShellBuiling();
 return 0;
}



int CListShell::ShellBuiling()
 {
  bool event=false;
  ConvexHull_Move_InnerSet();
  
  if(InnerSet.begin==EMPTY)return -1;
  InnerSet.SortX();
      InnerSet.GoToBegin();
      (ConvexHull<<InnerSet.t[InnerSet.cur]).GoToEnd();
      InnerSet.DeleteCur();
  if(InnerSet.begin==EMPTY)return 0;

  
  
  do{
     if(InnerSet.t[InnerSet.cur].x==ConvexHull.t[ConvexHull.cur].x)
         {
          if(InnerSet.t[InnerSet.cur].y>ConvexHull.t[ConvexHull.cur].y)
          {
           int tmp;
               tmp=ConvexHull.t[ConvexHull.cur].y;
               ConvexHull.t[ConvexHull.cur].y=InnerSet.t[InnerSet.cur].y;
               InnerSet.t[InnerSet.cur].y=tmp;
          }
         }
     else 
         {
          event = true;
          break;    
         }
    }while(InnerSet.CurNext()!=EMPTY);



  if(event)
  {
   (ConvexHull<<InnerSet.t[InnerSet.cur]).GoToEnd();
   if(InnerSet.begin==InnerSet.cur)InnerSet.DeleteCur();
   else{InnerSet.DeleteCur();InnerSet.CurNext();}
   if(InnerSet.begin==EMPTY)event=false;         
  }


  if(event)
   {
      do{
         n1:
         

         if(InnerSet.t[InnerSet.cur].x==ConvexHull.t[ConvexHull.cur].x)
          {
              if(InnerSet.t[InnerSet.cur].y>ConvexHull.t[ConvexHull.cur].y)
              {

               int tmp;
                   tmp=ConvexHull.t[ConvexHull.cur].y;
                   ConvexHull.t[ConvexHull.cur].y=InnerSet.t[InnerSet.cur].y;
                   InnerSet.t[InnerSet.cur].y=tmp;
                
     			if(ConvexHull.t[ConvexHull.cur].prev==ConvexHull.begin){continue;}
     			do{
     				if(
     					TanTwoCPoint(ConvexHull.t[ConvexHull.t[ConvexHull.GetCurPrev()].prev],ConvexHull.t[ConvexHull.GetCurPrev()])
                                                                                                                                    >=
                            TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurPrev()],ConvexHull.t[ConvexHull.cur])
                      )break;
     			 	ConvexHull.CurPrev();
     			    InnerSet.AddBeginPrev(ConvexHull.t[ConvexHull.cur]);
     			    ConvexHull.DeleteCur();
     			    ConvexHull.GoToEnd();

     			}while(ConvexHull.t[ConvexHull.GetCurPrev()].prev!=EMPTY);

              }
              continue;
     	   }
              
              
          
        
         for(;
              (ConvexHull.GetCurPrev()!=ConvexHull.begin)&&
               (
               TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurPrev()],ConvexHull.t[ConvexHull.cur])
                                                                                              <
                            TanTwoCPoint(ConvexHull.t[ConvexHull.cur],InnerSet.t[InnerSet.cur])
               );)
                  {ConvexHull_OneMove_InnerSet();}
         
         if(ConvexHull.GetCurPrev()==ConvexHull.begin)
         { 
          
           if(
              TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurPrev()],ConvexHull.t[ConvexHull.cur])
                                                                                             <
                           TanTwoCPoint(ConvexHull.t[ConvexHull.cur],InnerSet.t[InnerSet.cur])
             ){
               int tmp;
               tmp=ConvexHull.t[ConvexHull.cur].x;
               ConvexHull.t[ConvexHull.cur].x=InnerSet.t[InnerSet.cur].x;
               InnerSet.t[InnerSet.cur].x=tmp;
                  tmp=ConvexHull.t[ConvexHull.cur].y;
                  ConvexHull.t[ConvexHull.cur].y=InnerSet.t[InnerSet.cur].y;
                  InnerSet.t[InnerSet.cur].y=tmp;
              } 
           else
              {
               (ConvexHull<<InnerSet.t[InnerSet.cur]).GoToEnd();
               if(InnerSet.begin==InnerSet.cur&&InnerSet.begin==InnerSet.end){InnerSet.DeleteCur();return 0;}
               else if(InnerSet.begin==InnerSet.cur){InnerSet.DeleteCur();goto n1;}
               else InnerSet.DeleteCur();
              } 
         }
         else
         {
          (ConvexHull<<InnerSet.t[InnerSet.cur]).GoToEnd();
          if(InnerSet.begin==InnerSet.cur&&InnerSet.begin==InnerSet.end){InnerSet.DeleteCur();return 0;}
          else if(InnerSet.begin==InnerSet.cur){InnerSet.DeleteCur();goto n1;}
          else InnerSet.DeleteCur();
         }
    
        }while(InnerSet.CurNext()!=EMPTY);
     event=false;
    }
   


    if(InnerSet.begin==EMPTY)return 0;
    	InnerSet.SortX();
    	InnerSet.GoToBegin();
    	ConvexHull.GoToBegin();
    
    int start=ConvexHull.begin;
    
    if(InnerSet.t[InnerSet.cur].x==ConvexHull.t[ConvexHull.cur].x)
       {
        (ConvexHull>>InnerSet.t[InnerSet.cur]).GoToBegin();
        InnerSet.DeleteCur();start=ConvexHull.begin;
       
          do{
             if(InnerSet.t[InnerSet.cur].x==ConvexHull.t[ConvexHull.cur].x)
             {
                if(InnerSet.t[InnerSet.cur].y<ConvexHull.t[ConvexHull.cur].y)
                {
                 int tmp;
                      tmp=ConvexHull.t[ConvexHull.cur].y;
                      ConvexHull.t[ConvexHull.cur].y=InnerSet.t[InnerSet.cur].y;
                      InnerSet.t[InnerSet.cur].y=tmp;
                }
             }
             else 
             {
              event = true;
              break;    
             }
            }while(InnerSet.CurNext()!=EMPTY);

       }
       else event=true;
 

 if(event)
    {
        (ConvexHull>>InnerSet.t[InnerSet.cur]).GoToBegin();
 
          if(InnerSet.begin==InnerSet.cur&&InnerSet.begin==InnerSet.end){InnerSet.DeleteCur();goto n2;}
          else if(InnerSet.begin==InnerSet.cur){InnerSet.DeleteCur();goto n3;}
          else InnerSet.DeleteCur();
        
        while(InnerSet.CurNext()!=EMPTY)
          {
           n3:
           

           if(InnerSet.t[InnerSet.cur].x==ConvexHull.t[ConvexHull.cur].x)
             {
                 if(InnerSet.t[InnerSet.cur].y<ConvexHull.t[ConvexHull.cur].y)
                 {
                   int tmp;
                      tmp=ConvexHull.t[ConvexHull.cur].y;
                      ConvexHull.t[ConvexHull.cur].y=InnerSet.t[InnerSet.cur].y;
                      InnerSet.t[InnerSet.cur].y=tmp;
                 
                   if(ConvexHull.t[ConvexHull.cur].next==start){continue;}
     			   do{
     				  if(
     			  		TanTwoCPoint(ConvexHull.t[ConvexHull.t[ConvexHull.GetCurNext()].next],ConvexHull.t[ConvexHull.GetCurNext()])
                                                                                                                                    <=
                            TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurNext()],ConvexHull.t[ConvexHull.cur])
                      )break;
     			 	ConvexHull.CurNext();
     			    InnerSet.AddBeginPrev(ConvexHull.t[ConvexHull.cur]);
     			    ConvexHull.DeleteCur();
     			    ConvexHull.GoToBegin();

     			   }while(ConvexHull.GetCurNext()!=start);

                 }
                 continue;
             }
        
           for(;(ConvexHull.GetCurNext()!=start)&&
                (
                 TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurNext()],ConvexHull.t[ConvexHull.cur])
                                                                                                >
                              TanTwoCPoint(ConvexHull.t[ConvexHull.cur],InnerSet.t[InnerSet.cur])
                );)
                {ConvexHull_OneMove_InnerSet();}
         
           if(ConvexHull.GetCurNext()==start)
           {
             if(
                TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurNext()],ConvexHull.t[ConvexHull.cur])
                                                                                               >
                             TanTwoCPoint(ConvexHull.t[ConvexHull.cur],InnerSet.t[InnerSet.cur])
               ){

                 int tmp;
                  tmp=ConvexHull.t[ConvexHull.cur].x;
                  ConvexHull.t[ConvexHull.cur].x=InnerSet.t[InnerSet.cur].x;
                  InnerSet.t[InnerSet.cur].x=tmp;
                    tmp=ConvexHull.t[ConvexHull.cur].y;
                    ConvexHull.t[ConvexHull.cur].y=InnerSet.t[InnerSet.cur].y;
                    InnerSet.t[InnerSet.cur].y=tmp;
                    
                }
             else
             {
               (ConvexHull>>InnerSet.t[InnerSet.cur]).GoToBegin();
               if(InnerSet.begin==InnerSet.cur&&InnerSet.begin==InnerSet.end){InnerSet.DeleteCur();goto n2;}
               else if(InnerSet.begin==InnerSet.cur){InnerSet.DeleteCur();goto n3;}
               else InnerSet.DeleteCur();
        
             } 
           }
           else
           {
            (ConvexHull>>InnerSet.t[InnerSet.cur]).GoToBegin();
              if(InnerSet.begin==InnerSet.cur&&InnerSet.begin==InnerSet.end){InnerSet.DeleteCur();goto n2;}
              else if(InnerSet.begin==InnerSet.cur){InnerSet.DeleteCur();goto n3;}
              else InnerSet.DeleteCur();
           }
        }
    }
     
     n2:
     if(ConvexHull.t[ConvexHull.cur].x!=ConvexHull.t[ConvexHull.end].x)
      {
       for(;(ConvexHull.cur!=start)&&
            (
             TanTwoCPoint(ConvexHull.t[ConvexHull.GetCurNext()],ConvexHull.t[ConvexHull.cur])
                                                                                            >
                      TanTwoCPoint(ConvexHull.t[ConvexHull.cur],ConvexHull.t[ConvexHull.end])
            );)
              {ConvexHull_OneMove_InnerSet();}
      }
      
      if(InnerSet.begin==EMPTY)return 0;
      event=true;
      InnerSet.AllSortXY();InnerSet.GoToBegin();ConvexHull.cur=start;
      while(event)
      {
      	 if(InnerSet.t[InnerSet.cur].x==ConvexHull.t[ConvexHull.cur].x)
      	 	{ConvexHull.AddAfter(InnerSet.t[InnerSet.cur]);
      	 	 ConvexHull.CurNext();
      	 	 InnerSet.DeleteCur();
      	 	 if(InnerSet.cur==EMPTY)event=false;
      	 	}
      	 else break;	
      }

      InnerSet.GoToEnd();
      ConvexHull.GoToBegin();
      bool B=false;

      while(event)
      {
      	if(InnerSet.t[InnerSet.end].x==ConvexHull.t[ConvexHull.end].x)
      	{
      		if(B)
      		{
      		 ConvexHull.AddBeginPrev(InnerSet.t[InnerSet.end]);
      		 ConvexHull.GoToBegin();
      		 ConvexHull.SwapCurNext();
      		 InnerSet.DeleteCur();
      		 if(InnerSet.cur==EMPTY)event=false;
      		}
      		else
      	    {
      	     ConvexHull.AddBeginPrev(InnerSet.t[InnerSet.end]);
      	     InnerSet.DeleteCur();
      	     B=true;
      	     if(InnerSet.cur==EMPTY)event=false;
      	    }
      	}
      	else break;
      }
   
   return 0;
 }

