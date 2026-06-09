#ifndef INTERFACES_H
#define INTERFACES_H

#include <map>
#include <string>

#include "Evento.h"
#include "Oportunidades.h"
#include "Servico.h"
#include "Spotted.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"

void exibirMenuInicial(GerenciadorPerfis &gerenciador_, int &aux1, int &aux2, int &id, std::string &nome,
                       std::string &usuario, std::string &senha, std::string &bio, std::string &telefone, std::string &email);

void exibirMenuAbas(std::map<int, Spotted> &postDeSpotted_, std::map<int, Evento> &postDeEvento_,
                    std::map<int, Servico> &postDeServico_, std::map<int, Oportunidades> &postDeOportunidade_, Perfil &usuarioLogado,
                    int &aux2, const int id, GerenciadorPerfis &gerenciador_);

void exibirSpotted(std::map<int, Spotted> &postDeSpotted_);

void exibirEventos(std::map<int, Evento> &postDeEvento_, Perfil &usuarioLogado);

void exibirOportunidades(std::map<int, Oportunidades> &postDeOportunidade_);

void exibirServicos(std::map<int, Servico> &postDeServico_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_);

void exibirAbaBuscar(GerenciadorPerfis &gerenciador_, std::map<int, Evento> &postDeEvento_, std::map<int, Oportunidades> &postDeOportunidade_, std::map<int, Servico> &postDeServico_);

void exibirInfoUsuario(Perfil &perfil);

void configuracoes(Perfil &perfil, GerenciadorPerfis &gerenciador_, int &acesso);

#endif // INTERFACES_H