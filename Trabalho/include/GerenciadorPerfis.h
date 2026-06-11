#ifndef GERENCIADOR_PERFIS_H_
#define GERENCIADOR_PERFIS_H_

#include "Perfil.h"
#include <map>
#include <set>

/**
 * @brief Representa uma forma de armazenar e organizar os perfis da plataforma
 *
 * Armazena um map para guardar todos os perfis associados ao seu respectivo id/chave (atributo "idu" da classe Perfil)
 * Armazena outro map para guardar os ids dos usuarios
 * Armazena um set para guardar os emails dos usuarios
 * Armazena, tambem, o id do usuario usado para fazer o controle dos dados nos maps
 */
class GerenciadorPerfis
{
public:
    /**
     * @brief Construtor padrao
     *
     * Inicializa perfis_ e IDUsuario_
     * Declara id_ e atribui 0 a ele
     */
    GerenciadorPerfis();

    /**
     * @brief Cria um novo perfil
     *
     * Chama o construtor padrao da classe Perfil, armazenao novo perfil em perfis_ e guarda seu id em IDUsuario_
     *
     * @param nome string com o nome da pessoa
     * @param usuario string com o nome de usuario
     * @param senha string com a senha codificada
     * @param bio string com a biografia do usuario
     * @param telefone string com o numero de contato
     * @param email string com o email da pessoa
     */
    void criaPerfil(std::string nome, std::string usuario, std::string senha,
                    std::string bio, std::string telefone, std::string email);

    /**
     * @brief Edita alguma informacao especifica do perfil selecionado
     *
     * @param id chave associada ao perfil que se quer editar
     * @param parametro string que informa qual atributo do perfil sera editado
     * @param novo string que armazena o novo dado que substituira o antigo na edicao
     *
     * @details
     * Se parametro for igual a "bio", por exemplo, novo sera a nova biografia que substituira a antiga.
     * Funciona da mesma forma para todos os "tipos de parametro"
     */
    void editarPerfil(int id, std::string parametro, std::string novo);

    /**
     * @brief Deleta o perfil selecionado de perfis_ e deleta tambem seu id de IDUsuario_
     *
     * @param id chave do perfil selecionado para poder acha-lo em perfis_
     * @param usuario nome de usuario do perfil
     *
     * Essa funcao localiza o perfil no map perfis_ e localiza seu id no map IDUsuario_
     * Ao encontra-los, ela os elimina.
     */
    void apagaPerfil(int id, std::string usuario);

    /**
     * @brief Verfica se o perfil existe dentro de perfis_
     *
     * @param usuario nome de usuario usado para buscar o perfil desejado no map perfis_
     * @param senha string com a senha codificada
     *
     * @return true se o perfil for encontrado
     * @return false se ele nao for encontrado
     */
    bool verificaPerfil(std::string usuario, std::string senha);

    /**
     * @brief verifica se o email digitado existe dentro do set emailV
     *
     * @param email string que contem o email a ser verificado
     *
     * @return true se o email for achado no set
     * @return false se ele nao for encontrado
     */
    bool buscaemail(std::string email);

    /**
     * @brief encontra o perfil desejado em perfis_
     *
     * @param usuario nome de usuario do perfil que deseja encontrar
     *
     * @return ponteiro para o objeto do tipo Perfil que se desejava encontrar no map perfis_
     */
    Perfil *buscaPorUsuario(std::string usuario);

    /**
     * @brief encontra o perfil desejado em perfis_
     *
     * @param id chave/id do perfil que deseja encontrar
     *
     * @return ponteiro para o objeto do tipo Perfil que se desejava encontrar no map perfis_
     */
    Perfil *buscaPorID(int id);

    /**
     * @brief Permuta os caracteres da senha de forma a nao armazena-la da forma original
     *
     * @param senha string com a senha nao codificada do perfil
     *
     * @return string com a senha codificada
     */
    std::string codificador(std::string senha);

    /**
     * @brief Permuta os caracteres da senha de forma a transforma-la de volta no seu estado original
     *
     * @param senha string com a senha codificada
     *
     * @return string com a senha original
     */
    std::string decodificador(std::string senha);

private:
    std::map<int, Perfil> perfis_;
    std::map<std::string, int> IDUsuario_;
    std::set<std::string> emailV;
    int id_ = 0;
};

#endif