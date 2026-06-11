#pragma once
#include <string>
#include <vector>
#include "Perfil.h"
#include "Post.h"

/*
 * @brief Representa um post de serviço
 *
 * E um post, ou seja, herda os atributos e metodos da classe post
 * Armazena uma descricao do servico
 * Armazena numero de contato, id do perfil que o postou e o perfil da pessoa que postou
 * Armazena o id desse servico que sera usado como a chave associada a ele no map que armazena todos os objetos dessa classe
 */
class Servico : public Post
{
private:
    std::string descricaoDoServico_;
    std::string numeroContato_; ///< O numero para contatar o servico pode ser diferente do telefone_ (atributo de perfil)
    int idDeArmazenamento_;     ///< Chave do map de servicos relacionada com o objeto servico declarado
    int idDoPerfilAssociado_;
    Perfil perfilAssociadoS_;

public:
    /*
     * @brief Construtor padrao
     *
     * Inicializa descricaoDoServico_ e numeroContato_ vazios
     * Declara idArmazenamento e idDoPerfilAssociado_
     * Chama um construtor padrao da classe Perfil para inicializar o perfilAssociadoS_
     */
    Servico();

    /*
     * @brief Construtor padrao
     *
     * @param descricao texto atribuido como a descrição do serviço
     * @param num string com o numero de contato
     * @param idServi chave do map de servicos associada ao objeto servico criado
     * @param idPerf a chave do perfil que postou o servico a ser criado
     * @param perf perfil da pessoa que esta criando esse objeto servico
     *
     * Inicializa descricaoDoServico_ e numeroContato_ vazios
     * Declara idArmazenamento e idDoPerfilAssociado_
     * Chama um construtor padrao da classe Perfil para inicializar o perfilAssociadoS_
     */
    Servico(std::string descricao, std::string num, int idServi, int idPerf, Perfil perf);

    /*
     * @brief Destrutor padrao
     *
     * Desaloca as strings descricaoDoServico_ e numeroContato_
     */
    ~Servico();

    // Getters
    std::string getDescricaoDoServico() const;
    std::string getNumeroContato() const;
    int getIdServico() const;
    int getIdPerfilAssociado() const;
    const Perfil &getPerfilAssociado() const;

    // Setters
    void setDescricaoDoServico(std::string descricaoL);
    void setNumeroContato(std::string numL);
    void setIdServico(int novoId);
    void setIdPerfilAssociado(int novoIdPerfil);
    void setPerfilAssociado(Perfil novoPerfilAssociado);
};
