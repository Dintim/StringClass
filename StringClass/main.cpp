#include "string_.h"


void main()
{
	string_ s("hello");
	s.insert(2, "world");
	s.print();
	cout << endl;
	s.erase(3, 4);
	s.print();	

	system("pause");
}