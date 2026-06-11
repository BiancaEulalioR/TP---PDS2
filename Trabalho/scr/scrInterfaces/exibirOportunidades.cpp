#include <iostream>
#include <string>

#include "Oportunidades.h"
#include "exibirOportunidades.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//------------------------------------OPORTUNIDADES----------------------------------------------------------
void exibirOportunidades(std::map<int, Oportunidades> &postDeOportunidade_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_)
{

    int opcao = 0;

    while (opcao != 12)
    {
        std::cout << std::endl;
        std::cout << "=== OPORTUNIDADES ===" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Ver oportunidades publicadas" << std::endl;
        std::cout << "2. Publicar oportunidade" << std::endl;
        std::cout << "3. Editar oportunidade" << std::endl;
        std::cout << "4. Apagar oportunidade" << std::endl;
        std::cout << "5. Vizualizar comentarios" << std::endl;
        std::cout << "6. Publicar comentario em oportunidade" << std::endl; 
        std::cout << "7. Apagar comentario de oportunidade" << std::endl; 
        std::cout << "8. Vizualizar curtidas" << std::endl;
        std::cout << "9. Curtir Oportunidade" << std::endl;  
        std::cout << "10. Remover curtida de oportunidade" << std::endl; 
        std::cout << "11. Vizualizar informacoes de contato" << std::endl; 
        std::cout << "12. Voltar ao menu principal" << std::endl;
        std::cout << std::endl;

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
                std::cout << "Contato: " << i.second.getContato() << std::endl;
                std::cout << i.second.getLikes() << " curtidas " << i.second.getComments() << " comentarios" << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
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

            std::cout << "Digite o contato responsavel pela oportunidade:" << std::endl;
            std::getline(std::cin, contato);

            while (contato.empty())
            {
                std::cout << "Contato vazio. Digite novamente:" << std::endl;
                std::getline(std::cin, contato);
            }

            std::cout << "Digite a descricao da oportunidade:" << std::endl;
            std::getline(std::cin, descricao); // le a linha inteira, incluindo os espaços, e so para com Enter

            while (descricao.empty())
            {
                std::cout << "Descricao vazia. Digite novamente:" << std::endl;
                std::getline(std::cin, descricao);
            }


            Oportunidades novaOp(id, descricao, contato, usuarioLogado);
            postDeOportunidade_[id] = novaOp;

            std::cout << "Oportunidade publicada!" << std::endl;
            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.get();

            break;
        }
        // Editar oportunidade
        case 3:
        {

        std::cout << "Digite o ID da oportunidade: " << std::endl;

            int idOp;
            lerValor(idOp); //progdefensiva
            
            try {
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);   

                if(opSelecionada.getPerfil().getidu() == usuarioLogado.getidu()){
                
                    int opcaoEditar = 0;
                    std::string novaDescricao;
                    std::string novoContato;

                    while (opcaoEditar != 3){
                        std::cout << "O que deseja editar?" << std::endl;
                        std::cout << "1. Editar contato de oportunidade" << std::endl;
                        std::cout << "2. Editar descricao da oportunidade" << std::endl;
                        std::cout << "3. Voltar ao menu de oportunidades" << std::endl;
                        lerValor(opcaoEditar); //progdefensiva
                    

                        switch (opcaoEditar){
                            case 1:
                                std::cin.ignore();
                                std::cout << "Digite o novo contato:" << std::endl;
                                std::getline(std::cin, novoContato);

                                while (novoContato.empty())
                                {
                                    std::cout << "Contato vazio. Digite novamente:" << std::endl;
                                    std::getline(std::cin, novoContato);
                                }
                                
                                opSelecionada.setContato(novoContato);
                                std::cout << "Contato atualizado com sucesso!" << std::endl;
                                std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
                                std::cin.get();
                                break;

                            case 2:
                                std::cin.ignore();
                                std::cout << "Digite a nova descricao:" << std::endl;
                                std::getline(std::cin, novaDescricao);

                                while (novaDescricao.empty())
                                {
                                    std::cout << "Descricao vazia. Digite novamente:" << std::endl;
                                    std::getline(std::cin, novaDescricao);
                                }

                                opSelecionada.setDescricao(novaDescricao);
                                std::cout << "Descricao atualizada com sucesso!" << std::endl;
                                std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
                                std::cin.get();
                                break;

                            case 3:
                                break;

                            default:
                                std::cout << "Opcao invalida. Tente novamente digitando um numero de 1 a 3." << std::endl;
                                break;
                            }
                        }
                    }
                    else
                        std::cout << "Voce nao possui permissao para editar essa oportunidade." << std::endl;
                }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }


            std::cout << "Pressione enter para voltar ao menu de oportunidades" << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        // Apagar oportunidade
        case 4:
        {
            std::cout << "Digite o ID da oportunidade: " << std::endl;

            int idOp;
            lerValor(idOp); //progdefensiva
            try{
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);   

                if(opSelecionada.getPerfil().getidu() == usuarioLogado.getidu())
                {
                postDeOportunidade_.erase(idOp);
                std::cout << "Oportunidade removida com sucesso." << std::endl;
                }

                else
                    std::cout << "Voce nao possui permissao para apagar essa oportunidade." << std::endl;
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades" << std::endl;
            std::cin.ignore();
            std::cin.get();
            
            break;
        }
        
        // Visualizar comentarios
        case 5:
        {
 
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            try{
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

                std::cout << "Comentarios:" << std::endl;

                imprimirElementosComId(opSelecionada.listarComments());
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        // Publicar comentario
        case 6:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            try{
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

                std::string comentario;
                std::cin.ignore();

                std::cout << "Digite o comentario:" << std::endl;
                std::getline(std::cin, comentario);
                verificaTexto(comentario); //progdefensiva

                opSelecionada.inserirComment(usuarioLogado, comentario);

                std::cout << "Comentario publicado." << std::endl;
            }
            
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.get();

            break;
        }
        // Remover comentario
        case 7:
        {

            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            try {
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

                std::cout << "Comentarios:" << std::endl;

                imprimirElementosComId(opSelecionada.listarComments());

                int idComentario;

                std::cout << "Digite o id do comentario que deseja remover:" << std::endl;
                lerValor(idComentario); //progdefensiva
                const std::map<int, std::pair<Perfil, std::string>> &comentariosOp = opSelecionada.listarComments();
                std::map<int, std::pair<Perfil, std::string>>::const_iterator verificarComent = comentariosOp.find(idComentario);

                if (verificarComent != comentariosOp.end())
                {
                    if (verificarComent->second.first.getidu() == usuarioLogado.getidu())
                    {
                        opSelecionada.removerComment(idComentario);
                        std::cout << "Comentario removido com sucesso." << std::endl;
                    }
                    else
                    {
                        std::cout << "Voce nao possui permissao para apagar esse comentario." << std::endl;
                    }
                }
                else
                    std::cout << "Comentario nao encontrado." << std::endl;
            }
            
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        // Vizualizar curtidas
        case 8:
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            try{
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);
                std::cout << "Numero de curtidas da oportunidade selecionada: " << opSelecionada.getLikes() << std::endl;
                exibirUsuariosQueCurtiram(postDeOportunidade_, idOp, gerenciador_);
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.ignore();
            std::cin.get(); 

            break;
        }
        // Curtir oportunidade
        case 9:
        {
            std::cout << "Digite o ID da oportunidade: " << std::endl;

            int idOp;
            lerValor(idOp); //progdefensiva

            try {
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

                if(opSelecionada.inserirLike(usuarioLogado) == true)
                    std::cout << "Curtida registrada." << std::endl;

                else
                    std::cout << "Voce ja curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual:" << opSelecionada.getLikes() << std::endl;
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        //Remover curtida
        case 10:
        {
            std::cout << "Digite o ID da oportunidade: " << std::endl;    

            int idOp;
            lerValor(idOp); //progdefensiva

            try{
            Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

            if(opSelecionada.removerLike(usuarioLogado) == true)
                std::cout << "Curtida removida." << std::endl;

            else
                std::cout << "Voce ainda nao curtiu essa publicacao." << std::endl;

            std::cout << "Numero de curtidas atual:" << opSelecionada.getLikes() << std::endl;
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.ignore();  
            std::cin.get();
            break;
        }

        // Visualizar informacoes de contato
        case 11: 
        {
            int idOp;

            std::cout << "Digite o id da oportunidade:" << std::endl;
            lerValor(idOp); //progdefensiva

            try{
                Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

                std::cout << "Usuario que publicou: " << opSelecionada.getPerfil().getUsuario() << std::endl;
                std::cout << "Contato: " << opSelecionada.getContato() << std::endl;
            }
            
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }

            std::cout << "Pressione enter para voltar ao menu de oportunidades." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;
        }

        case 12: {
            break;
        }
            
        default:
        {
            std::cout << "Opcao digitada invalida. tente novamente digitando um numero entre 1 e 12." << std::endl;
        }

        }   

    }
}

