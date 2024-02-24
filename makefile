GCCPARAMS=-fcompare-debug-second

compile: 
	g++ compiler/ecterc.cpp -o ecterc.exe $(GCCPARAMS)

compile-all-o:
	g++ compiler/ecterc.cpp -o compiler/bin/ecterc.o $(GCCPARAMS)
	g++ compiler/eas.cpp -o compiler/bin/eas.o $(GCCPARAMS)
	g++ compiler/egc.cpp -o compiler/bin/egc.o $(GCCPARAMS)
	g++ compiler/eerror.cpp -o compiler/bin/eeerror.o $(GCCPARAMS)
	g++ compiler/emem.cpp -o compiler/bin/emem.o $(GCCPARAMS)
	g++ compiler/etoken.cpp -o compiler/bin/etoken.o $(GCCPARAMS)
	g++ compiler/eparse.cpp -o compiler/bin/eparse.o $(GCCPARAMS)
	g++ compiler/eutil.cpp -o compiler/bin/eutil.o $(GCCPARAMS)
	g++ compiler/estate.cpp -o compiler/bin/estate.o $(GCCPARAMS)
	
link:

test-token:
	g++ compiler/etoken.cpp -o etoken.exe $(GCCPARAMS)