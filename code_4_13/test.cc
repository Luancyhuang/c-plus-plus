#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//void test_string()
//{
//  string s1("hello");
//  s1 += '\0';
//  s1 += "world";
//
//  cout << s1 << endl;
//  cout << s1.c_str() << endl;
//
//}

void test_vector1()
{
  vector<int> v1;
  vector<int> v2(10,8);
  vector<int> v3(++v2.begin(),--v2.end());

  vector<int> v4(v3);
  
  string s("hello world");
  vector<char> v5(s.begin(),s.end());

}

void test_vector2()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  //遍历
  for(size_t i=0;i<v.size();++i)
  {
    cout << v[i] << " ";
  }

  cout << endl;
  //迭代器
  vector<int>:: iterator it = v.begin();
  while(it != v.end())
  {
    cout << *it << " "; 
    ++it;
  }
  cout << endl;

  //范围for
  for(auto e: v)
  {
    cout << e << " ";
  }
  cout << endl;
  
  int a[] = {1,2,3};
  //原生指针就是天然的迭代器，数组支持范围for,会被替换成指针
  for(int* p = a; p < a + sizeof(a)/sizeof(int); ++p)
  {
  }
}

void test_vector3()
{
  vector<int> v;
  
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
   
  cout << v.max_size() << endl;
  
  v.reserve(100);//扩容
  v.resize(100);//扩容+初始化
  v.resize(2);

}

void test_vector4()
{
  vector<int> v; 
  
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  
  vector<int>::iterator ret = find(v.begin(),v.end(),3);
  if(ret != v.end())
  {
    cout << "找到了" << endl;    
    v.insert(ret,30);
    v.erase(ret);//不能在这里删，失效了，迭代器失效了
  }
   
  vector<int>::iterator pos = find(v.begin(),v.end(),3);
  if(pos != v.end())
  {
    v.erase(pos);  
  }

  v.insert(v.begin(),-1);
  v.clear();
  for(auto e: v)
  {
    cout << e << " ";
  }
  cout << endl;
}

int main()
{
  //test_string();
  //test_vector1()
  
  //test_vector2();
  //test_vector3();
  test_vector4();
  
  return 0;
}


