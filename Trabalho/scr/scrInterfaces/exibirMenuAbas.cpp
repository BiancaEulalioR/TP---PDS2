#include <iostream>
#include <string>

#include "exibirMenuAbas.h"
#include "exibirSpotted.h"
#include "exibirEventos.h"
#include "exibirOportunidades.h"
#include "exibirServicos.h"
#include "exibirAbaBuscar.h"
#include "exibirInfoUsuario.h"
#include "configuracoes.h"
#include "Tratamentoerros.hpp" 

void exibirMenuAbas(Perfil& usuarioLogado, int &acesso, const int id, GerenciadorPerfis& gerenciador_, 
                    std::map<int, Spotted> &postDeSpotted_, std::map<int, Evento> &postDeEvento_, 
                    std::map<int, Oportunidades>& postDeOportunidade_, std::map<int, Servico> &postDeServico_)
{
    while(acesso){
        int aux3 = 0;
        std::cout << std::endl;
        std::cout << "=== QUAL ABA DESEJA ACESSAR? === " << std::endl;
        std::cout << std::endl;
        std::cout << "1. Spotted" << std::endl;
        std::cout << "2. Eventos" << std::endl;
        std::cout << "3. Oportunidades" << std::endl;
        std::cout << "4. Servicos" << std::endl;
        std::cout << "5. Buscar" << std::endl;
        std::cout << "6. Perfil" << std::endl;
        std::cout << "7. Configuracoes" << std::endl;
        std::cout << std::endl;
        lerValor(aux3); //progdefensiva

        switch (aux3)
        {
        case 1:
        {
            exibirSpotted(postDeSpotted_, usuarioLogado, gerenciador_);
            break;
        }
        case 2:
        {
            exibirEventos(postDeEvento_, usuarioLogado, gerenciador_);
            break;
        }
         case 3:
        {
            exibirOportunidades(postDeOportunidade_, usuarioLogado, gerenciador_);
            break;
        }
        case 4:
        {
            exibirServicos(postDeServico_, usuarioLogado, gerenciador_);
            break;
        }
        case 5: {
            exibirAbaBuscar(gerenciador_, postDeEvento_, postDeOportunidade_, postDeServico_);
            break; 
        }
        case 6:
        {
            exibirInfoUsuario(usuarioLogado, gerenciador_);
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
            std::cout << std::endl;
            break;
        }
        }
    }
}

