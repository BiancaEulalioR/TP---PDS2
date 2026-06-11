#include <iostream>
#include <string>

#include "Spotted.h"
#include "exibirSpotted.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"
#include "GerenciadorPerfis.h"

//--------------------------------------SPOTTED----------------------------------------------------------
void exibirSpotted(std::map<int, Spotted> &postDeSpotted_, Perfil& usuarioLogado, GerenciadorPerfis &gerenciador_)
{

    int opcaoSpotted = 0;


    while (opcaoSpotted != 10)
    {
        std::cout << "=== SPOTTED ===" << std::endl;
        std::cout << "1. Ver spotteds publicados" << std::endl;
        std::cout << "2. Publicar spotted" << std::endl;
        std::cout << "9. Apagar spotted" << std::endl;
        std::cout << "3. Visualizar comentarios" << std::endl;
        std::cout << "4. Publicar comentario em spotted" << std::endl;
        std::cout << "5. Apagar comentario de spotted" << std::endl;
        std::cout << "6. Visualizar curtidas" << std::endl;
        std::cout << "7. Curtir spotted" << std::endl;
        std::cout << "8. Remover curtida de spotted" << std::endl;
        std::cout << "10. Voltar ao menu principal" << std::endl;
        lerValor(opcaoSpotted); //progdefensiva

        switch (opcaoSpotted)
        {
         //ver spotteds publicados
        case 1:
        {
           
            for (auto &i : postDeSpotted_)
            {
                std::cout << "SPOTTED (" << i.first << ")" << std::endl;
                std::cout << i.second.getSpotted() << std::endl;
                std::cout << i.second.getLikes() << " curtidas" << std::endl;
                std::cout << i.second.getComments() << " comentarios" << std::endl;
                std::cout << " " << std::endl;
            }

            std::cout << "Pressione enter para voltar para o menu de spotteds " << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        
         //publicar spotted
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
         //visualizar comentarios
        case 3:
        {
             std::cout << "Digite o ID do spotted: " << std::endl;

            int idSpotted;
            lerValor(idSpotted); //progdefensiva

            try{
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);

                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(spottedSelecionado.listarComments());
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }           
                       
            std::cout << "Pressione enter para voltar." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }
        // Publicar comentários
        case 4:
        {
            std::cout << "Digite o ID do spotted: " << std::endl;

            int idSpotted;
            lerValor(idSpotted); //progdefensiva
           try{
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);
                std::string comentarioSpotted;
                std::cout << "Digite o comentario: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, comentarioSpotted);
                verificaTexto(comentarioSpotted); //progdefensiva

                spottedSelecionado.inserirComment(usuarioLogado, comentarioSpotted);
                std::cout << "Comentario publicado." << std::endl;
            }           
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar para o menu de spotteds." << std::endl;
            std::cin.get();
            break;         
        }
        // Apagar comentários
        case 5:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted;
            lerValor (idSpotted); //progdefensiva
            
            try{
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);
                
                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(spottedSelecionado.listarComments());

                std::cout << "Digite o ID do comentario que deseja remover:" << std::endl;
                int idComentario;
                lerValor(idComentario);

                const std::map<int, std::pair<Perfil, std::string>> &comentariosSpotted = spottedSelecionado.listarComments();
                std::map<int, std::pair<Perfil, std::string>>::const_iterator verificarCommentSpotted = comentariosSpotted.find(idComentario);

                if(verificarCommentSpotted != comentariosSpotted.end()){

                    if(verificarCommentSpotted -> second.first.getidu() == usuarioLogado.getidu()){

                        spottedSelecionado.removerComment(idComentario);
                        std::cout << "Comentario removido com sucesso." << std::endl;
                    }

                    else {
                        std::cout << "Voce nao possui permissao para apagar esse comentario" << std::endl;
                    }
                }

                else
                    std::cout << "Comentario nao encontrado." << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }           
            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        // Visualizar curtidas -- CORRIGIDO AYLA: case 6 faltando
        case 6:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted;
            lerValor(idSpotted); //progdefensiva

            try
            {
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);
                std::cout << "Numero de curtidas: " << spottedSelecionado.getLikes() << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar para o menu de spotteds." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        //curtir
        case 7:
        {
            std::cout << "Digite o ID do spotted:" << std::endl;
            int idSpotted;
            lerValor  (idSpotted); //progdefensiva

            try {
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);
                
                if(spottedSelecionado.inserirLike(usuarioLogado) == true)
                    std::cout << "Curtida registrada." << std::endl;

                else
                    std::cout << "Voce ja curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual:" << spottedSelecionado.getLikes() << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar para o menu de spotted." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;           // volta ao menu
        }
        //remover curtida
        case 8:
        {
           std::cout << "Digite o ID do spotted: " << std::endl;

            int idSpotted;
            lerValor(idSpotted); //progdefensiva

            try // CORRIGIDO 5: adicionado try/catch
            {
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);

                if (spottedSelecionado.removerLike(usuarioLogado) == true)
                    std::cout << "Curtida removida." << std::endl;
                else
                    std::cout << "Voce nao curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual: " << spottedSelecionado.getLikes() << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar para o menu de spotted." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;

        }
        //remover spotted
        case 9:
        {
            std::cout << "Digite o ID do spotted: " << std::endl;

            int idSpotted;
            lerValor(idSpotted); //progdefensiva
            try // CORRIGIDO 5: adicionado try/catch
            {
                Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);

                if (spottedSelecionado.getPerfil().getidu() == usuarioLogado.getidu())
                {
                    postDeSpotted_.erase(idSpotted);
                    std::cout << "Spotted removido com sucesso." << std::endl;
                }
                else
                    std::cout << "Voce nao possui permissao para apagar esse spotted." << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar para menu de spotted." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        case 10:
        {
            break;
        }

        default:
        {
            std::cout << "Opcao invalida. Tente novamente digitando um numero entre 1 e 10." << std::endl;
            break;
        }        
        }
    }
}


