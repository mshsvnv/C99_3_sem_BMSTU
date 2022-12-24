#!/bin/bash

# $1: файл с входными данными
# $2: файл с выходными эталонными данными
# $3: файл с ключами

pos_out="$2"
# array - массив для нахождения кол-ва ошибок утечки памяти
array=()

if [[ "$#" -eq 3 ]]; then
	pos_in="$1"
	pos_out="$2"
	args="$3"
elif [[ "$#" -eq 2 ]]; then
	pos_in="$1"
	pos_out="$2"
else
	args="$3"
fi

touch ./out/pos_res.txt

if [[ "$pos_in" != "" ]]; then
	# нужен ли valgrind
	if [[ "$USE_VALGRIND" != "" ]]; then
		xargs -a "$args" valgrind --log-file=./out/log.txt ./app.exe < "$pos_in"
	else
		xargs -a "$args" ./app.exe < "$pos_in" 
	fi
else
	if [[ "$USE_VALGRIND" != "" ]]; then
		xargs -a "$args" valgrind --log-file=./out/log.txt ./app.exe
	else
		xargs -a "$args" ./app.exe 
	fi
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



