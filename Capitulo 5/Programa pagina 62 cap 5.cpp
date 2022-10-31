#include <cmath> // std :: abs
#include <algorithm> // std :: max

// Regresa true ssi la diferencia entre a y b est� dentro del porcentaje epsilon del n�mero mayor de a y b
bool approximatelyEqual (double a, double b, double epsilon)
{
		return (std :: abs (a - b) <= (std :: max (std :: abs(a), std :: abs (b)) * epsilon));
}
