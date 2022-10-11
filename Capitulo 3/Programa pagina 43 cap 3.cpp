#include <iostream>

int getUserinput()
{
		std :: cerr << "llamada a getUserinput() \n";
		std :: cout << "Ingrese un numero: ";
		int x{};
		std :: cin >> x;
		return x;
}

int main ()
{
		std :: cerr << "Clamada a main ()\n";
		int x{ getUserinput() };
		std :: cout << "Usted ingreso: " << x;
		
		return 0;
}
