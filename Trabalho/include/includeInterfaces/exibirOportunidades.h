#ifndef EXIBIROPURTUNIDADES_H
#define EXIBIROPURTUNIDADES_H

#include <map>
#include <string>

#include "Oportunidades.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"
#include "Post.h"

/**
 * @brief Exibe a aba de oportunidades, suas acoes e publicacoes.
 * Permite interagir com publicacoes e fazer publicacoes de oportunidade.
 *
 * @param postDeOportunidade_ Armazena as postagens de oportunidade.
 * @param usuarioLogado  Armazena o usuario que esta logado.
 * @param gerenciador_   Armazena o perfil associado
 *
 * @details A aba de oportunidades tem as seguintes opcoes em switch case:
 * Ver oportunidades publicadas, publicar oportunidade, editar oportunidade, apagar oportunidade,
 * visualizar comentarios, publicar comentario em oportunidade,
 * apagar comentario de oportunidade, visualizar curtidas,
 * curtir oportunidade, remover curtida de oportunidade e ver informacoes de contato da oportunidade
 *
 */
void exibirOportunidades(std::map<int, Oportunidades> &postDeOportunidade_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif