#!/bin/bash

if [[ ! -z "$1" ]]; then 
    k="$1"
else
    k=10
fi

if [[ "$2" == "BUILD" ]]; then
    ./build_apps.sh
fi

if [ ! -d data ]; then
    mkdir data
else
    rm -r data
    mkdir data
fi

i=0
while [[ "$i" -lt "$k" ]]; do
    i=$((i+1))
    echo -n -e "LOADING : $i from $k\n\r"
    
    ./update_data.sh

    echo -n -e "\033[2K\r\033[A\033[A\033[2K\r\033[A"
done

echo -e "\n::::Making prepocessing::::\n"
python3 make_preproc.py
sleep 2
echo -n -e "\033[2K\r\033[A\033[A\033[2K\r\033[A"

echo -e "\n::::Making postpocessing::::\n"
python3 make_postproc.py
sleep 2
echo -n -e "\033[2K\r\033[A\033[A\033[2K\r\033[A"

if [ ! -d graphs ]; then
    mkdir graphs
else 
    rm -r graphs
    mkdir graphs
fi

echo -e "\n::::Making First Graph::::\n"
gnuplot -persist graph_1.gpi
sleep 2
echo -n -e "\033[2K\r\033[A\033[A\033[2K\r\033[A"

