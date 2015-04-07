#pragma once
#include <iostream>
#include "Iset.h"
using namespace std;
template <class T> class MySet :
public ISet<T>
{
private:
	int sizeset;
	T* mass;
public:
	 MySet();
	 MySet(int n);
	 virtual int size() const;
	 virtual  void add(const T& elem);
	 virtual  void remove(const T& elem);
	 T& operator [](int index);
	 virtual  bool contains(const T& elem) const;
	 template <class T> friend ostream& operator << (ostream& out, const MySet<T>& a);
	~MySet();
};
	template <class T> MySet<T>::MySet() //  Выделяется память под 1 элемент
	{
		sizeset = 0;
	}
	template <class T> MySet<T>::MySet(int n) // Выделяется память под заданное количество элементов, повторяющиеся элементы не записываютс, и память под них не выделяется
	{
		sizeset = n;
			mass = new T[sizeset];
			for (int i = 0; i < sizeset; i++)
			{
				T elem;
				cin >> elem;
				mass[i] = elem;
				for (int j = 0; j < i; j++)
				{
					if (elem == mass[j])
					{
						sizeset--;
						i--;
						break;
					}
				}
			}
			if (n != sizeset)
			{
				T* t = new T[sizeset];
				for (int i = 0; i < sizeset; i++)
				{
					t[i] = mass[i];
				}
				delete[] mass;
				mass = t;
			}
	}
	template <class T>  int MySet<T>::size() const
	{
		int d = (int)sizeset;
		return d;
	}
	template <class T>  void MySet<T>::add(const T& elem) 
	{
		T* t = new T[sizeset+1];    // Выделяется память под новый элемент
		if (sizeset != 0)
		{
			for (int i = 0; i < sizeset; i++) При добавлении проверяются все элементы в множестве, чтобы не было повторяющихся элементов O(N)
			{
				t[i] = mass[i];
				if (mass[i] == elem)
				{
					std::cout << '\n' << "Element is already in the set" << endl;
					return;
				}
			}
		}
		delete[] mass;
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
		else  cout << "\nError! Index>size" << endl;
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
		T* t = new T[sizeset - 1]; 
		for (int i = 0; ; i++)           // При удалении проверяются все элементы в множестве пока не будет найден нужный или до конца O(N)
		{
			if (mass[i] == elem)
			{
				if (sizeset != 1)
				{
					for (int j = i; j < sizeset - 1; j++)
					{
						t[j] = mass[j + 1];
					}
				}
				delete[] mass;
				mass = t;
				sizeset--;
				return;
			} 
			t[i] = mass[i];
		}
	}
	template <class T> MySet<T>::~MySet()
	{
		if (mass)
			delete[] mass;
	};
	
