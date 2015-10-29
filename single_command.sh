#!/bin/bash

$1 $2

if [ $1 -eq 127]||[ $2 -eq 127];
then
	exit 1
else
	exit 0
