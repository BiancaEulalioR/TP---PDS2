#include <iostream>
#include <string>

#include "Servico.h"
#include "exibirServicos.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

//--------------------------------------SERVIÇO----------------------------------------------------------
void exibirServicos(std::map<int, Servico> &postDeServico_, Perfil &usuarioLogado, GerenciadorPerfis &gerenciador_)
{
    int opcao = 0;

    while(opcao != 12) {
        std::cout << std::endl;
        std::cout << "=== SERVICOS ===" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Ver servicos publicados" << std::endl;
        std::cout << "2. Publicar um servico" << std::endl;
        std::cout << "3. Editar servico" << std::endl;
        std::cout << "4. Remover servico" << std::endl;
        std::cout << "5. Vizualizar comentarios" << std::endl;
        std::cout << "6. Publicar comentario em um servico" << std::endl;
        std::cout << "7. Remover comentario de um servico" << std::endl;
        std::cout << "8. Vizualizar curtidas" << std::endl;
        std::cout << "9. Curtir servico" << std::endl;
        std::cout << "10. Remover curtida de um servico" << std::endl;
        std::cout << "11. Ver informacoes de contato de um servico" << std::endl;
        std::cout << "12. Voltar ao menu principal" << std::endl;
        std::cout << std::endl;
        lerValor(opcao); // progdefensiva

        switch (opcao)
        {
        case 1:
            for (auto &i : postDeServico_)
            {
                std::cout << "SERVICO (" << i.first << ") " << std::endl;
                std::cout << (i.second).getDescricaoDoServico() << std::endl;
                std::cout << (i.second).getLikes() << " likes  " << (i.second).getComments() << " comentarios  " << std::endl;
            }
            std::cout << "\nPressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        case 2:
        {
            std::string descricaoLida, contatoLido;
            int idS = postDeServico_.size();
            std::cout << "Digite o texto do servico a ser publicado:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, descricaoLida);

            while (descricaoLida.empty())
            {
                std::cout << "Descricao vazia. Digite novamente:" << std::endl;
                std::getline(std::cin, descricaoLida);
            }

            std::cout << "Agora digite o numero de contato com ddd, tudo junto :" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, contatoLido);

            Servico novoServico(descricaoLida, contatoLido, idS, usuarioLogado.getidu(), usuarioLogado);
            postDeServico_.insert({idS, novoServico});
            std::cout << "Servico publicado!" << std::endl;
            std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 3:
        {
            std::cout << "Digite o id do servico:" << std::endl;
            int idLido;
            lerValor(idLido); // progdefensiva

            try{
                Servico &servicoSelecionado = acharPost(postDeServico_, idLido);
                if (servicoSelecionado.getPerfilAssociado().getidu() == usuarioLogado.getidu())
                {
                    std::cout << "O que deseja editar?" << std::endl;
                    std::cout << "1. Editar contato do servico;" << std::endl;
                    std::cout << "2. Editar a descricao do servico;" << std::endl;
                    std::cout << "3. Voltar ao menu de servicos." << std::endl;
                    int opcao;
                    lerValor(opcao); // progdefensiva

                    switch (opcao)
                    {
                    case 1:
                    {
                        std::cout << "Digite o novo numero de contato:" << std::endl;
                        std::string contatoStr;

                        std::cin.ignore();
                        std::getline(std::cin, contatoStr);

                        servicoSelecionado.setNumeroContato(contatoStr);
                        std::cout << "Contato atualizado com sucesso!" << std::endl;
                        std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        break;
                    }
                    case 2:
                    {
                        std::cout << "Digite a nova descricao do servico:" << std::endl;
                        std::string novaDescricaoServico;
                        std::cin.ignore();
                        std::getline(std::cin, novaDescricaoServico);
                        servicoSelecionado.setDescricaoDoServico(novaDescricaoServico);
                        std::cout << "Servico atualizado com sucesso!" << std::endl;
                        std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        break;
                    }
                    case 3:
                        break;
                    default:
                        std::cout << "Opcao invalida. Tente novamente digitando um numero de 1 a 3." << std::endl;
                        std::cin.ignore();
                        std::cin.get();
                        break;
                    }
            
                }
                else
                {
                    std::cout << "Voce nao possui permissao para editar esse servico." << std::endl;
                }
            }

            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
                std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
        }
        case 4:
        {
            std::cout << "Digite o ID do servico: " << std::endl;

            int idServico;
            lerValor(idServico); // progdefensiva
            
            try{
                Servico &servicoSelecionado = acharPost(postDeServico_, idServico);

                if (servicoSelecionado.getPerfilAssociado().getidu() == usuarioLogado.getidu())
                {
                    postDeServico_.erase(idServico);
                    std::cout << "Servico removido com sucesso." << std::endl;
                }

                else
                    std::cout << "Voce nao possui permissao para apagar esse servico." << std::endl;
            }
            
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 5:
        {
            std::cout << "Digite o ID do servico: " << std::endl;
            int idserv;
            lerValor(idserv); // progdefensiva

            try {
                Servico &servicoSelecionado = acharPost(postDeServico_, idserv);
                std::cout << "Comentarios: " << std::endl;
                imprimirElementosComId(servicoSelecionado.listarComments());
                std::cout << std::endl;
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
        case 6:
        {
            std::cout << "Digite o ID do servico: " << std::endl;
            int idserv1;
            lerValor(idserv1); // progdefensiva
            try{
                Servico &servicoSelecionado1 = acharPost(postDeServico_, idserv1);
                std::string novoComentario;
                std::cout << "Digite o comentario:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, novoComentario);
                verificaTexto(novoComentario); //progdefensiva

                servicoSelecionado1.inserirComment(usuarioLogado, novoComentario);
                std::cout << "Comentario publicado." << std::endl;
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
        case 7:
        {
            std::cout << "Digite o ID do servico: " << std::endl;

            int idServico;
            lerValor(idServico); // progdefensiva

            try{
                Servico &servicoSelecionado = acharPost(postDeServico_, idServico);

                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(servicoSelecionado.listarComments());

                std::cout << "\nDigite o ID do comentario que deseja remover:" << std::endl;
                int idComentario;
                lerValor(idComentario); // progdefensiva

                const std::map<int, std::pair<Perfil, std::string>> &comentariosServico = servicoSelecionado.listarComments();
                auto verificarComentServico = comentariosServico.find(idComentario);

                if (verificarComentServico != comentariosServico.end())
                {

                    if (verificarComentServico->second.first.getidu() == usuarioLogado.getidu())
                    {

                        servicoSelecionado.removerComment(idComentario);
                        std::cout << "Comentario removido com sucesso." << std::endl;
                    }

                    else
                    {
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

            std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            
            break;
        }
        case 8:
        {
            std::cout << "Digite o ID do servico: " << std::endl;
            int idServico;
            lerValor(idServico); // progdefensiva
            try{
                Servico &servicoSelecionado = acharPost(postDeServico_, idServico);

                std::cout << "Numero de curtidas do post de servico selecionado: " << servicoSelecionado.getLikes() << std::endl;
                exibirUsuariosQueCurtiram(postDeServico_, idServico, gerenciador_);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 9:
        {
            std::cout << "Digite o ID do servico: " << std::endl;

            int idServico;
            lerValor(idServico); // progdefensiva
            try{
                Servico &servicoSelecionado = acharPost(postDeServico_, idServico);

                if (servicoSelecionado.inserirLike(usuarioLogado) == true)
                    std::cout << "Curtida registrada." << std::endl;

                else
                    std::cout << "Voce ja curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual:" << servicoSelecionado.getLikes() << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 10:
        {
            std::cout << "Digite o ID do servico: " << std::endl;

            int idServico;
            lerValor(idServico); // progdefensiva
            try {
                Servico &servicoSelecionado = acharPost(postDeServico_, idServico);

                if (servicoSelecionado.removerLike(usuarioLogado) == true)
                    std::cout << "Curtida removida." << std::endl;

                else
                    std::cout << "Voce nao curtiu essa publicacao." << std::endl;

                std::cout << "Numero de curtidas atual:" << servicoSelecionado.getLikes() << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Pressione enter para voltar ao menu de servicos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 11:
        {
            std::cout << "Digite o ID do servico: " << std::endl;
            int idserv2;
            lerValor(idserv2); // progdefensiva

            try{
                Servico &servicoSelecionado2 = acharPost(postDeServico_, idserv2);
                std::string nomeDoPrestador = (servicoSelecionado2.getPerfilAssociado()).getUsuario();
                std::cout << "Usuario que publicou: " << nomeDoPrestador << std::endl;
                std::cout << "Telefone para contado: " << servicoSelecionado2.getNumeroContato() << std::endl;
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
        case 12:
            break;
        default:
            std::cout << "Opcao nao encontrada. Pressione enter para tentar novamente." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
    } 
}

