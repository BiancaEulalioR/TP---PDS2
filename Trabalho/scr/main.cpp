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
    int aux1, aux2 = 0, aux3 = 0;
    std::cin >> aux1;
    std::string n, u, s, b, t, e;
    Perfil gerenciador_;

while(1){
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
        aux2 = 1;
        break;
        }

        case 2: {   
            std::cout << "Nome de usuario: " << std::endl;
            std::cin >> u;
            std::cout << "Senha: " << std::endl;
            std::cin >> s;
            if(gerenciador_.verificaPerfil(u, s)){
                aux2 = 1;
                std::cout << "Bem vindo!!" << std::endl;
            } else std::cout << "Perfil nao encontrado.";
        }
    }

    while(aux2){
        std::cout << "Qual aba deseja acessar: " << std::endl;
        std::cout << "1. Spotted" << std::endl;
        std::cout << "2. Eventos" << std::endl;
        std::cout << "3. Oportunidades" << std::endl;
        std::cout << "4. Serviços" << std::endl;
        std::cout << "5. Informações do usuario" << std::endl;
        std::cin >> aux3;

        switch (aux3){
            case 1: {

            }
            case 2: {

            }
            case 3:{

            }
            case 4:{

            }
            case 5:{
                
            }
        }
    }
 }
}