#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include <vector>
#include "Post.h"


class Spotted{
    private:

    //listas de posts do Spotted
    std::vector <std::string> lista;

    public:

    Spotted(); //Construtor

    //Cria um novo post e adiciona na listagem
    void criarPost(std::string s);

     //Remove post publicado da listagem
    void apagarPost(int indice);

     //Lista os posts publicados
    void listarPosts();
    };
    
    #endif
