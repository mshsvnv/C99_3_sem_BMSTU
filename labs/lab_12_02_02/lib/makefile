CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -Wfloat-equal -Wfloat-conversion

LIB_NAME := my_lib.so 
OBJS_DYN := $(patsubst src/%.c, out/%.o, $(wildcard src/*.c))

RM := rm
MKD := mkdir -p out

lib : out/$(LIB_NAME)

unit_tests.exe : out/$(LIB_NAME)
	$(CC) $(CFLAGS) -c unit_tests/check_main.c -o out/check_main.o
	$(CC) -o $@ out/check_main.o -L$(DIR_STAT)/out $< -lcheck -lpthread -lrt -lm -lsubunit

out/$(LIB_NAME) : $(OBJS_DYN)
	$(CC) $^ -shared -o $@

out/%.o : */%.c
	$(MKD)
	$(CC) $(CFLAGS) -c $< -o $@ -fpic

.PHONY: lib unit clean

unit : CFLAGS += -g3
unit : unit_tests.exe
	./$^

clean :
	$(RM) *.exe *.txt out/*
