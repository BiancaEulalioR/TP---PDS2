#ifndef EXIBIRMENUABAS_H
#define EXIBIRMENUABAS_H

#include <map>
#include "Spotted.h"
#include "Evento.h"
#include "Servico.h"
#include "Oportunidades.h"
#include "Perfil.h"
#include "GerenciadorPerfis.h"


/**
 * @brief Exibe o menu principal de abas do sistema
 *
 * Apresenta ao usuário logado as abas disponíveis da plataforma,
 * permitindo acessar os módulos de Spotted, Eventos, Oportunidades,
 * Serviços, Busca, Perfil e Configurações. O menu permanece em
 * execução enquanto o usuário estiver logado.
 *
 * @param usuarioLogado perfil do usuário logado
 * @param acesso variável de controle da sessão do usuário
 * @param id identificador do usuário logado
 * @param gerenciador_ gerenciador responsável pelos perfis cadastrados
 * @param postDeSpotted_ conjunto de posts da aba Spotted
 * @param postDeEvento_ conjunto de posts da aba Eventos
 * @param postDeOportunidade_ conjunto de posts da aba Oportunidades
 * @param postDeServico_ conjunto de posts da aba Serviços
 */

void exibirMenuAbas(Perfil& usuarioLogado, int &acesso, const int id, GerenciadorPerfis& gerenciador_, 
                    std::map<int, Spotted> &postDeSpotted_, std::map<int, Evento> &postDeEvento_, 
                    std::map<int, Oportunidades>& postDeOportunidade_, std::map<int, Servico> &postDeServico); 

#endif 
