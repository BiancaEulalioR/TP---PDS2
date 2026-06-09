#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//--------------------------------------SERVIÇO----------------------------------------------------------
void exibirServicos(std::map<int, Servico> &postDeServico_)
{

    int opcao = 0;
    std::cout << "=== SERVICOS ===" << std::endl;
    std::cout << "1. Ver servicos publicados;" << std::endl;
    std::cout << "2. Publicar um servico;" << std::endl;
    std::cout << "3. Vizualizar comentarios;" << std::endl;
    std::cout << "4. Publicar comentario em um servico;" << std::endl;
    std::cout << "5. Remover comentario de um servico;" << std::endl;
    std::cout << "6. Vizualizar curtidas;" << std::endl;
    std::cout << "7. Curtir servico;" << std::endl;
    std::cout << "8. Remover curtida de um servico;" << std::endl;
    std::cout << "9. Remover servico;" << std::endl;
    std::cout << "10. Ver informacoes de contato de um servico;" << std::endl;
    std::cout << "11. Voltar ao menu principal." << std::endl;
    lerValor(opcao); // progdefensiva.

    switch (opcao)
    {
    case 1:
        for (auto &i : postDeServico_)
        {
            std::cout << "SERVICO (" << i.first << ") " << std::endl;
            std::cout << (i.second).getDescricaoDoServico() << std::endl;
            std::cout << (i.second).getLikes() << " likes  " << (i.second).getComments() << " comentarios  " << std::endl;
        }
        std::cout << "\nPressione enter para voltar." << std::endl;
        std::cin.ignore();
        std::cin.get();
        break;
    case 2:
    {
        std::string descricaoLida, contatoLido;
        int idS = postDeServico_.size();
        std::cout << "Digite a descricao do novo servico:" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, descricaoLida);

        while (descricaoLida.empty())
        {
            std::cout << "Descricao vazia. Digite novamente:" << std::endl;
            std::getline(std::cin, descricaoLida);
        }

        std::cout << "Digite o numero de contato com ddd, tudo junto :" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, contatoLido);
        while (contatoLido.size() != 11)
        {
            std::cout << "Numero invalido. Digite novamente" << std::endl;
            std::getline(std::cin, contatoLido);
        }

        break;
    }
    case 3:
    {
        std::cout << "Deseja ver os comentarios de qual post de servico?(digite o id)" << std::endl;
        int idserv;
        lerValor(idserv); // progdefensiva
        Servico &servicoSelecionado = acharPost(postDeServico_, idserv);
        std::cout << "Comentarios: " << std::endl;
        imprimirElementos(servicoSelecionado.listarComments());
        std::cout << std::endl;
        std::cout << "Pressione enter para voltar." << std::endl;
        std::cin.ignore();
        std::cin.get();
        break;
    }
    case 4:
    {
        std::cout << "Em qual post de Servico deseja deixar um comentario?(digite o id)" << std::endl;
        int idserv1;
        lerValor(idserv1); // progdefensiva
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
    case 10:
    {
        std::cout << "De qual servico deseja ver as informacoes de contato?(digite o id)" << std::endl;
        int idserv2;
        lerValor(idserv2); // progdefensiva
        Servico &servicoSelecionado2 = acharPost(postDeServico_, idserv2);
        std::string nomeDoPrestador = (servicoSelecionado2.getPerfil()).getUsuario();
        std::cout << "Usuario que postou esse servico: " << nomeDoPrestador << std::endl;
        std::cout << "Telefone para contado: " << servicoSelecionado2.getNumeroContato() << std::endl;
        std::cout << "Pressione enter para voltar." << std::endl;
        std::cin.ignore();
        std::cin.get();
        break;
    }
    case 11:
        break;
    default:
        std::cout << "Opcao nao encontrada. Pressione enter para tentar novamente." << std::endl;
        std::cin.ignore();
        std::cin.get();
        break;
    }
}
