#include <iostream>
#include "Evento.h"
#include "Oportunidades.h"
#include "Perfil.h"
#include "Post.h"
#include "Servico.h"
#include "Spotted.h"
#include <string>

void main(){
    //criação de um perfil

    std::cout << "Qual ação deseja realizar: " << std::endl;
    std::cout << "1.Criar Perfil " << std::endl << "2.Entrar " << std::endl;
    int aux1, aux2;
    std::cin >> aux1;
    std::string n, u, s, b, t, e;
    Perfil gerenciador_;


    switch(aux1){

        case 1: {
        std::cout << "E-mail: " << std::endl;
        std::cin >> e;
        std::cout << "Nome completo: " << std::endl;
        std::cin >> n;
        std::cout << "Nome de usuario: " << std::endl;
        std::cin >> u; 
        std::cout << "Senha: " << std::endl;
        std::cin >> s;
        std::cout << "Biografia: " << std::endl;
        std::cin >> b;
        std::cout << "Telefone: " << std::endl;
        std::cin >> t;
        gerenciador_.criaPerfil(n, u, s, b, t, e);
        break;
        }

        case 2: {   
            std::cout << "Nome de usuario: " << std::endl;
            std::cin >> n;
            std::cout << "Senha: " << std::endl;
            std::cin >> s;
            if(gerenciador_.verificaPerfil(n, s)){
                aux2 = 1;
                std::cout << "Bem vindo!!" << std::endl;
            } else std::cout << "Perfil nao encontrado.";
        }
    }

}