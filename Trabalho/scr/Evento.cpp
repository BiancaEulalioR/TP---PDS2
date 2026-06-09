#include "Evento.h"

Evento::Evento() : idCont_(0), textoEvento_(""), contato_("") {}

Evento::Evento(const std::string& textoEvento, const std::string& contato,
        const Perfil& usuario) : textoEvento_(textoEvento), contato_(contato), perfilAssociadoEvento_(usuario) {}


std::string Evento::getTextoEvento() const{
    return textoEvento_; }


std::string Evento::getContato() const{
    return contato_; }


Perfil Evento::getPerfil() const{
    return perfilAssociadoEvento_; }


void Evento::editarContato(const std::string& novoContato){
    contato_ = novoContato; }            

void Evento::editarEvento(const std::string& novoTexto) {
    textoEvento_ = novoTexto; }
            
void Evento::apagarEvento(){
    textoEvento_ = "";
    contato_ = ""; }
