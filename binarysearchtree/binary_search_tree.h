#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace K
{
    template<class K>
    //struct BinarySearchTreeNode
    struct BSTreeNode
    {
    	BSTreeNode<K>* _left;
    	BSTreeNode<K>* _right;
    	K _key;
    
    	BSTreeNode(const K& key)
    		:_left(nullptr)
    		,_right(nullptr)
    		,_key(key)
    	{}
    };
    
    template<class K>
    struct BSTree
    {
    	typedef BSTreeNode<K> Node;
    public:
    	BSTree()
    		:_root(nullptr)
    	{}
    	
    	bool Find(const K& key)
    	{
    		Node* cur = _root;
    		
    		while(cur)
    		{
    			if(cur->_key < key)
    			{
    				cur = cur->_right;
    			}
    			else if(cur->_key > key)
    			{
    				cur = cur->_left;
    			}
    			else
    			{
    				return true;
    			}
    		}
    
    		return false;	
    	}
    
    	bool Erase(const K& key)
    	{
    		Node* parent = nullptr;
    		Node* cur = _root;
    
    		while(cur)
    		{
    			if(cur->_key < key)
    			{
    				parent = cur;
    				cur = cur->_right;
    			}
    			else if(cur->_key > key)
    			{
    				parent = cur;
    				cur = cur->_left;			
    			}
    			else
    			{
    				//找到并开始删除
    				if(cur->_left == nullptr)
    				{
    					if(parent == nullptr)
    					{
    						_root = cur->_right;
    					}
    					else
    					{
    						if(parent->_left == cur)
    						{
    							parent->_left = cur->_right;
    						}
    						else
    						{
    							parent->_right = cur->_right;
    						}
    					}
    
    					delete cur;
    				}
    				else if(cur->_right == nullptr)
    				{
    					if(parent == nullptr)
    					{
    						_root = cur->_left;
    					}
    					else
    					{
    						if(parent->_left == cur)
    						{
    							parent->_left = cur->_left;
    						}
    						else
    						{
    							parent->_right = cur->_left; 
    						}
    					}
    
    					delete cur;
    				}
    				else
    				{
    					Node* minParent = cur;
    					Node* min = cur->_right;
    					while(min->_left)
    					{
    						minParent = min;
    						min = min->_left;						 
    					}
    					
    					cur->_key = min->_key;
    
    					if(minParent->_left == min)
    					{
    						minParent->_left = min->_right;
    					}
    					else
    					{
    						minParent->_right = min->_right;
    					}
    
    					delete min;
    				}
    
    				return true;
    			}
    		}
    
    		return false;
    	}
    
    	bool Insert(const K& key)
    	{
    		if(_root == nullptr)
    		{
    			_root = new Node(key);
    			return true;
    		}
    		
    		Node* parent = nullptr;
    		Node* cur = _root;
    
    		while(cur)
    		{
    			if(cur->_key < key)
    			{
    				parent = cur;
    				cur = cur-> _right;
    			}
    			else if(cur->_key > key)
    			{
    				parent = cur;
    				cur = cur->_left;
    			}
    			else 
    			{
    				return false;
    			}
    		}
    
    		cur = new Node(key);
    		if(parent->_key < key)
    		{
    			parent->_right = cur;
    		}
    		else
    		{
    			parent->_left = cur;
    		}
    
    		return true;	
    	}
    
    //private:
    	bool _EraseR(Node*& root, const K& key)
    	{
    		if(root == nullptr)
    		{
    			return false;
    		}
    
    		if(root->_key < key)
    		{
    			return _EraseR(root->_right, key);
    		}
    		else if(root->_key > key)
    		{
    			return _EraseR(root->_left, key);
    		}
    		else
    		{
    			Node* del = root;
    
    			if(root->_left == nullptr)
    			{
    				root = root->_right;
    			}
    			else if(root->_right == nullptr)
    			{
    				root = root->_left;
    			}
    			else
    			{
    				Node* min = root->_right;
    				while(min->_left)
    				{
    					min = min->_left;
    				}
    
    				swap(min->_key, root->_key);
    				//递归到右子树去删除 
    				return _EraseR(root->_right, key); 
    				
    			}
    
    			delete del;
    			return true;
    		}
    	}
    
    	Node* _FindR(Node* root, const K& key)
    	{ 
    		if(root == nullptr)
    		{
    			return nullptr;
    		}
    
    		if(root->_key < key)
    		{
    			return _FindR(root->_right, key);
    		}
    		else if(root->_key > key)
    		{
    			return _FindR(root->_left, key);
    		}
    		else
    		{
    			return root;
    		}
    	}
    
    	Node* FindR(const K& key)
    	{
    		return _FindR(_root, key);
    	}
    	
    	bool _InsertR(Node*& root,const K& key)
    	{
    		if(root == nullptr)
    		{
     			root = new Node(key); 
    			return true;
    		}
    		
    		if(root->_key < key)
    		{
    			return _InsertR(root->_right, key);
    		}
    		else if(root->_key > key)
    		{
    			return _InsertR(root->_left, key);
    		}
    		else
    		{
    			return false;
    		}
    	}
    
    	bool InsertR(const K& key)
    	{
    		return _InsertR(_root, key);
    	}
    
    	bool EraseR(const K& key)
    	{
    		return _EraseR(_root, key);
    	}
    	
    	void InOrder()
    	{
    		_InOrder(_root);
    		cout << endl;
    	}
    
    	void _InOrder(Node* root)
    	{
    		if(root == nullptr)
    		{
    			return;
    		}
    
    		_InOrder(root->_left);
    		cout << root->_key << " ";
    		_InOrder(root->_right);
    	}
    
    private:
    	Node* _root;
    };
    
    void TestBSTree()
    {
    	BSTree<int> t;
    	int a[]= {5, 3, 4, 5, 5, 1, 7, 8, 2, 6, 0, 9};
    	for(auto e : a)
    	{
    		t.Insert(e);	
    	}
    
    	t.InOrder();
    
    	t.Erase(7);
    	t.InOrder();
    
    	t.Erase(5);
    	t.InOrder();
    	
    	t.Erase(1);
    	t.InOrder();
    
    	for(auto e : a)
    	{
    		t.Erase(e);	
    		t.InOrder();
    	}
    	t.InOrder();
    }
}

