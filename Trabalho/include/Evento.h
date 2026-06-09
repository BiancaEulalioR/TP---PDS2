#ifndef EVENTO_H
#define EVENTO_H

#include <string>

#include "Perfil.h"
#include "Post.h"

class Evento : public Post {
        private:

            std::string textoEvento_; //Evento a ser inserido
            std::string contato_; //Informações de contato
            Perfil organizador_; //Perfil do organizador do evento
            Perfil perfilAssociadoEvento_;

        public:
            Evento(); //Construtor 
            Evento(const std::string& textoEvento, const std::string& contato,
                                    const Perfil& organizador,  Perfil& usuario);

            //Getters
            std::string getTextoEvento() const;
            std::string getContato() const;
            Perfil getOrganizador() const;
            Perfil getPerfil() const;

            //Metodos
            void editarContato(const std::string& novoContato);
            void editarOrganizador(const Perfil& novoOrganizador);
            void editarEvento(const std::string& novoTexto);
            void apagarEvento();
};

#endif // EVENTO_H