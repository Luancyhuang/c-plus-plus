#include <iostream>
using namespace std;
//字符串里面最后一个单词的长度
//计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
int main()
{
  string s;
  while(getline(cin,s))
  {
    size_t pos = s.rfind(' ');
    cout << s.size() - pos -1 << endl;
  }

  return 0;
}
