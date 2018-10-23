#include "string_.h"
//#include <stdlib.h>
//#include <stdlib.h>
//#include <cstring>


void main()
{
	

	string_ s("hello");
	string_ d(" world");
	s += d;
	s.print();

	system("pause");
}