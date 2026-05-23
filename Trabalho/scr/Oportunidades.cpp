#include "Oportunidades.h"


Oportunidades::Oportunidades(int id,
                             const std::string& descricao,
                             const std::string& contato,
                             const std::string& usuario) {

    id_ = id;
    descricao_ = descricao;
    contato_ = contato;
    usuario_ = usuario;


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

std::string Oportunidades::getUsuario() const {
    return usuario_;
}

void Oportunidades::editarOportunidade(const std::string& novaDescricao,
                                       const std::string& novoContato) {

    descricao_ = novaDescricao;
    contato_ = novoContato;
}

void Oportunidades::apagarOportunidade(){

    descricao_ = "";
    contato_ = "";

}