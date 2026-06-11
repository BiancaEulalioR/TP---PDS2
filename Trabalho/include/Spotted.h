#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include "Perfil.h"
#include "Post.h"

/**
 * @brief Faz postagens de texto de forma anonima
 * Armazena o texto da publicacao anonima e
 * o usuario associado a postagem,
 * faz operacoes basicas de rede sociais
 * e classe filha de post herdando seus metodos e atributos
 */
    class Spotted : public Post {
    private:
    //dados
    std::string textoSpotted_; //texto do spotted
    Perfil perfilAssociadoSpotted_;

    public:
    /**
    * @brief Construtor padrao. Inicializa vazio
    */
    Spotted(); 

    /**
    * @brief Construtor padrao. 
    * @param textoSpotted_ texto a ser publicado
    * @param perfilAssociadoSpotted_ usuario que fara a publicação
    */
    Spotted(std::string spotted_, Perfil& usuario);

    //getters
    Perfil getPerfil() const;
    std::string getSpotted();

    void apagarPost();  
    
    };
    
    #endif

