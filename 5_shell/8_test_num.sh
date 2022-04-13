#!/bin/bash
echo "please input a num(1-9)"
read num
[ $num -eq 5 ]
echo $?
[ $num -ne 5 ]
echo $?
[ $num -gt 5 ]
echo $?
[ $num -ge 5 ]
echo $?
[ $num -lt 5 ]
echo $?
[ $num -le 5 ]
echo $?
