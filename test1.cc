#include <iostream>
using namespace std;

#include <string>

class Solution
{
public:
  string reverseOnlyLetters(string s)
  {
    size_t begin = 0;
    size_t end = s.size() - 1; 
    
    while(begin < end)
    {
      while((begin < end) && !isalpha(s[begin])) 
      {
        ++begin;      
      }

      while((begin < end) && !isalpha(s[end])) 
      {
        --end;
      }
      
      swap(s[begin],s[end]);      
      
      ++begin;
      --end;
    }

    return s;
  }
};

int main()
{
  //Solution st;

  string s1("abcd-efg");
  string s2("abcd1efg");
  
  cout << Solution().reverseOnlyLetters(s1) << endl;//匿名对象直接调取
  cout << Solution().reverseOnlyLetters(s2) << endl;

  return 0;
}
