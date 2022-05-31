#!/bin/bash
make -C ..
make -C .. bonus
gcc generator.c -o generateur
clear
# while true
# do 
	# ARG=$1
	ARG=`./generateur $1 -2147483648 2147483647`
	#echo $ARG
	# ../push_swap $ARG
	../push_swap $ARG | wc -l
	../push_swap $ARG | ../checker_linux $ARG 
	../push_swap $ARG | ../checker $ARG
	#sleep 0.2
# done