#pragma once
#include <vector>
#include <list>

namespace hxw
{
	template<class T, class Container>
	class stack
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}
		
		size_t size() const
		{
			return _con.size();		
		}

		const T& top() const
		{
			return _con.back();		
		}
		
		void push(const T& x)
		{
			_con.push_back(x);	
		}

		void pop()
		{
			_con.pop_back();
		}

	private:
		//vector<T> _v;
		Container _con;
	};

	void test_stack1()
	{
		stack<int, std::vector<int>> s;//数组栈
		//stack<int, std::list<int>> s;//链表栈
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		//s.pop();
		while(!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}








}

