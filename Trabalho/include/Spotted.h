#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include <map>
#include "Perfil.h"
#include "Post.h"


    class Spotted : public Post {
    private:
    //dados
    std::string spotted_; //texto do spotted
    std::map <int ,std::string> lista;
    int idCont_; //chave do map
    

    public:

    Spotted(); 

    Spotted(std::string spotted_, Perfil& usuario);
    void apagarPost(int indice);
    const std::map<int, std::string>& listarPosts();  
    };
    
    #endif
