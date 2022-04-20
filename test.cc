#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <queue>
#include <functional>

void test_priority_queue()
{
  //默认是大的优先级高--大堆，默认给的仿函数是less,
  //priority_queue<int> pq;
  
  //控制小的优先级高  --小堆，给的是greater防函数
  priority_queue< int,vector<int>,greater<int> > pq;
  
  pq.push(3);
  pq.push(3);
  pq.push(7);
  pq.push(1);
  pq.push(9);
  
  while(!pq.empty())
  {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

int main()
{    
  test_priority_queue();
  
  return 0;
}


