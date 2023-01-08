GCC:= gcc 
CFLAGS := -std=c99 -Wall -Werror -Wvla -Wpedantic
OBJS := $(patsubst ./%.c, ./%.o, $(wildcard ./*.c))

app.exe : $(OBJS)
	$(GCC) $^ -o $@

# %.o : %.c *.h
# 	$(GCC) $(CFLAGS) -c $<

valgrind: app.exe
	valgrind --leak-check=full -s ./app.exe

clear:
	rm *.exe *.o