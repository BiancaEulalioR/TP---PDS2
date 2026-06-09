#include "Post.h"
#include "Perfil.h"

Post::Post()
{
  idCont = 0; // chave do map comments
  qtdComments = 0;
}

void Post::inserirLike(Perfil& autor){
  if(likes.find(autor.getidu()) == likes.end()){
    likes.insert(autor.getidu());
  }

  else{
    std::cout << "Voce ja curtiu essa publicacao." << std::endl;
  }
}

void Post::removerLike(Perfil& autor){
  if(likes.find(autor.getidu()) != likes.end()){
    likes.erase(autor.getidu());
  }

  else{
    std::cout << "Voce nao curtiu essa publicacao." << std::endl;
  }
}

void Post::inserirComment(Perfil& autor, std::string comment)
{
  comments[idCont] = std::make_pair(autor,comment);
  idCont++; //aumenta o índice do próximo comentário
  qtdComments++;
}

void Post::removerComment(int id)
{
  comments.erase(id);
  qtdComments--;
}

size_t Post::getLikes()
{
  return likes.size();
}

void Post::idContador()
{
  idCont++;
}

int Post::getComments(){
  return qtdComments;
}

const std::map<int, std::pair<Perfil, std::string>>& Post::listarComments()
{
  return comments;
}
