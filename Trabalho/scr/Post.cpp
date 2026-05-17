#include "Post.h"


    Post::Post(){
      likes = 0;
      idCont = 0; //chave do map comments
    }
    
    void Post::inserirLike(){
      likes += 1 ;
    }

    void Post::removerLike(){
      likes -= 1 ;
    }

    void Post::inserirComment(std::string comment){
      comments[idCont] = comment;
      idCont++; //aumenta o índice do próximo comentário
    }

    void Post::removerComment(int id){
      comments.erase(id);
    }

    int Post::getLikes(){
      return likes;
    }

    const std::map<int, std::string>& Post::listarComments() {
    return comments; 
    }

