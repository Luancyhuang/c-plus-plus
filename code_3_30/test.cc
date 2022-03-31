#include <iostream>
using namespace std;

//int count = 0;
/*class A
{
public:
  A(int a = 0)
   :_a(a)
  {
    ++_scount;
  }

  A(const A& aa)
   :_a(aa._a)
  {
    ++_scount;
  }

  //没有this 指针，只能访问静态的成员变量和静态成员函数
  static int GetCount()
  {
    //_a; 
    return _scount;
  }

private:
  int _a;

  //静态成员变量属于整个类，所有对象，生命周期在整个程序运行期间
  //类的成员函数中可以随便访问
  static int _scount;//声明
};

int A:: _scount = 0;//指定类域里面进行初始化（定义）


void f(A a)
{
  
}
int main()
{
  A a1;
  A a2 = 1;
  f(a1);
  cout << count << endl;
  count++;
  cout << count << endl;

  //类外面访问的方式：->public (公用）

  
  //cout << A::_scount << endl;
  //cout << a1._scount << endl;
  //cout << a2._scount << endl;
  cout << a1.GetCount() << endl;
  
  return 0;
}*/

/*class Sum
{
public:
  Sum()
  {
    _ret += _i;
    ++_i;
  }

  static int get_ret()
  {
    return _ret; 
  }

  static void Init()
  {
    _i = 1;
    _ret = 0;
  }

private:
  static int _i;
  static int _ret;
};

int Sum:: _i = 1;
int Sum:: _ret = 0;

class Solution
{
public:
  int sum_solution(int n)
  {
    //Sum a[n];
    Sum::Init();
    Sum* p = new Sum[n];
    delete [] p;
    return Sum::get_ret();  
  }
};


int main()
{
  //定义一个对象去调用一个成员函数
  Solution st;
  cout << st.sum_solution(10) << endl;
  //直接用匿名函数去调用一个成员函数
  cout << Solution().sum_solution(10) << endl;

  return 0;
}*/
class B
{
public:
  B(int b = 0)
   :_b(b)
   {}

private: 
  int _b;
};
//C++11
class A
{
//内置类型不处理，自定义类型处理
public:

  //A(int a1)
  // :_a1(a1)
  // {}

private:
  //要注意的是这里不是初始化，因为这里是声明，不能初始化
  int _a1 = 1;//不是定义，而是给成员变量缺省值
  B _bb;
};

int main()
{  
  A aa;

  return 0;
}
