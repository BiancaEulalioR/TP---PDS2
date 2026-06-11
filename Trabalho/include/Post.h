#ifndef POST_H_
#define POST_H_

#include <string>
#include <map>
#include <set>
#include "Perfil.h"

/**
 * @brief Classe mae
 * Armazena quantidade de curtidas 
 * alem do conteudo e quantidade de comentarios
 * e classe mae de todas as classes 
 * disponibilizando seus metodos de acoes em redes sociais
 * 
 */
class Post
{
private:
    //dados
    std::set<int> likes;
    int idCont; //chave do map
    int qtdComments;
    std::map<int, std::pair<Perfil, std::string>> comments;

public:
    /**
    * @brief Construtor padrao. Inicializa vazio.
    */
    Post();

    /**
    * @brief Deixa uma curtida no post
    * @param autor usuario associado ao post
    * @return true se o usuario associado nao curtiu, false se o usuario curtiu
    * @details evita que o usuario curta novamente uma postagem
    */
    bool inserirLike(Perfil& autor);

    /**
    * @brief Remove sua curtida no post
    * @param autor usuario associado ao post
    * @return true se o usuario associado curtiu, false se o usuario nao curtiu
    * @details evita que o usuario descurta novamente uma postagem que ele nao curtiu
    */
    bool removerLike(Perfil& autor);

    /**
    * @brief Remove sua curtida no post
    * @param autor usuario associado ao post
    * @param comment comentario a ser publicado 
    */
    void inserirComment(Perfil& autor, std::string comment);

    /**
    * @brief Remove sua curtida no post
    * @param id do comentario a ser removido
    * @details remove o comentario baseado no seu id
    */
    void removerComment(int id);

    size_t getLikes();
    int getComments();

    virtual void idContador();//ver se estamos usando

    std::set<int>& getPessoasQueCurtiram();
    const std::map<int, std::pair<Perfil, std::string>>& listarComments();  
};

#endif

