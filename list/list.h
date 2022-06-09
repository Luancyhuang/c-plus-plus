#pragma once
#include <assert.h>

namespace hxw
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& data = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(data)
		{}
	};

	template<class T, class Ref, class Ptr>	
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;

		//typedef __list_iterator 
		
		Node* _node;
		__list_iterator(Node* x)
			:_node(x)
		{}

		//it1 = it2
		//拷贝构造和赋值重载是否需要我们自己实现呢？
		//析构呢？迭代器是借助节点的指针访问修改链表
		//节点是属于链表，不属于迭代器，所以它不管释放
		
		//*it
	    Ref operator*()
		{
			return _node->_data;		
		}

	    Ptr operator->()
		{
			return &_node->_data;		
		}
		
		//++it
		self& operator++()
		{
			_node = _node->_next;		 
			return *this;
		}

		//it++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;		 
			return tmp;
		}

		//--it
		self& operator--()
		{
			_node = _node->_prev;		 
			return *this;
		}

		//it--
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;		 
			return tmp;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const self& it) const
		{
			return _node == it._node;
		}
	};

	template<class T> 
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		
		/*void f()
		{
			Node* pNode = _head->_next;
			iterator it = _head->_next;

			*pNode;
			*it;

			++pNode;
			++it;
		}*/
		
		iterator begin()		
		{
			return iterator(_head->_next);
		}

		iterator end()		
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const	
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		list(const list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			
			for(auto e : lt)
			{
				push_back(e);
			}
		}

		list<T>& operator=(const list<T>& lt)
		{
			if(this != &lt)
			{
				clear();
				for(auto e : lt)
				{	
					push_back(e);
				}
			}
			
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while(it != end())
			{
				//iterator del = it++;
				//delete del._node;
				erase(it++);
			}

			//_head->_next = _head;
			//_head->_prev = _head;
		}

		void push_front(const T& x)
		{
			 insert(begin(),x);
		}

		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node* NewNode = new Node(x);
			tail->_next = NewNode;
			NewNode->_prev = tail;
			NewNode->_next = _head;
			_head->_prev = NewNode;*/

			insert(end(),x);
		}
		//这里insert以后，pos会不会失效？不会失效
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}
		
		//这里erase以后，pos会不会失效？一定失效
	    iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			delete pos._node;
			prev->_next = next;
			next->_prev = prev;		

			return iterator(next);
		}

		void pop_back()
		{
			erase(--end());		
		}

		void pop_front()
		{
			erase(begin()); 
		}
	
	private:
		Node* _head;		
	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while(it != lt.end())
		{			
			cout << *it << " ";
			++it;
		}
		cout << endl;	
	}

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		
		//lt.f();

		print_list(lt);
		
		list<int>::iterator it = lt.begin();
		while(it != lt.end())
		{
			*it *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	
	struct Date
	{
		int _year;
		int _month;
		int _day;	

		Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			,_month(month)
			,_day(day)
		{}

	};

	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date(2022,6,8));
		lt.push_back(Date(2022,6,9));
		lt.push_back(Date(2022,6,10));

	    list<Date>::iterator it = lt.begin();
		while(it != lt.end())
		{
			//cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;		
			//本来是it->->_year
			//这里编译器进行优化，省略了一个->
			//所有类型只要想重载->都是这样
			cout << it->_year << "/" << it->_month << "/" << it->_day << endl;		
			++it;
		}
	}

	void test_list3()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int> lt2(lt1);
		
		for(auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}
