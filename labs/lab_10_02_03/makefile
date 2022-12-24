# compiler
CC := gcc
# flags for compilation
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -Wfloat-equal -Wfloat-conversion
# a list of generated objects
OBJS := $(filter-out out/main.o, $(patsubst src/%.c, out/%.o, $(wildcard src/*.c)))

RM := rm

app.exe : $(OBJS) out/main.o
	$(CC) -o $@ $^ -lm

unit_tests.exe : $(OBJS) out/check_main.o
	$(CC) -o $@ $^ -lcheck -lpthread -lrt -lm

./out/%.o : */%.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean unit func release debug

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

unit : OBJS := $(filter-out out/check_main.o, $(patsubst unit_tests/%.c, out/%.o, $(wildcard unit_tests/*.c)))
unit : unit_tests.exe
	./unit_tests.exe

func : debug
	func_tests/scripts/./func_tests.sh

clean : 
	$(RM) *.exe out/* *.txt
