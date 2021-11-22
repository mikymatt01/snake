link: main.o drawer.o rules.o messages.o list.o
	gcc -pthread main.o drawer.o rules.o messages.o list.o -o snake

main.o:
	gcc -c main.c

drawer.o:
	gcc -c drawer.c

rules.o:
	gcc -c rules.c

messages.o:
	gcc -c messages.c
	
list.o:
	gcc -c list.c
	
clear:
	rm *.o
