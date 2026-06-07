#include "Perfil.h"
// Getters
    std::string Perfil::getNome() const{
        return nome_;
    }

    std::string Perfil::getUsuario() const{
        return usuario_;
    }

    std::string Perfil::getSenha() const{
        return senha_;
    }
    
    std::string Perfil::getBio() const{
        return bio_;
    }

    std::string Perfil::getTelefone() const{
        return telefone_;
    }

    std::string Perfil::getEmail() const{
        return email_;
    }

    int Perfil::getidu() const{
        return idu;
    }


// Setters
    void Perfil::setNome(std::string nome){
        nome_ = nome;
    }

    void Perfil::setSenha(std::string senha){
        senha_ = senha;
    }

    void Perfil::setBio(std::string bio){
        bio_ = bio;
    }

    void Perfil::setTelefone(std::string telefone){
        telefone_ = telefone;
    }

    void Perfil::setEmail(std::string email){
        email_ = email;
    }

    void Perfil::setUsuario(std::string usuario){
        usuario_ = usuario;
    }

    void Perfil::setidu(int id){
        idu = id;
    }