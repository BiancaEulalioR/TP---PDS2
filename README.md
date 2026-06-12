# TP---PDS2

## Integrantes 

- Ayla Barcelos (aylabarcelos);
- Nicole Portes (portesvalina);
- Samara Aquino (Samaraquinof);
- Gustavo Henrique (GustavoHenriquedns);
- Bianca Ramos (BiancaEulalioR);


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
## Como Compilar e Executar
Estando na pasta "Trabalho", os comandos que devem ser digitados no terminal, usando o WSL, são:
- make clean
- git pull
- make
- .build/Trabalho

---
## Link do video

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
├── include/
│  └── includeInterfaces/
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
│  └── Oportunidades.h
│  └── Perfil.h
│  └── Post.h
│  └── Servico.h
│  └── Spotted.h
│  └── Tratamentoerros.hpp
└── src/
│  └── scrInterfaces/
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
└── Nova pasta/html/
│  └── [arquivos gerados pelo Doxygen]
└── makefile
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
- Validação de ID --> Presente em todos os cases nos quais é preciso achar um post usando a função "acharPost()", garantindo que o ID existe antes de operar;
- Verificação de e-mail "verificaEmail()" -->  Usada no cadastro e edição de perfil. Exige @, . e campo não vazio;
- Verificação de usuario "verificaUsuario()" --> Usada no cadastro e na parte de edição do perfil. Rejeita entradas vazias e caracteres que não sejam letras, números, . ou _;
- Verificação de telefone "verificaTelefone()" --> Usada na parte de cadastro e de edição do perfil. Ela só permite que o número de telefone tenha 11 caracteres e apenas números, ou seja, não são permitidos caracteres especiais. Tambám não permite que o telefone esteja vazio;
- verificação de senha "verificaSenha()" --> Usada no cadastro e na parte de editar o perfil. Verifica se a senha tem no mínimo 6 caracteres e se não está vazio;
- Tratamento de entradas do cin "lerValor()" --> Verifica se o valor digitado está compatível com a variável esperada.

---
## Divisão de Tarefas Entre os Integrantes
- *AYLA*: Inicialmente a integrante ficou responsável pela implementação da classe de oportunidades, seguido da criação do menu de oportunidades, e por fim os tratamentos de execeções de validação de entradas, ID, verificação de usuario, telefone, senha, e email;
- *BIANCA*: Inicialmente ficou com a parte da implementação da classe Servico, seguida da criação do menu de servicos e das funções auxiliares acharPost(), imprimirElementos() e exibirUsuariosQueCurtiram();
- *GUSTAVO*: Inicialmente responsável por criar a classe de perfil e gerenciamento de perfil, seguido da criação do menu inicial e exibir menu abas, aba de configurações e edição de perfil e por fim compilar o código;
- *NICOLE*: Inicialmente a participante ficou responsável por implementar a classe Eventos, seguido da implementação do menu de Eventos. Com isso, realizou a implementação da correlação entre os usuários as publicações e comentários feitos nas diversas classes, além de implementar a main. Por fim, também criou a função de buscar e redigiu o makefile, além de contribuir ativamente na coordenação dos testes de implementação do projeto. 
- *SAMARA*: Inicialmente a integrante ficou responsável pela implementação da classe Spotted, e seu respectivo menu. Além disso implementou a classe Post, sendo ela a classe mãe das outras classes, responsável pelos metódos e atributos herdados pelas mesmas. Por fim realizou a implementação e criação da função de tratamentos de execeções responsável pela validação de entradas vazias na publicação de comentários em todos os menus.
---
## Linha do Tempo das Sprints
- *Sprint 1*: De 16/04 a 23/04 --> Criamos esse repositório no GitHub, Escolhemos a ideia definitiva do projeto e aperfeiçoamos seu escopo e fizemos os commits de teste no GitHub;
- *Sprint 2*: De 24/04 a 07/05 --> Criamos as pastas/diretórios para armazenar os tipos de arquivos específicos (.cpp, .h, .o etc), nos reunimos para fazer os "User Stories"  e os cartões CRC das classes que planejamos implementar. Além disso, criamos os arquivos de cabeçalho (.h) para as classes que planejavamos ter;
- *Sprint 3*: De 12/05 a 25/05 --> Implementamos os arquivos .cpp das classes que cada um ficou responsável;
- *Sprint 4*: De 27/05 a 02/06 --> Fizemos os switch cases das abas do campus connect inicialmente todos no arquivo main.cpp, que, nesse momento ficou com aproximadamente 1000 linhas. Além disso, completamos algumas das classes que faltavam ter herança da classe post;
- *Sprint 5*: De 03/06 a 11/06 --> Separamos o código da main que se tratava dos switch cases das abas específicas em arquivos diferents, para que o trabalho ficasse mais viável e organizado, criamos a classe GerenciadorPerfis para tomar de conta das ações relacionadas ao manuseio dos perfis da plataforma e testamos todo o código em arquivos locais, fazendo alterações pontuais em partes que apresentavam erros. Além disso, fizemos os comentários seguindo a padronização do doxygen, fizemos o makefile e a gravação do projeto funcionando.

