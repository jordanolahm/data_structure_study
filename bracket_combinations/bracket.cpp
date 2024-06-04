
#include "bracket.hpp"
#include <stack>
#include <regex>
#include <iostream>

using namespace std; 

// 1. Cria uma pilha vazia. 
// 2. Itera sobre cada elemento da string de entrada. 
// 3. Verifica se o char é um dos elementos de abertura, se for adiciona na pilha. 
// 4. Caso não for, ele verifica se o char é um elemento de fechamento. Caso for, ele verifica se a pilha ta vazia  ou se o caracter no topo da 
//pilha não corresponde ao elemento de fechamento.  Validacao com && verifica se é de fechamento e o de abertura esta no topo da pilha.
// retorna false, pois esta desbalanceado. 
// 5. Remove o elemento do topo da pilha, porque ja sabemos que esta desbalanceado. 
// 6. Retorna true se a pilha estiver vazia. 


bool stackMethodVerify(const std::string* str) {
    stack<char> s;
    //// {]} -> { => ] => }
    for (char c : *str) { // enumeration => le cada caracter da string de entrada
        if (c == '(' || c == '[' || c == '{') { // verifica se o char é algum dos elementos '{' '[' '(' de abertura, adiciona na pilha. 
            s.push(c); // adiciona o elemento na pilha
        } else if (c == ')' || c == ']' || c == '}') { // se o char for algum elemento de fechamento '}' ']' ')' ele faz mais uma verificacao.  
            if (s.empty() || (c == ')' && s.top() != '(') || // verifica se a pilha esta vazia, no caso do primeiro elemento ser de fechamento. 
                (c == ']' && s.top() != '[') || // verifica se o elemento lido é de fechamento e se o topo da pilha tem elemento de abertura.
                (c == '}' && s.top() != '{')) {
                return false;
            }
            s.pop(); // remove o elemento do topo da pilha
        }
    }

    return s.empty(); // retorna true se a pilha estiver vazia.
}


bool stackMethodVerifyDefault(const std::string* str) {
    stack<char> s; // cria a pilha vazia do tipo char

    for (char c : *str) { // itera na pilha 
        if (c == '(' || c == '[' || c == '{') { // verifica se o char selecionado é um elemento de abertura. 
            s.push(c); // caso seja, adiciona na pilha. 
        } else if (c == ')' || c == ']' || c == '}') {  //se nao for elemento abertura, ele verifica se o elemento é de fechamento. 
            if (s.empty()) { // se for, ele verifica se a pilha está vazia, nesse caso se estiver vazia e o elemento for de fechamento, portanto retorna false. 
                return false;
            }

            char top = s.top(); // cria uma variavel que recebe o topo da pilha
            s.pop(); // adiciona o elemento na pilha.  

            if ((top == '(' && c != ')') || // verifica se o char varrido corresponde a o elemento de abertura correspondente. 
                (top == '[' && c != ']') ||
                (top == '{' && c != '}')) { // garante que o elemento não vai duplicar, Topo da pilha tem elemento de abertura e o elemento lido diferente
                return false; // do elemento de fechamento. 
            }
        }
    }

    return s.empty();
}

// o padrao regex utiliza a lib de regex para leitura da string. 
// 1. Define pattern do regex
// 2. compara o patter com a string de input

bool regexValidBrackets(const std::string* str) {
  regex pattern("^[\\(\\[\\{]([\\(\\[\\{])*([\\)\\]\\}])*$");
  return regex_match(*str, pattern);
}

// Funcao que recebe string

// 1. Cria-se variaveis para contar os elementos, uma para cada elemento. Um elemento a esquerda e outro a direita. 
// 2. Itera sobre a string verificando a quantidade de cada elemento, atribuindo valor a ele. 
// 3. Dentro do proprio laço compara, se o valor do elemento a direita for maior que o da esquerda retorna falso. 
// 4. Se nao retorna true, se os valores referentes aos elementos da esquerda e direita forem iguais. 

bool validateString(const std::string* str) {
    int count_left_bracket = 0;
    int count_right_bracket = 0;
    int count_left_paren = 0;
    int count_right_paren = 0;
    int count_left_keys = 0; 
    int count_right_keys = 0; 

    for (char c : *str) {
        if (c == '[') {
            count_left_bracket++;
        } else if (c == ']') {
            count_right_bracket++;
        } else if (c == '(') {
            count_left_paren++;
        } else if (c == ')') {
            count_right_paren++;
        }else if (c == '{') {
            count_left_keys++;
        }else if (c == '}') {
            count_right_keys++;
        }

        if (count_right_bracket > count_left_bracket ||
            count_right_paren > count_left_paren ||
            count_right_keys > count_left_keys) {
            return false;
        }
    }

    return count_left_bracket == count_right_bracket &&
           count_left_paren == count_right_paren && count_left_keys == count_right_keys;
}
