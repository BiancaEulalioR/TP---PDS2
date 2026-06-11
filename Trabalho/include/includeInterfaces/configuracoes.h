#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H

#include "Perfil.h"
#include "GerenciadorPerfis.h"

/**
 * @brief Exibe a aba de configuracoes, e suas acoes.
 * Permite visualizar e alterar os dados da conta logada, alem de poder desconectar dela.
 *
 * @param perfil referencia que aponta para o perfil logado.
 * @param acesso int que indica que ha uma conta logada ou nao. Seu valor e zero se ninguem estiver logado.
 * @param gerenciador_  Armazena o perfil associado
 *
 * @details A aba de configuracoes tem as seguintes opcoes em switch case:
 * Exibir na tela as informacoes do perfil logado, editar essas informacoes do perfil,
 * apagar a conta, desconectar do perfil logado, retornar ao menu principal.
 */
void configuracoes(Perfil &perfil, GerenciadorPerfis &gerenciador_, int &acesso);

#endif