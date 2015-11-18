#!/bin/bash

read -e userinput

if $userinput == 0; then
	echo "path exists"
	return 0;
else
	echo "path does not exists"	
	return 1;
fi
