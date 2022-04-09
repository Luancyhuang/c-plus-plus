#include <iostream>
using namespace std;

/*int Add(int left,int right)
{
  return left + right;

}

template<class T1,class T2>
T2 Add(const T1& left,const T2& right)
{
  return left + right;
}

int main()
{
  int a1 = 10,a2 = 20;
  double d1 = 10.1,d2 = 20.2;

  cout << Add(a1,a2) << endl;
  cout << Add(d1,d2) << endl;
  
  cout << Add(a1,d2) << endl;


  return 0;
}*/

//类的模版
template<class T>
class Stack
{
public:
  Stack(int capacity = 4)
       :_top(0)
       ,_capacity(capacity)
  {
    _a = new T[capacity];
  }
  ~Stack()
  {
    delete[] _a;
    _a = nullptr;
    _capacity = _top = 0;
  }
  void Push(const T& x);//类里面声明)

private:
  T* _a;
  int _top;
  int _capacity;
};
//类外面定义
//需要指定类域范围
//类模版,不是一个普通类
template<class T>
void Stack<T>::Push(const T& x)
{
  //...

}

int main()
{
  //显示支持实例化
  Stack<int> st1;//存储int
  Stack<double> st2;//存储double
  Stack<char> st3;//存储char
  Stack<int*> st4;//存储int*
  
  st1.Push(1);
  return 0;
}
