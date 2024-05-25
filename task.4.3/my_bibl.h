
class CComplexVector1;
class CComplexVector2;

class CComplexVector1:public CComplexVector
{
  size_t i;
  std::vector<std::string> * fname;
public:
  CComplexVector1(){SetZero();i=0;fname=NULL;}
  CComplexVector1(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname);
  CComplexVector1(const CComplexNumber & a,size_t i,std::vector<std::string>* fname);
  CComplexVector1(const CComplexVector & b,size_t i,std::vector<std::string>* fname);
  CComplexVector1(CComplexVector && b,size_t i,std::vector<std::string>* fname);
  ~CComplexVector1(){}

  CComplexVector1(const CComplexVector1 & b);
  CComplexVector1(CComplexVector1 && b);
  CComplexVector1(const CComplexVector2 & b);
  CComplexVector1(CComplexVector2 && b);

  double func1()const;//сумма первых координат
  double func2()const;//сумма вторых координат
  double func3()const;//попарная сумма координат
  double func4()const;//сумма разностей первой и второй координаты
  double func5()const;//сумма разностей второй и первой
  double func6()const;//сумма квадратов первых координат
  double func7()const;//сумма квадратов вторых координат
  double func8()const;//сумма квадратов всех координат

  virtual void Show_();
  virtual void Output_file(const char* filename);
  virtual void Output_();

  virtual void Show();
  virtual void Output();
  friend class CComplexVector2;
protected:
  size_t  Retur_i()const{return i;}
  size_t & Retur_i_(){return i;}
  std::vector<std::string>* Retur_fname()const{return fname;}
  std::vector<std::string>*& Retur_fname_(){return fname;}
};


class CComplexVector2:public CComplexVector
{
  size_t i;
  std::vector<std::string> * fname;
public:
  CComplexVector2(){SetZero();i=0;fname=NULL;}
  CComplexVector2(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname);
  CComplexVector2(const CComplexNumber & a,size_t i,std::vector<std::string>* fname);
  CComplexVector2(const CComplexVector & b,size_t i,std::vector<std::string>* fname);
  CComplexVector2(CComplexVector && b,size_t i,std::vector<std::string>* fname);
  ~CComplexVector2(){}

  CComplexVector2(const CComplexVector1 & b);
  CComplexVector2(CComplexVector1 && b);
  CComplexVector2(const CComplexVector2 & b);
  CComplexVector2(CComplexVector2 && b);

  double func1()const;//сумма первых координат
  double func2()const;//сумма вторых координат
  double func3()const;//попарная сумма координат
  double func4()const;//сумма разностей первой и второй координаты
  double func5()const;//сумма разностей второй и первой
  double func6()const;//сумма квадратов первых координат
  double func7()const;//сумма квадратов вторых координат
  double func8()const;//сумма квадратов всех координат


  virtual void Show_();
  virtual void Output_file(const char* filename);
  virtual void Output_();

  virtual void Show();
  virtual void Output();
  friend class CComplexVector1;
protected:
  size_t  Retur_i()const{return i;}
  size_t & Retur_i_(){return i;}
  std::vector<std::string>* Retur_fname()const{return fname;}
  std::vector<std::string>*& Retur_fname_(){return fname;}
};

class FabricCComplexVector1:public FabricCComplexVector
{
public:
  virtual CComplexVector* Create(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname);
};

class FabricCComplexVector2:public FabricCComplexVector
{
public:
  virtual CComplexVector* Create(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname);
};

class Fabric_1:public Fabric_
  {
  public:
    Fabric_1()
    {
     Retur_Fabric().push_back(new FabricCComplexVector1);
     Retur_Fabric().push_back(new FabricCComplexVector2);
    }
    ~Fabric_1()
    {
      delete Retur_Fabric()[0];
      delete Retur_Fabric()[1];
    }
  };

//-------------------------------------------
void Out_Put_Info(const char* filename,size_t MAX,int MAX_Number=1000,size_t MAX_Dlin=10,int MAX_clas=1);
void Output_OPM_senterFile(Vec_& VC,const char* filename);
