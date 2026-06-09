#include "Post.h"
#include "Perfil.h"

Post::Post()
{
  likes = 0;
  idCont = 0; // chave do map comments
  qtdComments = 0;
}

void Post::inserirLike()
{
  likes += 1;
}

void Post::removerLike()
{
  likes -= 1;
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

int Post::getLikes()
{
  return likes;
}
void Post::idContador()
{
  idCont++;
}
int Post::getComments(){
  return qtdComments;
}
const std::map<int, std::pair<Perfil, std::string>>& listarComments()
{
  return comments;
}
