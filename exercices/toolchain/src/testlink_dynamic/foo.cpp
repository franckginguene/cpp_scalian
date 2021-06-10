#include <iostream>
 
extern "C"
{
	__declspec(dllexport) void foo(void)
	{
	    std::cout << "Hello from lib foo!" << std::endl;
	}
}