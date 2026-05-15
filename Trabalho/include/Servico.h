#pragma once
#include <string>
#include <vector>
#include "Perfil.h"
#include "Post.h"

// Depois vou ajeitar para ser uma classe filha de post quando fizermos a implementacao dos contratos
class Servico : public Post
{
private:
    // Perfil da pessoa responsavel pelo post de servico:
    Perfil prestadorDoServico_;

    // Texto do post do perfil:
    std::string descricaoDoServico_;

public:
    // 1. Construtores:
    Servico();
    Servico(Perfil PrestadorServico);

    // 2. Destrutor:
    ~Servico();

    // 3. "Getters":
    std::vector<std::string> getListaDeComentarios();

    std::string getDescricaoDoServico();

    Perfil getPerfilDoPrestador();

    // 4. Metodos:
    void editarDescricao(std::string ParteDoTexto, int numeroCaracteres, std::string novoTexto);
};
