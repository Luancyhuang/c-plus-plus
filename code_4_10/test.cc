#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void test_string1()
{
  string s1("hello,world");
  //遍历+修改
  //下标+【】
  for(size_t i = 0;i < s1.size(); ++i)
  {
    cout << s1[i] << " ";  
  }
  cout << endl;
  //访问形式1:数组+[]下标的方式
  //访问形式2:迭代器
  string::iterator it = s1.begin();
  while(it != s1.end())
  {
     *it -= 1;
     ++it; 
  }

  cout << endl;

  it = s1.begin();
  while(it != s1.end())
  {
    cout << *it << " ";
    ++it; 
  }
  cout << endl;
  //访问形式3:范围for,自动往后迭代，自动判断结束
  for(auto e: s1)
  {
    cout << e << " ";
  }
  cout << endl;
}
//反向迭代器
void test_string2()
{
  
  string s1("hello,world");
  
  //string::reverse_iterator rit = s1.rbegin();
  auto rit = s1.rbegin();//auto 自动推导
  while(rit != s1.rend())
  {
    cout << *rit << " ";
    ++rit;
  }
  cout << endl; 

  list<int> lt(10,5);
  list<int>::iterator LtIt = lt.begin();
  while(LtIt != lt.end())
  {
    cout << *LtIt << " ";
    ++LtIt;
  }
  cout << endl;
}

void TestPushBack()
{
  string s;
  size_t sz = s.capacity();
  s.reserve(1000);//申请至少能存储1000个字符的空间

  cout << "capacity changed:" << sz << '\n';
  cout << "makint s grow:\n";
  for(int i=0;i<100;++i)
  {
    s += 'c';  
    if(sz != s.capacity())
    {
      sz = s.capacity();
      cout << "capacity changed:" << sz << '\n';
    }
  }
}

void test_string3()
{
  string s1;
  s1.reserve(100);
  
  string s2;
  s2.resize(200,'x');
}

void test_string4()
{
  string s("hello,world");
  
  cout << s << endl;
  cout << s.c_str() << endl;
  
  string file("file.txt.zip");
  FILE* f = fopen(file.c_str(),"w");
  size_t pos = file.rfind('.');
  if(pos != string::npos)
  {
    string suffix = file.substr(pos,file.size() - pos);
    cout << suffix << endl;
  }
  
  //https://www.cplusplus.com/reference/string/string/find/
  string url("https://www.cplusplus.com/reference/string/string/find/");
  size_t pos1 = url.find(':');
  string protocol =  url.substr(0,pos1 - 0);
  cout << protocol << endl;

  size_t pos2 = url.find('/',pos1 + 3);
  string domain = url.substr(pos1 + 3,pos2 - (pos1+3));
  cout << domain << endl;


  string uri = url.substr(pos2+1);
  cout << uri << endl;
  
}
 
void  test_string5()
{
  //头插，效率，O(N),尽量少用

  string s("hello,world");
  s.insert(0,1,'x');
  cout << s << endl;
  
  s.insert(s.begin(),'y');
  cout << s << endl;
  
  s.insert(0,"txt");
  cout << s << endl;
  
  s.insert(4,"&&&&&&");
  cout << s << endl;

}

void test_string6()
{ 
  //尽量少用头部和中间的删除，因为要挪动数据，效率低
  string s("hello,world");
  s.erase(0,1);
  s.erase(s.size() - 1 ,1);
  cout << s << endl;

}

int main()
{
  //test_string1();
  //test_string2();
  
  //TestPushBack();
  //test_string3();
 // test_string4();
  //test_string5();
  test_string6();
 
 return 0;
}
