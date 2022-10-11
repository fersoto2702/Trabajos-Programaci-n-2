#include <iostream>

int readNumber()
{
		std :: cout << "Por favor ingrese un numero: ";
		int x{};
		std :: cin >> x;
		return x;
}

void writeAnswer(int x)
{
		std :: cout << "El cociente es: " << x;
}

int main ()
{
		int x{ 8 };
		int y{ 4 };
		x = readNumber();
		x = readNumber();
		writeAnswer(x/y);
		
		return 0;
}
