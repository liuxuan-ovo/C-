#!/bin/bash
test -z $yn
echo $?

echo "please input a y/n"
read yn
[ -z "$yn" ]
echo 1:$?

[ $yn = "y" ]
echo 2:$?
