#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include "Perfil.h"
#include "Post.h"


    class Spotted : public Post {
    private:
    //dados
    std::string spotted_; //texto do spotted
    Perfil perfilAssociadoSpotted_;

    public:

    Spotted(); 
    Spotted(std::string spotted_, Perfil& usuario);
    std::string getSpotted();
    void apagarPost();  
    Perfil getPerfil() const;
    };
    
    #endif

