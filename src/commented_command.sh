#!/bin/bash

read input_variable
echo "where do you want to save? If you dont want to save leave it blank"
read file_name

$input_variable >> $file_name

echo "finished to write comment"

