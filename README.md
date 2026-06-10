# TP---PDS2

## Integrantes 

- Ayla Barcelos 
- Nicole Portes
- Samara Aquino
- Gustavo Henrique
- Bianca Ramos 


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
| **Spotted**  | Criar post, apagar post                                              | Post        |
| **Eventos**  | Criar eventos, editar eventos, informações de contato, apagar eventos               | Perfil, Post |
| **Oportunidades** | Criar oportunidades, editar oportunidades, informações de contato, apagar oportunidade              | Perfil, Post       |
| **Serviços** | Criar serviços, editar serviços                                                    | Perfil, Post       |

---
## Organização - CampusConnect

### Organização das pastas
- **Compliados/**: Contem o arquivo makefile;
- **build/**: Contém os arquivos .o gerados durante a compilação;
- **include/**: Contém os arquivos de cabeçalho (.h e .hpp), onde estão as declarações das classes e fuções utilizadas no programa;
- **src/**: Contém as implementações dessas classes e funções (arquivos .cpp).

---
### Arquitetura
```
. programa
├── Compilados/
│  └── makefile/
│    └── makefile
├── build/
│  └── [arquivos.o]
├── include/
│  └── interfaces(.h)/
|    └── configuracoes.h
|    └── exibirAbaBuscar.h
|    └── exibirEventos.h
|    └── exibirInfoUsuario.h
|    └── exibirMenuAbas.h
|    └── exibirMenuInicial.h
|    └── exibirOportunidades.h
|    └── exibirServicos.h
|    └── exibirSpotted.h
│  └── Evento.h
│  └── funcoesAuxiliares.hpp
│  └── GerenciadorPerfis.h
│  └── funcoesAuxiliares.hpp
│  └── Oportunidades.h
│  └── Perfil.h
│  └── Post.h
│  └── Servico.h
│  └── Spotted.h
│  └── Tratamentoerros.hpp
└── src/
│  └── Interfaces(.cpp)/
|    └── configuracoes.cpp
|    └── exibirAbaBuscar.cpp
|    └── exibirEventos.cpp
|    └── exibirInfoUsuario.cpp
|    └── exibirMenuAbas.cpp
|    └── exibirMenuInicial.cpp
|    └── exibirOportunidades.cpp
|    └── exibirServicos.cpp
|    └── exibirSpotted.cpp
│  └── Evento.cpp
│  └── funcoesAuxiliares.cpp
│  └── GerenciadorPerfis.cpp
│  └── main.cpp
│  └── Oportunidades.cpp
│  └── Perfil.cpp
│  └── Post.cpp
│  └── Servico.cpp
│  └── Spotted.cpp
│  └── Tratamentoerros.cpp
└── .gitignore
└── README.md
```
---
## Funcionalidades Prometidas e Entregues
- Possibilidade de criar um novo perfil ou fazer login em um perfil já existente;
- Feed de publicações interativo para todos os tipos de post, sejam eles de spotted, oportunidade, serviço ou evento;
- Possibilidade de curtir e comentar os posts;
- Abas para acessar os eventos, as oportunidades, os serviços, os spotteds;
- Aba para acessar e editar as informações do perfil logado;

### Itens Fora do Escopo que Foram Entregues
- Aba de busca;
- Possibilidade de sair do perfil e entrar em outro ou no mesmo, na aba de configurações;
- Associação de curtidas ao usuário que curtiu. Anteriormente planejávamos apenas implementar um contador de curtidas em cada post;
- Listar os usuários que curtiram determinado post;
- Associação dos comentários à quem comentou;
- Classe GrenciadorPerfis para fcilitar a manipulação das ações relacionadas aos perfis, como edições e armazenamento de dados;

---
### Tratamento de exceções/programação defensiva
- Tratamento de entradas vazias "verificaTexto()" --> Publicação de comentários em todas as funções de exibir;
- Validação de ID --> Presente em todos os cases nos quais é preciso achar um post usando a função "acharPost()";
- Verificação de e-mail "verificaEmail()" --> É usada no momento de fazer o cadastro e de editar o perfil. Ela verifica se o e-mail inserido pelo usuário possui "@" e ".";
- Verificação de usuario "verificaUsuario()" --> Usada no cadastro e na parte de editar o perfil. Vê se o nome de usuário fornecido não está vazio e se não contem espaços;
- Verificação de telefone "verificaTelefone()" --> Está na parte de cadastro e de editar o perfil. Ela só permite que o numero de telefone tenha 11 caracteres e apenas numeros, ou seja, não são permitidos caracteres especiais. Tambám não permite que o telefone esteja vazio;
- verificação de senha "verificaSenha()" --> Usada no cadastro e na parte de editar o perfil. Verifica se a senha tem no mínimo 6 caracteres e se não está vazio;
- Tratamento de entradas do cin "lerValor()" --> Verifica se o tipo digitado está coerente com a variável utilizada.

---
## Divisão de Tarefas Entre os Integrantes
- *Ayla*: Inicialmente a integrante ficou responsável pela implementação da classe de oportunidades, seguido da criação do menu de oportunidades, e por fim os tratamentos de execeções de validação de entradas, ID, verificação de usuario, telefone, senha, e email;
- *Bianca*: Inicialmente ficou com a parte da implementação da classe Servico, seguida da criação do menu de servicos e das funções auxiliares acharPost(), imprimirElementos() e exibirUsuariosQueCurtiram();
- *Gustavo*: Inicialmente responsável por criar a classe de perfil e gerenciamento de perfil, seguido da criação do menu inicial e exibir menu abas, aba de configurações e edição de perfil e por fim compilar o código;
- *Nicole*: Inicialmente a participante ficou responsável por implementar a classe Eventos, seguido da implementação do menu de Eventos. Com isso, realizou a implementação da correlação entre os usuários as publicações e comentários feitos nas diversas classes, além de implementar a main. Por fim, também criou a função de buscar e redigiu o makefile, além de contribuir ativamente na coordenação dos testes de implementação do projeto. 
- *Samara*: Inicialmente a integrante ficou responsável pela implementação das classes de Spotted e Post, seguido da criação do menu de Spotted, e por fim os tratamentos de exececões de validação de entradas de texto vazia.

---
## Ciclo de Desenvolvimento e Aprendizados
1. *Planejamento*: Primeiramente, planejávamos fazer
2. *O que Realmente foi implementado*: 
3. *Obstáculos*:
4. *Aprendizado*:

---
## Linha do Tempo das Sprints
- *Sprint 1*: De 16/04 a 23/04 --> Criamos esse repositório no GitHub, Escolhemos a ideia definitiva do projeto e aperfeiçoamos seu escopo e fizemos os commits de teste no GitHub;
- *Sprint 2*: De 24/04 a 07/05 --> Criamos as pastas/diretórios para armazenar os tipos de arquivos específicos (.cpp, .h, .o etc), nos reunimos para fazer os "User Stories"  e os cartões CRC das classes que planejamos implementar  




