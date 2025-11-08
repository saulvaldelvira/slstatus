
#include <stdio.h>
#include "../util.h"
#include "../slstatus.h"

const char* nmgr_ssid(const char *kind) {

        const char *cmd = "nmcli -f NAME,TYPE con show --active  | tail -n +2 | grep %s | \
                           awk '{ print $1 ; }'";
        snprintf(buf, sizeof(buf) - 1, cmd, kind);

        return run_command(buf);
}
