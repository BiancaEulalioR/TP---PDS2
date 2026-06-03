#include "Perfil.h"

void Perfil::criaPerfil(std::string nome, std::string usuario, std::string senha, 
                        std::string bio, std::string telefone, std::string email){
                        perfil_.nome_ = nome;
                        perfil_.senha_ = senha;
                        perfil_.bio_ = bio;
                        perfil_.telefone_ = telefone;
                        perfil_.email_ = email;
                        perfil_.usuario_ = usuario;
                        }

void Perfil::editarPerfil(std::string parametro, std::string novo){

    if(parametro == "nome")
        perfil_.nome_ = novo;

    if(parametro == "senha")
        perfil_.senha_ = novo;

    if(parametro == "bio")
        perfil_.bio_ = novo;

    if(parametro == "telefone")
        perfil_.telefone_ = novo;

    if(parametro == "email")
        perfil_.email_ = novo;

    if(parametro == "usuario")
        perfil_.usuario_ = novo;
}


bool Perfil::verificaPerfil(std::string usuario, std::string senha){
    return (perfil_.usuario_ == usuario &&
            perfil_.senha_ == senha);
}


void Perfil::apagaPerfil(std::string usuario){
// metodo perdeu o sentido agora que a main tem maps, o ideal é removermos 
}

// getters
std::string Perfil::getNome() const
{
    return perfil_.nome_;
}

std::string Perfil::getUsuario() const
{
    return perfil_.usuario_;
}

std::string Perfil::getSenha() const
{
    return perfil_.senha_;
}

std::string Perfil::getBio() const
{
    return perfil_.bio_;
}

std::string Perfil::getTelefone() const
{
    return perfil_.telefone_;
}

std::string Perfil::getEmail() const
{
    return perfil_.email_;
}