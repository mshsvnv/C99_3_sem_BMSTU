#!/bin/bash

opts=$(tail -1 keys.txt)

echo -e "\n::::Updating data::::\n"

sizes=$(head -1 keys.txt)
prog_num=$(head -2 keys.txt | tail -1)

for num in $prog_num; do
    for opt in $opts; do
        for size in $sizes; do
            echo -n -e "$num \\ $opt \\ $size \r"
            ./apps/app_"$num"_"$opt"_"$size".exe >> ./data/"$num"_"$opt"_"$size".txt
        done
    done
done

echo -n -e "\033[2K\r\033[A\033[A\033[2K\r\033[A"