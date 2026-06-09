#ifndef POST_H_
#define POST_H_

#include <string>
#include <map>
#include <set>
#include "Perfil.h"

class Post
{
private:
    //dados
    std::set<int> likes;
    int idCont; //chave do map
    int qtdComments;
    std::map<int, std::pair<Perfil, std::string>> comments;

public:

    Post();

    bool inserirLike(Perfil& autor);
    bool removerLike(Perfil& autor);

    void inserirComment(Perfil& autor, std::string comment);
    void removerComment(int id);

    size_t getLikes();
    int getComments();

    virtual void idContador();
    const std::map<int, std::pair<Perfil, std::string>>& listarComments();
};

#endif
