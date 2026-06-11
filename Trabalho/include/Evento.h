#ifndef EVENTO_H
#define EVENTO_H

#include <string>

#include "Perfil.h"
#include "Post.h"

/**
 * @brief Representa um post de evento
 *
 * E um post, ou seja, herda os atributos e metodos da classe Post.
 * Armazena as informacoes do evento, contato para comunicacao
 * e o perfil do usuario associado ao evento.
 */
 class Evento : public Post {
        private:

            std::string textoEvento_; ///< Texto contendo as informacoes do evento
            std::string contato_; ///< Informacoes de contato do evento
            Perfil organizador_; ///< Perfil do organizador do evento
            Perfil perfilAssociadoEvento_; ///< Perfil do usuario associado ao evento

        public:
        
            /**
            * @brief Construtor padrao
            *
            * Inicializa os atributos com valores vazios/padrao.
            * Necessario para uso em containers como std::map.
            */
            Evento();

            /**
            * @brief Construtor parametrizado
            *
            * @param textoEvento texto contendo as informacoes do evento
            * @param contato informacoes de contato para o evento
            * @param usuario perfil do usuario que esta criando o evento
            */
            Evento(const std::string& textoEvento, const std::string& contato, Perfil& usuario);

            //Getters
            std::string getTextoEvento() const;
            std::string getContato() const;
            Perfil getOrganizador() const;
            Perfil getPerfil() const;

            /**
            * @brief Altera as informacoes de contato do evento
            *
            * @param novoContato novo contato do evento
            */
            void editarContato(const std::string& novoContato);

            /** 
            * @brief Altera o organizador do evento
            *
            * @param novoOrganizador novo perfil organizador do evento
            */
            void editarOrganizador(const Perfil& novoOrganizador);

            /**
            * @brief Edita o texto do evento
            *
            * @param novoTexto novo texto contendo as informacoes do evento
            */
            void editarEvento(const std::string& novoTexto);

            /**
            * @brief Apaga os dados do evento
            *
            * Limpa as informacoes armazenadas no evento.
            */
            void apagarEvento();
};

#endif // EVENTO_H