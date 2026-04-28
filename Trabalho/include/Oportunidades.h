#ifndef OPORTUNIDADES_H
#define OPORTUNIDADES_H

#include "Perfil.h"
#include "Post.h"
 

#include <string>



// Representa uma oportunidade
class Oportunidades {

    private:
        
            std::string descricao_;  // descrição da oportunidade
            std::string contato_;    // informação de contato
            std::string usuario_;   // username do usuário que criou a oportunidade
            int id_;                // identificador único da oportunidade
            
    public:
    
    //Construtor responsável por incializar uma oportunidade
    Oportunidades(int id_, const std::string& descricao_, const std::string& contato_, const Perfil& usuario_);

    // Getters (acesso aos dados)
    int getId() const;
    std::string getDescricao() const;
    std::string getContato() const;
    std::string getUsuario() const;

    // Edita os dados da oportunidade
    // Pré-condição: só pode ser feita a edição se o usuario for o dono
    void editarOportunidade(const std::string& novaDescricao, const std::string& novoContato);

};

#endif // OPORTUNIDADES_H