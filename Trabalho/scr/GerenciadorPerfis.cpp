#include "GerenciadorPerfis.h"

    void GerenciadorPerfis::criaPerfil(std::string nome, std::string usuario, std::string senha, 
                        std::string bio, std::string telefone, std::string email){
                            Perfil novoPerfil;
                            novoPerfil.setNome(nome);
                            novoPerfil.setUsuario(usuario);
                            novoPerfil.setSenha(codificador(senha));
                            novoPerfil.setBio(bio);
                            novoPerfil.setTelefone(telefone);
                            novoPerfil.setEmail(email);
                            novoPerfil.setidu(id_);
                            perfis_[id_] = novoPerfil;
                            IDUsuario_[usuario] = id_;
                            id_++;
                        }

    void GerenciadorPerfis::editarPerfil(int id, std::string parametro, std::string novo){
        auto it = perfis_.find(id);

        if(it != perfis_.end()){
            if(parametro=="nome")
                it->second.setNome(novo);
            if(parametro=="usuario"){
                IDUsuario_.erase(it->second.getUsuario()); 
                IDUsuario_[novo] = id;                     
                it->second.setUsuario(novo);   
            }
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

         if(it != perfis_.end()){
            IDUsuario_.erase(it->second.getUsuario());
            perfis_.erase(it);
         }
     }

    
     bool GerenciadorPerfis::verificaPerfil(std::string usuario, std::string senha){
        Perfil* p;
        p = buscaPorUsuario(usuario);
        if(p==nullptr) return false;
        if((p->getUsuario()==usuario)&&(decodificador(p->getSenha())==senha)){
            return true;
        } else return false;
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

    Perfil* GerenciadorPerfis::buscaPorUsuario(std::string usuario){
        auto it = IDUsuario_.find(usuario);
        if(it!=IDUsuario_.end()){
        int id = it->second;
        return &perfis_[id];
        } 
        return nullptr;
    }

    Perfil* GerenciadorPerfis::buscaPorID(int id){
        auto it = perfis_.find(id);
        if(it != perfis_.end())
            return &it->second;
        return nullptr;
    }


