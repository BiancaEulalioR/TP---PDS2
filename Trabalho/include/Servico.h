#pragma once
#include <string>
#include <vector>
#include "Perfil.h"
#include "Post.h"

class Servico : public Post
{
private:
    // Texto do post do perfil:
    std::string descricaoDoServico_;

public:
    // 1. Construtores:
    Servico();
    Servico(std::string descricao);

    // 2. Destrutor:
    ~Servico();

    // 3. "Getters":
    std::string getDescricaoDoServico();

    // 4. Metodos:
    void editarDescricao(std::string ParteDoTexto, int numeroCaracteres, std::string novoTexto);
    void reescreverDescricao(std::string novaDescricao);
};
