srcs:=$(wildcard *.c)
exe:=$(patsubst %.c,%.o,$(srcs))


%:%.c
	$(CC) $^  -c  $@ 

all:$(exe)
	$(CC) $^ -o server
.PHONY: clean rebuild

rebuild:clean all
clean:
	$(RM)  $(exe) server
