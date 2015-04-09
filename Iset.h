#pragma once
template <class T> class ISet {
public:

	virtual void add(const T& elem) = 0;

	virtual void remove(const T& elem) = 0;



	virtual int size() const = 0;
};
