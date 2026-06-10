#include <iostream>
#include <map>
#include "Evento.h"
#include "Oportunidades.h"
#include "Post.h"
#include "Servico.h"
#include "Spotted.h"
#include "GerenciadorPerfis.h"
#include "Interfaces(.h)/configuracoes.h"
#include "Interfaces(.h)/exibirAbaBuscar.h"
#include "Interfaces(.h)/exibirEventos.h"
#include "Interfaces(.h)/exibirInfoUsuario.h"
#include "Interfaces(.h)/exibirMenuAbas.h"
#include "Interfaces(.h)/exibirMenuInicial.h"
#include "Interfaces(.h)/exibirOportunidades.h"
#include "Interfaces(.h)/exibirServicos.h"
#include "Interfaces(.h)/exibirSpotted.h"
#include <string>

int main()
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
                exibirMenuAbas(*usuarioLogado, acesso, id, gerenciador_, postDeSpotted_, postDeEvento_, postDeOportunidade_, postDeServico_);
            
            else{
                std::cout << "ERRO 404" << std::endl;
                acesso = 0;
            }

        }
    }

    return 0;
}