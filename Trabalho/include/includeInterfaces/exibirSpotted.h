#ifndef EXIBIRSPOTTED_H
#define EXIBIRSPOTTED_H

#include <map>
#include "Spotted.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

void exibirSpotted(std::map<int, Spotted> &postDeSpotted_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif