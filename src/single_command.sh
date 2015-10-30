#!/bin/bash

$1 $2

if [ "$1" == "ls" ]; then
	exit 1
elif [ "$1" == "echo" ]; then
	exit 1
elif [ "$1" == "mkdir" ]; then
	exit 1
else
	exit 0
fi
