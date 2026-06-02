#pragma once

#include <iostream>
#include <map>
#include <string>

// Funcoes normais: ---------------------------------------------------------------------

//---------------------------------------------------------------------------------------
// Funcoes com template:-----------------------------------------------------------------
template <typename ch, typename val>
val &acharPostOuPerfil(const std::map<ch, val> &conjunto, ch idEscolhido)
{
    auto procurado = conjunto.find(idEscolhido);
    if (procurado != conjunto.end())
        return procurado->second;
    else
    {
        do
        {
            std::cout << "Não encontrado. Digite novamente: ";
            std::cin.ignore();
            std::cin >> idEscolhido;
        } while (procurado == conjunto.end()) return procurado->second;
    }
}
