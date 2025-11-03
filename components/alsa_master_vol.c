/* Created by William Rabbermann */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../util.h"

const char *
alsa_master_vol(const char *unused)
{
        char *cmd = "amixer get Master | tail -n 1 | awk -F'[][]' '{ \
                     printf $2;\
                     if ($4 == \"on\") \
                             print 1; \
                     else print 0; \
        }'";

	FILE *fp = popen(cmd, "r");
        int vol;
        int is_on;
        fscanf(fp, "%d%%%d", &vol, &is_on);
        pclose(fp);

        char *icon = is_on ? "\U000f057e"  : "\U000f0581";
        return bprintf("%s %d%%", icon, vol);
}
