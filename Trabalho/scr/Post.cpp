#include "Post.h"
#include "Perfil.h"

Post::Post()
{
  likes = 0;
  idCont = 0; // chave do map comments
}

void Post::inserirLike()
{
  likes += 1;
}

void Post::removerLike()
{
  likes -= 1;
}

void Post::inserirComment(std::string comment)
{
  comments[idCont] = comment;
  idCont++; // aumenta o índice do próximo comentário
}

void Post::removerComment(int id)
{
  comments.erase(id);
}

int Post::getLikes()
{
  return likes;
}
void Post::idContador()
{
  idCont++;
}
Perfil Post::getPerfil()
{
  return perfilAssociado;
}

const std::map<int, std::string> &Post::getComments()
{
  return comments;
}
