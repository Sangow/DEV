all: clean TextHandler.o templates.o run.exe

TextHandler.o:
	g++ TextHandler.cpp -c

templates.o:
	g++ templates.cpp -c

run.exe:
	g++ *.o main.cpp

start:
	run.exe

clean:
	rm -rf *.o run.exe a.out