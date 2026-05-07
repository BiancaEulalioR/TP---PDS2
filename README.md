# TP---PDS2

## Integrantes COMMIT TESTE

-Ayla Barcelos 
-Nicole Portes
-Samara Aquino
-Gustavo Henrique
-Bianca Ramos 


-------------------------------------------

*ESCOPO INICIAL DO TRABALHO*

 O intuito deste projeto é o desenvolvimento de uma rede social voltada aos alunos da UFMG, com o objetivo de facilitar a
vida universitária e a comunicação entre os estudantes. A solução consiste em uma plataforma, com funcionalidades como feed de publicações interativo (com curtidas e comentários), área de eventos, divulgação de oportunidades (estágios, projetos, etc.) e oferta de serviços entre alunos. Além disso, para o acesso à plataforma, o sistema contará com perfis de usuário, sendo possível a criação de novos perfis, login em perfis já existentes e edição de dados do perfil pessoal (como nome de usuário e senha).

## User Stories (História de usuario) – CampusConnect

---

### História 1
**Como** aluno da Universidade Federal de Minas Gerais,  **quero** criar um usuário no aplicativo CampusConect **para** estabelecer uma comunicação mais direta entre a comunidade discente.

**Critérios de aceitação:**
- Criar um username único por usuário
- Criar e alterar informações de cadastro (username e senha)
- Criar uma biografia no meu perfil

---
### História 2
**Como** usuário do aplicativo CampusConect, **quero** poder estabelecer uma comunicação anônima com a comunidade discente **para** me expressar sem me identificar.

**Critérios de aceitação:**
- Não mostrar o perfil do usuário
- Permitir apenas mensagens de texto
- Exibir em uma aba única no feed

---
### História 3
**Como** usuário do aplicativo CampusConect, **quero** publicar e visualizar os eventos da instituição **para** me manter informado sobre as principais atividades da comunidade.

**Critérios de aceitação:**
- Visualizar eventos
- Publicar eventos
- Definir informações gerais (data, horário e local)

---
### História 4
**Como** usuário do aplicativo CampusConect e empreendedor, **quero** poder publicar ofertas de serviço **para** atingir o público da instituição.

**Critérios de aceitação:**
- Publicar serviços
- Visualizar os demais anúncios da comunidade já ofertados
- Inserir informações de contato nas publicações feitas

--- 

### História 5
**Como** usuário do aplicativo CampusConect, **quero** ter acesso a oportunidades acadêmicas e profissionais **para** incrementar meu currículo durante a graduação.

**Critérios de aceitação:**
- Publicação de oportunidades pelos usuários
- Visualizar oportunidades publicadas
- Inserir informações de contato nas publicações feitas

---
## Cartões CRC – CampusConnect

| Classe               | Responsabilidades                                                                    | Colaborações |
|----------------------|--------------------------------------------------------------------------------------|--------------|
| **Perfil** | Nome, usuário, senha, biografia, editar perfil, telefone, e‑mail, apagar perfil    | –            |
| **Post**     | Curtir, descurtir, comentar, apagar comentário                                      | –            |
| **Spotted**  | Criar post, apagar post, listar post                                                | Post        |
| **Eventos**  | Criar eventos, editar eventos, informações de contato, apagar eventos               | Perfil, Post |
| **Oportunidades** | Criar oportunidades, editar oportunidades, informações de contato, apagar oportunidade              | Perfil, Post       |
| **Serviços** | Criar serviços, editar serviços                                                    | Perfil, Post       |




