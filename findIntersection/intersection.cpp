#include "intersection.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

// funcao para fazer o parse da string ["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"]
// logica é converter em arrays a partir da virgula que separa as duas listas. 
// 1. Definir uma funcao de parser do vetor. 
// 2. Definida cada lista, varrer na lista comparando os valores de cada indice. 
// 3. Se forem iguais, armazenar num vetor auxiliar. 
// 4. O resultado é varrer o vetor auxiliar com os elementos iguais em ambos vetores. Converter o tipo string para inteiro. 


vector<int> parseStringToVector(const string &str) {
    vector<int> result;  //define vetor resultado do tipo inteiro
    string temp = ""; // define variavel auxiliar

    for(char ch: str) { // varre o vetor recebido. 
        if(ch == ',') { // se o char for a virgula
            if(!temp.empty()) { //verifica se a string nao esta vazia
                result.push_back(stoi(temp)); // aloca no vetor auxiliar de inteiro a string lida convertida para inteiro
                temp = "";
            }
        } else {
            temp += ch; // se for vazia incrementa o valor de ch
        }
    }

    if(!temp.empty()) { // verifica se a string nao esta vazia
        result.push_back(stoi(temp)); //aloca elementos no vetor auxiliar
    }

    return result; // retorna o vetor
}

string FindIntersection(string strArr[]) {
    vector<int> list1 = parseStringToVector(strArr[0]); 
    vector<int> list2 = parseStringToVector(strArr[1]); 

    vector<int> intersection; 

    for(int i = 0; i < list1.size(); i++) { 
        for(int j = 0; j < list2.size(); j++) {
            if(list1[i] == list2[j]) {
                intersection.push_back(list1[i]); 
                break; 
            }
        }
    }

    if(intersection.empty()) {
        return "false"; 
    }

    string result; 
    for(int k = 0; k < intersection.size(); k++) {
        result += to_string(intersection[k]);
        if(k != intersection.size() - 1) {
            result += ",";
        }
    }

    return result; 

}