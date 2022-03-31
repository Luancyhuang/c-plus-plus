#include <iostream>
using namespace std;

int GetMonthDay(int year,int month)
{
  static int monthDayArray[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int day = monthDayArray[month];
  
  if((month == 2 && year%4== 0 && year%100 != 0) ||( year%400 == 0))
  {
    ++day;
  }

  return day;
}


int main()
{ 
  int year,month,day;
  cin >> year >> month >> day;
  
  int n = 0;
  for(int i = 0; i<month ;++i)
  {
    n += GetMonthDay(year,i);  
  }

  n += day;
  cout << n << endl;

  return 0;
}
