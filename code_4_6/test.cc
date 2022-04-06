#include <iostream>
#include <stdio.h>
using namespace std;
//数字金字塔
//本题要求实现函数输出n行数字金字塔.其中n是用户传入的参数，为[1, 9]的正整数。要求函数按照如样例所示的格式打印出n行数字金字塔。注
//意每个数字后面跟一个空格
//    1
//   2 2
//  3 3 3
// 4 4 4 4
//5 5 5 5 5
/*void pyramid(int n)
{
   int i;   
   for(i=1;i<=n;i++)
   {
     int j;
     for(j=1;j<=n-i;j++)
     {
       printf(" ");//打印空格     
     }
     for(j=1;j<=i;j++)
     {
       printf("%d ",i);//打印数字
     }
     printf("\n");
   }
}

int main()
{
  int n;
  cin >> n;
  pyramid(n);
  
  return 0;
}*/
//符号函数 
//其中x是用户传入的整型参数。符号函数的定义为：若x大于0，sign(x) = 1；若x等于0，sign(x) = 0；否则，sign(x) = −1。
int sign(int x)
{
  if(x>0)
    return 1;
  else if(x<0)
    return -1;
  else 
    return 0;
}

int main()
{
  int x;
  cin >> x;
  printf("sign(%d) = %d\n",x,sign(x));
  
  return 0;
}

