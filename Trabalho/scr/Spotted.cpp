#include "Post.h"
#include "Spotted.h"


    Spotted::Spotted() : Post() {
        idCont_ = 0;
     }

    void Spotted::criarPost(std::string s){
    lista[idCont_] = s;
    idCont_++;
    }

    void Spotted::apagarPost(int indice){
    lista.erase(indice);
    //adicionar verificação de índice
    }
    
    const std::map<int, std::string>& Spotted::listarPosts(){
    return lista; //cout no main
    }
