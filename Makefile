inverted_search.out: main.o  validation.o create.o display.o search.o save.o update.o 
	gcc -o inverted_search.out main.o  validation.o create.o display.o search.o save.o update.o
main.o: main.c
	gcc -c main.c
validation.o: validation.c
	gcc -c validation.c
create.o: create.c
	gcc -c create.c
display.o: display.c
	gcc -c display.c
search.o: search.c
	gcc -c search.c
save.o: save.c
	gcc -c save.c
update.o: update.c
	gcc -c update.c
clean:
	rm *.o *.out
