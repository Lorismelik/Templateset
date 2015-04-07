#include "templateset.h"
void main(void)
	{
	   MySet <char> st(6);
	   char i = '3';
	   st.add(i);
	   cout << st << endl;
	   bool b = st.contains(i);
	   cout << boolalpha << b << endl;
	   st.remove(i);
	   int c=st.size();
	   cout << c << endl;
	   cout << st << endl;
	   i = '7';
	   st.add(i);
	   cout << st << endl;
	   c = st.size();
	   cout << c << endl;
	} 
