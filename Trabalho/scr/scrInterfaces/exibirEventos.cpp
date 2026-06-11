#include <iostream>
#include <string>

#include "Evento.h"
#include "exibirEventos.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//--------------------------------------EVENTOS----------------------------------------------------------
void exibirEventos(std::map<int, Evento> &postDeEvento_, Perfil& usuarioLogado, GerenciadorPerfis &gerenciador_)
{
    int opcaoEvento = 0;

    while (opcaoEvento != 11)
    {
        std::cout << std::endl;
        std::cout << "=== EVENTOS ===" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Ver eventos publicados" << std::endl;
        std::cout << "2. Publicar evento" << std::endl;
        std::cout << "3. Editar evento" << std::endl;
        std::cout << "4. Apagar evento" << std::endl;
        std::cout << "5. Visualizar comentarios" << std::endl;
        std::cout << "6. Publicar comentario em evento" << std::endl;
        std::cout << "7. Apagar comentario de evento" << std::endl;
        std::cout << "8. Visualizar curtidas" << std::endl;
        std::cout << "9. Curtir evento" << std::endl;
        std::cout << "10. Remover curtida de evento" << std::endl;
        std::cout << "11. Voltar ao menu principal" << std::endl;
        std::cout << std::endl;
        lerValor(opcaoEvento); //progdefensiva

        switch (opcaoEvento)
        {

        // Ver eventos publicados
        case 1:
        {

            for (auto &i : postDeEvento_)
            {
                std::cout << "EVENTO (" << i.first << ")" << std::endl;
                std::cout << i.second.getPerfil().getUsuario() << std::endl;
                std::cout << "Contato: " << i.second.getContato() << std::endl;
                std::cout << i.second.getTextoEvento() << std::endl;
                std::cout << i.second.getLikes() << " curtidas" << std::endl;
                std::cout << i.second.getComments() << " comentarios" << std::endl;
                std::cout << " " << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de eventos " << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Publicar evento
        case 2:
        {
            std::string texto_evento, contato_evento;
            int id = postDeEvento_.size();

            std::cout << "Digite o contato responsavel pela organizacao do evento:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, contato_evento);

            while(contato_evento.empty()){

                std::cout << "Contato vazio. Tente novamente." << std::endl;
                std::getline(std::cin, contato_evento);
            }

            std::cout << "Digite o texto do evento a ser publicado:" << std::endl;
            std::getline(std::cin, texto_evento);

            while(texto_evento.empty()){
                
                std::cout << "Descricao vazia. Tente novamente." << std::endl;
                std::getline(std::cin, texto_evento);
            }

            Evento novoEvento(texto_evento, contato_evento, usuarioLogado);
            postDeEvento_[id] = novoEvento;

            std::cout << "Evento publicado!" << std::endl;
            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.get();
            break;
        }

        // Editar evento
        case 3:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva
            
            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);   

                if(eventoSelecionado.getPerfil().getidu() == usuarioLogado.getidu()){
                    
                    int opcaoEditarEvento = 0;
                    std::string novoContato, novoTexto;

                    while (opcaoEditarEvento != 3){
                    std::cout << "O que deseja editar?" << std::endl;
                    std::cout << "1. Editar contato de evento" << std::endl;
                    std::cout << "2. Editar descricao do evento" << std::endl;
                    std::cout << "3. Voltar ao menu de eventos" << std::endl;
                    lerValor(opcaoEditarEvento); //progdefensiva

                        switch (opcaoEditarEvento)
                        {
                            case 1:
                            {
                                std::cout << "Digite o novo contato:" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, novoContato);

                                while(novoContato.empty()){

                                    std::cout << "Contato vazio. Tente novamente." << std::endl;
                                    std::getline(std::cin, novoContato);
                                }

                                eventoSelecionado.editarContato(novoContato);
                                std::cout << "Contato atualizado com sucesso." << std::endl;
                                std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
                                std::cin.get();
                                break;
                            }

                            case 2:
                            {
                                std::cout << "Digite o novo evento:" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, novoTexto);

                                while(novoTexto.empty()){

                                    std::cout << "Descricao vazia. Tente novamente." << std::endl;
                                    std::getline(std::cin, novoTexto);
                                }

                                eventoSelecionado.editarEvento(novoTexto);
                                std::cout << "Evento atualizado com sucesso." << std::endl;
                                std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
                                std::cin.get();
                                break;
                            }

                            case 3:
                            {
                                break;
                            }

                            default:
                            {
                                std::cout << "Opcao invalida. Tente novamente digitando um numero de 1 a 3." << std::endl;
                                break;
                            }
                        }
                }
            }

            else
                std::cout << "Voce nao possui permissao para editar esse evento." << std::endl;
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Apagar evento
        case 4:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva

            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);   

                if(eventoSelecionado.getPerfil().getidu() == usuarioLogado.getidu()){
                postDeEvento_.erase(idEvento);
                std::cout << "Evento removido com sucesso." << std::endl;
                }

                else
                    std::cout << "Voce nao possui permissao para apagar esse evento." << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Visualizar comentários
        case 5:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva

            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(eventoSelecionado.listarComments());
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }


            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }

        // Publicar comentários
        case 6:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                lerValor(idEvento); //progdefensiva

            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);
                std::string comentarioEvento;
                std::cout << "Digite o comentario: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, comentarioEvento);
                verificaTexto(comentarioEvento); //progdefensiva

                eventoSelecionado.inserirComment(usuarioLogado, comentarioEvento);
                std::cout << "Comentario publicado." << std::endl;
            }    
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            
            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.get();
            break;
        }

        // Apagar comentários
        case 7:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva

            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(eventoSelecionado.listarComments());

                std::cout << "Digite o ID do comentario que deseja remover:" << std::endl;
                int idComentario;
                lerValor(idComentario); //progdefensiva

                const std::map<int, std::pair<Perfil, std::string>> &comentariosEvento = eventoSelecionado.listarComments();
                std::map<int, std::pair<Perfil, std::string>>::const_iterator verificarComentEvento = comentariosEvento.find(idComentario);

                if(verificarComentEvento != comentariosEvento.end()){

                    if(verificarComentEvento -> second.first.getidu() == usuarioLogado.getidu()){

                        eventoSelecionado.removerComment(idComentario);
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

            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Visualizar curtidas
        case 8:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva
            try
            {
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);
                std::cout << "Numero de curtidas do evento selecionado:" << eventoSelecionado.getLikes() << std::endl;
                exibirUsuariosQueCurtiram(postDeEvento_, idEvento, gerenciador_);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }            

            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Curtir
        case 9:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva

            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

                if(eventoSelecionado.inserirLike(usuarioLogado) == true)
                    std::cout << "Curtida registrada." << std::endl;

                else
                    std::cout << "Voce ja curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual:" << eventoSelecionado.getLikes() << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Remover curtida
        case 10: {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva

            try{
                Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

                if(eventoSelecionado.removerLike(usuarioLogado) == true)
                    std::cout << "Curtida removida." << std::endl;
                
                else
                    std::cout << "Voce nao curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual:" << eventoSelecionado.getLikes() << std::endl;
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Sair
        case 11: {
        break;  }


        // Tratamento de exceção
        default:
        {
            std::cout << "Opcao digitada invalida. Tente novamente digitando um numero entre 1 e 11." << std::endl;
            break;
        }
        }
    }
}