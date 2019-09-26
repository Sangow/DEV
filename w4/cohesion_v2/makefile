all: clean obj link

obj: excepions.o basic.o category.o item.o order.o customer.o

excepions.o:
	g++ Exceptions.cpp -c

basic.o:
	g++ Basic.cpp -c

category.o:
	g++ Category.cpp -c

item.o:
	g++ Item.cpp -c

order.o:
	g++ Order.cpp -c

customer.o:
	g++ Customer.cpp -c

link:
	g++ *.o main.cpp

clean:
	rm -rf *.o a.out a.exe