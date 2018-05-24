all: main.o link_list.o library.o
	gcc -o test main.o link_list.o library.o

main.o: main.c link_list.h library.h
	gcc -c main.c

link_list.o: link_list.c link_list.h
	gcc -c link_list.c

library.o: library.c library.h
	gcc -c library.c

clean:
	rm test
	rm *.o
	rm *~

run:
	./test
