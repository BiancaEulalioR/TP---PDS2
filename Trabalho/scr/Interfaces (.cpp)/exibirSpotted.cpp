#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//--------------------------------------SPOTTED----------------------------------------------------------
void exibirSpotted(std::map<int, Spotted> &postDeSpotted_)
{

    int opcaoSpotted = 0;
    while (opcaoSpotted != 10)
    {
        std::cout << "=== SPOTTED ===" << std::endl;
        std::cout << "1. Ver spotteds publicados" << std::endl;
        std::cout << "2. Publicar spotted" << std::endl;
        std::cout << "3. Visualizar comentarios" << std::endl;
        std::cout << "4. Publicar comentario em spotted" << std::endl;
        std::cout << "5. Remover comentario de spotted" << std::endl;
        std::cout << "6. Visualizar curtidas" << std::endl;
        std::cout << "7. Curtir spotted" << std::endl;
        std::cout << "8. Remover curtida de spotted" << std::endl;
        std::cout << "9. Remover spotted" << std::endl;
        std::cout << "10. Voltar ao menu principal" << std::endl;
        lerValor(opcaoSpotted); //progdefensiva

        switch (opcaoSpotted)
        {
        case 1:
        {
            std::cout << "=== SPOTTED ===" << std::endl;
            for (auto &it : postDeSpotted_)
            {

                std::cout << "SPOTTED: " << it.first << std::endl;
                for (auto &i : it.second.listarPosts())
                {

                    std::cout << "Post ID: " << i.first << " | Conteudo: " << i.second << std::endl;
                    std::cout << "Curtidas: " << it.second.getLikes() << std::endl;
                    std::cout << "Comentarios: " << it.second.getComments() << std::endl;
                }
            }
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            break;
        }

        case 2:
        {
            std::cout << "Digite o conteudo do spotted que gostaria de publicar: " << std::endl;
            Spotted novoSpotted;
            std::string spotted;
            std::getline(std::cin, spotted);

            novoSpotted.criarPost(spotted);

            std::cout << "Spotted publicado!" << std::endl;
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;             // volta ao menu
        }
        case 3:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted;
            lerValor(idSpotted); //progdefensiva
            try
            {
                Spotted& spottedSelecionado = acharPost(postDeSpotted_, idSpotted);

                std::cout << "Comentarios: " << std::endl;
                imprimirElementos(spottedSelecionado.listarComments());
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << std::endl;
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        case 4:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted1;
            lerValor (idSpotted1); //progdefensiva
            try{
            Spotted &spottedSelecionado1 = acharPost(postDeSpotted_, idSpotted1);
            std::string novoComentarioSpotted;
            std::cout << "Digite o comentario:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, novoComentarioSpotted); // ler a linha inteira

            while (novoComentarioSpotted.empty()) // comentário vazio
            {
                std::cout << "O comentario esta vazio. Por favor, digite novamente:" << std::endl;
                std::cin.ignore(); // limpa buffer
                std::getline(std::cin, novoComentarioSpotted);
            }

            spottedSelecionado1.inserirComment(novoComentarioSpotted);
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Comentario publicado!" << std::endl;
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;             // volta ao menu
        }
        case 5:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted3;
            lerValor (idSpotted3); //progdefensiva

            Spotted &spottedSelecionado3 = acharPost(postDeSpotted_, idSpotted3);
            const auto &comentarios = spottedSelecionado3.listarComments();

            std::cout << "Comentarios:" << std::endl;

            if (comentarios.empty())
            {
                std::cout << " O post nao tem comentarios" << std::endl;
            }
            else
            {
                std::cout << "Comentarios:" << std::endl;
                for (auto &it : comentarios)
                {
                    std::cout << "ID: " << it.first << " | Conteudo: " << it.second << std::endl;
                }
            }

            std::cout << "==========================" << std::endl;
            std::cout << "Digite o ID do comentario:" << std::endl;

            int idSpottedComment;
            lerValor (idSpottedComment);//progdefensiva

            spottedSelecionado3.removerComment(idSpottedComment);
            std::cout << "Comentario removido!" << std::endl;
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;             // volta ao menu
        }
        case 7:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted2;
            lerValor  (idSpotted2); //progdefensiva
            try{
            Spotted &spottedSelecionado2 = acharPost(postDeSpotted_, idSpotted2);
            spottedSelecionado2.inserirLike();
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Like publicado!" << std::endl;
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;             // volta ao menu
        }
        case 8:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted4;
            lerValor(idSpotted4); //progdefensiva

            Spotted &spottedSelecionado4 = acharPost(postDeSpotted_, idSpotted4);
            deixarCurtida(spottedSelecionado4);
            
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;

            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;           
        }
        case 9:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted6;
            lerValor (idSpotted6);//progdefensiva

            try {
            Spotted &spottedSelecionado5 = acharPost(postDeSpotted_, idSpotted6);
            spottedSelecionado5.apagarPost(idSpotted6);

            std::cout << "Spotted removido!" << std::endl;
            std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;             // volta ao menu
        }

        case 10:
        {
            break;
        }
        }
    }
}
