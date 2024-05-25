
class FabricCComplexVector;
struct CComplexNumber;
class CComplexVector;
class Fabric_;
class Vec_;
class ListName;

struct CComplexNumber
{
  double Re;
  double Im;

  void SetZero(){Re=Im=0;}

  CComplexNumber(){Re=0;Im=0;}
  CComplexNumber(double Re){this->Re=Re;Im=0;}
  CComplexNumber(double Re,double Im){this->Re=Re,this->Im=Im;}
  CComplexNumber(const CComplexNumber & b){this->Re=b.Re;this->Im=b.Im;}

  CComplexNumber  operator+(const CComplexNumber & a){return CComplexNumber (Re+a.Re,Im+a.Im);}
  CComplexNumber  operator-(const CComplexNumber & a){return CComplexNumber (Re-a.Re,Im-a.Im);}
  CComplexNumber& operator=(const CComplexNumber & a){Re=a.Re;Im=a.Im;return *this;}
  CComplexNumber  operator~(){return CComplexNumber (Re,-Im);}
  CComplexNumber& operator+=(const CComplexNumber & a){Re+=a.Re;Im+=a.Im;return *this;}
  CComplexNumber  operator*(const CComplexNumber& a){return CComplexNumber (Re*a.Re-Im*a.Im,Re*a.Im+Im*a.Re);}

  void Show();
  void Show(std::ofstream & f);

};

std::ostream& operator<<(std::ostream& cout,const CComplexNumber& b);

struct CComplexNumber_bas:public CComplexNumber
{
  CComplexVector* V_;
  size_t i;

  CComplexNumber_bas( const CComplexNumber& b,size_t i,CComplexVector* V_);//:CComplexNumber(b);
  CComplexNumber_bas&  operator=(const CComplexNumber& b);
};


class CComplexVector
{
private:

  CComplexNumber* V;
  size_t N;
  size_t MAX;

public:

  void SetZero(){N=0;MAX=0;V=NULL;}
  CComplexVector& move_CopyOnly(CComplexVector &b);
  CComplexVector& CopyOnly(const CComplexVector&b);
  void Clean();
  void emplase_new();

  CComplexVector(){SetZero();}
  CComplexVector(size_t N,size_t MAX,CComplexNumber* V);
  CComplexVector(const CComplexNumber & a);
  CComplexVector(const CComplexVector & b);
  CComplexVector(CComplexVector && b);
  ~CComplexVector(){Clean();}

  CComplexVector& operator=(const CComplexVector& b);
  CComplexVector& operator=(const CComplexNumber& b);
  CComplexVector& operator=(CComplexVector && b);
  CComplexVector  operator+(const CComplexVector& b);
  CComplexVector  operator-(const CComplexVector& b);
  CComplexNumber  operator*(const CComplexVector& b);
  CComplexVector  operator~();
  CComplexNumber_bas operator[](int i);

  int Add_push_back(double Re,double Im);
  int Add_push_back(CComplexNumber& b);
  int Del_pop_back();

  static int Input(std::vector<CComplexVector*>& Vec,std::vector<FabricCComplexVector* >& Fabric,ListName& vecname,const char* filename);
  virtual void Output();
  virtual void Show();

  friend std::ostream& operator<<(std::ostream& cout,const CComplexVector& b);
  friend class Vec_;
  friend class CComplexNumber_bas;

protected:

  CComplexNumber* ReturV()const{return V;}
  size_t  ReturN()const{return N;}
  size_t  ReturMAX()const{return MAX;}
  CComplexNumber*& ReturV_(){return V;}
  size_t & ReturN_(){return N;}
  size_t & ReturMAX_(){return MAX;}
};

std::ostream& operator<<(std::ostream& cout,const CComplexVector& b);

class FabricCComplexVector
{
public:
 FabricCComplexVector(){}
 virtual CComplexVector* Create(size_t N,size_t MAX,CComplexNumber* V,size_t i,std::vector<std::string>* fname) = 0;
 virtual ~FabricCComplexVector(){}
};

    class Fabric_
      {
          std::vector<FabricCComplexVector*> Fabric;
        public:
          Fabric_(){}
          ~Fabric_(){}
          friend class CComplexVector;
          std::vector<FabricCComplexVector*>& Retur_Fabric(){return Fabric;}
      };

    class Vec_
      {
          std::vector<CComplexVector*> Vec;
        public:
          Vec_(){}
          Vec_(std::vector<FabricCComplexVector* >& Fabric,ListName& vecname,const char* filename);
          ~Vec_(){for(size_t i=0;i<Vec.size();i++){delete Vec[i]->ReturV_();}}

          friend class CComplexVector;
          std::vector<CComplexVector*>& Retur_Vec(){return Vec;}
      };

    class ListName
      {
          std::vector<std::string> vecfname;
        public:
          friend class CComplexVector;
          size_t AddFile(const char* filename);
        protected:
          std::vector<std::string>& Retur_vecfname(){return vecfname;}
      };
