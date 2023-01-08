GCC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

app.exe : $(OBJS)
	$(GCC) $^ -o $@

%.o : %.c *h
	$(GCC) $(CFLAGS) $< -c

clear:
	rm *.o *.exe

valgrind : app.exe
	valgrind --leak-check=full -s ./app.exe