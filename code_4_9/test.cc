#include <iostream>
using namespace std;

template<class T>
class  basic_string
{
private:
  T* _str;
  //...
};

//b编码--值 == 符号建立映射关系--编码表 ASCII 表
//typedef basic_string<char> string;
//unicode 表示的是全世界文字编码表 utf -8 utf - 16 utf -32
//gbk --中文自身制作的编码表

/*int main()
{
  //string s1("hello"); 
  char str1[] = "hello";
  char str2[] = "吃饭";
  
  //cout << str << endl;
  str2[1] += 1;
  str2[3] += 1;

  str2[1] += 1;
  str2[3] += 1;

  str2[1] += 1;
  str2[3] += 1;
  
  cout << sizeof(char) << endl;
  cout << sizeof(wchar_t) << endl;

  return 0;
}*/

#include <string>
/*int main()
{
  string s1;
  string s2("hello,world");
  string s3(s2);

  cin >> s1;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  
  string s4(s2,2,4);
  cout << s4 << endl;

  string s5(s2,2);
  cout << s5 << endl;
  
  string s6(s2,2,100);
  cout << s6 << endl;
  
  string s7("hello,world",2);
  cout << s7 << endl;
  
  string s8(10,'!');
  cout << s8 << endl;

  return 0;
}*/

/*int main()
{
  string s1;
  cin >> s1;
  //length 不包含‘\0',计算的是有效字符的长度，不包含作为结尾标识符的'\0‘
  cout << s1.size() << endl;
  cout << s1.length() << endl;
  cout << s1.max_size() << endl;
  
  cout << s1.capacity() << endl;

  s1.clear();
  cout << s1 << endl;
  cout << s1.capacity() << endl;

  return 0;
}*/

/*int main()
{
  string s1("hello,world");
  cout << s1 << endl;
  //可以读operator
  for(size_t i = 0;i < s1.size();++i)
  {
   //这里的引用返回不是为了减少拷贝，而是为了支持修改返回的对象
    cout << s1.operator[](i) << " ";
    cout << s1[i] << " ";  
  }
  cout << endl;
  //可以写operator 
  for(size_t i = 0;i < s1.size();++i)
  {
    s1[i] += 1;    
  }

  cout << endl;
  cout << s1 << endl;
  
  for(size_t i = 0;i<s1.size();++i)
  {
    s1.at(i) -= 1;
  }
  
  cout << endl;
  cout << s1 << endl;
  
  s1[100];//operator[] 报错的机制就是assert 断言的方式，简单粗暴
  
  try
  {
    s1.at(100);//抛异常的机制报错
  }
  catch(exception &e)
  {
    cout << e.what() << endl;
  }

  return 0;
}*/

int main()
{
  
  string s1;
  s1.push_back('a');
  s1.append("bcde");
  
  cout << s1 << endl;
  s1 += ':';
  s1 += "hello,world";
  cout << s1 << endl;

  return 0;
}








