#ifndef OPORTUNIDADES_H
#define OPORTUNIDADES_H

#include "Perfil.h"
#include "Post.h"


#include <string>
#include <vector>


// Classe que gerencia várias oportunidades (lista)
class Oportunidades {

    private:
        
      // Representa UMA oportunidade (entidade) e só essa classe usa
        struct Oportunidade {
            std::string descricao;  // descrição da oportunidade
            std::string contato;    // informação de contato
            std::string usuario;   // username do usuário que criou a oportunidade
            int id;                // identificador único da oportunidade
        };
    
    // vetor que armazena todas as oportunidades do sistema
        std::vector<Oportunidade> oportunidades; 

        int proximoId; 
        // Controla o próximo ID único a ser atribuído, evitando 
        // recalcular ou buscar IDs no vetor

    public:
    
    //Construtor
    Oportunidades(); 

    // Cria uma nova oportunidade e adiciona ao vetor
    void criarOportunidade(const std::string& descricao, const std::string& contato, const Perfil& usuario);

    // Lista todas as oportunidades
    void listarOportunidades();

    // Edita uma oportunidade específica
    // Só deve permitir edição se o usuario for o dono
    void editarOportunidade(int id, const Perfil& usuario,  const std::string& novaDescricao, const std::string& novoContato);

    // Remove uma oportunidade
    // Também deve verificar se o usuario é o dono
    void removerOportunidade(int id, const Perfil& usuario);
};

#endif // OPORTUNIDADES_H