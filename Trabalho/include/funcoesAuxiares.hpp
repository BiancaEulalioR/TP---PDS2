#pragma once

#include <iostream>
#include <map>
#include <string>

// Funcoes normais: ---------------------------------------------------------------------

//---------------------------------------------------------------------------------------
// Funcoes com template:-----------------------------------------------------------------

// funcao responsavel por achar o elemento de qualquer map (seja o que guarda algum tipo de post seja um perfil) atraves do seu id.
// retorna uma referencia para esse elemento/valor achado.
template <typename ch, typename val>
val &acharPost(const std::map<ch, val> &conjunto, ch idEscolhido)
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

template <typename ch>
void imprimirElementos(const std::map<ch, std::string> &conjunto)
{
    for (const auto &i : conjunto)
    {
        std::cout << (i.second) << std::endl;
    }
}
