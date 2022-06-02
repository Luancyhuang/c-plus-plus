#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

namespace hxw
{
  class string
  {
  public:
    /*string()
      :_str(new char[1])
      ,_size(0)
      ,_capacity(0)
    {
      _str[0] = '\0';
    }*/
    typedef char* iterator;
    
    iterator begin()
    {
      return _str;
    }

    iterator end()
    {
      return _str + _size;
    }

    string(const char* str = "")
      :_size(strlen(str))
      ,_capacity(_size)
    {
      _str = new char[_capacity + 1];
      strcpy(_str,str);
    }
    //s2(s1);
    string(const string& s)
      :_size(s._size)
      ,_capacity(s._capacity)
    {
      _str = new char[_capacity + 1];
      strcpy(_str,s._str);
    }
    //s1 = s3;
    /*string& operator=(const string& s)
    {
      if(this != &s)
      {
        //delete[] _str;
        //_str = new char[strlen(s._str) + 1]; 
	char* tmp = new char[s._capacity + 1];        
	//strcpy(_str,s._str);      
        strcpy(tmp,s._str);        
	delete[] _str;
	_str = tmp;
	_size = s._size;
	_capacity = s._capacity;
      }
      return *this;
    }*/

    //s1 = s3;
    /*string& operator=(const string& s)
    {
      if(this != s)
      {
        string tmp(s);
        swap(_str,tmp_str);
      }
      return *this;
    }*/

    string& operator=(string s)
    {
      swap(_str, s._str);
      return *this;    
    }

    /*string& operator=(string s)
    {
      swap(s);
      return *this;    
    }*/
    
    ~string()
    {
      delete[] _str;
      _str = nullptr;
      _size = _capacity = 0;
    }
    
    const char* c_str() const
    {
      return _str;
    }

    size_t size() const
    {
      return _size;    
    }
   
    //const char& operator[](size_t pos) const
    char& operator[](size_t pos)    
    {

      assert(pos < _size);

      return _str[pos];
    }

    void reserve(size_t n)
    {
      if(n > _capacity)
      {
        char* tmp = new char[n + 1];
        strcpy(tmp,_str);
        delete[] _str;
        
	_str = tmp;      
        _capacity = n;
      }    
    } 

    void resize(size_t n, char ch = '\0')
    {
       if(n <= _size)
       {
	  _size = n;
          _str[n] = '\0';
       }
       else
       {
         if(n > _capacity)
	 {
	   reserve(n);
	 }

	 memset(_str + _size, ch, n - _size);
	 _size = n;
	 _str[n] = '\0';       
       }  
    }

    size_t find(char ch)
    {
      for(size_t i = 0; i < _size; ++i)
      {
        if(ch == _str[i])
	{
	  return i;
	}      
      }
      return npos;    
    }

    size_t find(const char* s, size_t pos = 0)
    {
      const char* ptr = strstr(_str + pos, s);

      if(ptr == nullptr)
      {
        return npos;
      }
      else
      {
        return ptr - _str;
      }
    }

    string& insert(size_t pos,char ch)
    {
      assert(pos <= _size);
      
      if(_size == _capacity)
      {
        reserve(_capacity == 0 ? 4 : _capacity * 2);	
      }
      
      size_t end = _size + 1;
      while(end > pos)
      {
        _str[end] = _str[end - 1];
	--end;
      }

      _str[pos] = ch;
      ++_size; 

      return *this;
    }

    string& insert(size_t pos,const char* s)
    {
      assert(pos <= _size);
      
      size_t len = strlen(s);
      if(_size + len > _capacity)
      {
        reserve(_size + len);
      }
      
      size_t end = _size + len;
      while(end >= pos + len)
      {
        _str[end] = _str[end - len];
	--end;
      }

      strncpy(_str + pos, s, len);
      _size += len;

      return *this;    
    }

    string& erase(size_t pos = 0, size_t len = npos)
    {
       assert(pos < _size);

       if(len == npos || pos + len >= _size)
       {
         _str[pos] = '\0';
	 _size = pos;       
       }
       else
       {       
         strcpy(_str + pos, _str + pos + len); 
         _size -= len;
       }

       return *this;    
    }
     
