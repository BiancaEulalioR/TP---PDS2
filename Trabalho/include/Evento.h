#ifndef EVENTOS_H
#define EVENTOS_H

#include <string>
#include "Perfil.h"
#include "Post.h"

class Evento {
        private:
            std::string textoEvento; //Evento a ser inserido

            std::string contato; //Informações de contato

            Perfil organizador; //Perfil do organizador do evento

            Post post; //Para incluir curtidas e comentários

        public:
            Evento(); //Construtor 

            //Getters
            std::string getTextoEvento();

            std::string getContato();
            
            Perfil getOrganizador();

            //Metodos
            Evento criarEvento(std::string textoEvento, std::string contato, Perfil organizador);

            void editarEvento(std::string textoEvento);

            Evento infoContato(std::string contato);

            void listarEvento(std::string textoEvento);

            void excluirEvento(std::string textoEvento);

};

#endif // EVENTOS_H