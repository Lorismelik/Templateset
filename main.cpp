#include "templateset.h"
	
void main(void)
	{
	   MySet <char> st(6);
	   char i = '3';
	   bool b = st.contains(i);
	   cout <<boolalpha<<b << '\n';
	   st.remove(i);
	   int c=st.size();
	   cout << c;
	   cout << '\n' << st;
	   st.add(i);
	   cout << '\n' << st;
	} 
