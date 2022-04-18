#include <iostream>
#include <list>
using namespace std;

void test_list1()
{
  list<int> lt;

  lt.push_back(1);
  lt.push_back(2);
  lt.push_back(3);
  lt.push_back(4);
  
  list<int>::iterator it = lt.begin();
  
  while(it != lt.end())
  {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  
  list<int>::reverse_iterator rit = lt.rbegin();
  while(rit != lt.rend())
  {
    cout << *rit << " ";  
    ++rit;
  }
  cout << endl;
  
  for(auto e: lt)
  {
    cout << e << " ";
  }
  cout << endl;

}

void test_list2()
{
  list<int> lt;

  lt.push_back(1);
  lt.push_back(3);
  lt.push_back(3);
  lt.push_back(3);
  lt.push_back(2);
  lt.push_back(2);
  lt.push_back(4);
  
  //lt.sort();

  for(auto e: lt)
  {
    cout << e << " ";
  }
  cout << endl;

  //lt.reverse();
  
  for(auto e: lt)
  {
    cout << e << " ";
  }
  cout << endl;

  lt.unique();//去重之前需要先排序，不然去重不干净

  for(auto e: lt)
  {
    cout << e << " ";
  }
  cout << endl;
}

int main()
{
  //test_list1();
  test_list2();
  
  return 0;
}




