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
/*int sign(int x)
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
}*/

//使用函数求奇数和
//本题要求实现一个函数，计算N个整数中所有奇数的和，同时实现一个判断奇偶性的函数
//其中函数even将根据用户传入的参数n的奇偶性返回相应值：当n为偶数时返回1，否则返回0。函数OddSum负责计算并返回传入的N个整数List[]中所有奇数的和。
/*#define MAXN 10
int even(int n)
{
  if(n%2==0)
    return 1;
  else
    return 0;
}

int OddSum(int List[],int N)
{
  int sum = 0;
  for(int i=0;i<N;i++)
  {
    if(even(List[i]) == 0)
       sum += List[i];  
  }
  return sum;
}

int main()
{
  int N; 
  int List[MAXN];
  
  cin >> N;
  printf("Sum of ( ");
  //输入数据
  for(int i=0;i<N;i++)
  {
    scanf("%d",&List[i]); 

    if(even(List[i]) == 0)
    {
      printf("%d ",List[i]);  
    }
  }
  printf(") = %d\n",OddSum(List,N));
 
  return 0;
}*/
//使用函数计算两点间的距离
//本题要求实现一个函数，对给定平面任意两点坐标(x 
//1
//​	
// ,y 
// 1
// ​	
//  )和(x 
//  2
//  ​	
//   ,y 
//   2
//   ​	
//    )，求这两点之间的距离
// 其中用户传入的参数为平面上两个点的坐标(x1, y1)和(x2, y2)，函数dist应返回两点间的距离。
#include <math.h>

/*double dist(double x1,double y1,double x2,double y2)
{
  double dist;
  dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  return dist;
}

int main()
{
  double x1,y1,x2,y2;
  scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
  printf("dist = %.2f\n",dist(x1,y1,x2,y2));

  return 0;
}*/
//使用函数求素数和
//本题要求实现一个判断素数的简单函数、以及利用该函数计算给定区间内素数和的函数。
//素数就是只能被1和自身整除的正整数。注意：1不是素数，2是素数。
/*int prime(int p)
{
  int i;
  if(p<2)
    return 0;
  for(i=2;i<=sqrt(p);i++)
  {
    if(p%i==0)
      return 0;  
  }
  return 1;
}

int PrimeSum(int m,int n)
{
  int sum = 0;
  for(int i=m;i<=n;i++)
  {
    if(prime(i) == 1)
      sum += i;
  }
  return sum;
}

int main()
{
  int m,n,p;

  scanf("%d%d",&m,&n);
  printf("Sum of(");

  for(p=m;p<=n;p++)
  {
    if(prime(p) != 0)
    {
      printf("%d ",p);
    }  
  }
  printf(") = %d\n",PrimeSum(m,n));

  return 0;
}*/
//使用函数统计指定数字的个数
//本题要求实现一个统计整数中指定数字的个数的简单函数。
//其中number是不超过长整型的整数，digit为[0, 9]区间内的整数。函数CountDigit应返回number中digit出现的次数。
int CountDigit(int number, int digit)
{
  int count = 0;
  
  if(number < 0)
    number *= -1;
  
  do
  {
    if(number %10 == digit)
      count++;
    number /= 10;
  }while(number>0);

  return count;
}

int main()
{
  int number,digit;
  scanf("%d%d",&number,&digit);
  
  printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

  return 0;
}






