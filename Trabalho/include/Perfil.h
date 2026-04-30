#ifndef PERFIL_H_
#define PERFIL_H_

#include <string>

class Perfil{
    public:
    //metodos
    Perfil criaPerfil(std::string nome, std::string usuario, int senha, 
                        std::string bio, int telefone, std::string email);
    Perfil editarPerfil(std::string parametro);
    Perfil apagaPerfil(std::string nome);

    private:
    //dados
    std::string nome;
    std::string usuario;
    int senha;
    std::string bio;
    int telefone;
    std::string email;


};
#endif