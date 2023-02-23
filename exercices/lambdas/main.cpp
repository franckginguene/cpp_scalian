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
	// Fonction lambda �l�mentaire
	//////////////////////////////////
	// // EXO 1.0 : Quel est la syntaxe de la lambda �l�mentaire ?
	// TODO
	// On peut la mettre dans une variable puis l'appeler... mais il ne se passe �videmment rien.
	//auto fonc = TODO;
	//fonc();

	// EXO 1.1 : Trouver et afficher le type de fonc avec l'aide de "typeid"
	printHeader("Exercice 1");
	// TODO std::cout << ? << std::endl;

	// EXO 2 : Hello world
	// D�clarer et appeler une lambda qui affiche "Hello world!"
	printHeader("Exercice 2");
	// TODO

	// Premier vrai exemple
	//////////////////////////////////

	// EXO 3.0 : remplacer l'appel de cette fonction par l'appel � une fonction lambda
	printHeader("Exercice 3");
	std::vector<int> vect = {1, 2, 3, 4};
	dispAndAdd(vect);
	// TODO
	// ...
	//LambdaDispAndAdd(vect);
	// EXO 3.1 : remplacer l'appel de cette fonction par l'appel � un algorithme de la std ()

	// Block de capture
	//////////////////////////////////
	printHeader("Exercice 4");
	// Ex�cutez mentalement les block pour d�duire les sorties
	// V�rifiez ensuite vos r�ponses en d�commantant le code
	{
		int a = 1;
		auto addAndDisp_ref = [&a](int b)
		{
			int sum = a + b;
			//std::cout << "sum = " << sum << '\t';
		};
		addAndDisp_ref(2);
		//std::cout << ", a = " << a << std::endl;
	}
	{
		int a = 1;
		auto addAndDisp_ref = [&a](int b)
		{
			a += b;
			//std::cout << "sum = " << a << '\t';
		};
		addAndDisp_ref(2);
		//std::cout << ", a = " << a << std::endl;
	}
	{
		int a = 1;
		auto addAndDisp_ref = [a](int b) mutable
		{
			a += b;
			std::cout << "sum = " << a << '\t';
		};
		addAndDisp_ref(2);
		//std::cout << ", a = " << a << std::endl;
		addAndDisp_ref(2);
		//std::cout << ", a = " << a << std::endl;
	}

	// Lambda polymorphiques
	//////////////////////////////////
	printHeader("Exercice 5");
	{
		// Ecrire une fonction lambda qui ajoute une valeur � chacun des �l�ments d'un vecteur
		//auto addValVect = // TODO
		int a = 1;
		std::vector<double> vect{ 1., 1., 1. };
		//addValVect(a, vect);
		// TODO : afficher la somme des �l�ments du vecteur
		// std::cout << ? << std::endl;
	}
	{
		// lambda polymorphique
		// Ecrire une fonction lambda capable de faire la somme de deux nombres de n'importe quel type
		// (int, float, double etc.)
		//auto addTwoVal = TODO
		//std::cout << addTwoVal(1, 2.) << std::endl;
	}

	return 0;
}