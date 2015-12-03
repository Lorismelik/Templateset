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
	MySet();       //Для меня деньги бумага
	MySet(const MySet<T>& a);     //Для тебя свобода
	virtual int size() const;     //На американскую мечту сегодня мода
	virtual  void add(const T& elem);     //Работать роботом, ради бумажной мечты
	virtual  void remove(const T& elem);       //Ты менеджер среднего звена
	MySet<T>& operator =(const MySet<T>& a);      //Ты не работаешь под, ты работаешь на
	virtual  bool contains(const T& elem) const;     //Твой этот век, твоя компьютерная эра
	template <class T> friend ostream& operator << (ostream& out, const MySet<T>& a);   //Главное не человек, а его карьера

};
template <class T> MySet<T>::MySet() 
{
	sizeset = 0;       //тебе повезло
	mass = new T[1];    //ты не такой как все
	capacity = 1;       // ты работаешь В ОФИСЕ
};
template <class T> MySet<T>::MySet(const MySet<T>& a) 
{                                                  
	sizeset = a.sizeset;       //степ
	capacity = sizeset + 1;     //бай
	mass = new T[capacity];     //степ
	
	for (int i = 0; i<sizeset; i++) //пока от монитора не ослеп
		mass[i] = a.mass[i];
}
template <class T>  int MySet<T>::size() const
{
	int d = (int)sizeset;   
	return d;                 
}
template <class T>  void MySet<T>::add(const T& elem)      
{
	if (contains(elem) == true)           //Количество операций при переборе равно количеству операций функции contains.
	{
		return;
	}
	else
	{
		if (sizeset == capacity)     //Когда количество реальных элементов достигает количеству выделенной памяти
		{                            //под все элементы множества, количество выделенной памяти удваивается.
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
	for (int i = 0; i < sizeset; i++) //Количетво операций при переборе в среднем равняется (N+1)/2.
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
template <class T>	void MySet<T>::remove(const T& elem) // Производится поиск указанного элемента в множестве помощью
{                                                            // прямого перебора. Сложность O(N).
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
