main:main.o printf1.o
	gcc main.o printf1.o -o main
main.o:main.c main.h printf1.h
	gcc -c main.c -o main.o
printf1.o:printf1.c main.h
	gcc -c printf1.c -o printf1.o
clean:
	rm *.o main
