all: runall

runall: Passport.o Date.o a.exe run

compile: Passport.o Date.o a.exe

Passport.o:
	g++ -c Passport.cpp

Date.o:
	g++ -c Date.cpp

a.exe:
	g++ *.o main.cpp -o a.exe

run:
	a.exe

clean:
	rm -rf *.o a.exe