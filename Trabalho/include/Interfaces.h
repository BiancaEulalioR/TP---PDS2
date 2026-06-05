#ifndef INTERFACE_H
#define INTERFACE_H

#include <map>
#include <string>

#include "Evento.h"
#include "Oportunidades.h"
#include "Servico.h"
#include "Spotted.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

void exibirMenuInicial(GerenciadorPerfis& gerenciador_, int& aux1, int& aux2, int& aux3, int& id, std::string& n, 
                        std::string& u, std::string& s, std::string& b, std::string& t, std::string& e);

void exibirMenuAbas(std::map<int, Spotted>& postDeSpotted_, std::map<int, Evento>& postDeEvento_,
    std::map<int, Servico>& postDeServico_, std::map<int, Oportunidades>& postDeOportunidade_, int& aux2;); 


void exibirSpotted(std::map<int, Spotted>& postDeSpotted_);

void exibirEventos(std::map<int, Evento>& postDeEvento_);

void exibirOportunidades(std::map<int, Oportunidades>& postDeOportunidade_);

void exibirServicos(std::map<int, Servico>& postDeServico_);

void exibirInfoUsuario(Perfil& perfil);

#endif // INTERFACE_H