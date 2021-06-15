#include <iostream>
#include "foo.h"
#include "bar.h"

int main(void)
{
	std::cout << "Hello from main!" << std::endl;
    foo();
    bar();
    return 0;
}