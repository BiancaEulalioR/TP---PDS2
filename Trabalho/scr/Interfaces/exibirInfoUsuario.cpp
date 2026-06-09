#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//------------------------------INFORMAÇÕES DO USUÁRIO----------------------------------------------------------
void exibirInfoUsuario(Perfil &perfil)
{
    int opcao = 0;
    while(opcao!=5){
        std::cout << "===PERFIL===" << std::endl;
        std::cout << "1.Exibir Informações do perfil" << std::endl;
        std::cout << "2.Editar biografia" << std::endl;
        std::cout << "3.Editar nome de usuario" << std::endl;
        std::cout << "4.Retornar ao menu principal" << std::endl;
        lerValor(opcao); //progdefensiva

        switch(opcao){
            case 1: {
                std::cout << "Informações do perfil:" << std::endl;
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
                perfil.setBio(biotemp);
                std::cout << "Bio alterada com sucesso" << std::endl;
                break;
            }
            case 3: 
            {
                std::string usuariotemp;
                std::cout << "Nome de usuario atual: " << std::endl;
                std::cout << perfil.getUsuario() << std::endl;
                std::cout << "Informe o novo nome de usuario" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, usuariotemp);
                perfil.setUsuario(usuariotemp);
                std::cout << "Nome de usuario alterado com sucesso!" << std::endl;
                break;
            }
            case 4:
            break;

            default: {
                std::cout << "Opcao invalida, tente novamente" << std::endl;
                break;
            }
        }
    }

}

