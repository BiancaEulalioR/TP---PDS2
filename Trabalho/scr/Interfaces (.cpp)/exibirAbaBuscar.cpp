#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//--------------------------------------BUSCAR------------------------------------------------------------------
void exibirAbaBuscar(GerenciadorPerfis& gerenciador_, std::map<int, Evento>& postDeEvento_, std::map<int, 
                    Oportunidades>& postDeOportunidade_, std::map<int, Servico>& postDeServico_)
{
    int opcaoBuscar = 0;

    while(opcaoBuscar != 2){
        std::cout << "=== BUSCAR ===" << std::endl;
        std::cout << "1. Buscar por usuário" << std::endl;
        std::cout << "2. Voltar para menu principal" << std::endl;
        lerValor(opcaoBuscar); //progdefensiva

            switch(opcaoBuscar){
                case 1: 
                {
                    std::string usuarioBuscado;

                    std::cout << "Digite o nome de usuario que deseja buscar:" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, usuarioBuscado);

                    Perfil* usuarioEncontrado = gerenciador_.buscaPorUsuario(usuarioBuscado);

                    if(usuarioEncontrado != nullptr){
                        int opcaoAcessarPost = 0;

                        std::cout << "=== PERFIL DE USUARIO ===" << std::endl;
                        std::cout << usuarioEncontrado -> getNome() << std::endl;
                        std::cout << "@" << usuarioEncontrado-> getUsuario() << std::endl;
                        std::cout << usuarioEncontrado -> getBio() << std::endl;
                        std::cout << "1. Acessar publicacoes de @" << usuarioEncontrado-> getUsuario() << std::endl;
                        lerValor(opcaoAcessarPost);

                        switch(opcaoAcessarPost){

                            case 1:
                            {

                            int opcaoPostUsuario = 0;

                            while(opcaoPostUsuario != 4){
                                    std::cout << "1. Eventos" << std::endl;
                                    std::cout << "2. Oportunidades" << std::endl;
                                    std::cout << "3. Servicos" << std::endl;
                                    std::cout << "4. Voltar ao perfil" << std::endl;
                                    lerValor(opcaoPostUsuario);
                                        
                                    switch(opcaoPostUsuario){
                                        case 1: 
                                        {
                                            std::cout << "=== EVENTOS DE @" << usuarioEncontrado-> getUsuario() << " ===" << std::endl;

                                            bool possuiEventos = false;

                                            for(auto& i : postDeEvento_)
                                            {
                                                if(i.second.getPerfil().getidu() == usuarioEncontrado->getidu())
                                                {
                                                    possuiEventos = true;
                                                    std::cout << "EVENTO (" << i.first << ")" << std::endl;
                                                    std::cout << i.second.getTextoEvento() << std::endl;
                                                    std::cout << "Contato: " << i.second.getContato() << std::endl;
                                                    std::cout << i.second.getLikes() << " curtidas" << std::endl;
                                                    std::cout << i.second.getComments() << " comentarios" << std::endl;
                                                    std::cout << std::endl;
                                                }
                                            }

                                            if(possuiEventos == false){
                                                std::cout << "Esse usuario nao possui eventos publicados" << std::endl;
                                            }

                                            std::cout << "Pressione enter para voltar para o menu de publicacoes." << std::endl;
                                            std::cin.get();
                                            break;
                                        }
                                        case 2:
                                        {
                                            std::cout << "=== OPORTUNIDADES DE @" << usuarioEncontrado-> getUsuario() << " ===" << std::endl;

                                            bool possuiOportunidades = false;

                                            for(auto& i : postDeOportunidade_)
                                            {
                                                if(i.second.getPerfil().getidu() == usuarioEncontrado->getidu())
                                                {
                                                    possuiOportunidades = true;
                                                    std::cout << "OPORTUNIDADE (" << i.first << ")" << std::endl;
                                                    std::cout << i.second.getDescricao() << std::endl;
                                                    std::cout << "Contato: " << i.second.getContato() << std::endl;
                                                    std::cout << i.second.getLikes() << " curtidas" << std::endl;
                                                    std::cout << i.second.getComments() << " comentarios" << std::endl;
                                                    std::cout << std::endl;
                                                }
                                            }

                                            if(possuiOportunidades == false){
                                                std::cout << "Esse usuario nao possui oportunidades publicados" << std::endl;
                                            }

                                            std::cout << "Pressione enter para voltar para o menu de publicacoes." << std::endl;
                                            std::cin.get();
                                            break;
                                        }
                                        case 3:
                                        {
                                            std::cout << "=== SERVICOS DE @" << usuarioEncontrado-> getUsuario() << " ===" << std::endl;

                                            bool possuiServico = false;

                                            for(auto& i : postDeServico_)
                                            {
                                                if(i.second.getPerfilAssociado().getidu() == usuarioEncontrado->getidu())
                                                {
                                                    possuiServico = true;
                                                    std::cout << "SERVICO (" << i.first << ")" << std::endl;
                                                    std::cout << i.second.getDescricaoDoServico() << std::endl;
                                                    std::cout << "Contato: " << i.second.getNumeroContato() << std::endl;
                                                    std::cout << i.second.getLikes() << " curtidas" << std::endl;
                                                    std::cout << i.second.getComments() << " comentarios" << std::endl;
                                                    std::cout << std::endl;
                                                }
                                            }

                                            if(possuiServico == false){
                                                std::cout << "Esse usuario nao possui servicos publicados" << std::endl;
                                            }

                                            std::cout << "Pressione enter para voltar para o menu de publicacoes." << std::endl;
                                            std::cin.get();
                                            break;
                                        }
                                        case 4:
                                        {
                                          break;
                                        }
                                        default:
                                        {
                                            std::cout << "Opcao nao encontrada. Por favor, tente novamente." << std::endl;
                                            break;
                                        }
                                
                                    }

                            }
                            }
                        default:{
                            std::cout << "Opcao nao encontrada. Por favor, tente novamente." << std::endl;
                            break;
                        }
                        }
                    }
                    else{
                        std::cout << "Usuario nao encontrado." << std::endl;
                    }

                    std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
                    std::cin.get();
                    break;

                }

                case 2: 
                {
                    break;
                }

                default:
                {
                    std::cout << "Opcao nao encontrada. Por favor, tente novamente." << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }

            }

    }
}
