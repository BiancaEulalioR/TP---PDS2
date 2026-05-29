#include "Post.h"
#include "Spotted.h"


    Spotted::Spotted() : Post() {
        idCont = 0;
     }

    void Spotted::criarPost(std::string s){
    lista[idCont] = s;
    idCont++;
    }

    void Spotted::apagarPost(int indice){
    lista.erase(indice);
    //adicionar verificação de índice
    }
    
    const std::map<int, std::string>& Spotted::listarPosts(){
    return lista; //cout no main
    }
