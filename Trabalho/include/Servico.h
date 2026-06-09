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
    // o numero para contatar o servico pode ser diferente do telefone_ (atributo de perfil)
    int numeroContato_;
    int idDeArmazenamento_;
    int idDoPerfilAssociado_;
    Perfil perfilAssociadoS_;

public:
    // 1. Construtores:
    Servico();
    Servico(std::string descricao, int num, int idServi, int idPerf, Perfil perf);

    // 2. Destrutor:
    ~Servico();

    // 3. "Getters":
    std::string getDescricaoDoServico() const;
    int getNumeroContato() const;
    int getIdServico() const;
    int getIdPerfilAssociado() const;
    const Perfil &getPerfilAssociado() const;

    // 4. "Setters":
    void setDescricaoDoServico(std::string descricaoL);
    void setNumeroContato(int numL);
    void setIdServico(int novoId);
    void setIdPerfilAssociado(int novoIdPerfil);
    void setPerfilAssociado(Perfil novoPerfilAssociado);
};
