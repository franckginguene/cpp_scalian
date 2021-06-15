#include <vector>
#include <iostream>

float add(double a, double b)
{
	return a + b;
}

enum MyEnum { a, b, c };
void func(MyEnum e)
{
	switch (e)
	{
	case a:
	case b:
	break;
	}
}

int main(int argc, char * argv)
{
	float res = add(1., 2.);

	test:

	while (42) 
	{ 
		const char* pc = "Hello";
		if (pc != "Hello")
		{
			break;
		} 
	}

	func(MyEnum::a);
}

