compile: 
	gcc compiler/ecterc.cpp -o compiler/../ecterc.exe

compile-all-o:
	gcc compiler/ecterc.cpp -o compiler/bin/ecterc.o
	gcc compiler/eas.cpp -o compiler/bin/eas.o
	gcc compiler/egc.cpp -o compiler/bin/egc.o
	gcc compiler/eerror.cpp -o compiler/bin/eeerror.o
	gcc compiler/emem.cpp -o compiler/bin/emem.o
	gcc compiler/etoken.cpp -o compiler/bin/etoken.o
	gcc compiler/eparse.cpp -o compiler/bin/eparse.o
	gcc compiler/eutil.cpp -o compiler/bin/eutil.o
	gcc compiler/estate.cpp -o compiler/bin/estate.o
	