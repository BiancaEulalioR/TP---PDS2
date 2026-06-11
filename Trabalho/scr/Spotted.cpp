#include "Post.h"
#include "Spotted.h"


    Spotted::Spotted() : textoSpotted_() {}

    Spotted::Spotted(std::string spotted_, Perfil& usuario) {
        textoSpotted_ = spotted_;
        perfilAssociadoSpotted_ = usuario;
    }
        

    std::string Spotted::getSpotted(){
        return textoSpotted_;
    }

    void Spotted::apagarPost(){
        textoSpotted_ = "";
    }
    Perfil Spotted::getPerfil() const{
        return perfilAssociadoSpotted_; }
    

