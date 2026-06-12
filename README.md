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
- **include/**: Contém os arquivos de cabeçalho (.h e .hpp), onde estão as declarações das classes e fuções utilizadas no programa;
- **src/**: Contém as implementações dessas classes e funções (arquivos .cpp);
- **Nova pasta/html**: Contém os arquivos gerados pelo Doxygen.

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
- Classe GerenciadorPerfis para facilitar a manipulação das ações relacionadas aos perfis, como edições e armazenamento de dados;

---
## Instruções de uso com exemplos (entradas/saídas)

O sistema é executado via terminal e opera por meio de menus interativos numerados. O usuário navega inserindo o número correspondente à opção desejada e pressionando Enter.

---
### Menu inicial
Ao iniciar o sistema, o usuário é recebido com:

```
=== CAMPUSCONNECT ===

=== QUAL ACAO DESEJA REALIZAR? ===

1. CONNECTE-SE
2. CADASTRE-SE
```

#### Login (`1`)

```
Nome de usuario:
> joaosilva
Senha:
> *******

Bem vindo ao CampusConnect!
```

**Credenciais inválidas:**
```
Usuario ou senha incorretos.
1. Tentar novamente
2. Voltar ao menu
```

#### Cadastro (`2`)

```
=== CRIAR CONTA ===

E-mail:
> joao@email.com
Nome completo:
> João Silva
Nome de usuario:
> joaosilva
Senha:
> *******
Telefone:
> 31999990000

Connectado com sucesso!
Seja bem vindo ao CampusConnect!
```
### Menu Principal
Após o login, o sistema exibe o menu de navegação:

```
=== QUAL ABA DESEJA ACESSAR? ===

1. Spotted
2. Eventos
3. Oportunidades
4. Servicos
5. Buscar
6. Perfil
7. Configuracoes
```

**Entrada:** `1` → Acessa a aba Spotted  
### 1. Spotted

```
=== SPOTTED ===
1. Ver spotteds publicados
2. Publicar spotted
3. Apagar spotted
4. Visualizar comentarios
5. Publicar comentario em spotted
6. Apagar comentario de spotted
7. Visualizar curtidas
8. Curtir spotted
9. Remover curtida de spotted
10. Voltar ao menu principal
```

**Ver spotteds (`1`):**
```
SPOTTED (0)
Alguém sabe o que aconteceu na bibllioteca hoje?
3 curtidas
2 comentarios
```

**Publicar spotted (`2`):**
```
Digite o spotted a ser publicado:
> O bandejão hoje estava pessimo

Spotted publicado!
```

**Apagar spotted (`3`):**
```
Digite o ID do spotted:
> 0

Spotted removido com sucesso.
// Sem permissão: Voce nao possui permissao para apagar esse spotted.
```

**Publicar comentário (`5`):**
```
Digite o ID do spotted:
> 0
Digite o comentario:
> Parece que dois amigos brigaram...

Comentario publicado.
```

**Curtir spotted (`8`):**
```
Digite o ID do spotted:
> 0

Curtida registrada.
Numero de curtidas atual: 4
// Já curtido: Voce ja curtiu essa publicacao.
```

---

### 2. Eventos

```
=== EVENTOS ===
1. Ver eventos publicados
2. Publicar evento
3. Editar evento
4. Apagar evento
5. Visualizar comentarios
6. Publicar comentario em evento
7. Apagar comentario de evento
8. Visualizar curtidas
9. Curtir evento
10. Remover curtida de evento
11. Voltar ao menu principal
```

**Ver eventos (`1`):**
```
EVENTO (0)
@joao
Contato: (31) 99999-0000
Festa Junina do bloco de Engenharia - 20/06, 19h
5 curtidas
3 comentarios
```

**Publicar evento (`2`):**
```
Digite o contato responsavel pela organizacao do evento:
> (31) 99999-0000
Digite o texto do evento a ser publicado:
> Palestra sobre IA - 15/07, Sala 302

Evento publicado!
```

**Editar evento (`3`):**
```
Digite o ID do evento:
> 0
1. Editar contato de evento
2. Editar descricao do evento
3. Voltar ao menu de eventos
> 2
Digite o novo evento:
> Palestra sobre IA - 16/07, Sala 302

Evento atualizado com sucesso.
// Sem permissão: Voce nao possui permissao para editar esse evento.
```

> Comentários e curtidas seguem o mesmo padrão da aba Spotted.

---

### 3. Oportunidades

```
=== OPORTUNIDADES ===
1. Ver oportunidades publicadas
2. Publicar oportunidade
3. Editar oportunidade
4. Apagar oportunidade
5. Vizualizar comentarios
6. Publicar comentario em oportunidade
7. Apagar comentario de oportunidade
8. Vizualizar curtidas
9. Curtir Oportunidade
10. Remover curtida de oportunidade
11. Vizualizar informacoes de contato
12. Voltar ao menu principal
```

**Publicar oportunidade (`2`):**
```
Digite o contato responsavel pela oportunidade:
> (31) 98888-2222
Digite a descricao da oportunidade:
> Processo seletivo para monitor de Cálculo 2 - 18/06

Oportunidade publicada!
```

**Visualizar informações de contato (`11`):**
```
Digite o id da oportunidade:
> 0

Usuario que publicou: @joao
Contato: (31) 98888-2222
```

> Editar, apagar, comentários e curtidas seguem o mesmo padrão da aba Eventos.

---

### 4. Serviços

```
=== SERVICOS ===
1. Ver servicos publicados
2. Publicar um servico
3. Editar servico
4. Remover servico
5. Vizualizar comentarios
6. Publicar comentario em um servico
7. Remover comentario de um servico
8. Vizualizar curtidas
9. Curtir servico
10. Remover curtida de um servico
11. Ver informacoes de contato de um servico
12. Voltar ao menu principal
```

**Publicar serviço (`2`):**
```
Digite o texto do servico a ser publicado:
> Aulas de violão para iniciantes
Agora digite o numero de contato com ddd, tudo junto:
> 31988887777

Servico publicado!
```

**Ver informações de contato (`11`):**
```
Digite o ID do servico:
> 0

Usuario que publicou: @maria
Telefone para contado: 31988887777
```

> Editar, apagar, comentários e curtidas seguem o mesmo padrão da aba Eventos.

---

### 5. Buscar

```
=== BUSCAR ===
1. Buscar por usuario
2. Voltar para menu principal
```

**Buscar usuário (`1`):**
```
Digite o nome de usuario que deseja buscar:
> maria

=== PERFIL DE USUARIO ===

Maria Souza
@maria
Estudante de Letras apaixonada por literatura
1. Acessar publicacoes de @maria
```

Ao acessar as publicações, um submenu é exibido:

```
1. Eventos
2. Oportunidades
3. Servicos
4. Voltar ao perfil
```

```
=== EVENTOS DE @maria ===

EVENTO (2)
Show de Talentos - 25/07, Auditório Central
Contato: (31) 98888-1111
10 curtidas
4 comentarios

// Sem publicações: Esse usuario nao possui eventos publicados
// Usuário inexistente: Usuario nao encontrado.
```

---

### 6. Perfil

```
=== PERFIL ===
1. Exibir Informacoes do perfil
2. Editar biografia
3. Editar nome de usuario
4. Retornar ao menu principal
```

**Exibir perfil (`1`):**
```
=== INFORMACOES DO PERFIL ===

João Silva
@joaosilva
Estudante de Ciência da Computação - 3º período
```

**Editar biografia (`2`):**
```
Biografia atual:
Estudante de Ciência da Computação - 3º período
Informe a nova bio:
> Apaixonado por IA e sistemas embarcados

Bio alterada com sucesso
```

---

### 7. Configurações

```
=== CONFIGURACOES ===
1. Exibir informacoes de perfil
2. Editar informacoes de perfil
3. Apagar conta
4. Desconnectar
5. Retornar ao menu principal
```

**Exibir informações (`1`):**
```
=== INFORMACOES DE USUARIO ===

Email: joao@email.com
Nome: João Silva
Telefone: 31999990000
```

**Editar informações (`2`)** abre um submenu:
```
1. E-mail
2. Telefone
3. Usuario
4. Senha
5. Voltar ao menu de configuracoes
```

Exemplo — alterar senha (`4`):
```
Digite sua senha atual:
> *******
Informe a nova senha:
> novasenha123
Informe novamente a nova senha:
> novasenha123

Senha atualizada com sucesso!
// Senhas diferentes: As senhas devem estar iguais, tente novamente.
// 3 erros seguidos: Numero maximo de tentativas atingida. Operacao cancelada.
```

**Apagar conta (`3`):**
```
Tem certeza que deseja se desconnectar para sempre? E um caminho sem volta...
1. Confirmar
2. Cancelar
> 1

=== CONTA DESCONNECTADA PARA SEMPRE ===
```

**Desconectar (`4`):** encerra a sessão e retorna à tela inicial.

---
## Tratamento de exceções/programação defensiva
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




