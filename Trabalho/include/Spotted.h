#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include <map>
#include "Post.h"


    class Spotted : public Post {
    private:

    std::map <int ,std::string> lista;
    int idCont; //chave do map
    

    public:

    Spotted(); 

    void criarPost(std::string s);

    void apagarPost(int indice);

    const std::map<int, std::string>& listarPosts();  
    };
    
    #endif
