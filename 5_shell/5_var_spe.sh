#!/bin/bash
name=teacher
string1="good morning $name"
string2='good morning $name'
echo $string1
echo $string2

echo "today is `date`"
echo 'today is `date`'
echo -e "this\n is\ta\ntest"

( name=student;echo "1 $name" )
echo 1:$name
{ name=student;echo "2 $name"; }
echo 2:$name
