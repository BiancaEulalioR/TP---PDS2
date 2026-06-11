#include <iostream>
#include <string>

#include "Evento.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//------------------------------INFORMAÇÕES DO USUÁRIO----------------------------------------------------------
void exibirInfoUsuario(Perfil &perfil, GerenciadorPerfis &gerenciador_)
{
    int opcao = 0;
    while(opcao!=5){
        std::cout << std::endl;
        std::cout << "=== PERFIL ===" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Exibir Informacoes do perfil" << std::endl;
        std::cout << "2. Editar biografia" << std::endl;
        std::cout << "3. Editar nome de usuario" << std::endl;
        std::cout << "4. Retornar ao menu principal" << std::endl;
        std::cout << std::endl;
        lerValor(opcao); //progdefensiva

        switch(opcao){
            case 1: {
                std::cout << std::endl;
                std::cout << "=== INFORMACOES DO PERFIL ===" << std::endl;
                std::cout << std::endl;
                std::cout << perfil.getNome() << std::endl;
                std::cout << perfil.getUsuario() << std::endl;
                std::cout << perfil.getBio() << std::endl;
                break;
            }

            case 2:
            {
                std::string biotemp;
                std::cout << "Biografia atual: " << std::endl;
                std::cout << perfil.getBio() << std::endl;
                std::cout << "Informe a nova bio: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, biotemp);
                gerenciador_.editarPerfil(perfil.getidu(), "bio", biotemp);
                std::cout << std::endl;
                std::cout << "Bio alterada com sucesso" << std::endl;
                break;
            }
            case 3: 
            {
                std::string nometemp;
                std::cout << "Nome do perfil atual: " << std::endl;
                std::cout << perfil.getNome() << std::endl;
                std::cout << "Informe o novo nome do perfil" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, nometemp);
                gerenciador_.editarPerfil(perfil.getidu(), "nome", nometemp);
                std::cout << std::endl;
                std::cout << "Nome do perfil alterado com sucesso!" << std::endl;
                break;
            }
            case 4:{
                opcao = 5;
                break;
            }
            

            default: {
                std::cout << "Opcao invalida, tente novamente" << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }

}

