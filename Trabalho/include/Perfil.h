#ifndef PERFIL_H_
#define PERFIL_H_

#include <string>
#include <vector>

class Perfil{
    public:
    //metodos
    void criaPerfil(std::string nome, std::string usuario, std::string senha, 
                        std::string bio, std::string telefone, std::string email);
    void editarPerfil(std::string usuario, std::string parametro, std::string novo);
    void apagaPerfil(std::string usuario);
    bool verificaPerfil(std::string usuario, std::string senha);
    std::string getUsuario();
    
    private:
    //dados
    struct Usuario{
    std::string nome_;
    std::string senha_;
    std::string bio_;
    std::string telefone_;
    std::string email_;
    std::string usuario_;
    };

    std::vector <Usuario> Perfil_;

};
#endif