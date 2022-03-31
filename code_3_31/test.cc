#include <iostream>
#include <stdlib.h>

using namespace std;

//int GetMonthDay(int year,int month)
//{
//  static int monthDayArray[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//  int day = monthDayArray[month];
//  
//  if((month == 2 && year%4== 0 && year%100 != 0) ||( year%400 == 0))
//  {
//    ++day;
//  }
//
//  return day;
//}
//
//int main()
//{ 
//  int year,month,day;
//  cin >> year >> month >> day;
//  
//  int n = 0;
//  for(int i = 0; i<month ;++i)
//  {
//    n += GetMonthDay(year,i);  
//  }
//
//  n += day;
//  cout << n << endl;
//
//  return 0;
//}

//int main()
//{
//  //动态申请int 和5个int数组
//  //总结malloc/free 和new/delete 对于内置类型没有本质区别，只有用法上的区别
//  //
//  int* p1 = (int*)malloc(sizeof(int));
//  int* p2 = (int*)malloc(sizeof(int)*5);
//
//  //int* p3 = new int(5);//动态申请一个int空间，这块空间初始化为5
//  int* p3 = new int;
//  //c++ 98 不支持初始化new的数组
//  //c++11支持初始化数组,用花括号{}列表初始化
//
//  int* p4 = new int[5]{1,2};//动态申请5个int空间
//
//  free(p1);
//  free(p2);
//
//  delete p3;
//  delete[] p4;
//  
//  p1 = nullptr;
//  p2 = nullptr;
//
//  p3 = nullptr;
//  p4 = nullptr;
//
//  
//
//  return 0;
//}

//int main()
//{
//  //面向对象的语言，处理错误的方式一般是抛异常，--try catch
//  //面向过程的语言，处理错误的方式是是什么->返回值+错误码
//  
//  char* c1 = (char*) malloc(10);
//  if(c1 == nullptr)
//  {
//    printf("%da\n",errno);
//    perror("malloc fail\n");
//    exit(-1);
//  }
//  else
//  {
//    printf("%p\n",c1);  
//  }
//
//  return 0;
//}
void BuyMemory()
{
  char* c1 = new char[1024u*1024u*1024u*2u-1];
  //c1 = new[1024U*1024u*1024u*1u];
  printf("%p\n",c1);

}
int main()
{
  char* c1 = nullptr;
  try
  { 
    BuyMemory();  
  }
  catch(const exception& e)
  {
     cout << e.what() << endl; 
  }

  printf("%p\n",c1);
  
  return 0;
}

