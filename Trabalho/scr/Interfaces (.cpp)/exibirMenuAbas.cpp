#include <iostream>
#include <string>

#include "Evento.h"
#include "exibirOportunidades.h" 
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

void exibirMenuAbas(std::map<int, Spotted> &postDeSpotted_, std::map<int, Evento> &postDeEvento_,
                    std::map<int, Servico> &postDeServico_, std::map<int, Oportunidades> &postDeOportunidade_, 
                     Perfil& usuarioLogado, int &acesso, const int id, GerenciadorPerfis& gerenciador_)
{
    while(acesso){
        int aux3 = 0;
        std::cout << "Qual aba deseja acessar: " << std::endl;
        std::cout << "1.Spotted" << std::endl;
        std::cout << "2.Eventos" << std::endl;
        std::cout << "3.Oportunidades" << std::endl;
        std::cout << "4.Serviços" << std::endl;
        std::cout << "5.Buscar" << std::endl;
        std::cout << "6.Perfil" << std::endl;
        std::cout << "7.Configuracoes" << std::endl;
        lerValor(aux3); //progdefensiva

        switch (aux3)
        {
        case 1:
        {
            exibirSpotted(postDeSpotted_);
            break;
        }
        case 2:
        {
            exibirEventos(postDeEvento_, usuarioLogado, gerenciador_);
            break;
        }
        case 3:
        {
            exibirOportunidades(postDeOportunidade_, usuarioLogado, gerenciador);
            break;
        }
        case 4:
        {
            exibirServicos(postDeServico_);
            break;
        }
        case 5: {
            exibirAbaBuscar(gerenciador_, postDeEvento_, postDeOportunidade_, postDeServico_);
            break;
        }
        case 6:
        {
            exibirInfoUsuario(usuarioLogado); // Necessário implementar após a criação do case
            break;
        }
        case 7:
        {
            configuracoes(usuarioLogado, gerenciador_, acesso);
            break;
        }
        default:
        {
            std::cout << "Opcao nao encontrada. Tente novamente." << std::endl;
            break;
        }
        }
    }
}
