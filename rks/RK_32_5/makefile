CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wvla -Wextra -Wfloat-equal -Wfloat-conversion
OBJS := $(filter-out out/main.o, $(patsubst src/%.c, out/%.o, $(wildcard src/*.c)))

RM := rm

app.exe : $(OBJS) out/main.o
	$(CC) -o $@ $^ -lm

./out/%.o : */%.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean release debug 

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

clean : 
	$(RM) *.exe out/* 
