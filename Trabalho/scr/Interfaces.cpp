#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"
#include "Tratamentoerros.hpp"

void exibirMenuInicial(GerenciadorPerfis &gerenciador_, int &aux1, int &acesso, int &id, std::string &nome,
                       std::string &usuario, std::string &senha, std::string &bio, std::string &telefone,
                       std::string &email)
{

    do
    {
        std::cout << "Qual ação deseja realizar: " << std::endl;
        std::cout << "1.Entrar " << std::endl
                  << "2.Criar Perfil " << std::endl;
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
                    std::cout << "Bem vindo!" << std::endl;
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
                    aux1 = opcao;
                }
            } while (acesso != 1 && aux1 != 2);
            aux1 = 0;
            break;
        }

        case 2:
        {
            std::cout << "E-mail: " << std::endl;
            std::cin >> email;
            std::cout << "Nome completo: " << std::endl;
            std::cin >> nome;
            std::cout << "Nome de usuario: " << std::endl;
            std::cin >> usuario;
            std::cout << "Senha: " << std::endl;
            std::cin >> senha;
            std::cout << "Telefone: " << std::endl;
            std::cin >> telefone;
            bio = " ";
            gerenciador_.criaPerfil(nome, usuario, senha, bio, telefone, email);
            Perfil *p = gerenciador_.buscaPorUsuario(usuario);
            id = p->getidu();
            acesso = 1;
            std::cout << "Perfil criado com sucesso! Bem vindo!" << std::endl;
            break;
        }

        default:
            std::cout << "Opção invalida! Tente novamente." << std::endl;
        }
    } while (acesso != 1);
}

void exibirMenuAbas(std::map<int, Spotted> &postDeSpotted_, std::map<int, Evento> &postDeEvento_,
                    std::map<int, Servico> &postDeServico_, std::map<int, Oportunidades> &postDeOportunidade_, 
                     Perfil& usuarioLogado, int &acesso, const int id, GerenciadorPerfis& gerenciador_)
{
    while(acesso){
        int aux3 = 0;
        std::cout << "Qual aba deseja acessar: " << std::endl;
        std::cout << "1.Spotted" << std::endl;
        std::cout << "2.Eventos" << std::endl;
        std::cout << "3.Oportunidades" << std::endl;
        std::cout << "4.Serviços" << std::endl;
        std::cout << "5.Informações do usuario" << std::endl;
        std::cout << "6.Configuracoes" << std::endl;
        lerValor(aux3); //progdefensiva

        switch (aux3)
        {
        case 1:
        {
            exibirSpotted(postDeSpotted_);
            break;
        }
        case 2:
        {
            exibirEventos(postDeEvento_, usuarioLogado);
            break;
        }
        case 3:
        {
            exibirOportunidades(postDeOportunidade_);
            break;
        }
        case 4:
        {
            exibirServicos(postDeServico_);
            break;
        }
        case 5:
        {
            exibirInfoUsuario(usuarioLogado); // Necessário implementar após a criação do case
            break;
        }
        case 6:
        {
            configuracoes(usuarioLogado, gerenciador_, acesso);
        }
        default:
        {
            std::cout << "Opcao nao encontrada. Tente novamente." << std::endl;
            break;
        }
        }
    }
}

