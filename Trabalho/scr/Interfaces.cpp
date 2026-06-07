#include <iostream>
#include <string>

#include "Evento.h"
#include "Interfaces.h"
#include "funcoesAuxiliares.hpp"

void exibirMenuInicial(GerenciadorPerfis& gerenciador_, int& aux1, int& acesso, int& id, std::string& nome, 
                        std::string& usuario, std::string& senha, std::string& bio, std::string& telefone, 
                        std::string& email){

    do{
        std::cout << "Qual ação deseja realizar: " << std::endl;
        std::cout << "1.Entrar " << std::endl
                  << "2.Criar Perfil " << std::endl;
        std::cin >> aux1;

        switch (aux1) {
        
            case 1: {
                do{
                    std::cout << "Nome de usuario: " << std::endl;
                    std::cin >> usuario;
                    std::cout << "Senha: " << std::endl;
                    std::cin >> senha;
                    if (gerenciador_.verificaPerfil(usuario, senha)) {
                        acesso = 1;
                        Perfil* p = gerenciador_.buscaPorUsuario(usuario);
                        id = p->getidu();
                        std::cout << "Bem vindo!" << std::endl; 
                    }
                    else{
                        std::cout << "Usuário ou senha incorretos." << std::endl; 
                        int opcao;
                        do{
                            std::cout << "1.Tentar novamente" << std::endl;
                            std::cout << "2.Voltar ao menu" << std::endl;
                            std::cin >> opcao;
                            if(opcao != 1 && opcao != 2)
                                std::cout << "Opção invalida! Tente novamente." << std::endl;
                        } while(opcao != 1 && opcao != 2);
                        aux1 = opcao;
                    }
                 } while(acesso != 1 && aux1 != 2);
                    aux1 = 0;
                    break;
            }   

            case 2: {
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
    }while(acesso!=1);

}

void exibirMenuAbas(std::map<int, Spotted>& postDeSpotted_, std::map<int, Evento>& postDeEvento_,
    std::map<int, Servico>& postDeServico_, std::map<int, Oportunidades>& postDeOportunidade_, int& acesso){
        int aux3 = 0;
        std::cout << "Qual aba deseja acessar: " << std::endl;
        std::cout << "1.Spotted" << std::endl;
        std::cout << "2.Eventos" << std::endl;
        std::cout << "3.Oportunidades" << std::endl;
        std::cout << "4.Serviços" << std::endl;
        std::cout << "5.Informações do usuario" << std::endl;
        std::cout << "6.Sair do perfil";
        std::cin >> aux3;

        switch(aux3){
            case 1:{
                exibirSpotted(postDeSpotted_);
            break; }
            case 2: {
                exibirEventos(postDeEvento_);
            break; }
            case 3: {
                exibirOportunidades(postDeOportunidade_);
            break; }
            case 4: {
                exibirServicos(postDeServico_);
            break; }
            case 5: {
                exibirInfoUsuario(); //Necessário implementar após a criação do case
            break; }
            case 6: {
                acesso = 0;
            break; }
            default: {
                std::cout << "Opcao nao encontrada. Tente novamente." << std::endl;
            break; }
        }    
} 

//--------------------------------------SPOTTED----------------------------------------------------------
void exibirSpotted(std::map<int, Spotted>& postDeSpotted_){
    std::cout << "spotteds disponiveis:" << std::endl;
    for (auto &it : postDeSpotted_) {

        std::cout << "SPOTTED" << it.first << std::endl;
        for (auto &i : it.second.listarPosts()) {
        // Imprime número de likes e comentários para cada mensagem do spotted
            std::cout << "likes: " << i.second.getLikes() << std::endl;
            std::cout << "Comentarios: " << i.second.getComments() << std::endl;
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
    
    switch (opcao) {
    case 1:
    {
        std::cout << "Deseja ver os comentarios de qual spotted?(digite o id)" << std::endl;
        int idSpotted;
        std::cin >> idSpotted;
        Spotted &spottedSelecionado = acharPost(postDeSpotted_, idSpotted);
        std::cout << "Comentarios: " << std::endl;
        imprimirElementos(spottedSelecionado.listarComments());
        std::cout << std::endl;
        std::cout << "Pressione enter para voltar." << std::endl;
        std::cin.ignore();
        std::cin.get();
    break;
    } 
                
    case 2:
    {
        std::cout << "Em qual post de Spotted deseja deixar um comentario?(digite o id)" << std::endl;
        int idSpotted1;
        std::cin >> idSpotted1;
        Servico &spottedSelecionado1 = acharPost(postDeSpotted_, idSpotted1);
        std::string novoComentarioSpotted;
        std::cout << "Digite seu comentario (apertando enter apenas quando terminar):" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, novoComentarioSpotted);//ler a linha inteira
        
        while (novoComentarioSpotted.empty()) //comentário vazio
        {
            std::cout << "O comentario esta vazio. Digite-o novamente:" << std::endl;
            std::cin.ignore(); //limpa buffer
            std::getline(std::cin, novoComentarioSpotted);
        }

        spottedSelecionado1.inserirComment(novoComentarioSpotted);
        std::cout << "Comentario publicado. Pressione Enter para voltar." << std::endl;
        std::cin.ignore(); // limpa buffer
        std::cin.get(); // espera o enter
    break;// volta ao menu
    }
    
    case 3:
    {
        std::cout << "Em qual post de Spotted deseja deixar um like? (digite o id)" << std::endl;
        int idSpotted2;
        std::cin >> idSpotted2;
        Spotted &spottedSelecionado2 = acharPost(postDeSpotted_, idSpotted2);

        spottedSelecionado2.inserirLike();
        std::cout << "Like publicado. Pressione Enter para voltar." << std::endl;
        std::cin.ignore(); // limpa buffer
        std::cin.get(); // espera o enter
    break;// volta ao menu
    }
    
    case 4:
    {
        std::cout << "Em qual post de Spotted deseja remover o comentario? (digite o id)" << std::endl;
        int idSpotted3;
        std::cin >> idSpotted3;
        Spotted &spottedSelecionado3 = acharPost(postDeSpotted_, idSpotted3);
    
        spottedSelecionado3.removerComment();
        std::cout << "comentario removido. Pressione Enter para voltar." << std::endl;
        std::cin.ignore(); // limpa buffer
        std::cin.get(); // espera o enter
    break;// volta ao menu
                    
    }
    
    case 5:
    {
        std::cout << "Em qual post de Spotted deseja remover o like? (digite o id)" << std::endl;
        int idSpotted4;
        std::cin >> idSpotted4;
        Spotted &spottedSelecionado4 = acharPost(postDeSpotted_, idSpotted4);

        spottedSelecionado4.removerLike();
        std::cout << "Like removido. Pressione Enter para voltar." << std::endl;
        std::cin.ignore(); // limpa buffer
        std::cin.get(); // espera o enter
    break;// volta ao menu
    }
}   }

//--------------------------------------EVENTOS----------------------------------------------------------
void exibirEventos(std::map<int, Evento>& postDeEvento_){
    int opcaoEvento = 0;

    while(opcaoEvento != 9){
        std::cout << "=== EVENTOS ===" << std::endl;
        std::cout << "1. Ver eventos publicados" << std::endl;
        std::cout << "2. Publicar evento" << std::endl;
        std::cout << "3. Visualizar comentários" << std::endl;
        std::cout << "4. Publicar comentario em evento" << std::endl;
        std::cout << "5. Remover comentario de evento" << std::endl;
        std::cout << "6. Visualizar curtidas" << std::endl;
        std::cout << "7. Curtir evento" << std::endl;
        std::cout << "8. Remover curtida de evento" << std::endl;
        std::cout << "9. Voltar ao menu principal" << std::endl;
        std::cin >> opcaoEvento;

        switch(opcaoEvento){
            case 1:{

                for(auto& i : postDeEvento_){
                    std::cout << "EVENTO ("<< i.first <<")" << std::endl;
                    std::cout << i.second.getTextoEvento() << std::endl;
                    std::cout << "Organizador: " << i.second.getOrganizador().getUsuario() << std::endl;
                    std::cout << "Contato: " << i.second.getContato() << std::endl;
                    std::cout << i.second.getLikes() << " curtidas" << std::endl;
                    std::cout << i.second.getComments() << " comentarios" << std::endl;  
                    std::cout << " " << std::endl;    }

                std::cout << "Pressione enter para voltar para o menu de eventos " << std::endl;
                std::cin.ignore();
                std::cin.get();
            break;  }
            
            case 2: {
                std::string texto_evento, contato_evento;
                int id = postDeEvento_.size();

                std::cout << "Digite o contato responsável pela organizacao do evento:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, contato_evento);

                std::cout << "Digite o texto do evento a ser publicado:" << std::endl;
                std::getline(std::cin, texto_evento);

                // organizador_ e perfilAssociado_ serao implementados apos verificacao de perfis

                Evento novoEvento(id, texto_evento, contato_evento, Perfil());
                postDeEvento_[id] = novoEvento;

                std::cout << "Evento publicado!" << std::endl;
                std::cout << "Pressione enter para voltar." << std::endl;
                std::cin.get();
            break;  }

            case 3: {
                std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                std::cin >> idEvento;
                Evento& eventoSelecionado = acharPost(postDeEvento_, idEvento);

                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(eventoSelecionado.listarComments());

                std::cout << "Pressione enter para voltar." << std::endl;
                std::cin.ignore();
                std::cin.get();

            break;}

            case 4:{
                std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                std::cin >> idEvento;
                Evento& eventoSelecionado = acharPost(postDeEvento_, idEvento);
                std::string comentarioEvento;
                std::cout << "Digite o comentario: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, comentarioEvento);

                while(comentarioEvento.empty()){
                    std::cout << "O comentario esta vazio. Por favor, digite novamente:" << std::endl;
                    std::getline(std::cin, comentarioEvento);   }
                
                eventoSelecionado.inserirComment(comentarioEvento);
                std::cout << "Comentário publicado." << std::endl; 
                std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl; 
                std::cin.get();
            break;  }

            case 5: {
                std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                std::cin >> idEvento;
                Evento& eventoSelecionado = acharPost(postDeEvento_, idEvento);

                std::cout << "Comentarios:" << std::endl;
                imprimirElementosComId(eventoSelecionado.listarComments());

                std::cout << "Digite o ID do comentario que deseja remover:" << std::endl;
                int idComentario;
                std::cin >> idComentario;
                eventoSelecionado.removerComment(idComentario);

                std::cout << "Comentario removido." << std::endl;
                std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
                std::cin.ignore();
                std::cin.get();
            break;}

            case 6: {
                std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                std::cin >> idEvento;
                Evento& eventoSelecionado = acharPost(postDeEvento_, idEvento);

                std::cout << "Numero de curtidas do post selecionado:" << eventoSelecionado.getLikes() << std::endl;

                std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
                std::cin.ignore();
                std::cin.get();
            break;  }

            case 7: {
                std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                std::cin >> idEvento;
                Evento& eventoSelecionado = acharPost(postDeEvento_, idEvento);

                eventoSelecionado.inserirLike();
                std::cout << "Curtida registrada." << std::endl;
                std::cout << "Numero de curtidas atual:" << eventoSelecionado.getLikes() << std::endl;

                std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
                std::cin.ignore();
                std::cin.get();
            break;  }

            case 8: {
                std::cout << "Digite o ID do evento: " << std::endl;

                int idEvento;
                std::cin >> idEvento;
                Evento& eventoSelecionado = acharPost(postDeEvento_, idEvento);

                eventoSelecionado.removerLike();
                std::cout << "Curtida removida." << std::endl;
                std::cout << "Numero de curtidas atual:" << eventoSelecionado.getLikes() << std::endl;

                std::cout << "Pressione enter para voltar para o menu de eventos." << std::endl;
                std::cin.ignore();
                std::cin.get();
            break;  }


            case 9: {
            break;  }

            default: {
                std::cout << "Opcao digitada invalida. Tente novamente digitando um numero entre 1 e 9."  << std::endl;
            break;  }
            
        }
    }
}


//------------------------------------OPORTUNIDADES----------------------------------------------------------
void exibirOportunidades(std::map<int, Oportunidades>& postDeOportunidade_){
    std::cout << "Oportunidades disponiveis:" << std::endl;

    for (auto &i : postDeOportunidade_) {
        std::cout << "OPORTUNIDADE (" << i.first << ")" << std::endl;
        std::cout << i.second.getDescricao() << std::endl;
        std::cout << i.second.getLikes() << " likes " << i.second.getComments() << " comentarios" << std::endl;
    }

    std::cout << "Para onde deseja prosseguir?" << std::endl;
    std::cout << "1. Ver comentarios" << std::endl;
    std::cout << "2. Fazer comentario" << std::endl;
    std::cout << "3. Ver informacoes de contato da oportunidade" << std::endl;
    std::cout << "4. Curtir oportunidade" << std::endl;
    std::cout << "5. Voltar ao menu principal" << std::endl;
                    
    int opcao = 0;
    std::cin >> opcao;

    switch(opcao) {
    
    case 1: 
    {
        int idOp;

        std::cout << "Digite o id da oportunidade:" << std::endl;
        std::cin >> idOp;
                                    
        Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);
        std::cout << "Comentarios:" << std::endl;
        imprimirElementos(opSelecionada.listarComments());
        std::cout << std::endl;
        std::cout << "Pressione enter para voltar." << std::endl;
        std::cin.ignore();
        std::cin.get();
        
    break;
    }

    case 2:
    {
        int idOp;

        std::cout << "Digite o id da oportunidade:" << std::endl;
        std::cin >> idOp;
        Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);
                                
        std::string comentario;

        std::cout << "Digite seu comentario:" << std::endl;

        std::cin.ignore();
        std::getline(std::cin, comentario);

        while(comentario.empty())
        {
            std::cout << "O comentario esta vazio. Digite novamente:" << std::endl;
            std::getline(std::cin, comentario);
        }
                                
        opSelecionada.inserirComment(comentario);

        std::cout << "Comentario publicado. Pressione enter para voltar." << std::endl;

        std::cin.get();

    break;
    }

    case 3:
    {
        int idOp;

        std::cout << "Digite o id da oportunidade:" << std::endl;
        std::cin >> idOp;

        Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

        std::cout << "Usuario que publicou: " << opSelecionada.getPerfil().getUsuario() << std::endl;
        std::cout << "Contato: " << opSelecionada.getContato()<< std::endl;
        std::cout << "Pressione enter para voltar." << std::endl;
        std::cin.ignore();
        std::cin.get();

    break;  
    }

    case 4:
    {
        int idOp;

        std::cout << "Digite o id da oportunidade:" << std::endl;
        std::cin >> idOp;

        Oportunidades &opSelecionada = acharPost(postDeOportunidade_, idOp);

        opSelecionada.inserirLike();

        std::cout << "Like registrado. Pressione Enter para voltar." << std::endl;

        std::cin.ignore();
        std::cin.get();

    break;
    }

    case 5:
    break;
                            
    default:       
    std::cout << "Opcao nao encontrada. Tente novamente."<< std::endl;    

    break;
    } 
}


    //--------------------------------------SERVIÇO----------------------------------------------------------
void exibirServicos(std::map<int, Servico>& postDeServico_){
    std::cout << "servicos disponiveis:" << std::endl;
    for (auto &i : postDeServico_){
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


//------------------------------INFORMAÇÕES DO USUÁRIO----------------------------------------------------------
void exibirInfoUsuario(Perfil& perfil){
        //a ser implementado ainda
}