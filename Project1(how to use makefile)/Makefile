
Main:Main.o add.o sub.o
	g++ Main.o add/add.o sub/sub.o -o Main
Main.o:Main.cpp
	g++ Main.cpp -c -Wall -g -o Main.o
add.o:
	cd add;make
sub.o:
	cd sub;make
clean:
	rm *.o Main  -rf
clean_o:
	rm *.o 