//--------------------------------------SPOTTED----------------------------------------------------------
void exibirSpotted(std::map<int, Spotted> &postDeSpotted_)
{

    int opcaoSpotted = 0;
    while (opcaoSpotted != 10)
    {
        std::cout << "=== Spotted ===" << std::endl;
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
                std::cout << "  [Nenhum comentario neste post ainda]" << std::endl;
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
            try
            {

                if (spottedSelecionado4.getLikes() == 0)
                {
                    throw std::runtime_error("Erro: o numero de curtidas e nulo.");
                }

                spottedSelecionado4.removerLike();
                std::cout << "Like removido!" << std::endl;
                std::cout << "Pressione enter para voltar para o menu de spotted" << std::endl;
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Aviso: " << e.what() << std::endl;
            }

            std::cin.ignore(); // limpa buffer
            std::cin.get();    // espera o enter
            break;             // volta ao menu
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
//--------------------------------------EVENTOS----------------------------------------------------------
void exibirEventos(std::map<int, Evento> &postDeEvento_, Perfil& usuarioLogado)
{
    int opcaoEvento = 0;

    while (opcaoEvento != 11)
    {
        std::cout << "=== EVENTOS ===" << std::endl;
        std::cout << "1. Ver eventos publicados" << std::endl;
        std::cout << "2. Publicar evento" << std::endl;
        std::cout << "3. Apagar evento" << std::endl;
        std::cout << "4. Editar evento" << std::endl;
        std::cout << "5. Visualizar comentários" << std::endl;
        std::cout << "6. Publicar comentario em evento" << std::endl;
        std::cout << "7. Remover comentario de evento" << std::endl;
        std::cout << "8. Visualizar curtidas" << std::endl;
        std::cout << "9. Curtir evento" << std::endl;
        std::cout << "10. Remover curtida de evento" << std::endl;
        std::cout << "11. Voltar ao menu principal" << std::endl;
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

            std::cout << "Pressione enter para voltar para o menu de eventos " << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Publicar evento
        case 2:
        {
            std::string texto_evento, contato_evento;
            int id = postDeEvento_.size();

            std::cout << "Digite o contato responsável pela organizacao do evento:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, contato_evento);

            std::cout << "Digite o texto do evento a ser publicado:" << std::endl;
            std::getline(std::cin, texto_evento);

            Evento novoEvento(texto_evento, contato_evento, usuarioLogado);
            postDeEvento_[id] = novoEvento;

            std::cout << "Evento publicado!" << std::endl;
            std::cout << "Pressione enter para voltar para menu de eventos." << std::endl;
            std::cin.get();
            break;
        }

        // Apagar evento
        case 3:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);   

            if(eventoSelecionado.getPerfil().getidu() == usuarioLogado.getidu()){
            postDeEvento_.erase(idEvento);
            std::cout << "Evento removido com sucesso." << std::endl;
            }

            else
                std::cout << "Voce nao possui permissao para apagar esse evento." << std::endl;

            std::cout << "Pressione enter para voltar para menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Editar evento
        case 4:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);   

            if(eventoSelecionado.getPerfil().getidu() == usuarioLogado.getidu()){
                
                int opcaoEditarEvento = 0;
                std::string novoContato, novoTexto;

                while (opcaoEditarEvento != 3){
                std::cout << "O que deseja editar?" << std::endl;
                std::cout << "1. Editar contato de evento" << std::endl;
                std::cout << "2. Editar texto do evento" << std::endl;
                std::cout << "3. Voltar ao menu de eventos" << std::endl;
                lerValor(opcaoEditarEvento); //progdefensiva

                    switch (opcaoEditarEvento)
                    {
                        case 1:
                        {
                            std::cout << "Digite o novo contato:" << std::endl;
                            std::cin.ignore();
                            std::getline(std::cin, novoContato);
                            eventoSelecionado.editarContato(novoContato);
                            std::cout << "Contato atualizado com sucesso." << std::endl;
                            break;
                        }

                        case 2:
                        {
                            std::cout << "Digite o novo evento:" << std::endl;
                            std::cin.ignore();
                            std::getline(std::cin, novoTexto);
                            eventoSelecionado.editarEvento(novoTexto);
                            std::cout << "Evento atualizado com sucesso." << std::endl;
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

            std::cout << "Pressione enter para voltar para menu de eventos." << std::endl;
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
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

            std::cout << "Comentarios:" << std::endl;
            imprimirElementosComId(eventoSelecionado.listarComments());

            std::cout << "Pressione enter para voltar." << std::endl;
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
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);
            std::string comentarioEvento;
            std::cout << "Digite o comentario: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, comentarioEvento);

            while (comentarioEvento.empty())
            {
                std::cout << "O comentario esta vazio. Por favor, digite novamente:" << std::endl;
                std::getline(std::cin, comentarioEvento);
            }

            eventoSelecionado.inserirComment(usuarioLogado, comentarioEvento);
            std::cout << "Comentário publicado." << std::endl;
            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
            std::cin.get();
            break;
        }

        // Apagar comentários
        case 7:
        {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva
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

            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
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
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

            std::cout << "Numero de curtidas do post selecionado:" << eventoSelecionado.getLikes() << std::endl;

            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
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
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

            if(eventoSelecionado.inserirLike(usuarioLogado) == true)
                std::cout << "Curtida registrada." << std::endl;

            else
                std::cout << "Voce ja curtiu essa publicacao." << std::endl;

            std::cout << "Numero de curtidas atual:" << eventoSelecionado.getLikes() << std::endl;

            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }

        // Remover curtida
        case 10: {
            std::cout << "Digite o ID do evento: " << std::endl;

            int idEvento;
            lerValor(idEvento); //progdefensiva
            Evento &eventoSelecionado = acharPost(postDeEvento_, idEvento);

            if(eventoSelecionado.removerLike(usuarioLogado) == true)
                std::cout << "Curtida removida." << std::endl;
            
            else
                std::cout << "Voce nao curtiu essa publicacao." << std::endl;

            std::cout << "Numero de curtidas atual:" << eventoSelecionado.getLikes() << std::endl;

            std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
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
            std::cout << "Opcao digitada invalida. Tente novamente digitando um numero entre 1 e 9." << std::endl;
            break;
        }
        }
    }
}

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
    lerValor(opcao); //progdefensiva

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
        lerValor(idserv); //progdefensiva
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
        lerValor(idserv1); //progdefensiva
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
        lerValor(idserv2); //progdefensiva
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

//------------------------------INFORMAÇÕES DO USUÁRIO----------------------------------------------------------
void exibirInfoUsuario(Perfil &perfil)
{
    int opcao = 0;
    while(opcao!=5){
        std::cout << "===PERFIL===" << std::endl;
        std::cout << "1.Exibir Informações do perfil" << std::endl;
        std::cout << "2.Adicionar biografia" << std::endl;
        std::cout << "3.Editar biografia" << std::endl;
        std::cout << "4.Editar nome de usuario" << std::endl;
        std::cout << "5.Retornar ao menu principal" << std::endl;
        lerValor(opcao); //progdefensiva

        switch(opcao){
            case 1: {
                std::cout << "Informações do perfil:" << std::endl;
                std::cout << perfil.getNome() << std::endl;
                std::cout << perfil.getUsuario() << std::endl;
                std::cout << perfil.getBio() << std::endl;
                break;
            }
            case 2:{
                std::cout << "Informe a bio que deseja adicionar" << std::endl;
                std::string biotemp;
                std::getline(std::cin, biotemp);
                perfil.setBio(biotemp);
                std::cout << "Bio adicionada com sucesso" << std::endl;
                break;
            }
            case 3:
            {
                std::string biotemp;
                std::cout << "Biografia atual: " << std::endl;
                std::cout << perfil.getBio() << std::endl;
                std::cout << "Informe a nova bio: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, biotemp);
                perfil.setBio(biotemp);
                std::cout << "Bio alterada com sucesso" << std::endl;
                break;
            }
            case 4: 
            {
                std::string usuariotemp;
                std::cout << "Nome de usuario atual: " << std::endl;
                std::cout << perfil.getUsuario() << std::endl;
                std::cout << "Informe o novo nome de usuario" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, usuariotemp);
                perfil.setUsuario(usuariotemp);
                std::cout << "Nome de usuario alterado com sucesso!" << std::endl;
                break;
            }
            case 5:
            break;

            default: {
                std::cout << "Opcao invalida, tente novamente" << std::endl;
                break;
            }
        }
    }

}

