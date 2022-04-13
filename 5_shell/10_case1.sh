#!/bin/bash
echo "please input your choice $i"
read i

echo "this script will print your choice"

case "$i" in
	"one")
		echo "your choice is one"
		;;
	"two")
		echo "your choice is two"
		;;
	"three")
		echo "your choice is three"
		;;
	*)
		echo "error please try again!"
		exit 1
		;;
esac
