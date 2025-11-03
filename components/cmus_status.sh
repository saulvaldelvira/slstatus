while read key value1 value2 ; do
    [ "$key" = "status" ] && status="$value1"
    [ "$value1" = "title" ] && title="$value2"
    [ "$value1" = "artist" ] && artist="$value2"
done <<< $(cmus-remote --query 2> /dev/null)
[ "$status" = "playing" ] && echo -e "$title - $artist" || echo ""
