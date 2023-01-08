GCC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla -g
OBJS := $(patsubst %.c, %.o, $(wildcard *.c))

app.exe: $(OBJS)
	$(GCC) $^ -o $@

%.o : %.c *.h
	$(GCC) $(CFLAGS) $< -c

clear:
	rm *.o *.exe