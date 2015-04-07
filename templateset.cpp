# Templateset
#pragma once
#include <iostream>
using namespace std;

template <class T> class ISet {
public:

	virtual void add(const T& elem) = 0;

	virtual void remove(const T& elem) = 0;

	virtual bool contains(const T& elem) const = 0;

	virtual int size() const = 0;
};

template <class T> class MySet :
public ISet<T>
{
private:
	int sizeset;
	T* mass;
public:
	 MySet();
	 MySet(int n);
	 int size() const;
	 void add(const T& elem);
	 void remove(const T& elem);
	 T& operator [](int index);
	 bool contains(const T& elem) const;
	 template <class T> friend ostream& operator << (ostream& out, const MySet<T>& a);
	~MySet();
};
	template <class T> MySet<T>::MySet()
	{
		sizeset = 0;
	}
	template <class T> MySet<T>::MySet(int n)
	{
		sizeset = n;
		if (n)
		{
			mass = new T[sizeset];
			for (int i = 0; i<sizeset; i++)
				cin >> mass[i];
		}
		else
			mass = 0;
	}
	template <class T>  int MySet<T>::size() const
	{
		int d = (int)sizeset;
		return d;
	}
	template <class T>  void MySet<T>::add(const T& elem)
	{
		T* t = new int[sizeset+1];
		for (int i = 0; i < sizeset; i++)
		{
			t[i] = mass[i];
			if (mass[i] == elem)
			{
				std::cout <<'\n'<<"Element is already in the set";
				return;
			}
		}
		t[sizeset] = elem;
		mass = t;
		sizeset++;
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
	template <class T> T& MySet<T>::operator[](int index)
	{
		if (index<sizeset) return mass[index];
		else  cout << "\nError! Index>size";
	}
	template <class T> ostream& operator <<(ostream& out, const MySet<T>& a)
	{
		if (a.mass == 0)
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
		for (int i = 0; ; i++)
		{
			if (mass[i] == elem)
			{
				for (int j = i; j < sizeset - 1; j++)
				{
					mass[j] = mass[j + 1];
				}
				sizeset--;
				return;
			}   
		}
	}
	template <class T> MySet<T>::~MySet()
	{
		if (mass)
			delete[] mass;
	};
