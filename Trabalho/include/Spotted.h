#ifndef SPOTTED_H_
#define SPOTTED_H_

#include <string>
#include "Perfil.h"
#include "Post.h"

/**
 * @brief Faz posts anônimos
 * Armazena o texto da publicação anônima e
 * o usuário associado a postagem,
 * faz operações básicas de rede sociais
 * 
 */
    class Spotted : public Post {
    private:
    //dados
    std::string textoSpotted_; //texto do spotted
    Perfil perfilAssociadoSpotted_;

    public:
    /**
    * @brief Construtor padrão. Inicializa textoSpotted_ e perfilAssociadoSpotted_ vazios
    */
    Spotted(); 

    /**
    * @brief Construtor padrão. 
    * @param textoSpotted_ texto a ser publicado
    * @param perfilAssociadoSpotted_ usuario que fará a publicação
    */
    Spotted(std::string spotted_, Perfil& usuario);
    Perfil getPerfil() const;
    std::string getSpotted();

    void apagarPost();  
    
    };
    
    #endif

