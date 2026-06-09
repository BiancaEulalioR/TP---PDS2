#include <iostream>
#include <string>

#include "Spotted.h"
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
            std::string spotted;
            int id = postDeSpotted_.size();

            std::cout << "Digite o conteudo do spotted que gostaria de publicar: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, spotted);

            Spotted novoSpotted(spotted, usuarioLogado);
            postDeSpotted_[id] = novoSpotted;

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
        // Publicar comentários
        case 4:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted1;
            lerValor (idSpotted1); //progdefensiva
            try{
            Spotted &spottedSelecionado1 = acharPost(postDeSpotted_, idSpotted1);
            
            std::cout << "Comentarios:" << std::endl;
            imprimirElementosComId(spottedSelecionado1.listarComments());

            
            std::string novoComentarioSpotted;
            std::cout << "Digite o comentario que gostaria de publicar:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, novoComentarioSpotted); // ler a linha inteira

            while (novoComentarioSpotted.empty()) // comentário vazio
            {
                std::cout << "O comentario esta vazio. Por favor, digite novamente:" << std::endl;
                std::getline(std::cin, novoComentarioSpotted);
            }

            spottedSelecionado1.inserirComment(usuariologado, novoComentarioSpotted);
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
        // Apagar comentários
        case 5:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted3;
            lerValor (idSpotted3); //progdefensiva
            Spotted &spottedSelecionado3 = acharPost(postDeSpotted_, idSpotted3);
            
           std::cout << "Comentarios:" << std::endl;
            imprimirElementosComId(spottedSelecionado3.listarComments());

            std::cout << "Digite o ID do comentario que deseja remover:" << std::endl;
            int idComentarioS;

            const std::map<int, std::pair<Perfil, std::string>> &comentariosSpotted = spottedSelecionado.listarComments();
            std::map<int, std::pair<Perfil, std::string>>::const_iterator verificarCommentSpotted = comentariosSpotted.find(idComentario);

            if(verificarCommentSpotted != comentariosSpotted.end()){

                if(verificarCommentSpotted -> second.first.getidu() == usuarioLogado.getidu()){

                    spottedSelecionadO3.removerComment(idComentarioS);
                    std::cout << "Comentario removido com sucesso." << std::endl;
                }

                else {
                    std::cout << "Voce nao possui permissao para apagar esse comentario" << std::endl;
                }
            }

            else
                std::cout << "Comentario nao encontrado." << std::endl;

            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 7:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted2;
            lerValor  (idSpotted2); //progdefensiva

            Spotted &spottedSelecionado2 = acharPost(postDeSpotted_, idSpotted2);
            
            if(spottedSelecionado2.inserirLike(usuarioLogado) == true)
                std::cout << "Curtida registrada." << std::endl;

            else
                std::cout << "Voce ja curtiu essa publicacao." << std::endl;

            std::cout << "Numero de curtidas atual:" << spottedSelecionado2.getLikes() << std::endl;

            std::cout << "Pressione enter para voltar para o menu de spotted." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;           // volta ao menu
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