    void push_back(char ch)
    {
      if(_size == _capacity)
      {
        reserve(_capacity == 0 ? 4 : _capacity * 2);        
      }

      _str[_size] = ch;
      ++_size;
      _str[_size] = '\0';        
    }


    void append(const char* str)
    {
       size_t len = strlen(str);       
       
       if(_size + len > _capacity)
       {
          reserve(_size + len);         	           
       }

       strcpy(_str + _size,str);    
       
       _size += len;    
    }

    string& operator+=(char ch)
    {
      push_back(ch);
      return *this;
    }

    string& operator+=(const char* str)
    {
      append(str);
      return *this;
    }

    bool operator<(const string& s) const
    {
    
      return strcmp(_str, s._str) < 0;
    }

  private:
    char* _str;
    size_t _size;
    size_t _capacity;//有效字符的空间数，不计算'\0'
    static const size_t npos;  
  };
  const size_t string:: npos = -1;
   
  bool operator<(const string& s1, const string& s2)
  {
    /*size_t i1 = 0, i2 = 0;
    while(i1 < s1.size() && i2 < s2.size())
    {
      if(s1[i1] < s2[i2])
      {
        return true;
      }
      else if(s1[i1] > s2[i2])
      {
        return false;      
      }
      else
      {
        ++i1;
	++i2;
      }
    }
    
    return i2 < s2.size() ? true : false;*/

    return strcmp(s1.c_str(), s2.c_str()) < 0;
  }

  bool operator==(const string& s1, const string& s2)
  {
    return strcmp(s1.c_str(), s2.c_str()) == 0;       
  }

  bool operator<=(const string& s1, const string& s2)
  {
    return s1 < s2 || s1 == s2;       
  }

  bool operator>(const string& s1, const string& s2)
  {
    return !(s1 <= s2);      
  }
   
  bool operator>=(const string& s1, const string& s2)
  {
    return !(s1 < s2);
  }

  bool operator!=(const string& s1, const string& s2)
  {
    return !(s1 == s2);
  }
  
  //cout << s1;
  ostream& operator<<(ostream& out, const string& s)
  {
    for(auto ch : s)
    {
      out << ch;
    }
    
    return out;
  }
  
  istream& operator>>(istream& in, string& s)
  {
    char ch = in.get();
    while(ch != ' ' &&  ch != '\n')
    {
      s += ch;
      ch = in.get(); 
    }

    return in;
  }

  void test_string1()
  {
    string s1("hello,world");
   
    string s3("sort");

    s1 = s3;

    

    /*string s2; 
    cout << s1.c_str() << endl;
    
    cout << s2.c_str() << endl;
    string s3("sort");
    //s1 = s3;
    s1[0]  = 'x';
    //s1[30];

    for(size_t i = 0; i < s1.size(); ++i)
    {  
       cout << s1[i] << " ";    
    }
    cout << endl;*/

    /*string::iterator it = s1.begin();
    while(it != s1.end())
    {
      *it += 1;
      ++it;
    }
    
    it = s1.begin();
    while(it != s1.end())
    {
      cout << *it << " ";
      ++it;    
    }
    cout << endl;
  
    for(auto e : s1)
    {    
      cout << e << " ";
    }
    cout << endl;*/

  }

  void test_string2()
  {
    string s1("hello,world");
    s1.push_back('@');  
    s1.push_back(' ');

    s1.append("hello,bit");    
    cout << s1.c_str() << endl;
  
    string s2;
    s2 += 'x';
    s2 += "yz 123";

    cout << s2.c_str() << endl;  
  }

  void test_string3()
  {
    string s1("hello");
    string s2("hello");
    cout << (s1 < s2) << endl;    
    
    string s3("abcd");
    string s4("abcde");
    cout << (s3 < s4) << endl;    
    
    string s5("abcde");
    string s6("abcd");
    cout << (s5 < s6) << endl;    
  }

} 






