all: clean TextHandler.o templates.o link

TextHandler.o:
	g++ TextHandler.cpp -c

templates.o:
	g++ templates.cpp -c

link:
	g++ *.o main.cpp

clean:
	rm -rf *.o a.out