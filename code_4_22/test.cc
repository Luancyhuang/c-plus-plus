#include <iostream>
using namespace std;

/*template<class T1,class T2>
class Data
{
public:
  Data()
  {
    cout << "Data<T1,T2>" << endl;
  }
private:
  T1 _d1;
  T2 _d2;
};

//全特化
template<>
class Data<int,char>
{
public:
  Data()
  {
    cout << "Data<int,char>" << endl;
  }
private:
  int _d1;
  char _d2;
};
//偏特化
template<class T1>
class Data<T1,char>
{
public:
  Data()
  {
    cout << "Data<T1,char>" << endl;
  }
private:
  int _d1;
  char _d2;
};

int main()
{
  Data<int,int> d1;
  Data<int,char> d2;

  Data<char,char> d3;
  Data<double,char> d4;

  return 0;
}*/

class A 
{
public:
  operator bool()
  {
    return _a != 0;
  }
//private:
  int _a;
};

int main()
{
  A a;
  while(a)
  {
    cin >> a._a;
  }

  return 0;
}

