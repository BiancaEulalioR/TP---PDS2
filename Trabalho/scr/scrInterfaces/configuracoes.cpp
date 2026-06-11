#include <iostream>
#include <string>

#include "Evento.h"
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

        switch(opcao){
            case 1:
            
            {
                std::cout << "Informacoes do usuario:" << std::endl;
                std::cout << "Email: " << perfil.getEmail() << std::endl;
                std::cout << "Nome: " << perfil.getNome() << std::endl;
                std::cout << "Telefone: " << perfil.getTelefone() << std::endl;
                break;
            }

            case 2:
            {
                int opcaoEditarPerfil = 0;

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

                            verificaEmail(emailTemp);

                            while (gerenciador_.buscaemail(emailTemp) &&
                                emailTemp != perfil.getEmail()) // informar email existe ou o próprio e-mail
                            {
                                std::cout << "Esse email ja esta cadastrado. Digite outro:" << std::endl;
                                std::cin >> emailTemp;
                                verificaEmail(emailTemp);
                            }

                            gerenciador_.editarPerfil(perfil.getidu(), "email", emailTemp);
                            std::cout << "Email atualizado com sucesso!" << std::endl;
                            break;
                        }

                        case 2:
                        {
                            std::cout << "Numero de telefone atual: " << std::endl << perfil.getTelefone() << std::endl;
                            std::cout << "Informe o novo numero de telefone: " << std::endl;
                            std::string telefoneTemp;
                            std::cin >> telefoneTemp;

                            verificaTelefone(telefoneTemp);
                            gerenciador_.editarPerfil(perfil.getidu(), "telefone", telefoneTemp);
                            std::cout << "Telefone atualizado com sucesso!" << std::endl;

                            break;
                        }

                        case 3:
                        {
                            std::cout << "Usuario atual: " << std::endl << perfil.getUsuario() << std::endl;
                            std::cout << "Informe o novo usuario: " << std::endl;
                            std::string usuarioTemp;
                            std::cin >> usuarioTemp;

                            verificaUsuario(usuarioTemp);

                            while (gerenciador_.buscaPorUsuario(usuarioTemp) != nullptr && usuarioTemp != perfil.getUsuario())
                            {   
                                std::cout << "Esse usuario ja esta cadastrado. Digite outro:" << std::endl;
                                std::cin >> usuarioTemp;
                                verificaUsuario(usuarioTemp);
                            }

                            gerenciador_.editarPerfil(perfil.getidu(), "usuario", usuarioTemp);
                            std::cout << "Usuario atualizado com sucesso!" << std::endl;

                            break;
                        }

                        case 4:
                        {
                            std::cout << "Senha atual: " << std::endl << perfil.getSenha() << std::endl;
                            std::cout << "Informe a novo senha: " << std::endl;
                            std::string senhaTemp;
                            std::cin >> senhaTemp;
                            verificaSenha(senhaTemp);
                            
                            gerenciador_.editarPerfil(perfil.getidu(), "senha", senhaTemp);
                            std::cout << "Senha atualizada com sucesso!" << std::endl;
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
                        std::cout << "Conta apagada com sucesso." << std::endl;
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