#include <iostream>

int add (int x, int y)
{
    return x + y;
}

 void printResult(int z)
{
    std::cout << "la respuesta es: " << z << '\n';
}
int getUserinput()
{
    std::cout << "ingresar un numero: ";
    int x{};
    std::cin >> x;
    return --x;
}

int main()
{
    int x{ getUserinput() };
    int y{ getUserinput() };
    
    int z { add(x, y) };
    printResult(z);
    
    return 0;
}
