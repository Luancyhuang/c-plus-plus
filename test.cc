#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

void test_string1()
{
  string s1("hello,world");
  //遍历+修改
  //方式1:数组下标
  //
  for(size_t i = 0; i < s1.size(); ++i)
  {
    cout << s1[i] << " ";
  }
  cout << endl;
  
  //方式2:迭代器
  string::iterator it = s1.begin();
  while(it != s1.end())
  {
    *it += 1;
    ++it;
  }
  cout << endl;

  it = s1.begin();//再次初始化
  while(it != s1.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  
  //方式3:语法糖--范围for,自动往后迭代，自动判断结束
  
  for(auto& e : s1)
  {
    e -= 1;
  }
  
  for(auto e : s1)
  {
    cout << e << " ";  
  }
  cout << endl;  
}

void func(const string& s)
{
  auto it = s.begin();

  while(it != s.end())
  {
    //*it -= 1;
    cout << *it << " ";
    ++it;
  }

  cout << endl;
}


void test_string2()
{
  string s1("hello,world");

  //string::reverse_iterator rit = s1.rbegin();
  auto rit = s1.rbegin();
  
  while(rit != s1.rend())
  {
    cout << *rit << " ";
    ++rit;
  }

  cout << endl;
   
  list<int> Lt(10,5);
  list<int>::iterator LtIt = Lt.begin();

  while(LtIt != Lt.end())
  {
    cout << *LtIt << " ";
    ++LtIt; 
  }
  cout << endl;   
  
  string str("hello,world");
  func(str); 
}

void TestPushBack()
{
  string s;
  
  s.reserve(100);//至少申请100个数据空间
  
  size_t sz = s.capacity();
  
  cout << "sz->capacity: " << sz << '\n';    
  
  cout << "making s grow:\n";
  
  for(int i = 0; i < 100; ++i)
  {
  
    //s.pushback('c');
    s += 'c';

    if(sz != s.capacity())
    {
      sz = s.capacity();
      cout << "capacity changed: " << sz << '\n';    
    }
  }
}

void test_string3()
{
  string s1;
  s1.reserve(100);
  
  string s2;
  s2.resize(100,'x');

  string s3("hello,world");
  s3.reserve(100);

  string s4("hello,world");
  s4.resize(100,'x');

  string s5("hello,world");
  s5.resize(5);

}

void test_string4()
{
  string s("hello,world");
  
  cout << s << endl;
  //cout << s.operator<<() << endl;
  cout << s.c_str() << endl;
   
  string file("test.txt.zip");

  FILE* fout = fopen(file.c_str(),"w");
  
  size_t pos = file.rfind('.');

  //npos是string 里的一个静态变量 返回值是size_t， 值是-1
  if(pos != string::npos)
  {
    //string suffix = file.substr(pos,file.size() - pos);  
    string suffix = file.substr(pos);  
    
    cout << suffix << endl;
  }

  string url("https://www32.cplusplus.com/reference/string/string/find/");
  
  size_t pos1 = url.find(':');
  string protocol = url.substr(0,pos1 - 0);
  cout << protocol << endl;

  size_t pos2 = url.find('/',pos1 + 3);
  string domain = url.substr(pos1 + 3,pos2 - (pos1 + 3));
  cout << domain << endl;
  
  string resource  = url.substr(pos2 + 1);
  cout << resource << endl;

}

void test_string5()
{
  string s("hello,world");

  s += ' ';
  s += "!!!!";
  cout << s << endl;
  
  //头插，效率是O（N） 尽量少用
  s.insert(s.begin(),1,'x');
  cout << s << endl;
}

void test_string6()
{
  string s("hello,world");
  
  //尽量少用头部和中间的删除，因为要挪动数据，效率低
  s.erase(0,1);
  s.erase(s.size() - 1, 1);
  cout << s << endl;

  s.pop_back();
  cout << s << endl;
}

void test_string7()
{
  string s;

  getline(cin,s);

  size_t pos = s.rfind(' ');
  if(pos == string::npos)
  {
    cout << s.size() << endl;  
  }
  else
  {
    cout << s.size() - pos - 1;  
  }
  cout << '\n';
}

int main()
{
  //test_string1();
  //test_string2();
  
  //test_string3();
  //test_string4();
  //test_string5();
  //test_string6();
  test_string7();
  
  //TestPushBack();  

  return 0;
}

