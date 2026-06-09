#include "Evento.h"

Evento::Evento() : idCont_(0), textoEvento_(""), contato_("") {}

Evento::Evento(const std::string& textoEvento, const std::string& contato, const Perfil& organizador, 
        const Perfil& usuario) : idCont_(id), textoEvento_(textoEvento), contato_(contato), organizador_(organizador), 
        perfilAssociadoEvento_(usuario) {}
            // perfilAssociado_ inicializado com usuario (ajustar após verificação de perfis)


std::string Evento::getTextoEvento() const{
    return textoEvento_; }


std::string Evento::getContato() const{
    return contato_; }


Perfil Evento::getOrganizador() const{
    return organizador_; }

Perfil Evento::getPerfil() const{
    return perfilAssociadoEvento_; }


void Evento::editarContato(const std::string& novoContato){
    contato_ = novoContato; }            

void Evento::editarOrganizador(const Perfil& novoOrganizador){
    organizador_ = novoOrganizador; }

void Evento::editarEvento(const std::string& novoTexto) {
    textoEvento_ = novoTexto; }
            
void Evento::apagarEvento(){
    textoEvento_ = "";
    contato_ = ""; }
