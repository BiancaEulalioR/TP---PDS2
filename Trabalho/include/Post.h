#ifndef POST_H_
#define POST_H_

#include <string>
#include <vector>


class Post{
    private:

    //curtidas
    int likes;

    //comentários
    std::vector <std::string> comments;

    public:
    Post(); //construtor

    //Inserir a curtida no post
    void inserirLike();

     //Remover a curtida post
    void removerLike();

     //Inserir um comentário no post
    void inserirComment(std::string comment);

    //Remover o comentário do post
    void removerComment(int *indice);

    };
    
    #endif
