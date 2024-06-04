#include <iostream>
using namespace std; 


int fatorial (int numero) { 
    if(numero == 0) {
        return 1; 
    } else if(numero < 0) {
        return -1; 
    }
    return numero * (fatorial(numero - 1)); 
}

// varre todos os numeros menor o numero multiplicando, quando o numero é menor que 0, retorna -1
int fatorialCommon (int numero) { 
    if(numero < 0) { 
        return -1; 
    }
    int result = 1; 
    for (int i = 1; i <= numero; ++i ) {
       result *= i;  
    }
    return result; 
}


int main () {
    int number;

    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    int result = fatorial(number);
    int result_common = fatorialCommon(number); 
    std::cout << number << "! = " << result << std::endl;
    std::cout << number << "! = " << result_common << std::endl;

    return 0; 
}