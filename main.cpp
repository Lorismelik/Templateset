#include "templateset.h"
void main(void)
{
	MySet <char> st;
	char i = '3';
	st.add(i);
	cout << st << endl;
	bool b = st.contains(i);
	cout << boolalpha << b << endl;
	st.remove(i);
	int c = st.size();
	cout << c << endl;
	cout << st << endl;
}
