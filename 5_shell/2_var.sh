#!/bin/bash
echo "this is the var test shell script"
name="sunplus edu"
echo "$name is me"
echo '$name is me'

echo "please input a string"
read string
echo "the string of your input is $string"

readonly var=1000
#var=200

export public_var=300
