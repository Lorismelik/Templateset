#include "templatebintree.h"
void main()
{
	MySet <int> st;
	int i = 3;
	st.add(i);
	i = 2;
	st.add(i);
	i = 33;
	st.add(i);
	i = 0;
	st.add(i);
	i = 6;
	st.add(i);
	st.show(std::cout);
	std::cout << "\n";
	st.remove(i);
	st.show(std::cout);
	i = 3;
	std::cout << "\n";
	st.remove(i);
	st.show(std::cout);
}
