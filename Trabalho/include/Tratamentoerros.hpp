#pragma once
#include <iostream>


// PROGRAMACAO DEFENSIVA

/**
 * @brief Verifica se o tipo da entrada digitada 
 * esta coerente com o tipo utilizado
 * @tparam T tipo  da entrada
 * @param valor Valor a ser verificado
 */
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

/**
 * @brief Verifica se o texto digitado 
 * nao esta vazio
 * @param texto Texto que precisa ser verificado
 */
void verificaTexto(std::string &texto);

/**
 * @brief Verifica se o email digitado 
 * nao esta vazio e se possui "@" e ".";
 * @param email Email que precisa ser verificado
 */
void verificaEmail(std::string &email);

/**
 * @brief Verifica se o email digitado 
 * nao esta vazio e se possui no minimo 6 caracteres
 * @param senha Senha que precisa ser verificada
 */
void verificaSenha(std::string &senha);

/**
 * @brief Verifica se o telefone digitado 
 * nao esta vazio e se possui no minimo 11 caracteres numericos
 * @param telefone Telefone que precisa ser verificada
 */
void verificaTelefone(std::string &telefone);

/**
 * @brief Verifica se o usuario digitado 
 * nao esta vazio e se nao contem espacos
 * @param usuario Usuario que precisa ser verificada
 */
void verificaUsuario(std::string &usuario);
