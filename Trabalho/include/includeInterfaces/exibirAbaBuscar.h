#ifndef EXIBIRABUSCAR_H
#define EXIBIRABUSCAR_H

#include <map>
#include "Evento.h"
#include "Oportunidades.h"
#include "Servico.h"
#include "GerenciadorPerfis.h"

void exibirAbaBuscar(GerenciadorPerfis& gerenciador_, std::map<int, Evento>& postDeEvento_,
                    std::map<int, Oportunidades>& postDeOportunidade_, std::map<int, Servico>& postDeServico_);

#endif 