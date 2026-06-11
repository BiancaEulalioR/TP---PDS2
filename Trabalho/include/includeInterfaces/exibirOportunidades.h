#ifndef EXIBIROPURTUNIDADES_H
#define EXIBIROPURTUNIDADES_H

#include <map>
#include <string>


#include "Oportunidades.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"
#include "Post.h"

void exibirOportunidades(std::map<int, Oportunidades>& postDeOportunidade_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif