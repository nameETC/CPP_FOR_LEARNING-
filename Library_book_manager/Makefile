
Main:Main.o Manager.o Reader.o Book.o
	g++ Main.o Parts/Manager.o Parts/Reader.o Parts/Book.o -o Main
Main.o:Main.cpp
	g++ Main.cpp -c -Wall -g -o Main.o
Manager.o:
	cd Parts;make
Reader.o:
	cd Parts;make
Book.o:
	cd Parts;make
clean:
	rm *.o Main  -rf
clean_o:
	rm *.o 