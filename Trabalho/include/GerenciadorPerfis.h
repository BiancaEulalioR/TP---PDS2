#ifndef GERENCIADOR_PERFIS_H_
#define GERENCIADOR_PERFIS_H_

#include "Perfil.h"
#include <map>

class GerenciadorPerfis{
    public:
    void criaPerfil(std::string nome, std::string usuario, std::string senha, 
                        std::string bio, std::string telefone, std::string email);
    void editarPerfil(int id, std::string parametro, std::string novo);
    void apagaPerfil(int id, std::string usuario);
    bool verificaPerfil(std::string usuario, std::string senha);
    Perfil* buscaPorUsuario(std::string usuario);
    std::string codificador(std::string senha);
    std::string decodificador(std::string senha);

    private:
    std::map<int, Perfil> perfis_;
    std::map<std::string, int> IDUsuario_;
    int id_ = 0;
};

#endif