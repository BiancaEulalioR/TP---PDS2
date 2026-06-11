#ifndef OPORTUNIDADES_H
#define OPORTUNIDADES_H

#include "Perfil.h"
#include "Post.h"

#include <string>

/**
 * @brief Representa um post de oportunidade
 *
 * E um post, ou seja, herda os atributos e metodos da classe Post.
 * Armazena uma descricao da oportunidade, um contato responsavel,
 * o id da oportunidade e o perfil do usuario que a publicou.
 */
class Oportunidades : public Post
{

private:
    std::string descricao_;  ///< Descricao da oportunidade
    std::string contato_;    ///< Contato responsavel pela oportunidade
    int id_;                 ///< Identificador unico da oportunidade, usado como chave no map
    Perfil perfilAssociado_; ///< Perfil do usuario que publicou a oportunidade

public:
    /**
     * @brief Construtor padrao
     *
     * Inicializa os atributos com valores vazios/padrao.
     * Necessario para uso em containers como std::map.
     */
    Oportunidades();

    /**
     * @brief Construtor parametrizado
     *
     * @param id identificador unico da oportunidade
     * @param descricao texto descrevendo a oportunidade
     * @param contato string com o contato responsavel pela oportunidade
     * @param usuario perfil do usuario que esta publicando a oportunidade
     */
    Oportunidades(int id, const std::string &descricao, const std::string &contato, const Perfil &usuario);

    // Getters
    int getId() const;
    std::string getDescricao() const;
    std::string getContato() const;
    Perfil getPerfil() const;

    // Setters
    void setContato(const std::string &novoContato);
    void setDescricao(const std::string &novaDescricao);

    /**
     * @brief Edita a descricao e o contato da oportunidade
     *
     * @param novaDescricao nova descricao da oportunidade
     * @param novoContato novo contato responsavel pela oportunidade
     */
    void editarOportunidade(const std::string &novaDescricao, const std::string &novoContato);

    /**
     * @brief Apaga os dados da oportunidade
     *
     * Limpa os atributos da oportunidade.
     */
    void apagarOportunidade();
};

#endif // OPORTUNIDADES_H
