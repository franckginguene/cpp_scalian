#include <iostream>
 
extern "C"
{
	__declspec(dllexport) void bar(void)
	{
	    std::cout << "Hello from lib bar!" << std::endl;
	}
}