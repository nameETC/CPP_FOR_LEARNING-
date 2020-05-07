Main:Main.o mystack.o
	g++ Parts/mystack.o Main.o -o Main
Main.o:Main.cpp
	g++ Main.cpp -c -Wall -g -o Main.o
mystack.o:
	cd Parts;make;
clean:
	rm *.o rf