namespace KV
{
    template<class K, class V>
    //struct BinarySearchTreeNode
    struct BSTreeNode
    {
    	BSTreeNode<K, V>* _left;
    	BSTreeNode<K, V>* _right;
    	K _key;
		V _value;
    
    	BSTreeNode(const K& key, const V& value)
    		:_left(nullptr)
    		,_right(nullptr)
    		,_key(key)
			,_value(value)
    	{}
    };
    
    template<class K,class V>
    struct BSTree
    {
    	typedef BSTreeNode<K,V> Node;
    public:
    	BSTree()
    		:_root(nullptr)
    	{}
    	
    	Node* Find(const K& key)
    	{
    		Node* cur = _root;
    		
    		while(cur)
    		{
    			if(cur->_key < key)
    			{
    				cur = cur->_right;
    			}
    			else if(cur->_key > key)
    			{
    				cur = cur->_left;
    			}
    			else
    			{
    				return cur;
    			}
    		}
    
    		return nullptr;	
    	}
    
    	bool Erase(const K& key)
    	{
    		Node* parent = nullptr;
    		Node* cur = _root;
    
    		while(cur)
    		{
    			if(cur->_key < key)
    			{
    				parent = cur;
    				cur = cur->_right;
    			}
    			else if(cur->_key > key)
    			{
    				parent = cur;
    				cur = cur->_left;			
    			}
    			else
    			{
    				//找到并开始删除
    				if(cur->_left == nullptr)
    				{
    					if(parent == nullptr)
    					{
    						_root = cur->_right;
    					}
    					else
    					{
    						if(parent->_left == cur)
    						{
    							parent->_left = cur->_right;
    						}
    						else
    						{
    							parent->_right = cur->_right;
    						}
    					}
    
    					delete cur;
    				}
    				else if(cur->_right == nullptr)
    				{
    					if(parent == nullptr)
    					{
    						_root = cur->_left;
    					}
    					else
    					{
    						if(parent->_left == cur)
    						{
    							parent->_left = cur->_left;
    						}
    						else
    						{
    							parent->_right = cur->_left; 
    						}
    					}
    
    					delete cur;
    				}
    				else
    				{
    					Node* minParent = cur;
    					Node* min = cur->_right;
    					while(min->_left)
    					{
    						minParent = min;
    						min = min->_left;						 
    					}
    					
    					cur->_key = min->_key;
    					cur->_value = min->_value;
    
    					if(minParent->_left == min)
    					{
    						minParent->_left = min->_right;
    					}
    					else
    					{
    						minParent->_right = min->_right;
    					}
    
    					delete min;
    				}
    
    				return true;
    			}
    		}
    
    		return false;
    	}
    
