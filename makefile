noStringsAttached: fulawkaJordanA2.o main.o 
	gcc -Wall -std=c99 fulawkaJordanA2.o main.o -o bin/noStringsAttached 

fulawkaJordanA2.o: src/fulawkaJordanA2.c include/fulawkaJordanA2.h 
	gcc -Wall -std=c99 -c src/fulawkaJordanA2.c

main.o: src/main.c include/fulawkaJordanA2.h 
	gcc -Wall -std=c99 -c src/main.c

clean: 
	rm *.o bin/noStringsAttached