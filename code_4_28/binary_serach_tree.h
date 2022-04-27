#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BSTNode
{
  BSTNode<K>* _left;
  BSTNode<K>* _right;
  K _key;

  BSTNode(const K& key)
    :_left(nullptr)
    ,_right(nullptr)
    ,_key(key)
  {}
};

template<class K>
struct BST
{
  typedef BSTNode<K> Node;
public:
  BST()
    :_root(nullptr)
  {}
  
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
      //插入的数比当前的数要大
      if(cur->_key < key)
      {
        parent = cur;
	cur = cur->_right;
      }
      //插入的数比当前的数小
      else if(cur->_key > key)
      {
        parent = cur;
	cur = cur->_left;
      }
      //插入的数相等
      else
      {
        return false;
      }
    }
    //链接
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

  bool Find(const K& key)
  {
    Node* cur = _root;
    while(cur)
    {
      if(cur->_key < key)
      {
        cur = cur->_right;
      }
      else if(cur->key > key)
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

  /*bool Erase(const K& key)
  {
    
  }*/

  void InOrder()
  {
    _InOrder(_root);
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

void TestBST()
{
  BST<int> t;
  int a [] = {5,3,4,1,7,8,2,6,0,9};
  for(auto e : a)
  {
    t.Insert(e);
  }

  //cout << endl;
  //排序+去重
  t.InOrder();

  cout << endl;
}
