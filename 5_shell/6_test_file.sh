#!/bin/bash
test -e /dev/qaz
echo $?

test -e /home
echo $?

test -d /home
echo $?

test -f /home
echo $?

