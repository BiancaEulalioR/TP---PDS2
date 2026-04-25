#ifndef PERFIL_H_
#define PERFIL_H_

#include <string>

class Perfil{
    private:
    //Nome a ser inserido pelo usuário 
    std::string nome;

    //Nome de exibição a ser escolhido pelo usuário
    std::string usuario;

    //Senha de acesso
    int senha;

    //Biografia do perfil do usuário
    std::string bio;

    //Número de telefone de contato do usuário
    int telefone;

    //Email de contato do usuário
    std::string email;

    public:
    //Solicita as informações necessárias para criar perfil do usuário
    Perfil criaPerfil(std::string nome, std::string usuario, int senha, 
                        std::string bio, int telefone, std::string email);

    // Altera informação desejada
    Perfil editarPerfil(std::string parametro);

    //Apaga o perfil do usuário
    Perfil apagaPerfil(std::string nome);
};
#endif