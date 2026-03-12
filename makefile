CC = gcc
main : main.c provided.o make.o modify.o
	$(CC) -o $@ $^
provided.o : provided.c
	$(CC) -c $^
modify.o : modify.c
	$(CC) -c $^
make.o : make.c
	$(CC) -c $^
clean:
	rm *.o main