#ifndef POST_H_
#define POST_H_

#include <string>
#include <map>
#include "Perfil.h"

class Post
{
private:
    int likes;
    int idCont; // chave do map
    std::map<int, std::string> comments;
    Perfil perfilAssociado;

public:
    Post();

    void inserirLike();

    void removerLike();

    void inserirComment(std::string comment);

    void removerComment(int id);

    int getLikes();

    Perfil getPerfil();

    virtual void idContador();
    const std::map<int, std::string>& getComments(); // passagem por referência

    const std::map<int, std::string> &listarComments(); // passagem por referência
};

#endif
