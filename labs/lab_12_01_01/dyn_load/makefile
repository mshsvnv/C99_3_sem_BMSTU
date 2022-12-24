CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wvla -Wextra -Wfloat-equal -Wfloat-conversion

LIB_NAME := my_lib.so 
OBJS_DYN := $(filter-out out/main.o, $(patsubst src/%.c, out/%.o, $(wildcard src/*.c)))

RM := rm
MKD := mkdir -p out

app.exe : out/$(LIB_NAME)
	$(CC) $(CFLAGS) -c src/main.c -o out/main.o
	$(CC) -o $@ out/main.o -ldl

unit_tests.exe : out/$(LIB_NAME)
	$(CC) $(CFLAGS) -c unit_tests/check_main.c -o out/check_main.o
	$(CC) -o $@ out/check_main.o -ldl -lcheck -lpthread -lrt -lm -lsubunit

out/$(LIB_NAME) : $(OBJS_DYN)
	$(CC) $^ -shared -o $@

out/%.o : */%.c
	$(MKD)
	$(CC) $(CFLAGS) -c $< -o $@ -fpic

.PHONY: debug release clean unit func

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

unit : CFLAGS += -g3
unit : unit_tests.exe
	./$^

func : debug
func : app.exe
	./func_tests/scripts/func_tests.sh

clean :
	$(RM) *.exe *.txt out/*
