#ifndef EXIBIRSERVICOS_H
#define EXIBIRSERVICOS_H

#include <map>
#include "Servico.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

/**
 * @brief Exibe a aba de servico, suas acoes e publicacoes.
 * Permite interagir com publicacoes e fazer publicacoes de servico.
 *
 * @param postsDeServico_ Armazena as postagens do Servico.
 * @param usuarioLogado  Armazena o usuario que esta logado.
 * @param gerenciador_   Armazena o perfil associado
 *
 * @details A aba de servicos tem as seguintes opcoes em switch case:
 * Ver servicos publicados, publicar servico, editar servico, apagar servico,
 * visualizar comentarios, publicar comentario em servico,
 * apagar comentario de servico, visualizar curtidas,
 * curtir servico, remover curtida de servico e ver informacoes de contato do servico
 *
 */
void exibirServicos(std::map<int, Servico> &postDeServico_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif
