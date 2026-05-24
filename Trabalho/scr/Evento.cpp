#include "Evento.h"

Evento::Evento(){
    _textoEvento = "";
    _contato = ""; }

std::string Evento::getTextoEvento(){
    return _textoEvento; }


std::string Evento::getContato(){
    return _contato; }


Perfil& Evento::getOrganizador(){
    return organizador; }

Post& Evento::getPost(){
    return post; }

            
void Evento::criarEvento(std::string textoEvento, std::string contato, Perfil organizador){
    Evento novoEvento;
    novoEvento._textoEvento = textoEvento;
    novoEvento._contato = contato;
    novoEvento.organizador = organizador;
    _listaEvento.push_back(novoEvento); }
            
void Evento::editarContato(std::string novoContato){
    _contato = novoContato; }

void Evento::editarOrganizador(Perfil novoOrganizador){
    organizador = novoOrganizador; }
            
void Evento::editarEvento(std::string novoTexto){
    _textoEvento = novoTexto; }
            
void Evento::excluirEvento(std::string textoEvento){
    for (int i = 0; i < _listaEvento.size(); i++){
        if (_listaEvento[i]._textoEvento == textoEvento){
            _listaEvento.erase(_listaEvento.begin() + i);
        break; }  }   }
