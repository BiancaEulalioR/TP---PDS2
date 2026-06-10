#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//------------------------------CONFIGURAÇÕES---------------------------------------------------------------------
void configuracoes(Perfil &perfil, GerenciadorPerfis& gerenciador_, int &acesso){
    int opcao = 0;
    while(opcao!=4){
        std::cout << "===CONFIGURACOES===" << std::endl;
        std::cout << "1.Exibir informacoes de perfil" << std::endl;
        std::cout << "2.Editar informacoes de perfil" << std::endl; // Implementar aindaaaaa
        std::cout << "3.Apagar conta" << std::endl;
        std::cout << "4.Sair da conta" << std::endl;
        std::cout << "5.Retornar ao menu principal" << std::endl;
        lerValor(opcao); //progdefensiva
        std::cout << opcao << std::endl;

        switch(opcao){
            case 1:
            {
                std::cout << "Informacoes do usuario:" << std::endl;
                std::cout << perfil.getEmail() << std::endl;
                std::cout << perfil.getNome() << std::endl;
                std::cout << perfil.getTelefone() << std::endl;
                break;
            }

            case 2:
            {
                int opcaoEditarPerfil = 0;
                std::cout << "AAAAAAA" << std::endl;

                while (opcaoEditarPerfil!=5){
                    std::cout << "O que deseja editar?" << std::endl;
                    std::cout << "1. E-mail" << std::endl;
                    std::cout << "2. Telefone" << std::endl;
                    std::cout << "3. Usuário" << std::endl;
                    std::cout << "4. Senha" << std::endl;
                    std::cout << "5. Voltar ao menu de configuracoes" << std::endl;
                    lerValor(opcaoEditarPerfil); //progdefensiva

                    switch(opcaoEditarPerfil){
                        case 1:
                        {
                            std::cout << "E-mail atual: " << std::endl << perfil.getEmail() << std::endl;
                            std::cout << "Informe o novo e-mail: " << std::endl;
                            std::string emailTemp;
                            std::cin >> emailTemp;
                            gerenciador_.editarPerfil(perfil.getidu(), "email", emailTemp);
                            break;
                        }

                        case 2:
                        {
                            std::cout << "Numero de telefone atual: " << std::endl << perfil.getTelefone() << std::endl;
                            std::cout << "Informe o novo numero de telefone: " << std::endl;
                            std::string telefoneTemp;
                            std::cin >> telefoneTemp;
                            gerenciador_.editarPerfil(perfil.getidu(), "telefone", telefoneTemp);
                            break;
                        }

                        case 3:
                        {
                            std::cout << "Usuario atual: " << std::endl << perfil.getUsuario() << std::endl;
                            std::cout << "Informe o novo usuario: " << std::endl;
                            std::string usuarioTemp;
                            std::cin >> usuarioTemp;
                            gerenciador_.editarPerfil(perfil.getidu(), "usuario", usuarioTemp);
                            break;
                        }

                        case 4:
                        {
                            std::cout << "Senha atual: " << std::endl << perfil.getSenha() << std::endl;
                            std::cout << "Infrmore o novo senha: " << std::endl;

                            std::string senhaTemp;
                            std::cin >> senhaTemp;
                            gerenciador_.editarPerfil(perfil.getidu(), "senha", senhaTemp);
                            break;

                        }

                        case 5:
                        {
                            break;
                        }

                        default:
                        {
                            std::cout << "Opcao invalida, tente novamente." << std::endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 3:
            {
                int opcao2 = 0;
                while(opcao2 != 1 && opcao2 != 2){
                    std::cout << "Tem certeza que deseja apagar a sua conta, e um caminho sem volta!" << std::endl;
                    std::cout << "1.Confirmar" << std::endl << "2.Cancelar" << std::endl;
                    lerValor(opcao2); //progdefensiva;
                    if(opcao2 != 1 && opcao2 != 2)
                    std::cout << "Opcao invalida tente novamente" << std::endl;
                }
                    if(opcao2==1){
                        gerenciador_.apagaPerfil(perfil.getidu(), perfil.getUsuario());
                        acesso = 0;
                        opcao = 4;
                    }
                    break; 
            }
            case 4:
            {
                acesso = 0;
                opcao = 4;
                break;
            }         
            case 5:{
                opcao = 4;
                break;
            }      
            default:{
                std::cout << "Opcao invalida, tente novamente." << std::endl;
                break;
            }
        }
    }
}