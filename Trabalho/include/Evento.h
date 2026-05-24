#ifndef EVENTO_H
#define EVENTO_H

#include <string>
#include <vector>
#include "Perfil.h"
#include "Post.h"

class Evento {
        private:

            std::string _textoEvento; //Evento a ser inserido
            std::string _contato; //Informações de contato
            Perfil organizador; //Perfil do organizador do evento
            Post post; //Para incluir curtidas e comentários
            std::vector<Evento> _listaEvento; // Para inserir os eventos cadastrados

        public:
            Evento(); //Construtor 

            //Getters
            std::string getTextoEvento();
            std::string getContato();
            Perfil getOrganizador();
            Post getPost();

            //Metodos
            void criarEvento(std::string textoEvento, std::string contato, Perfil organizador);
            void editarContato(std::string novoContato);
            void editarOrganizador(Perfil novoOrganizador);
            void editarEvento(std::string novoTexto);
            void excluirEvento(std::string textoEvento);

};

#endif // EVENTO_H