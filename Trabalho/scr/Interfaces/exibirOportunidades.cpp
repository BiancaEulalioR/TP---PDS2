#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//------------------------------------OPORTUNIDADES----------------------------------------------------------
void exibirOportunidades(std::map<int, Oportunidades> &postDeOportunidade_)
{

    int opcao;

    do
    {

        std::cout << "=== OPORTUNIDADES ===" << std::endl;
        std::cout << "1. Ver oportunidades" << std::endl;
        std::cout << "2. Publicar oportunidade" << std::endl;
        std::cout << "3. Ver comentarios" << std::endl;
        std::cout << "4. Fazer comentario" << std::endl;
        std::cout << "5. Remover comentario" << std::endl;
        std::cout << "6. Ver informacoes de contato" << std::endl;
        std::cout << "7. Curtir oportunidade" << std::endl;
        std::cout << "8. Remover curtida" << std::endl;
        std::cout << "9. Voltar ao menu principal" << std::endl;

        lerValor(opcao); //progdefensiva

        switch (opcao)
        {
        // Ver oportunidades
        case 1:
        {

            for (auto &i : postDeOportunidade_)
            {
                std::cout << "OPORTUNIDADE (" << i.first << ")" << std::endl;
                std::cout << i.second.getDescricao() << std::endl;
                std::cout << i.second.getLikes() << " likes " << i.second.getComments() << " comentarios" << std::endl;
            }

            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.ignore(); // Ignora/descarta caracteres do buffer
            std::cin.get();    // Captura um único caractere, obs:testar se qualquer tecla funciona
            break;
        }
        // Publicar oportunidade
        case 2:
        {
            std::string descricao;
            std::string contato;

            int id = postDeOportunidade_.size();

            std::cin.ignore();

            std::cout << "Digite a descricao da oportunidade:" << std::endl;
            std::getline(std::cin, descricao); // le a linha inteira, incluindo os espaços, e so para com Enter

            while (descricao.empty())
            {
                std::cout << "Descricao vazia. Digite novamente:" << std::endl;
                std::getline(std::cin, descricao);
            }

            std::cout << "Digite um contato:" << std::endl;
            std::getline(std::cin, contato);

            while (contato.empty())
            {
                std::cout << "Contato vazio. Digite novamente:" << std::endl;
                std::getline(std::cin, contato);
            }

            // TODO:
            // Substituir Perfil() pelo perfil do usuario logado
            Oportunidades novaOp(id, descricao, contato, Perfil());

            postDeOportunidade_[id] = novaOp;

            std::cout << "Oportunidade publicada com sucesso!" << std::endl;

            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.get();

            break;
        }
        // Ver comentarios
        case 3:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            Oportunidades &opSelecionada =
                acharPost(postDeOportunidade_, idOp);

            std::cout << "Comentarios:" << std::endl;

            imprimirElementosComId(opSelecionada.listarComments());

            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }
        // Fazer comentario
        case 4:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva
            Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

            std::string comentario;
            std::cin.ignore();

            std::cout << "Digite seu comentario:" << std::endl;
            std::getline(std::cin, comentario);

            while (comentario.empty())
            {
                std::cout << "O comentario esta vazio. Digite novamente:" << std::endl;
                std::getline(std::cin, comentario);
            }

            opSelecionada.inserirComment(comentario);

            std::cout << "Comentario publicado. Pressione enter para voltar." << std::endl;

            std::cin.get();
            break;
        }
        // Remover comentario
        case 5:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

            std::cout << "Comentarios:" << std::endl;

            imprimirElementosComId(opSelecionada.listarComments());

            int idComentario;

            std::cout << "Digite o id do comentario que deseja remover:" << std::endl;
            lerValor(idComentario); //progdefensiva

            opSelecionada.removerComment(idComentario);

            std::cout << "Comentario removido." << std::endl;

            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }
        // Ver informacoes de contato
        case 6:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

            std::cout << "Usuario que publicou: " << opSelecionada.getPerfil().getUsuario() << std::endl;
            std::cout << "Contato: " << opSelecionada.getContato() << std::endl;
            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }
        // Curtir oportunidade
        case 7:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

            opSelecionada.inserirLike();

            std::cout << "Like registrado." << std::endl;
            std::cout << "Numero de likes: " << opSelecionada.getLikes() << std::endl;
            std::cout << "Pressione enter para voltar." << std::endl;

            std::cin.ignore();
            std::cin.get();

            break;
        }
        // Remover curtida
        case 8:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

            opSelecionada.removerLike();

            std::cout << "Like removido." << std::endl;
            std::cout << "Numero de likes: " << opSelecionada.getLikes() << std::endl;

            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }
        // Voltar ao menu principal
        case 9:
            break;

        default:
            std::cout << "Opcao invalida." << std::endl;
        }

    } while (opcao != 9);
}
