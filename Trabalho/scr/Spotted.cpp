#include "Post.h"
#include "Spotted.h"


    Spotted::Spotted() : idCont_(0), spotted_() {}

    Spotted::Spotted(std::string spotted_, Perfil& usuario) : idCont_(id), 
    perfilAssociadoSpotted_(usuario){}
        

    std::string Spotted::getSpotted(){
    return spotted_;
    }

    void Spotted::apagarPost(){
    spotted_ = "";
    }
    Perfil Spotted::getPerfil() const{
    return perfilAssociadoSpotted_; }
    

