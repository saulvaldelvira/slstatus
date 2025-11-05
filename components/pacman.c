#include <stdio.h>
#include <time.h>
#include "../util.h"

const char* pacman_last_upgrade(const char *unused) {

        char *cmd = "last=$( grep 'full system upgrade' /var/log/pacman.log | tail -1 | awk -F'[][]' ' { print $2; }' )\
        date -d \"$last\" +%s";

	FILE *fp = popen(cmd, "r");
        int last_update_secs;
        fscanf(fp, "%d", &last_update_secs);
        pclose(fp);

        time_t diff_secs = time(0) - last_update_secs;
        time_t days = diff_secs / 3600 / 24;


        if (days >= 2) {
                return bprintf(" \U000f06b0 Update!");
        } else {
                return "";
        }

}
