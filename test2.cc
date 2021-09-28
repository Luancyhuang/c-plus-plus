#include <iostream>

using namespace std;

class TDate
{
	private:
		int year;
		int month;
		int day;
	public:
		TDate(int y=0,int m =0,int d = 0)
		{
		  year = y;
		  month = m;
		  day = d;
		}
		void print()
		{
		  cout << day << '/' << month << '/' << year << endl;
		
		}
};

int main()
{
  int year = 0;
  int month = 0;
  int day = 0;
  cin >> year >> month >> day;
  TDate d(year,month,day);
  //输出
  d.print();
  return 0;
}