    	bool Insert(const K& key, const V& value)
    	{
    		if(_root == nullptr)
    		{
    			_root = new Node(key, value);
    			return true;
    		}
    		
    		Node* parent = nullptr;
    		Node* cur = _root;
    
    		while(cur)
    		{
    			if(cur->_key < key)
    			{
    				parent = cur;
    				cur = cur-> _right;
    			}
    			else if(cur->_key > key)
    			{
    				parent = cur;
    				cur = cur->_left;
    			}
    			else 
    			{
    				return false;
    			}
    		}
    
    		cur = new Node(key, value);
    		if(parent->_key < key)
    		{
    			parent->_right = cur;
    		}
    		else
    		{
    			parent->_left = cur;
    		}
    
    		return true;	
    	}
    
    //private:
    	bool _EraseR(Node*& root, const K& key)
    	{
    		if(root == nullptr)
    		{
    			return false;
    		}
    
    		if(root->_key < key)
    		{
    			return _EraseR(root->_right, key);
    		}
    		else if(root->_key > key)
    		{
    			return _EraseR(root->_left, key);
    		}
    		else
    		{
    			Node* del = root;
    
    			if(root->_left == nullptr)
    			{
    				root = root->_right;
    			}
    			else if(root->_right == nullptr)
    			{
    				root = root->_left;
    			}
    			else
    			{
    				Node* min = root->_right;
    				while(min->_left)
    				{
    					min = min->_left;
    				}
    
    				swap(min->_key, root->_key);
    				//递归到右子树去删除 
    				return _EraseR(root->_right, key); 
    				
    			}
    
    			delete del;
    			return true;
    		}
    	}
    
    	Node* _FindR(Node* root, const K& key)
    	{ 
    		if(root == nullptr)
    		{
    			return nullptr;
    		}
    
    		if(root->_key < key)
    		{
    			return _FindR(root->_right, key);
    		}
    		else if(root->_key > key)
    		{
    			return _FindR(root->_left, key);
    		}
    		else
    		{
    			return root;
    		}
    	}
    
    	Node* FindR(const K& key)
    	{
    		return _FindR(_root, key);
    	}
    	
    	bool _InsertR(Node*& root,const K& key)
    	{
    		if(root == nullptr)
    		{
     			root = new Node(key); 
    			return true;
    		}
    		
    		if(root->_key < key)
    		{
    			return _InsertR(root->_right, key);
    		}
    		else if(root->_key > key)
    		{
    			return _InsertR(root->_left, key);
    		}
    		else
    		{
    			return false;
    		}
    	}
    
    	bool InsertR(const K& key)
    	{
    		return _InsertR(_root, key);
    	}
    
    	bool EraseR(const K& key)
    	{
    		return _EraseR(_root, key);
    	}
    	
    	void InOrder()
    	{
    		_InOrder(_root);
    		cout << endl;
    	}
    
    	void _InOrder(Node* root)
    	{
    		if(root == nullptr)
    		{
    			return;
    		}
    
    		_InOrder(root->_left);
    		cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
    	}
    
    private:
    	Node* _root;
    };

	void TestBSTree1()
	{
		//字典
		BSTree<string, string> dict;
		dict.Insert("sort","排序");
		dict.Insert("left","左边");
		dict.Insert("right","右边");

		string str;
		while(cin >> str)
		{
			BSTreeNode<string,string>* ret = dict.Find(str);
			if(ret)
			{
				cout << "对应中文解释:" << ret->_value << endl;
			}
			else
			{
				cout << "无此单词" << endl;
			}
		}
	}

	void TestBSTree2()
	{
		//统计水果出现的次数
		string arr[] = {"苹果","西瓜","苹果","西瓜","苹果","苹果","西瓜","苹果","香蕉"};
		BSTree<string, int> countTree;
		for(auto& str : arr)
		{
			auto ret = countTree.Find(str);
			if(ret)
			{

				ret->_value++;
			}
			else
			{
				countTree.Insert(str, 1);
			}
		}

		countTree.InOrder();
	}
}
