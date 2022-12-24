#!/bin/bash

# $1: файл с входными данными
# $2: файл с ключами

if [[ "$#" -eq 2 ]]; then
	neg_in="$1"
	args="$2"
else
	args="$1"
fi

if [[ "$neg_in" != "" ]]; then
	if [[ "$USE_VALGRIND" != "" ]]; then
		xargs -a "$args" valgrind --log-file=log.txt ./app.exe < "$neg_in"
	else
		xargs -a "$args" ./app.exe < "$neg_in"
	fi
else
	if [[ "$USE_VALGRIND" != "" ]]; then
		xargs -a "$args" valgrind --log-file=log.txt ./app.exe 
	else
		xargs -a "$args" ./app.exe 
	fi
fi

exit_code="$?"

if [[ "$exit_code" -ne 0 ]]; then
	exit_code=0
else
	exit_code=1
fi

if [[ "$USE_VALGRIND" != "" ]]; then
	mapfile -t array < <(tail -1 log.txt | grep -Eo "[0-9]*")
	
	if [[ ${array[1]} -ne 0 ]]; then
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 10 - негативный тест пройден, есть утечки памяти
			exit 10   
		else
			# код возврата 20 - негативный тест не пройден, есть утечки памяти	
			exit 20
		fi
	else
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 30 - негативный тест пройден, нет утечек памяти
			exit 30
		else
			# код возврата 40 - негативный тест не пройден, нет утечек памяти
			exit 40
		fi
	fi
else
	exit "$exit_code"
fi
