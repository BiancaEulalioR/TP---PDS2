#ifndef EXIBIRABUSCAR_H
#define EXIBIRABUSCAR_H

#include <map>
#include "Evento.h"
#include "Oportunidades.h"
#include "Servico.h"
#include "GerenciadorPerfis.h"

/**
 * @brief Exibe a aba de busca, e suas acao de buscar um usuario.
 * Alem disso, ao encontrar o usuario buscado, essa aba tambem permite vizualizar os posts especificos dessa pessoa
 *
 * @param postDeEvento_ referencia que aponta para o map que armazena os posts de evento.
 * @param postDeOportunidade_ referencia que aponta para o map que armazena os posts de oportunidade.
 * @param postDeServico_ referencia que aponta para o map que armazena os posts de servico.
 * @param gerenciador_  Armazena o perfil associado
 *
 * @details A aba de configuracoes tem as seguintes opcoes principais em switch case:
 * buscar pelo perfil e retornar ao menu principal.
 * dentro da case buscar por perfil, ha outro switch com abas/cases para acessar as publicacoes feitas pelo
 * usuario do tipo oportunidade, servico e evento.
 * As publicacoes de spotted nao sao acessadas pois esse tipo de post foi planejado para ser anonimo.
 */
void exibirAbaBuscar(GerenciadorPerfis &gerenciador_, std::map<int, Evento> &postDeEvento_,
                     std::map<int, Oportunidades> &postDeOportunidade_, std::map<int, Servico> &postDeServico_);

#endif