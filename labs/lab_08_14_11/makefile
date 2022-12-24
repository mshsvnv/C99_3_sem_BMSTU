# compiler
CC := gcc
# flags for compilation
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -Wfloat-equal -Wfloat-conversion
# a list of generated objects
OBJS := out/file_funcs.o out/matrix_funcs.o out/other_matrix_funcs.o out/memory_func.o

RM := rm

app.exe : $(OBJS) out/main.o
	$(CC) -o $@ $^

unit_tests.exe : $(OBJS) out/check_main.o
	$(CC) -o $@ $^ -lcheck -lpthread -lrt -lm

unit : debug
unit : unit_tests.exe
	./unit_tests.exe

./out/%.o : unit_tests/%.c
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@ 

./out/%.o : */%.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean debug release func unit

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

func : debug
	func_tests/scripts/./func_tests.sh

clean : 
	$(RM) *.exe out/* *.txt 
