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
	
	for(auto e : lt)
	{
		cout << e << " ";	
	}
	cout << endl;

	list<int>::reverse_iterator rit = lt.rbegin();
	while(rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;	
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(2);
	
	//sort（）算法里的sort需要随机迭代器
   
	lt.sort(); 
	for(auto e : lt)
	{
		cout << e << " ";	
	}
	cout << endl;

	lt.reverse(); 
	for(auto e : lt)
	{
		cout << e << " ";	
	}
	cout << endl;
	 
	lt.unique();//去重先排序
	for(auto e : lt)
	{
		cout << e << " ";	
	}
	cout << endl;
}

#include "list.h"

int main()
{
	//test_list2();
    //hxw::test_list1();
    hxw::test_list3();

	return 0;
} 