//------------------------------CONFIGURAÇÕES---------------------------------------------------------------------
void configuracoes(Perfil &perfil, GerenciadorPerfis& gerenciador_, int &acesso){
    int opcao = 0;
    while(opcao!=4){
        std::cout << "===CONFIGURACOES===" << std::endl;
        std::cout << "1.Exibir informacoes de perfil" << std::endl;
        std::cout << "2.Apagar conta" << std::endl;
        std::cout << "3.Sair da conta" << std::endl;
        std::cout << "4.Retornar ao menu principal" << std::endl;
        lerValor(opcao); //progdefensiva

        switch(opcao){
            case 1:
            {
                std::cout << "Informacoes do usuario:" << std::endl;
                std::cout << perfil.getEmail() << std::endl;
                std::cout << perfil.getNome() << std::endl;
                std::cout << perfil.getTelefone() << std::endl;
                break;
            }
            case 2:
            {
                int opcao2 = 0;
                while(opcao2 != 1 && opcao2 != 2){
                    std::cout << "Tem certeza que deseja apagar a sua conta, é um caminho sem volta!" << std::endl;
                    std::cout << "1.Confirmar" << std::endl << "2.Cancelar" << std::endl;
                    lerValor(opcao2); //progdefensiva;
                    if(opcao2 != 1 && opcao2 != 2)
                    std::cout << "Opcao invalida tente novamente" << std::endl;
                }
                    if(opcao2==1){
                        gerenciador_.apagaPerfil(perfil.getidu(), perfil.getUsuario());
                        acesso = 0;
                        opcao = 4;
                    }
                    break; 
            }
            case 3:
            {
                acesso = 0;
                opcao = 4;
                break;
            }         
            case 4:{
                opcao = 4;
                break;
            }      
        }
    }
}