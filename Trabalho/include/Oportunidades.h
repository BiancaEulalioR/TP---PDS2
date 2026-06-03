#ifndef OPORTUNIDADES_H
#define OPORTUNIDADES_H

#include "Perfil.h"
#include "Post.h"

#include <string>

// Representa uma oportunidade, classe do tipo post
class Oportunidades : public Post
{

private:
    std::string descricao_; // descrição da oportunidade
    std::string contato_; // contato da oportunidade
    int id_;                // identificador único da oportunidade
    Perfil perfilAssociado_; // perfil do usuário que publicou a oportunidade

public:
    // Construtor responsável por incializar uma oportunidade
    Oportunidades(int id, const std::string &descricao, const std::string &contato, const Perfil &usuario);

    Oportunidades(); // construtor pro map
    
    // Getters (acesso aos dados)
    int getId() const;
    std::string getDescricao() const;
    std::string getContato() const;
    Perfil getPerfil() const;

    // Edita os dados da oportunidade
    // Pré-condição: só pode ser feita a edição se o usuario for o dono
    void editarOportunidade(const std::string &novaDescricao, const std::string &novoContato);
    // método para apagar a oportunidade
    void apagarOportunidade();
};

#endif // OPORTUNIDADES_H
