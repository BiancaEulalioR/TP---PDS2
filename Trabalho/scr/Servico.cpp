#include "Servico.h"

// Construtores:
Servico::Servico() {}

Servico::Servico(std::string descricao, int num, int idServi, int idPerf, Perfil perf)
{
    descricaoDoServico_ = descricao;
    numeroContato_ = num;
    idDeArmazenamento_ = idServi;
    idDoPerfilAssociado_ = idPerf;
    perfilAssociadoS_ = perf;
}

// Destrutor:
Servico::~Servico()
{
    descricaoDoServico_.clear();
}

// Getters:
std::string Servico::getDescricaoDoServico() const
{
    return descricaoDoServico_;
}

int Servico::getNumeroContato() const
{
    return numeroContato_;
}

int Servico::getIdServico() const
{
    return idDeArmazenamento_;
}

int Servico::getIdPerfilAssociado() const
{
    return idDoPerfilAssociado_;
}

const Perfil &Servico::getPerfilAssociado() const
{
    return perfilAssociadoS_;
}

// Setters:
void Servico::setDescricaoDoServico(std::string descricaoL)
{
    descricaoDoServico_ = descricaoL;
}

void Servico::setNumeroContato(int numL)
{
    numeroContato_ = numL;
}

void Servico::setIdServico(int novoId)
{
    idDeArmazenamento_ = novoId;
}

void Servico::setIdPerfilAssociado(int novoIdPerfil)
{
    idDoPerfilAssociado_ = novoIdPerfil;
}

void Servico::setPerfilAssociado(Perfil novoPerfilAssociado)
{
    perfilAssociadoS_ = novoPerfilAssociado;
}
