#include <iostream>
#include <map>
#include "Evento.h"
#include "Oportunidades.h"
#include "Post.h"
#include "Servico.h"
#include "Spotted.h"
#include "GerenciadorPerfis.h"
#include "Interfaces.h"
#include <string>

void main()
{
    // inicializando maps para guardar os posts:
    std::map<int, Spotted> postDeSpotted_;
    std::map<int, Evento> postDeEvento_;
    std::map<int, Oportunidades> postDeOportunidade_;
    std::map<int, Servico> postDeServico_;

    // lendo os posts e perfis ja salvos de outras vezes em que o programa foi aberto:

    // criação de um perfil

    int aux1, acesso = 0, id = 0;
    std::string nome, usuario, senha, bio, telefone, email;
    GerenciadorPerfis gerenciador_;

    while (1)
    {
        exibirMenuInicial(gerenciador_, aux1, acesso, id, nome, usuario, senha, bio, telefone, email);

        while (acesso){
            Perfil* usuarioLogado =  gerenciador_.buscaPorID(id);
            if(usuarioLogado != nullptr)
                exibirMenuAbas(postDeSpotted_, postDeEvento_, postDeServico_, postDeOportunidade_, acesso, id);
            
            else{
                std::cout << "ERRO 404" << std::endl;
                acesso = 0;
            }

        }
    }
}