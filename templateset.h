#pragma once
#include <iostream>
#include "Iset.h"
using namespace std;
class Exception {};
template <class T> class MySet :
public ISet<T>
{
private:
	int sizeset;
	T* mass;
	int capacity;
public:
	MySet();
	MySet(const MySet<T>& a);
	virtual int size() const;
	virtual  void add(const T& elem);
	virtual  void remove(const T& elem);
	MySet<T>& operator =(const MySet<T>& a);
	virtual  bool contains(const T& elem) const;
	template <class T> friend ostream& operator << (ostream& out, const MySet<T>& a);
	~MySet();
};
template <class T> MySet<T>::MySet() //  Выделяется память под 1 элемент
{
	sizeset = 0;
	mass = new T[1];
	capacity = 1;
};
template <class T> MySet<T>::MySet(const MySet<T>& a)
{
	sizeset = a.sizeset;
	capacity = sizeset + 1;
	mass = new T[capacity];
	for (int i = 0; i<sizeset; i++)
		mass[i] = a.mass[i];
}
template <class T>  int MySet<T>::size() const
{
	int d = (int)sizeset;
	return d;
}
template <class T>  void MySet<T>::add(const T& elem)
{
	if (contains(elem) == true)
	{
		return;
	}
	else
	{
		if (sizeset == capacity)
		{
			T* t;
			capacity *= 2;
			t = new T[capacity];
			for (int i = 0; i < sizeset; i++)
				t[i] = mass[i];
			if (mass!=0)
				delete[] mass;
			mass = t;
		}
		mass[sizeset] = elem;
		sizeset++;
	}
}
template <class T>  bool MySet<T>::contains(const T& elem) const
{
	for (int i = 0; i < sizeset; i++)
	{
		if (mass[i] == elem)
		{
			return true;
		}

	}
	return false;
}
template <class T> MySet<T>& MySet<T>::operator=(const MySet<T>& a)
{
	sizeset = a.sizeset;
	capacity = sizeset + 1;
	if (sizeset != 0)
	{
		if (mass != 0) delete[] mass;
		mass = new T[capacity];
		for (int i = 0; i<sizeset; i++)
			mass[i] = a.mass[i];
	}
	return *this;
}

template <class T> ostream& operator <<(ostream& out, const MySet<T>& a)
{
	if (a.sizeset == 0)
	{
		out << "Empty Set" << endl;
		return out;
	}
	for (int i = 0; i < a.sizeset; i++)
		out << a.mass[i] << " ";
	return out;
}
template <class T>	void MySet<T>::remove(const T& elem)
{
	int i = 0;
	for (i ; mass[i] != elem && i < sizeset; i++);
	if (i == sizeset && mass[sizeset] != elem)
	{
		return;
	};
	for (int j = i; j < sizeset - 1; j++) 
		mass[j] = mass[j + 1];         
	sizeset--;
}
template <class T> MySet<T>::~MySet()
{
	if (mass)
		delete[] mass;
};
