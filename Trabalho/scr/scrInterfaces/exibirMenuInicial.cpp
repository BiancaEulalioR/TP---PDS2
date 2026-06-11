#include <iostream>
#include <string>

#include "Evento.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

void exibirMenuInicial(GerenciadorPerfis &gerenciador_, int &aux1, int &acesso, int &id, std::string &nome,
                       std::string &usuario, std::string &senha, std::string &bio, std::string &telefone,
                       std::string &email)
{

    do
    {
        std::cout << "=== CAMPUSCONNECT ===" << std::endl;
        std::cout << std::endl;
        std::cout << "=== QUAL ACAO DESEJA REALIZAR? ===" << std::endl;
        std::cout << std::endl;
        std::cout << "1. CONNECTE-SE " << std::endl
                  << "2. CADASTRE-SE " << std::endl;
        std::cout << std::endl;          
        lerValor(aux1); // progdefensiva

        switch (aux1)
        {

        case 1:
        {
            do
            {
                std::cout << "Nome de usuario: " << std::endl;
                std::cin >> usuario;
                std::cout << "Senha: " << std::endl;
                std::cin >> senha;
                if (gerenciador_.verificaPerfil(usuario, senha))
                {
                    acesso = 1;
                    Perfil *p = gerenciador_.buscaPorUsuario(usuario);
                    id = p->getidu();
                    std::cout << "Bem vindo ao CampusConnect!" << std::endl;
                }
                else
                {
                    std::cout << "Usuario ou senha incorretos." << std::endl;
                    int opcao;
                    do
                    {
                        std::cout << "1.Tentar novamente" << std::endl;
                        std::cout << "2.Voltar ao menu" << std::endl;
                        lerValor(opcao); // progdefensiva
                        if (opcao != 1 && opcao != 2)
                            std::cout << "Opcao invalida! Tente novamente." << std::endl;
                    } while (opcao != 1 && opcao != 2);
                    if(opcao != 1) break;
                }
            } while (acesso != 1);
            aux1 = 0;
            break;
        }

        case 2:
        {
            std::cin.ignore();

            std::cout << std::endl;
            std::cout << "=== CRIAR CONTA ===" << std::endl;
            std::cout << std::endl;

            std::cout << "E-mail: " << std::endl;
            std::getline(std::cin, email);
            verificaEmail(email);
            while (gerenciador_.buscaemail(email))
            {
                std::cout << "Esse email ja esta cadastrado. Digite outro:"
                        << std::endl;

                std::getline(std::cin, email);
                verificaEmail(email);
            }            
            
            std::cout << "Nome completo: " << std::endl;
            std::getline(std::cin, nome);
             
            std::cout << "Nome de usuario: " << std::endl;
            std::getline(std::cin, usuario);
            verificaUsuario(usuario);
            // verificar se usuario ja existe:
            while (gerenciador_.buscaPorUsuario(usuario) != nullptr)
            {
                std::cout << "Esse nome de usuario ja esta em uso. Tente novamente: " << std::endl;
                std::getline(std::cin, usuario);
                verificaUsuario(usuario);
            }
             
            std::cout << "Senha: " << std::endl;
            std::getline(std::cin, senha);
            verificaSenha(senha);
            
            std::cout << "Telefone: " << std::endl;
            std::getline(std::cin, telefone);
            verificaTelefone(telefone);
            
            bio = " ";
            gerenciador_.criaPerfil(nome, usuario, senha, bio, telefone, email);
            Perfil *p = gerenciador_.buscaPorUsuario(usuario);
            id = p->getidu();
            acesso = 1;
            std::cout << std::endl;
            std::cout << "Connectado com sucesso!" << std::endl;
            std::cout << "Seja bem vindo ao CampusConnect!" std::endl;
            break;
        }

        default:
            std::cout << "Opcao invalida! Tente novamente." << std::endl;
        }
    } while (acesso != 1);
}
