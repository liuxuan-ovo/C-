#!/bin/bash
echo "press y to continue"
read yn
if [ $yn = "y" ];then
	echo "script is running..."
else
	echo "stopping!"
fi
