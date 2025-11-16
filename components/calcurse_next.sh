#!/bin/sh

fmt="%m;%s;%e\n"
next_apt=$(calcurse -Q --from today -r2 --filter-type cal \
    --format-apt $fmt \
    --format-recur-apt $fmt \
    --format-event $fmt \
    --format-recur-event $fmt \
    | grep ';')

curr=$(date +%s)
while IFS=';' read -r name start end ; do
    [ -z $start ] && continue
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

echo ""
