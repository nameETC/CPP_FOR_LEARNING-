
Manager.o:Manager.cpp Book.o Reader.o
	g++ -c Manager.cpp -Wall -g Book.o Reader.o -o Manager.o
Reader.o:Reader.cpp
	g++ -c Reader.cpp -Wall -g -o Reader.o
Book.o:Book.cpp 
	g++ -c Book.cpp -Wall -g -o Book.o
clean:
	rm *.o Main  -rf
clean_o:
	rm *.o 

# g++ -o Main Main.cpp Parts/Book.cpp Parts/Manager.cpp Parts/Reader.cpp
