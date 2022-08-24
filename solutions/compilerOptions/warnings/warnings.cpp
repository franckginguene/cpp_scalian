# include <string>
#include <iostream>

double add(double a, double b)
{
	return a + b;
}

enum MyEnum { a, b, c };
void func(MyEnum e)
{
	switch (e)
	{
	case a:
		break;
	case b:
		break;
	case c:
		break;
	default :
		break;
	}
}

int main()
{
	double res = add(1., 2.);
	std::cout << res;

	//test:

	while (true) 
	{ 
		std::string pc = "Hello";
		
		if (pc.compare("Hello") != 0)
		{
			break;
		} 
	}

	func(MyEnum::a);
}

