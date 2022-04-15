obj=main.o printf1.o
target=main
cflags=-Wall -g

$(target):$(obj)
	$(CC) $^ -o $@ $(cflags)
main.o:main.c main.h printf1.h
	$(CC) -c $< -o $@ $(cflags)
printf1.o:printf1.c main.h
	$(CC) -c $< -o $@ $(cflags)
clean:
	rm $(obj) $(target)
