#include "Oportunidades.h"


Oportunidades::Oportunidades(int id,
                             const std::string &descricao,
                             const std::string &contato,
                             const Perfil &usuario) {

    id_ = id;
    descricao_ = descricao;
    contato_ = contato;
    perfilAssociado_= usuario;


}

Oportunidades::Oportunidades()
{
    id_ = 0;
    descricao_ = "";
    contato_ = "";
}

int Oportunidades::getId() const {
    return id_;
}

std::string Oportunidades::getDescricao() const {
    return descricao_;
}

std::string Oportunidades::getContato() const {
    return contato_;
}

Perfil Oportunidades::getPerfil() const
{
    return perfilAssociado_;
}

void Oportunidades::editarOportunidade(const std::string& novaDescricao,
                                       const std::string& novoContato) {

    descricao_ = novaDescricao;
    contato_ = novoContato;
}

void Oportunidades::setContato(const std::string& novoContato) {
    contato_ = novoContato;
}

void Oportunidades::setDescricao(const std::string& novaDescricao) {
    descricao_ = novaDescricao;
}

void Oportunidades::apagarOportunidade(){

    descricao_ = "";
    contato_ = "";

}