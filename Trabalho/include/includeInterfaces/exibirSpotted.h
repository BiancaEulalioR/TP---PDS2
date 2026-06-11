#ifndef EXIBIRSPOTTED_H
#define EXIBIRSPOTTED_H

#include <map>
#include "Spotted.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

/**
 * @brief Exibe a aba de spotted, suas acoes e publicacoes.
 * Permite interagir com publicacoes e fazer publicacoes anonimas.
 *
 * @param postsDeSpotted_ Armazena as postagens de Spotted.
 * @param usuarioLogado  Armazena o usuario que esta logado.
 * @param gerenciador_   Armazena o perfil associado
 *
 * @details A aba spotted tem as seguintes opcoes em switch case:
 * Ver spotteds publicados, publicar spotted, apagar spotted,
 * visualizar comentarios, Publicar comentario em spotted
 * apagar comentario de spotted, visualizar curtidas
 * curtir spotted e remover curtida de spotted
 *
 */
void exibirSpotted(std::map<int, Spotted> &postDeSpotted_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif