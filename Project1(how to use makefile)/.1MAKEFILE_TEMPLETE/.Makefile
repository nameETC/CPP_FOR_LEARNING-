
Main:Main.o add.o sub.o
	g++ Main.o add.o sub.o -o Main
Main.o:Main.cpp
	g++ Main.cpp -c -Wall -g -o Main.o
add.o:add.cpp
	g++ add.cpp -c -Wall -g -o add.o
sub.o:sub.cpp
	g++ sub.cpp -c -Wall -g -o sub.o

clean:
	rm *.o Main  -rf
clean_o:
	rm *.o 