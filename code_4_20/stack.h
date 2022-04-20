#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <list>


//适配器模式
namespace hxw
{
  template<class T,class Container>

  class stack
  {
  public:
    bool empty() const
    {
      return _con.empty();
    }
    
    size_t size() const
    {
      return  _con.size();    
    }
    
    const T& top()//取栈顶的元素
    {
      return _con.back();    
    }

    void push(const T& x)
    {
      _con.push_back(x);

    }

    void pop()
    {
      _con.pop_back();
    }
  
  private:
   // vector<T> _v;
    Container _con;
  };
  
  void test_stack()
  {
    //后进先出--不支持迭代器
    stack<int,std::vector<int>> s;//数组栈
    //stack<int,std::list<int>> s;//链表栈
    //stack<int> s;
    //stack<int,string> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    //s.pop();
    while(!s.empty())
    {
      cout << s.top() << " ";
      s.pop();    
    }
    cout << endl;
  }
}
