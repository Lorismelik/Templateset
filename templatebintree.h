#pragma once
#include "Iset.h"
#include <iostream>
class Exception {};
template <typename T> class MySet :
public  ISet<T> 
{
	class Node
	{
		friend class MySet;
		T * value;
		Node * parent;
		Node * left;
		Node * right;
		Node(const T & elem, Node * p = 0) : parent(p), left(0), right(0) 
		{
			value = new T(elem);
		}
		~Node()
		{
			delete value;
		}
	};
	int sizeset;
	Node * seed;

	bool insertNode(const T & elem, Node * & n, Node * p = 0)
	{
		if (!n)
		{
			n = new Node(elem, p);
			return true;
		}
		else if (*(n->value) > elem)
			return insertNode(elem, n->left, n);
		else if (*(n->value) < elem)
			return insertNode(elem, n->right, n);
		else
			return false;
	}

	void insertTree(Node * & n, Node * t)
	{
		if (!n || !t)
			return;
		insertTree(n, t->left);
		insertTree(n, t->right);
		insertNode(*(t->value), n);
	}

	void delTree(Node * n){
		if (!n)
			return;
		delTree(n->left);
		delTree(n->right);
		delete n;
		n = 0;
	}

	Node * findNode(const T & elem, Node * n) {
		if (!n)
			return 0;
		else if (*(n->value) == elem)
			return n;
		else if (*(n->value) > elem)
			return findNode(elem, n->left);
		else
			return findNode(elem, n->right);
	}

	void showNodes(std::ostream & ost, Node * n) 
	{
		char delim = ' ';
		if (!n)
			return;
		showNodes(ost, n->left);
		ost << *(n->value) << delim;
		showNodes(ost, n->right);
	}


	// Конструктор копирования и оператор присваивания закрыты.
    MySet(const MySet &);
	MySet operator = (const MySet &);

public:
 	MySet();
	virtual void add(const T & elem);
	virtual void remove(const T & elem);
	virtual int size() const;
	void show(std::ostream & ost);
	~MySet();
};

template <typename T> MySet<T>::MySet() : seed(0)
{
	sizeset = 0; 
}

template <typename T> MySet<T>::~MySet()
{
	delTree(seed);
}
template <typename T> void MySet<T>::add(const T & elem){
		if (!insertNode(elem, seed))
			throw Exception();
		sizeset++;
	}

template <typename T> void MySet<T>::remove(const T & elem)
{
	Node * n = findNode(elem, seed);
	if (!n)
	{
		throw Exception();
	}
	else if (n == seed)
	{
		if (!n->right)
		{
			Node * aseed = n->left;
			delete seed;
			if (seed = aseed)
				seed->parent = 0;
		}
		else 
		{
			Node * aseed = seed->right;
			Node * aleft;
			for (aleft = aseed; aleft->left; aleft = aleft->left);
			aleft->left = seed->left;
			delete seed;
			seed = aseed;
			seed->parent = 0;
		}
	}
	else 
	{
		Node * & p = n->parent;
		if (n == p->left)
			p->left = 0;
		else
			p->right = 0;
		insertTree(p, n->left);
		insertTree(p, n->right);
		delTree(n);
	}
	sizeset--;
}
template <typename T> void MySet<T>::show(std::ostream & ost)
{
	showNodes(ost, seed);
}
template <typename T> int MySet<T>::size() const
{ 
	return sizeset;
};

