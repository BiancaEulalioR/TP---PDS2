#ifndef EXIBIRSERVICOS_H
#define EXIBIRSERVICOS_H

#include <map>
#include "Servico.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

void exibirServicos(std::map<int, Servico> &postDeServico_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

#endif s