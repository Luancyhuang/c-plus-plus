#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void test_vector1()
{
  vector<int> v1;
  
  vector<int> v2(10,8);
  
  vector<int> v3(++v2.begin(),--v2.end());
  
  vector<int> v4(v3);

  string s("hello,world");

  vector<char> v5(s.begin(),s.end());  

}

void test_vector2()
{
  vector<int> v;
  v.push_back(1); 
  v.push_back(2); 
  v.push_back(3); 
  v.push_back(4); 

  // 遍历方式1:下标+[]
  for(size_t i = 0; i < v.size(); ++i)
  {
    v[i] += 1;
    cout << v[i] << " "; 
  }
  cout << endl;
   
  // 遍历方式2；迭代器
  vector<int>::iterator it = v.begin(); 
  while(it != v.end())
  {
    *it -= 1;
    cout << *it << " ";
    ++it;
  }
  cout << endl;

  //遍历方式3:范围for
  for(auto e : v)
  {
    cout << e << " "; 
  }
  cout << endl; 

  int a[] = {1,2,3,4};
 
  //原生指针就是天然迭代器，数组支持范围for,会被替换指针
  for(int* p = a; p < a + sizeof(a)/sizeof(int); ++p)
  {
    cout << *p << " ";
  }
  cout << endl;
}

void test_vector3()
{
  vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  
  //v.reserve(100);//扩容
  //v.resize(100);//扩容+初始化/删除数据

  //cout << v.size() << endl;
  //v.reserve(2);
  //v[3];
  //v.at(3);
  
 //v.assign(10,5);

  vector<int>:: iterator ret = find(v.begin(),v.end(),3);
  
  if(ret != v.end())
  {
    cout << "找到了" << endl;
    v.insert(ret,30);
  
    //v.erase(ret);
  }
  
  v.insert(v.begin(),-1);

  vector<int>:: iterator pos = find(v.begin(),v.end(),3);
  
  if(pos != v.end())
  {
    v.erase(pos);
  }
  
  for(auto e : v)
  {
    cout << e << " ";  
  }

  cout << endl;
}

/*class Solution
{
public:
  int singleNumber(vector<int>& nums)
  {
    int val = 0;    
    for(auto e : nums)
    {
      val ^= e; 
    }   
    return val;
  }
};*/

/*int main()
{
  //test_vector2();  
  //test_vector3();  
  
  vector<int> v;

  //v.push_back(4);
  v.push_back(1);
  v.push_back(2);
  //v.push_back(1);
  v.push_back(2);

  cout << Solution().singleNumber(v) << endl;

  return 0;
}*/


class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> vv;
    vv.resize(numRows);

    for(size_t i = 0; i < numRows; ++i)
    {
      vv[i].resize(i + 1);
      vv[i].front() = vv[i].back() = 1;
      //vv[i][0] = vv[i][vv[i].size() - 1] = 1;      
    }

    for(size_t i = 0; i < vv.size(); ++i)
    {
      for(size_t j = 0; j < vv[i].size(); ++j)
      {
        if(vv[i][j] == 0)
	{
	  vv[i][j] = vv[i-1][j-1] + vv[i-1][j];	
	}
      }
    }

    for(size_t i = 0; i < vv.size(); ++i)    
    {
      for(int j = 0; j < vv[i].size(); ++j)
      {
        cout << vv[i][j] << " ";
      }
      cout << endl;
    }

    return vv;
  }
};

int main()
{   
  int row = 5;   
  
  Solution().generate(row);
   
  return 0;
}

/*int main()
{
  const int x = 1;
  double y = 2.2;
  cout << typeid(2).name() << endl;

  decltype(x) z = 2;
  return 0;
}*/
 


/*int main()
{
  vector<vector<int>> vv;

  vv.resize(5);
  
  for(size_t i = 0; i < 5; ++i)
  {
    vv[i].resize(i + 1);  
  }



  return 0;
}*/
