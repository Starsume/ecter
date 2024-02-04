GCCPARAMS=

compile: 
	g++ compiler\ecterc.c -o compiler\..\ecterc.exe

compile-all-o:
	g++ compiler/ecterc.cpp -o compiler/bin/ecterc.o
	g++ compiler/eas.cpp -o compiler/bin/eas.o
	g++ compiler/egc.cpp -o compiler/bin/egc.o
	g++ compiler/eerror.cpp -o compiler/bin/eeerror.o
	g++ compiler/emem.cpp -o compiler/bin/emem.o
	g++ compiler/etoken.cpp -o compiler/bin/etoken.o
	g++ compiler/eparse.cpp -o compiler/bin/eparse.o
	g++ compiler/eutil.cpp -o compiler/bin/eutil.o
	g++ compiler/estate.cpp -o compiler/bin/estate.o
	