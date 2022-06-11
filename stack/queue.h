#pragma once
#include <vector>
#include <list>

namespace hxw
{
	template<class T, class Container = deque<T>>
    class queue
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
		
		const T& front() const
		{
			return _con.front(); 
        }

		const T& back() const
		{
			return _con.back(); 
        }
		
		void push(const T& x)
		{
			_con.push_back(x);
		} 

		void pop()
		{
			_con.pop_front();
        }

    private:
		//vector<T> _v;
		Container _con;
	};

	void test_queue()
	{
		//queue<int> q;
		queue<int, list<int>> q;
						
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
}