--- 
## Ciclo de Desenvolvimento e Aprendizados
1. *Planejamento*: Primeiramente, planejávamos fazer algo bem parecido com o que agora temos, ou seja, toda a estrutura dividada em abas e com tipos diferentes de post (eventos, oportunidades, serviços e spotted). Também pensamos em fazer arquivos .txt para salvar os perfis e posts criados nas vezes passadas em que o programa tivesse sido aberto, servindo como um pequeno banco de dados. Achavamos também que toda a implementação das abas do CampusConnect deveria ser feita no arquivo main.cpp, e assim o fizemos, inicialmente.
2. *O que Realmente foi implementado*: Conseguimos entregar tudas as funcionalidades prometidas. O programa está completo conforme prometido e com algumas abas a mais, como a de busca e a configurações. O arquivo main.cpp ficou bem reduzido, de forma que agora apenas chama funções necessárias para o seu funcionamento. Além do mais, os arquivos .txt não foram implementados.
3. *Obstáculos*: Não tivemos tempo de terminar as funcionalidades de leitura e escrita nos arquivos .txt, então tivemos que apagar essa parte do código (com funções feitas pela metade). Outro desafio que precisou ser contornado ocorreu na sprint 4, quando tivemos que gastar um tempo a mais separando as partes do main.cpp que já haviam sido implementadas em arquivos diferentes para, apenas a partir daí, continuar a implementação
4. *Aprendizado*: Aprendemos que, no desenvolvimento de um projeto, nem sempre é possível executar tudo o que inicialmente foi pensado e que é necessário estabelecer prioridades claras em relação ao que realmente gastaremos nosso tempo e esforço para realizar. Também aprendemos que devemos modularizar mais o código desde o início, para não ficar como o main.cpp na sprint 4 com quase 1000 linhas e extremamente desorganizado.

---
## Documentação do Doxygen
O projeto foi inteiramente documentado através de comentários no padrão do Doxygen nos arquivos .h utilizados.

## Como Gerar a Documentação
1. abrir o doxygen GUI;
2. Selecionar, como ambiente de execuçaõ, o diretório raiz do trabalho;
3. Selecionar a aba "project" em "wizard" e escolher a pasta scr, certificando-se de deixar marcada a opção "Scan Recursively";
4. Ainda em "Wizard", mas agora na aba "mode", selecionar a opção "Optimize for C++ output";
5. Na aba "Output" em "Wizard", certificar-se de que "HTML" está marcado;
6. dar um click em "Run doxygen" na aba "run".

## Como acessar
- Apertar no botão "Show HTML output" ainda na aba "run";
- OU, simplesmente abrir o arquivo "index.html" gerado dentro da pasta escolhida para a geração dessa documentação;

---




