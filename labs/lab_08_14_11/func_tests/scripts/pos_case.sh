#!/bin/bash

# array - массив для нахождения кол-ва ошибок утечки памяти
array=()

args="$2"
pos_out="$1"

touch ./out/pos_res.txt

if [[ "$USE_VALGRIND" != "" ]]; then
	xargs -a "$args" valgrind --leak-check=full --show-leak-kinds=all -s --log-file=./out/log.txt ./app.exe
else
	xargs -a "$args" ./app.exe 
fi

./func_tests/scripts/comparator.sh ./out/pos_res.txt "$pos_out"

exit_code="$?"

if [[ "$USE_VALGRIND" != "" ]]; then
	
	mapfile -t array < <(tail -1 ./out/log.txt | grep -Eo "[0-9]*")
	
	if [[ ${array[1]} -ne 0 ]]; then
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 10 - позитивный тест пройден, есть утечки памяти
			exit 10   
		else
			# код возврата 20 - позитивный тест не пройден, есть утечки памяти	
			exit 20
		fi
	else
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 30 - позитивный тест пройден, нет утечек памяти
			exit 30
		else
			# код возврата 40 - тпозитивный ест не пройден, нет утечек памяти
			exit 40
		fi
	fi
else
	exit "$exit_code"
fi



