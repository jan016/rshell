#!/bin/bash

if [ $1 -eq 1 ]; then 
	exit 1
elif [ $1 -eq 0 ]&&[ $2 == ";" ];then
	exit 1
else
	exit 0
fi
