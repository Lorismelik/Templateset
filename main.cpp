#include "templateset.h"
void main(void)
{
	MySet <char> st;
	char i = '3';
	st.add(i);
	cout << st << endl;
	bool b = st.contains(i);
	cout << boolalpha << b << endl;
	int c = st.size();
	cout << c << endl;
	st.remove(i);
	c = st.size();
	cout << c << endl;
	cout << st << endl;
	i = '6';
	st.add(i);
	i = '7';
	st.add(i);
	MySet <char> sr;
	sr = st;
	cout << sr;
}
