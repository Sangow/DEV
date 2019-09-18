all: Passport.o Date.o link

Passport.o:
	g++ Passport.cpp -c

Date.o:
	g++ Date.cpp -c

link:
	g++ *.o main.cpp

clean:
	rm -rf *.o a.out