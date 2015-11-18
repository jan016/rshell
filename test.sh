#!/bin/bash

read -e userinput

if $userinput; then
	echo "path exists"
	exit 0;
else
	echo "path does not exists"	
	exit 1;
fi
