project2 : main.o hotel.o
	gcc main.o hotel.o -o project2

main.o : main.c hotel.h
	gcc -Wall -c main.c

hotel.o : hotel.c hotel.h
	gcc -Wall -c hotel.c

clean : 
	rm *.o project2