#ifndef POST_H_
#define POST_H_

#include <string>
#include <vector>


class Post{
    private:

    //Guarda a quantidade de likes
    int likes;

    //Guarda os comentários em um vector de string
    std::vector <std::string> comments;

    public:
    //Inicializa Post com 0 likes 
    Post(); 
    
    void inserirLike();

    void removerLike();

    //Insere um comentário no fim do post
    void inserirComment(std::string comment);

    //Remove o comentário feito pelo perfil
    void removerComment(int *indice);

    //Retorna o número de likes do post;
    int getLikes();

    //Retorna o número de comentários do post;
    int getComment();

    };
    
    #endif
