#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <set>
#include "Servico.h"
#include "Perfil.h"
#include <stdexcept>

// Funcoes normais: ---------------------------------------------------------------------

void carregarServicosSalvos(std::map<int, Servico> &servicos_);

//---------------------------------------------------------------------------------------
// Funcoes com template:-----------------------------------------------------------------

template <typename ch, typename val>
val &acharPost(const std::map<ch, val> &conjunto, ch idEscolhido)
{
    auto procurado = conjunto.find(idEscolhido);
    if (procurado == conjunto.end()){
        throw std::invalid_argument("ID nao encontrado.");
    }
        return procurado->second;
}

template <typename ch>
void imprimirElementos(const std::map<ch, std::string> &conjunto)
{
    for (const auto &i : conjunto)
    {
        std::cout << (i.second) << std::endl;
    }
}

template <typename ch, typename val>
void apagarPost(std::map<ch, val> &conjunto, ch chave)
{
    while (conjunto.find(chave) == conjunto.end())
    {
        std::cout << "id nao existente, digite novamente: ";
        std::cin.ignore();
        std::cin << chave;
    }
    conjunto.erase(chave);
}

template <typename ch>
void imprimirElementosComId(const std::map<ch, std::pair<Perfil, std::string>> &conjunto)
{
    for (const auto &i : conjunto)
    {
        std::cout << "ID: " << i.first << " - " 
                  << i.second.first.getUsuario() << ": " 
                  << i.second.second << std::endl;
    }
}