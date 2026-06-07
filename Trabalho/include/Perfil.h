#ifndef PERFIL_H_
#define PERFIL_H_

#include <string>

class Perfil{
    public:
        // Getters
    std::string getNome() const;
    std::string getUsuario() const;
    std::string getSenha() const;
    std::string getBio() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    int getidu() const;

    void setNome(std::string nome);
    void setSenha(std::string senha);
    void setBio(std::string bio);
    void setTelefone(std::string telefone);
    void setEmail(std::string email);
    void setUsuario(std::string usuario);
    void setidu(int id);
    
    private:
    //dados
    std::string nome_;
    std::string senha_;
    std::string bio_;
    std::string telefone_;
    std::string email_;
    std::string usuario_;
    int idu;
};
#endif