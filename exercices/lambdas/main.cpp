#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <execution>
//
void printHeader(const std::string& header)
{
	constexpr auto decorator = "---------";
	std::cout << std::endl << decorator << header << decorator << std::endl;
}
//
int dispAndAdd(const std::vector<int>& vect)
{
	int sum = 0;
	for (auto current : vect)
	{
		sum += current;
		std::cout << current << '\t';
	}
	std::cout << std::endl;
	
	return sum;
}
//
int main()
{
	// Fonction lambda élémentaire
	//////////////////////////////////
	// La syntaxe de la lambada élémentaire est la suivante 
	[](){};
	// On peut la mettre dans une variable puis l'appeler... mais il ne se passe évidemment rien.
	auto fonc = [](){};
	fonc();

	// EXO : Trouver le type de fonc avec l'aide de "typeid"
	printHeader("Exercice 1");
	std::cout << typeid(fonc).name() << std::endl;

	// EXO 2 : Hello world
	printHeader("Exercice 2");
	auto helloWorld = []() {std::cout << "hello world\n"; };
	helloWorld();

	// Premier vrai exemple
	//////////////////////////////////

	// EXO 3 : remplacer l'appel de cette fonction par l'appel à une fonction lambda
	printHeader("Exercice 3");
	std::vector<int> vect = {1, 2, 3, 4};
	dispAndAdd(vect);
	auto LambdaDispAndAdd = [](std::vector<int>& vect) {
		int sum = 0;
		for (auto current : vect)
		{
			sum += current;
			std::cout << current << '\t';
		}
		std::cout << std::endl;

		return sum;
	};
	LambdaDispAndAdd(vect);

	// Block de capture
	//////////////////////////////////
	printHeader("Exercice 4");
	{
		int a = 1;
		auto addAndDisp_ref = [&a](int b)
		{
			int sum = a + b;
			std::cout << "sum = " << sum << '\t';
		};
		addAndDisp_ref(2);
		std::cout << ", a = " << a << std::endl;
	}
	{
		int a = 1;
		auto addAndDisp_ref = [&a](int b)
		{
			a += b;
			std::cout << "sum = " << a << '\t';
		};
		addAndDisp_ref(2);
		std::cout << ", a = " << a << std::endl;
	}
	{
		int a = 1;
		auto addAndDisp_ref = [a](int b) mutable
		{
			a += b;
			std::cout << "sum = " << a << '\t';
		};
		addAndDisp_ref(2);
		std::cout << ", a = " << a << std::endl;
		addAndDisp_ref(2);
		std::cout << ", a = " << a << std::endl;
	}

	// Lambda polymorphiques
	//////////////////////////////////
	printHeader("Exercice 5");
	{
		auto addValVect = [](auto a, auto& vect)
		{
			for (auto& current : vect)
			{
				current += a;
			}
		};

		int a = 1;
		std::vector<double> vect{ 1., 1., 1. };
		addValVect(a, vect);
		std::cout << std::reduce(std::execution::par, vect.cbegin(), vect.cend()) << std::endl;
	}
	{
		// Exemple de lambda polymorphique
		auto addTwoVal = [](auto a, auto b)
		{
			return a + b;
		};
		std::cout << addTwoVal(1, 2.) << std::endl;
	}

	return 0;
}