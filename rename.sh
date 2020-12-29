#!/bin/bash

for dict in *
do
    if [[ -d $dict && $dict =~ ^[0-9]+_ ]]
    then
        t="$dict"
        if [ '_' == ${t:1:1} ]
        then
            echo '000'${t//_/'-'}
            mv "$dict" '000'${t//_/'-'}
        fi
        if [ '_' == ${t:2:1} ]
        then
            echo '00'${t//_/'-'}
            mv "$dict" '00'${t//_/'-'}
            #echo '00'$dict
        fi
        if [ '_' == ${t:3:1} ]
        then
            echo '0'${t//_/'-'}
            mv "$dict" '0'${t//_/'-'}
            #echo '0'$dict
        fi
    fi
    if [[ -d $dict && $dict =~ ^[0-9]+- ]]
    then
        t="$dict"
        if [ '-' == ${t:1:1} ]
        then
            mv  $t '000'$t 
            echo '000'$t
        fi
        if [ '-' == ${t:2:1} ]
        then
            mv  $t '00'$t
            echo '00'$t
        fi
        if [ '-' == ${t:3:1} ]
        then
            mv  $t '0'$t
            echo '0'$t
        fi
    fi
done
