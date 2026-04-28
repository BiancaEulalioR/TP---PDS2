#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Perfil.h"

// Depois vou ajeitar para ser uma classe filha de post quando fizermos a implementacao dos contratos
class Servico
{
private:
    // A lista dos comentarios:
    std::vector<std::string> comentario;

    // Perfil da pessoa responsavel pelo post de servico:
    Perfil perfil;

    // Texto do post do perfil:
    std::string descricaoDoServico;

public:
    // 1. Construtores:
    Servico();
    Servico(Perfil PrestadorServico);

    // 2. "Getters":
    int getNumeroDeComentarios();

    std::vector<std::string> getListaDeComentarios();

    std::string getDescricaoDoServico();

    // 3. Metodos:
    // 3.1. Editar o post do servico:
    void editarDescricao();
};
