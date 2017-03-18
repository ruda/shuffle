#!/bin/sh
#
# Print a random permutation of arguments.
# Copyright © 2000-201y Rudá Moura
#

# Exit immediately if a test fails
set -e

VERBOSE=1

test_version () {
    ./shuffle -v
}

test_perms () {
    ./shuffle -p 10 a | sort -u | wc -l
    ./shuffle -p 20 a b | sort -u | wc -l
    ./shuffle -p 60 a b c | sort -u | wc -l
    ./shuffle -p 240 a b c d | sort -u | wc -l
    ./shuffle -p 1200 a b c d e | sort -u | wc -l
    ./shuffle -p 7200 a b c d e f | sort -u | wc -l
    ./shuffle -p 504000 a b c d e f g | sort -u | wc -l
}

tc () {
    printf "%s: " $1
    result=`$1`
    result=`echo $result` # Remove new lines and whitespaces
    if [ `expr "$result" : "$2"` != 0 ] ; then
        echo "OK"
        return 0
    else
        echo "FAIL"
        [ $VERBOSE = 1 ] && echo "Expected: $2"
        [ $VERBOSE = 1 ] && echo "Result: $result"
        return 1
    fi
}

run_tests () {
    tc test_version ".*1\.17\.3.*Copyright"
    tc test_perms "1 2 6 24 120 720 5040"
}

if [ $# == 0 ]; then
    run_tests
else
    $1
fi

# vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4
