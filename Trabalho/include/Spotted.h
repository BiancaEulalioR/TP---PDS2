#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include <map>
#include "Post.h"


    class Spotted : public Post {
    private:
    //dados
    std::map <int ,std::string> lista;
    int idCont_; //chave do map
    

    public:

    Spotted(); 

    void criarPost(std::string spotted_);
    void apagarPost(int indice);
    const std::map<int, std::string>& listarPosts();  
    };
    
    #endif
