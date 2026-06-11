#ifndef PERFIL_H_
#define PERFIL_H_

#include <string>

/**
 * @brief Representa o perfil do usuario
 *
 * Armazena nome, senha, biografia, telefone, email e nome de usuario da pessoa; todos como strings.
 * Armazena tambem o id do perfil que e usado como a chave associada ao objeto perfil especifico no gerenciador
 */
class Perfil
{
public:
    /**
     * @brief Construtor padrao
     *
     * Inicializa nome_, senha_, bio_, telefone_, email_ e usuario_ como strings vazias
     * Declara idu
     */
    Perfil();

    /**
     * @brief Destrutor padrao
     *
     * Desaloca as strings nome_, senha_, bio_, telefone_, email_ e usuario_
     */
    ~Perfil();

    // Getters
    std::string getNome() const;
    std::string getUsuario() const;
    std::string getSenha() const;
    std::string getBio() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    int getidu() const;

    // Setters
    void setNome(std::string nome);
    void setSenha(std::string senha);
    void setBio(std::string bio);
    void setTelefone(std::string telefone);
    void setEmail(std::string email);
    void setUsuario(std::string usuario);
    void setidu(int id);

private:
    std::string nome_;
    std::string senha_;
    std::string bio_;
    std::string telefone_;
    std::string email_;
    std::string usuario_;
    int idu; ///< chave do map de perfis relacionada ao objeto do tipo Perfil
};
#endif