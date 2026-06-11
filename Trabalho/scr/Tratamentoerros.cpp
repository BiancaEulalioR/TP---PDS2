#include "Tratamentoerros.hpp"

void verificaTexto(std::string &texto){
    while(texto.empty()){
        try
        {
            throw std::invalid_argument("O texto inserido esta vazio.");      
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Erro: " << e.what() << " Por favor, digite novamente: "<< std::endl;
            std::getline(std::cin, texto); 
        }
    }
}

void verificaEmail(std::string &email)
{
    bool valido = false;
    while (!valido)
    {
        try
        {
            if (email.empty())
                throw std::invalid_argument("O email esta vazio.");

            // verifica se tem @ e .
            size_t arroba = email.find('@');
            size_t ponto = email.find('.', arroba);

            if (arroba == std::string::npos || ponto == std::string::npos || arroba == 0 || ponto == arroba + 1)
                throw std::invalid_argument("Email invalido. Use o formato exemplo@email.com");

            valido = true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Erro: " << e.what() << " Por favor, digite novamente: " << std::endl;
            std::getline(std::cin, email);
        }
    }
}

void verificaSenha(std::string &senha)
{
    bool valido = false;
    while (!valido)
    {
        try
        {
            if (senha.empty())
                throw std::invalid_argument("A senha esta vazia.");

            if (senha.size() < 6)
                throw std::invalid_argument("A senha deve ter pelo menos 6 caracteres.");

            valido = true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Erro: " << e.what() << " Por favor, digite novamente: " << std::endl;
            std::getline(std::cin, senha);
        }
    }
}

void verificaTelefone(std::string &telefone)
{
    bool valido = false;
    while (!valido)
    {
        try
        {
            if (telefone.empty())
                throw std::invalid_argument("O telefone esta vazio.");

            if (telefone.size() != 11)
                throw std::invalid_argument("O telefone deve ter 11 digitos com DDD.");

            for (char c : telefone)
            {
                if (!isdigit(c))
                    throw std::invalid_argument("O telefone deve conter apenas numeros.");
            }

            valido = true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Erro: " << e.what() << " Por favor, digite novamente: " << std::endl;
            std::getline(std::cin, telefone);
        }
    }
}

void verificaUsuario(std::string &usuario)
{
    bool valido = false;
    while (!valido)
    {
        try
        {
            if (usuario.empty())
                throw std::invalid_argument("O nome de usuario esta vazio.");

            for (char c : usuario)
            {
                if (!isalnum(c) && c != '.' && c != '_')
                    throw std::invalid_argument("O nome de usuario so pode conter letras, numeros, ponto e underline.");
            }

            valido = true;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Erro: " << e.what() << " Por favor, digite novamente: " << std::endl;
            std::getline(std::cin, usuario);
        }
    }
}