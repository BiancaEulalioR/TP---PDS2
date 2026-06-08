#include "funcoesAuxiliares.hpp"

void carregarServicosSalvos(std::map<int, Servico> &servicos_)
{
    std::fstream arqServ;
    arqServ.open("dadosSalvos/servicos.txt", std::ios::in | std::ios::out);
    std::string descricaoObtida, idLUsuario, idLido, numLikes;
    if (arqServ.is_open())
    {
        Servico servicoLido;
        std::string indicador;
        while (std::getline(arqServ, indicador, '|'))
        {

            if (indicador == "SERVICO")
            {
                std::getline(arqServ, descricaoObtida, '|');
                std::getline(arqServ, idLUsuario, '|');
                servicoLido.setDescricaoDoServico(descricaoObtida);
                continue;
            }
            if (indicador == "ID")
            {
                std::getline(arqServ, idLido, '|');
                continue;
            }
        }
    }
}
