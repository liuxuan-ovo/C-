#!/bin/bash
test -e /home && test -d /home && echo "true"
test 2 -lt 3 && test 5 -gt 3 && echo "equal"
test "aaa"="aaa" || [ "$yn"="y" ] && echo "equal"
