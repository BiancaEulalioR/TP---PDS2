#include "Post.h"
#include "Spotted.h"


    Spotted::Spotted() : idCont_(0), spotted_() {}

    Spotted::Spotted(std::string spotted_, Perfil& usuario) : idCont_(id), 
    perfilAssociadoEvento_(usuario){}
        

    void Spotted::apagarPost(int indice){
    lista.erase(indice);
    //adicionar verificação de índice
    }
    
    const std::map<int, std::string>& Spotted::listarPosts(){
    return lista; //cout no main
    }
