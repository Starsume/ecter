compile: 
	g++ compiler\ecterc.c -o compiler\..\ecterc.exe

compile-all:
	g++ compiler/ecterc.c -o compiler/bin/ecterc.o
	g++ compiler/eas.c -o compiler/bin/eas.o
	g++ compiler/egc.c -o compiler/bin/egc.o
	g++ compiler/eerror.c -o compiler/bin/eeerror.o
	g++ compiler/emem.c -o compiler/bin/emem.o
	g++ compiler/etoken.c -o compiler/bin/etoken.o
	g++ compiler/eparse.c -o compiler/bin/eparse.o
	g++ compiler/eutil.c -o compiler/bin/eutil.o
	g++ compiler/estate.c -o compiler/bin/estate.o
	