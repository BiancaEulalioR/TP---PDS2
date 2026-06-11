#ifndef EXIBIRMENUABAS_H
#define EXIBIRMENUABAS_H

#include <map>
#include "Spotted.h"
#include "Evento.h"
#include "Servico.h"
#include "Oportunidades.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

void exibirMenuAbas(Perfil& usuarioLogado, int &acesso, const int id, GerenciadorPerfis& gerenciador_, 
                    std::map<int, Spotted> &postDeSpotted_, std::map<int, Evento> &postDeEvento_, 
                    std::map<int, Oportunidades>& postDeOportunidade_, std::map<int, Servico> &postDeServico); 

#endif 
