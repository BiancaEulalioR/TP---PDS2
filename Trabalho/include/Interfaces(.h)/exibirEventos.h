#ifndef EXIBIREVENTOS_H
#define EXIBIREVENTOS_H

#include <map>
#include "Evento.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

void exibirEventos(std::map<int, Evento> &postDeEvento_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif 