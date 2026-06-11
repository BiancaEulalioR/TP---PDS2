#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <set>
#include "Servico.h"
#include "Perfil.h"
#include <stdexcept>
#include "GerenciadorPerfis.h"

/**
 * @brief Localiza o post, seja ele do tipo que for, dentro do seu map especifico atraves do id
 *
 * @tparam ch tipo da chave utilizada no map
 * @tparam val tipo do valor armazenado no map
 * @param conjunto Referencia que aponta para o map onde a funcao vai procurar o elemento
 * @param idEscolhido copia do valor do id do post que se quer encontrar
 *
 * @return referencia que aponta para o post encontrado no map
 */
template <typename ch, typename val>
val &acharPost(std::map<ch, val> &conjunto, ch idEscolhido)
{
    auto procurado = conjunto.find(idEscolhido);
    if (procurado == conjunto.end())
    {
        throw std::invalid_argument("ID nao encontrado.");
    }
    return procurado->second;
}

/**
 * @brief Imprime na tela todos os elementos de um map generico cujos valores sejam do tipo std::string
 *
 * @tparam ch tipo da chave utilizada no map
 * @param conjunto Referencia que aponta para o map que contem os elementos a serem impressos
 */
template <typename ch>
void imprimirElementos(const std::map<ch, std::string> &conjunto)
{
    for (const auto &i : conjunto)
    {
        std::cout << (i.second) << std::endl;
    }
}

/**
 * @brief deleta o post do map em que ele estava armazenado
 *
 * @tparam ch tipo da chave utilizada no map
 * @tparam val tipo do valor armazenado no map
 * @param conjunto referencia que aponta para io map no qual o post esta contido
 * @param chave id associado a esse post
 *
 * Antes de prosseguir, ela verifica se o post existe mesmo dentro do map
 */
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

/**
 * @brief Imprime a chave/id dos elementos de um map, seguido dos nomes de usuario de seus valores(posts)
 *
 * @tparam ch tipo da chave utilizada no map
 * @param conjunto Referencia que aponta para o map que contem os elementos a serem impressos
 */
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

/**
 * @brief Imprime na tela os nomes de usuario dos perfis que curtiram o post selecionado
 *
 * @tparam ch tipo da chave utilizada no map
 * @tparam TipoDePost pode ser Servico, Spotted, Oportunidade ou Evento
 * @param conjunto Referencia que aponta para o map que contem os posts
 * @param idEscolhido id do post selecionado para ver as curtidas
 * @param mapComOsPerfis_ map que armazena os posts
 */
template <typename ch, typename TipoDePost>
void exibirUsuariosQueCurtiram(std::map<ch, TipoDePost> &conjunto, ch idEscolhido, GerenciadorPerfis &mapComOsPerfis_)
{
    Post &postSelecionado = acharPost(conjunto, idEscolhido);
    std::set<int> setDeQuemCurtiu = postSelecionado.getPessoasQueCurtiram();
    std::cout << "Esse post recebeu curtidas de:" << std::endl;
    for (auto i = setDeQuemCurtiu.begin(); i != setDeQuemCurtiu.end(); i++)
    {
        Perfil *perfilQueCurtiu = mapComOsPerfis_.buscaPorID(*i);
        if (perfilQueCurtiu)
            std::cout << "@" << perfilQueCurtiu->getUsuario() << std::endl;
    }
    std::cout << std::endl;
}