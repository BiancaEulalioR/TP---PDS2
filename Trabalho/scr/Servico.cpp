#include "Servico.h"

Servico::Servico(Perfil PrestadorServico)
{
    prestadorDoServico_ = PrestadorServico;
}

std::string Servico::getDescricaoDoServico()
{
    return descricaoDoServico_;
}

Perfil Servico::getPerfilDoPrestador()
{
    return prestadorDoServico_;
}

// Aqui, os parametros de "editarDescricao" sao obtidos com cin e cout na main;
// Ela substitui a parte do texto "selecionada" pelo usuario por outra substring que ele digita (cin na main)
// Unica ressalva: essa funcao vai substituir a primeira ocorrencia do trecho dado na string "descricaoDoServico",
// ou seja, se a pessoa quiser editar um trecho (repetido, por exemplo) em sua segunda ou enesima ocorrencia
// isso nao sera possivel. A edicao nao ocorrera da forma esperada... A nao ser que lhe fosse pedido para
// selecionar um trecho maior do texto.
void Servico::editarDescricao(std::string ParteDoTexto, int numeroCaracteres, std::string novoTexto)
{
    numeroCaracteres = ParteDoTexto.size();
    size_t indiceEdicao = descricaoDoServico_.find(ParteDoTexto);
    if (indiceEdicao != std::string::npos)
        descricaoDoServico_.replace(indiceEdicao, numeroCaracteres, novoTexto);
}
