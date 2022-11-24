#!/bin/bash

# This program draws brazil's flag for worldcup

# set width and height
w=90
h=30

# clear the screen end set cursor to 1,1
echo -ne "\033[2J\033[1G\033[1H"

# paints green
for j in $(seq 1 $h); do
	for i in $(seq 1 $w); do
		if test $(($j%2)) -ne 0; then
			echo -ne "\033[42m \033[m"
		else
			echo -ne "\033[44m \033[m"
		fi
	done
	echo ""
done
