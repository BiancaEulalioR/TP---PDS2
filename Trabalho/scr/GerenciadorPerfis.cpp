#include "GerenciadorPerfis.h"

    void GerenciadorPerfis::criaPerfil(std::string nome, std::string usuario, std::string senha, int id, 
                        std::string bio, std::string telefone, std::string email){
                            Perfil novoPerfil;
                            novoPerfil.setNome(nome);
                            novoPerfil.setUsuario(usuario);
                            novoPerfil.setSenha(codificador(senha));
                            novoPerfil.setBio(bio);
                            novoPerfil.setTelefone(telefone);
                            novoPerfil.setEmail(email);
                            perfis_[id_] = novoPerfil;
                        }

    void GerenciadorPerfis::editarPerfil(int id, std::string parametro, std::string novo){
        auto it = perfis_.find(id);

        if(it != perfis_.end()){
            if(parametro=="nome")
                it->second.setNome(novo);
            if(parametro=="usuario")
                it->second.setUsuario(novo);
            if(parametro=="senha")
                it->second.setSenha(codificador(novo));
            if(parametro=="bio")
                it->second.setBio(novo);
            if(parametro=="telefone")
                it->second.setTelefone(novo);
            if(parametro=="email")
                it->second.setEmail(novo);
        }
     }

    
     void GerenciadorPerfis::apagaPerfil(int id, std::string usuario){
         auto it = perfis_.find(id);

         if(it != perfis_.end())
            perfis_.erase(it);
     }

    
     bool GerenciadorPerfis::verificaPerfil(int id, std::string usuario, std::string senha){
        auto it = perfis_.find(id);

        if(it != perfis_.end()){
            if((it->second.getUsuario() == usuario)&&(decodificador(it->second.getSenha()) == senha))
                return true;
            else return false;
        }
        return false;
     }


    std::string GerenciadorPerfis::codificador(std::string senha){
        for(int i = 0; i<senha.size(); i++)
            senha[i] += 2;
        return senha;
    }

    std::string GerenciadorPerfis::decodificador(std::string senha){
        for(int i = 0; i<senha.size(); i++)
            senha[i] -= 2;
        return senha;
    }



