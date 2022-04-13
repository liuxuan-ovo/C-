#!/bin/bash
declare -i sum
for(( i=1;i<=100;i++ ))
do
	sum=sum+i;
done
echo "the result is $sum"
