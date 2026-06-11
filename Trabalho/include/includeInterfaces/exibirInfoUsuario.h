#ifndef EXIBIRINFOUSUARIO_H
#define EXIBIRINFOUSUARIO_H


#include "Perfil.h"

/**
 * @brief Exibe e gerencia as informações do perfil do usuário.
 *
 * Apresenta um menu com opções para visualizar os dados do perfil,
 * editar a biografia e alterar o nome de usuário. As modificações
 * realizadas são registradas por meio do gerenciador de perfis.
 *
 * @param perfil perfil do usuário que está acessando suas informações.
 * @param gerenciador_ gerenciador responsável pelas operações de edição
 * e atualização dos perfis cadastrados.
 */

void exibirInfoUsuario(Perfil& perfil, GerenciadorPerfis& gerenciador_);

#endif 