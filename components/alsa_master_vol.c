/* Created by William Rabbermann */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../util.h"

const char *
alsa_master_vol(const char *unused)
{
        char *cmd = "amixer get Master | tail -n 1 | sed 's/.*\\[\\(.*\\)%\\].*\\(on\\|off\\).*/\\1%\\2/'";

	FILE *fp = popen(cmd, "r");
        int vol;
        char on_off[4] = {0};
        fscanf(fp, "%d%%%3s", &vol, on_off);
        pclose(fp);
        int is_on = strcmp(on_off, "on") == 0;

        char *icon = is_on ? "\U000f057e"  : "\U000f0581";
        return bprintf("%s %d%%", icon, vol);
}
