CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -Wfloat-equal -Wfloat-conversion

LIB_NAME := my_lib.a 
OBJS_STAT := $(filter-out out/main.o, $(patsubst src/%.c, out/%.o, $(wildcard src/*.c)))

RM := rm
MKD := mkdir -p out

app.exe : out/$(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ src/main.c $^

unit_tests.exe : out/$(LIB_NAME) out/check_main.o
	$(CC) -o $@ out/check_main.o -L /out $< -lcheck -lpthread -lrt -lm -lsubunit

out/$(LIB_NAME) : $(OBJS_STAT)
	ar rcs $@ $^
	ranlib $@

out/%.o : */%.c
	$(MKD)
	$(CC) $(CFLAGS) -c $< -o $@

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
