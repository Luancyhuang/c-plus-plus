#include <iostream>
using namespace std;

#include <string>

class Solution
{
public:
  int firstUniqChar(string s)
  {
    int CountArr[26] = {0};

    for(size_t i = 0; i < s.size(); ++i)
    {
      CountArr[s[i] - 'a']++;    
    }

    for(int j = 0; j < s.size(); ++j)
    {
      if(CountArr[s[j] - 'a'] == 1)       
      {
        return j;    
      }
    }    
    return -1;  
  }
};


int main()
{
  string s("aabb");

  cout << Solution().firstUniqChar(s) << endl;


  return 0;
}

