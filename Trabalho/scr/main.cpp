#include <iostream>
#include <map>
#include "Evento.h"
#include "Oportunidades.h"
#include "Post.h"
#include "Servico.h"
#include "Spotted.h"
#include "GerenciadorPerfis.h"
#include "includeInterfaces/configuracoes.h"
#include "includeInterfaces/exibirAbaBuscar.h"
#include "includeInterfaces/exibirEventos.h"
#include "includeInterfaces/exibirInfoUsuario.h"
#include "includeInterfaces/exibirMenuAbas.h"
#include "includeInterfaces/exibirMenuInicial.h"
#include "includeInterfaces/exibirOportunidades.h"
#include "includeInterfaces/exibirServicos.h"
#include "includeInterfaces/exibirSpotted.h"
#include <string>

int main()
{
    // inicializando maps para guardar os posts:
    std::map<int, Spotted> postDeSpotted_;
    std::map<int, Evento> postDeEvento_;
    std::map<int, Oportunidades> postDeOportunidade_;
    std::map<int, Servico> postDeServico_;

    // criação de um perfil

    int aux1, acesso = 0, id = 0;
    std::string nome, usuario, senha, bio, telefone, email;
    GerenciadorPerfis gerenciador_;

    while (1)
    {
        exibirMenuInicial(gerenciador_, aux1, acesso, id, nome, usuario, senha, bio, telefone, email);

        while (acesso)
        {
            Perfil *usuarioLogado = gerenciador_.buscaPorID(id);
            if (usuarioLogado != nullptr)
                exibirMenuAbas(*usuarioLogado, acesso, id, gerenciador_, postDeSpotted_, postDeEvento_, postDeOportunidade_, postDeServico_);

            else
            {
                std::cout << "ERRO 404" << std::endl;
                acesso = 0;
            }
        }
    }

    return 0;
}