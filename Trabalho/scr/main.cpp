#include <iostream>
#include <map>
#include "Evento.h"
#include "Oportunidades.h"
#include "Post.h"
#include "Servico.h"
#include "Spotted.h"
#include "funcoesAuxiares.hpp"
#include "GerenciadorPerfis.h"
#include <string>

void main()
{
    // inicializando maps para guardar os posts:
    std::map<int, Spotted> postDeSpotted_;
    std::map<int, Evento> postDeEvento_;
    std::map<int, Oportunidades> postDeOportunidade_;
    std::map<int, Servico> postDeServico_;
    std::map<int, Perfil> perfis_;

    // lendo os posts e perfis ja salvos de outras vezes em que o programa foi aberto:

    // criação de um perfil

    std::cout << "Qual ação deseja realizar: " << std::endl;
    std::cout << "1.Criar Perfil " << std::endl
              << "2.Entrar " << std::endl;
    int aux1, aux2 = 0, aux3 = 0, id = 0;
    std::cin >> aux1;
    std::string n, u, s, b, t, e;
    GerenciadorPerfis gerenciador_;

    while (1)
    {
        switch (aux1)
        {

        case 1:
        {
            std::cout << "E-mail: " << std::endl;
            std::cin >> e;
            std::cout << "Nome completo: " << std::endl;
            std::cin >> n;
            std::cout << "Nome de usuario: " << std::endl;
            std::cin >> u;
            std::cout << "Senha: " << std::endl;
            std::cin >> s;
            std::cout << "Biografia: " << std::endl;
            std::cin >> b;
            std::cout << "Telefone: " << std::endl;
            std::cin >> t;
            gerenciador_.criaPerfil(n, u, s, id, b, t, e);
            id++;
            aux2 = 1;
            break;
        }

        case 2:
        {
            std::cout << "Nome de usuario: " << std::endl;
            std::cin >> u;
            std::cout << "Senha: " << std::endl;
            std::cin >> s;
            if (gerenciador_.verificaPerfil(id, u, s))
            {
                aux2 = 1;
                std::cout << "Bem vindo!!" << std::endl;
            }
            else
                std::cout << "Perfil nao encontrado.";
        }
        }

        while (aux2)
        {
            std::cout << "Qual aba deseja acessar: " << std::endl;
            std::cout << "1.Spotted" << std::endl;
            std::cout << "2.Eventos" << std::endl;
            std::cout << "3.Oportunidades" << std::endl;
            std::cout << "4.Serviços" << std::endl;
            std::cout << "5.Postar" << std::endl;
            std::cout << "6.Informações do usuario" << std::endl;
            std::cout << "7.Sair do perfil";
            std::cin >> aux3;

            switch (aux3)
            {
            case 1:
            {
                std::cout << "spotteds disponiveis:" << std::endl;
                for (auto &spotted : postDeSpotted_)
                {
                    std::cout << "SPOTTED" << spotted.first << std::endl;
                    for (auto &i : spotted.second.listarPosts())
                    {
                        // Imprime número de likes e comentários para cada mensagem do spotted
                        std::cout << "likes: " << spotted.second.getLikes() << std::endl;
                        std::cout << "Comentarios: " << spotted.second.getComments() << std::endl;
                    }
                }
                int opcao = 0;
                std::cout << "para onde deseja prosseguir?" << std::endl;
                std::cout << "1. Ver os comentarios de um spotted;" << std::endl;
                std::cout << "2. Fazer um comentario em um spotted" << std::endl;
                std::cout << "3. Deixar o like em um spotted" << std::endl;
                std::cout << "4. Remover seu comentario de um spotted" << std::endl;
                std::cout << "5. Retirar seu like de um spotted" << std::endl;
                std::cin >> opcao;
                switch (opcao)
                {
                case 1:
                {
                }
                case 2:
                {
                }
                case 3:
                {
                }
                case 4:
                {
                }
                case 5:
                {
                }
                }
            }

            case 2:
            {
            }
            case 3:
            {
            }
            case 4:
            {
                std::cout << "servicos disponiveis:" << std::endl;
                for (auto &i : postDeServico_)
                {
                    std::cout << "SERVICO (" << i.first << ") " << std::endl;
                    std::cout << (i.second).getDescricaoDoServico() << std::endl;
                    std::cout << (i.second).getLikes() << " likes  " << (i.second).getComments() << " comentarios  " << std::endl;
                    // falta so por o numero de comentarios
                }
                int opcao = 0;
                std::cout << "para onde deseja prosseguir?" << std::endl;
                std::cout << "1. Ver os comentarios de um servico;" << std::endl;
                std::cout << "2. Fazer um comentario em um servico;" << std::endl;
                std::cout << "3. Ver informacoes de contato de um servico;" << std::endl;
                std::cout << "4. Voltar ao menu principal." << std::endl;
                std::cin >> opcao;

                switch (opcao)
                {
                case 1:
                {
                    std::cout << "Deseja ver os comentarios de qual post de servico?(digite o id)" << std::endl;
                    int idserv;
                    std::cin >> idserv;
                    Servico &servicoSelecionado = acharPost(postDeServico_, idserv);
                    std::cout << "Comentarios: " << std::endl;
                    imprimirElementos(servicoSelecionado.listarComments());
                    std::cout << std::endl;
                    std::cout << "Pressione enter para voltar." << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }
                case 2:
                {
                    std::cout << "Em qual post de Servico deseja deixar um comentario?(digite o id)" << std::endl;
                    int idserv1;
                    std::cin >> idserv1;
                    Servico &servicoSelecionado1 = acharPost(postDeServico_, idserv1);
                    std::string novoComentario;
                    std::cout << "Digite seu comentario (apertando enter apenas quando terminar):" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, novoComentario);
                    while (novoComentario.empty())
                    {
                        std::cout << "O comentario esta vazio. Digite-o novamente:" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, novoComentario);
                    }
                    servicoSelecionado1.inserirComment(novoComentario);
                    std::cout << "Comentario publicado. Pressione Enter para voltar." << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }
                case 3:
                {
                    std::cout << "De qual servico deseja ver as informacoes de contato?(digite o id)" << std::endl;
                    int idserv2;
                    std::cin >> idserv2;
                    Servico &servicoSelecionado2 = acharPost(postDeServico_, idserv2);
                    std::string nomeDoPrestador = (servicoSelecionado2.getPerfil()).getUsuario();
                    std::cout << "Usuario que postou esse servico: " << nomeDoPrestador << std::endl;
                    std::cout << "Telefone para contado: " << servicoSelecionado2.getNumeroContato() << std::endl;
                    std::cout << "Pressione enter para voltar." << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }
                case 4:
                    break;
                default:
                    std::cout << "Opcao nao encontrada. Tente novamente." << std::endl;
                    break;
                }
            }
            case 5:
            {
            }
            case 6:
            {
            }
            case 7:
            {
                aux2 = 0;
            }
            }
        }
    }
}