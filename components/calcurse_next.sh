#!/bin/sh

next_apt=$(calcurse -Q --from today -r2 --filter-type apt --format-apt "%m;%s;%e\n" | grep ';')

curr=$(date +%s)
while IFS=';' read -r name start end ; do
    if [ "$start" -gt "$curr" ]; then
        s=$(date --date="@$start" "+%H:%M")
        echo "$name ($s)"
        exit
    # elif [ "$end" -gt "$curr" ]; then
    #     e=$(date --date="@$end" "+%H:%M")
    #     echo "$name ($e) $delim"
    #     return
    fi
done<<<$next_apt
