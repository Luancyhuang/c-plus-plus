#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <functional>

using namespace std;

void test_stack()
{
	//后进先出的原则所以不支持用迭代器访问
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while(!q.empty())
	{
		cout << q.front() << " ";
		q.pop();		
	}
	cout << endl;
}

#include "stack.h"
#include "queue.h"
#include "priorityqueue.h"

void test_priority_queue1()
{
	//默认是大的优先级高，--默认给的仿函数是less
	//priority_queue<int> pq;
	
	//控制小的优先级--给一个greater的仿函数
	//greater<int>是类型
	priority_queue<int, vector<int>, greater<int>> pq;
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

template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

void test_priority_queue2() 
{
	//priority_queue<Date, vector<Date>> pq;
	//priority_queue<Date, vector<Date>, greater<Date>> pq;
	priority_queue<Date*> pq;
	
	pq.push(new Date(2022, 6, 11));
	pq.push(new Date(2021, 10, 11));
	pq.push(new Date(2023,  6, 11));

	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();	
	}
	cout << endl;
} 

//int main()
//{
//	//test_stack();
//	//test_queue();
//	//hxw::test_stack1();
//	//hxw::test_queue();
//	test_priority_queue2();
//	/*Less less;
//	cout << less(1, 2) << endl;
//	
//	Greater gt;
//	//cout << gt.operator()(1, 2) << endl;
//	cout << gt(1, 2) << endl;*/
//
//	//Less<int> lessi;
//	//cout << lessi(1, 2) << endl;
//	//cout << Less<int>()(1, 2) << endl;
//	//
//	//cout << Less<double>()(1.1, 2.2) << endl;
//
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////

template<class T, size_t N>
class myStack
{
public:
	void Push(const T& x)
	{}

	
private:
	T _a[N];
	size_t _top;
};

/*int main()
{
	//myStack<int, 100> st1;//100
	//myStack<int, 200> st2;//200
	
	array<int, 10> aa1;//c++11
	int aa2[10];//c

	cout << sizeof(aa1) << endl;
	cout << sizeof(aa2) << endl;

	return 0;
}*/


int main()
{
	 

	return 0;
}
























