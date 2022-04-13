#!/bin/bash

echo "please input your choice:"
read choice
case "$choice" in
	Y | yes | Yes | YES)
		echo "it's right"
		;;
	N* | n*)
		echo "it's wrong"
		;;
	*)
	exit 1
esac
