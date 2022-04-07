#include <iostream>
using namespace std;
/*void f()
{
  //跟malloc的用法是一样的
  //Stack* pst1 = (Stack*)operator new (sizeof(stack));
  char* p1 = (char*)malloc(0x7fffffff);
  if(p1 == nullptr)
  {
    printf("malloc fail\n");  
  }
  
  char* p2 = new char[0x7fffffff];
  
  cout << "hello,world" << endl;

}

int main()
{
  
  //printf("hello,world\n");
  //cout << "hello,wolrd" << endl;
  
  try
  {
    f();
  }
  catch(const exception& e)
  {
    cout << e.what() << endl;  
  }

  return 0;
}*/
//函数模版
//模版实例化
template<class T>// template(typename T) 模版参数列表--参数类型
/*void Swap(T& x1,T& x2) // 函数参数列表--参数对象
{
  T x = x1;
  x1 = x2;
  x2 = x;
}

int main()
{
  
  int a = 0,b = 1;
  double c = 1.1,d = 2.22;
  Swap(a,b);
  Swap(c,d);
  
  char e = 'A',f = 'B';
  Swap(e,f);

  return 0;
}*/
//参数既可以做参数，也可以做返回类型
T Add(const T& left,const T& right)
{
  return left + right;
}

int main()
{
  int a1 = 10,a2 = 20;
  double d1 = 10.1,d2 = 20.2;
  
  cout << Add(a1,a2) << endl;
  cout << Add(d1,d2) << endl;

  cout << Add((double)a1,d2) << endl;
  cout << Add<int>(a1,d2) << endl;//显示实例化
  cout << Add<double>(a1,d2) << endl;
  


  return 0;
}

