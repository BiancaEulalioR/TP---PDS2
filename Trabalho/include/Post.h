#ifndef POST_H_
#define POST_H_

#include <string>
#include <map>


class Post{
    private:

    int likes;
    int idCont; //chave do map
    std::map <int,std::string> comments;

    public:

    Post(); 
    
    void inserirLike();

    void removerLike();

    void inserirComment(std::string comment);

    void removerComment(int id);

    int getLikes();

    const std::map<int, std::string>& listarComments(); // passagem por referência

    };
    
    #endif
