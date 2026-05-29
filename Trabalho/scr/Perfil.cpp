#include "Perfil.h"

void Perfil::criaPerfil(std::string nome, std::string usuario, std::string senha, 
                        std::string bio, std::string telefone, std::string email){
                        Usuario perfil;
                        perfil.nome_ = nome;
                        perfil.senha_ = senha;
                        perfil.bio_ = bio;
                        perfil.telefone_ = telefone;
                        perfil.email_ = email;
                        perfil.usuario_ = usuario;
                        Perfil_.push_back(perfil);
                        }

void Perfil::editarPerfil(std::string usuario, std::string parametro, std::string novo){
        for(int i = 0; i < Perfil_.size(); i++){
            if(Perfil_[i].usuario_ == usuario){
                if(parametro == "nome")
                    Perfil_[i].nome_ = novo;
                if(parametro == "senha")
                    Perfil_[i].senha_ = novo;
                if(parametro == "bio")
                    Perfil_[i].bio_ = novo;
                if(parametro == "telefone")
                    Perfil_[i].telefone_ = novo;
                if(parametro == "email")
                    Perfil_[i].email_ = novo;
                if(parametro == "usuario")
                    Perfil_[i].usuario_ = novo;
                break;
            }
        }
}
bool Perfil::verificaPerfil(std::string usuario, std::string senha){
    for (int i = 0; i < Perfil_.size(); i++){
        if(Perfil_[i].usuario_ == usuario){
            if(Perfil_[i].senha_ == senha)
                return true;
        }
    }
    return false;
}

void Perfil::apagaPerfil(std::string usuario){
    for (int i = 0; i < Perfil_.size(); i++){
        if(Perfil_[i].usuario_ == usuario){
            Perfil_.erase(Perfil_.begin() + i);
            break;
        }
    }
}