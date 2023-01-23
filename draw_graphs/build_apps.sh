#!/bin/bash

if [ ! -d apps ]; then
    mkdir apps
else 
    rm -r apps
    mkdir apps
fi

opts=$(tail -1 keys.txt)

sizes=$(head -1 keys.txt)
prog_num=$(head -2 keys.txt | tail -1)

echo -e "\n ::Building apps:: \n"

for num in $prog_num; do
    for size in $sizes; do
        for opt in $opts; do
            echo -n -e "$num \\ $opt \\ $size \\r" 
            gcc -std=c99 -Wall -Werror -Wpedantic -Wextra \
            -DNMAX="$size" -"$opt" main_"$num".c -o ./apps/app_"$num"_"$opt"_"$size".exe
        done
    done
done

echo -n -e "\033[2K\r\033[A\033[A\033[2K\r\033[A"

