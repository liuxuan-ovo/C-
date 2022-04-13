#!/bin/bash
declare -i i
declare -i s
while [ "$i" != "101" ]
do
	s=s+i;
	i=i+1;
done
echo "the count is $s"
