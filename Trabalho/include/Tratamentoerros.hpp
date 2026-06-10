#pragma once

#include <iostream>


// PROGRAMACAO DEFENSIVA


template <typename T>
void lerValor(T& valor)
{
    while (!(std::cin >> valor))
    {
        std::cin.clear(); // remover estado de erro do cin
        std::cin.ignore(10000, '\n'); // remove a entrada errada do buffer
        std::cout << "Entrada invalida. Digite novamente: ";
    }
} 
void verificaTexto(std::string texto){
    bool entradaInvalida= true;
    while(entradaInvalida)
    try
    {
        if (texto.empty()){  
        throw std::invalid_argument("O texto inserido esta vazio.");
        }
        entradaInvalida = false;            
    }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Erro: " << e.what() << " Por favor, digite novamente: "<< std::endl;
            std::getline(std::cin, texto); 
            }
}