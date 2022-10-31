#include <iostream>

int main ()

bool approximatelyEqualAbsRel (double a, double b; double absEpsilon, double relEpsilon)
{
		// Comprueba si los n�meros est�n realmente cerca; es necesario cuando se comparan n�meros cercanos a 0
		double diff { std :: abs (a - b) };
		if (diff <= absEpsilon)
			return true;
		
		//De lo contrario, recurra al algoritmo de Knuth
		return (diff <= (std :: max (std :: abs(a), std :: abs (b)) * relEpsilon));
}
