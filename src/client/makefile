srcs:=$(wildcard *.c)
exe:=$(patsubst %.c,%.o,$(srcs))

result:= client

rebuild:clean all
build:$(result)



all:$(exe)
	$(CC) $^ -o $(result)

%.o:%.c
	$(CC) -c $^ -o  $@ 



.PHONY: clean rebuild

clean:
	$(RM)  $(exe) $(result)
