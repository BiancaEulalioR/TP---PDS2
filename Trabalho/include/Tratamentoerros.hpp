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
template <typename C> 
void deixarCurtida(C& valor){
            try
            {
             
                if (valor.getLikes() == 0)
                {
                    throw std::runtime_error("O nao post tem curtidas.");
                }

                valor.removerLike();
                std::cout << "Like removido!" << std::endl;
                std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Erro: " << e.what() << std::endl;
            }
}