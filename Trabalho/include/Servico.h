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
    std::string numeroContato_;
    int idDeArmazenamento_;
    int idDoPerfilAssociado_;
    Perfil perfilAssociadoS_;

public:
    // 1. Construtores:
    Servico();
    Servico(std::string descricao, std::string num, int idServi, int idPerf, Perfil perf);

    // 2. Destrutor:
    ~Servico();

    // 3. "Getters":
    std::string getDescricaoDoServico() const;
    std::string getNumeroContato() const;
    int getIdServico() const;
    int getIdPerfilAssociado() const;
    const Perfil &getPerfilAssociado() const;

    // 4. "Setters":
    void setDescricaoDoServico(std::string descricaoL);
    void setNumeroContato(std::string numL);
    void setIdServico(int novoId);
    void setIdPerfilAssociado(int novoIdPerfil);
    void setPerfilAssociado(Perfil novoPerfilAssociado);

    // 5. Metodos:
    void editarDescricao(std::string ParteDoTexto, int numeroCaracteres, std::string novoTexto);
    void reescreverDescricao(std::string novaDescricao);
};
