#include <iostream>

int agregar (int x, int y)
{
		return x - y; //Se supone que la función debe de agregar, pero no es así
}

int main ()
{
		std :: cout << agregar (5, 3); //Deberia de producir 8, pero produce 2
		
		return 0;
}
