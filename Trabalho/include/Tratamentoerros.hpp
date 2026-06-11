#pragma once
#include <iostream>


// PROGRAMACAO DEFENSIVA

/**
 * @brief Verifica se o tipo da entrada digitada 
 * esta coerente com o tipo utilizado
 * 
 * @tparam T tipo  da entrada
 * 
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
 * @brief Verifica o texto digitado 
 * 
 * @throws std::invalid_argument se o texto esta vazio
 * 
 * @param texto Texto que precisa ser verificado
 */
void verificaTexto(std::string &texto);

/**
 * @brief Verifica se o email digitado 
 * 
 * @throws std::invalid_argument se o email esta vazio
 * @throws std::invalid_argument se nao tiver "." ou "@"
 * 
 * @param email Email que precisa ser verificado
 */
void verificaEmail(std::string &email);

/**
 * @brief Verificao senha digitado
 * 
 * @throws std::invalid_argument se a senha esta vazia 
 * @throws std::invalid_argument se a senha nao tem no minimo 6 caracteres
 * 
 * @param senha Senha que precisa ser verificada
 */
void verificaSenha(std::string &senha);

/**
 * @brief Verifica o telefone digitado 
 * 
 * @throws std::invalid_argument se o telefone esta vazio
 * @throws std::invalid_argument se o telefone nao tem 11 numeros
 * 
 * @param telefone Telefone que precisa ser verificado
 */
void verificaTelefone(std::string &telefone);

/**
 * @brief Verifica se o usuario digitado 
 * 
 * @throws std::invalid_argument se o usuario esta vazio
 * @throws std::invalid_argument se o usuario contem espacos
 * @throws std::invalid_argument se o usuario contem algo alem de
 * letras, numeros, ponto e underline
 * 
 * @param usuario Usuario que precisa ser verificado
 */
void verificaUsuario(std::string &usuario);
