#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>
#include <algorithm>
using namespace std;

namespace hxw
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}
		//v2(v1)
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr) 
		{
			while(first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish); 
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr) 
		{
			//传统写法
		    //_start = new T[v.capacity()];
		    //_finish = _start + v.size(); 
		    //_endofstorage = _start + v.capacity();

		    //memcpy(_start, v._start, v.size()*sizeof(T));
		
			//现代写法
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		//v2 = v1
		vector<T>& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}

		const_iterator begin() const
		{
			return _start;		
		}

		const_iterator end() const
		{
			return _finish;		
		}

		iterator begin()
		{
			return _start;		
		}

		iterator end()
		{
			return _finish;		
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		const T& operator[](size_t i) const 
		{
			assert(i < size());
		    return _start[i];
		}

		T& operator[](size_t i)
		{
			assert(i < size());
		    return _start[i];
		}

		void reserve(size_t n)
		{
			if(n > capacity())
			{
				//扩容
				size_t sz = size();
				T* tmp = new T[n];
				if(_start)
				{
					//memcpy(tmp, _start,sizeof(T)*size());
					for(size_t i = 0; i < sz; ++i)
					{
						//T是int 一个一个拷贝
						//如果T是string，一个一个拷贝调用的是T的深拷贝赋值，也没问题、
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				//_finish = tmp + size();//size() = _finish - _start
				_start = tmp;
				_finish = _start + sz;//_finish - _start
				//_finish = _start + size();//size() = _finish - _start
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if(n < size())
			{
			    _finish = _start + n;
			}
			else
			{
				if(n > capacity())
				{
					reserve(n);
				}

				while(_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start); 
	        assert(pos <= _finish);

			//满了就扩容
			if(_finish == _endofstorage)
			{
				//扩容会导致pos失效，扩容后需要更行pos
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while(end >= pos)
			{
				*(end + 1) = *end;
				--end;			
			}

			*pos = x;
			++_finish;		

			return pos;
		}

		iterator erase(iterator pos)		
		{
			assert(pos >= _start && pos < _finish);
			
			iterator begin = pos + 1;
			while(begin < _finish)
			{
				 *(begin - 1) = *begin;
				 ++begin; 
			}

			--_finish;

			return pos;
		} 
		
		void push_back(const T& x)
		{
			if(_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish;
		}
		
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;	
	}; 

	void test_vector1()
	{
		vector<int> v;
		
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for(size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		
		while(it != v.end())
		{
		  cout << *it << " ";
		  ++it;		
		}
		cout << endl;

		for(auto e : v)
		{
		  cout << e << " ";		
		}
		cout << endl;
	
		int i = 0;
		int j = int();
		int k = int(10);
		int m(20);
	
	}

	class A	
	{
	public:
		//A()
		//{}

		~A()
		{
			cout << " ~A() " << endl;		
		}		
	};

	void test()
	{
		A();
		const A& x = A();

		//string("hello");
		//const string& s = string("hello111111");
	
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int> v2(v1);
		for(auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		
		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);

		v1 = v3;

		for(auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;		
	}

	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 2);
		if(pos != v1.end())
		{
			//如果insert中发生了扩容， 那么会导致it指向的空间会被释放
			//it本质是一个野指针，这种问题我们就叫迭代器失效
			v1.insert(pos, 20);					
		}

		for(auto e : v1)		
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{	
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		//v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator it = v1.begin();
		while(it != v1.end())
		{
			if(*it % 2 == 0)
			{
				it = v1.erase(it);
			}
			else
			{			
				++it;
			}
		}

		for(auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;	
	}

	void test_vector6()
	{
		vector<string> v;
		v.push_back("1111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");

	    for(auto& e : v)
		{
			cout << e << " ";		
		}
		cout << endl;
	}
} 

