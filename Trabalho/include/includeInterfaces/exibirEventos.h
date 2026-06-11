#ifndef EXIBIREVENTOS_H
#define EXIBIREVENTOS_H

#include <map>
#include "Evento.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

/**
 * @brief Exibe a aba de eventos, suas acoes e publicacoes.
 * Permite interagir com publicacoes e fazer publicacoes de eventos.
 *
 * @param postDeEvento_ Armazena as postagens de evento.
 * @param usuarioLogado  Armazena o usuario que esta logado.
 * @param gerenciador_   Armazena o perfil associado
 *
 * @details A aba de eventos tem as seguintes opcoes em switch case:
 * Ver eventos publicadas, publicar evento, editar evento, apagar evento,
 * visualizar comentarios, publicar comentario em evento,
 * apagar comentario de evento, visualizar curtidas,
 * curtir evento, remover curtida de evento e ver informacoes de contato do evento.
 *
 */
void exibirEventos(std::map<int, Evento> &postDeEvento_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif