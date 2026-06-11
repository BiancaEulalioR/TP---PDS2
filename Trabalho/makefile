all:
	mkdir -p build/classes build/classesExtras build/interfaces

	g++ -Iinclude -c scr/Evento.cpp -o build/classes/Evento.o
	g++ -Iinclude -c scr/Oportunidades.cpp -o build/classes/Oportunidades.o
	g++ -Iinclude -c scr/Perfil.cpp -o build/classes/Perfil.o
	g++ -Iinclude -c scr/GerenciadorPerfis.cpp -o build/classes/GerenciadorPerfis.o
	g++ -Iinclude -c scr/Post.cpp -o build/classes/Post.o
	g++ -Iinclude -c scr/Servico.cpp -o build/classes/Servico.o
	g++ -Iinclude -c scr/Spotted.cpp -o build/classes/Spotted.o

	g++ -Iinclude -c scr/Tratamentoerros.cpp -o build/classesExtras/Tratamentoerros.o

	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/configuracoes.cpp -o build/interfaces/configuracoes.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirAbaBuscar.cpp -o build/interfaces/exibirAbaBuscar.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirInfoUsuario.cpp -o build/interfaces/exibirInfoUsuario.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirMenuAbas.cpp -o build/interfaces/exibirMenuAbas.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirMenuInicial.cpp -o build/interfaces/exibirMenuInicial.o

	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirEventos.cpp -o build/interfaces/exibirEventos.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirOportunidades.cpp -o build/interfaces/exibirOportunidades.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirServicos.cpp -o build/interfaces/exibirServicos.o
	g++ -Iinclude -Iinclude/includeInterfaces -c scr/scrInterfaces/exibirSpotted.cpp -o build/interfaces/exibirSpotted.o

	g++ -Iinclude -Iinclude/includeInterfaces -c scr/main.cpp -o build/main.o

	g++ build/classes/Evento.o build/classes/Oportunidades.o build/classes/Perfil.o build/classes/GerenciadorPerfis.o \
		build/classes/Post.o build/classes/Servico.o build/classes/Spotted.o \
		build/classesExtras/Tratamentoerros.o \
		build/interfaces/configuracoes.o build/interfaces/exibirAbaBuscar.o build/interfaces/exibirInfoUsuario.o \
		build/interfaces/exibirMenuAbas.o build/interfaces/exibirMenuInicial.o \
		build/interfaces/exibirEventos.o build/interfaces/exibirOportunidades.o build/interfaces/exibirServicos.o \
		build/interfaces/exibirSpotted.o \
		build/main.o \
		-o build/Trabalho

clean:
	rm -rf build/