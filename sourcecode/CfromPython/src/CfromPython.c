#include <string.h>
#include "CfromPython.h"

static int initialized = 0;
static int running = 0;
static int throttled = 0;

__attribute__((visibility("default")))
const char* get_status(){
	if (!initialized) return "Status: OFFLINE";
	if (running && throttled) return "Status: THROTTLED";
	if (running) return "Status: RUNNING";
	return "Status: READY";
}

const char* handle_command(const char* cmd) {
    if (strcmp(cmd, "INIT") == 0) {
        initialized = 1;
        return "Device initialized.";
    }
    if (strcmp(cmd, "START") == 0) {
        if (!initialized) return "Error: Not initialized.";
        running = 1;
        return "Device started.";
    }
    if (strcmp(cmd, "THROTTLE") == 0) {
        if (!running) return "Error: Not running.";
        throttled = 1;
        return "Device throttled.";
    }

    if (strcmp(cmd, "SHUTDOWN") == 0) {
        initialized = 0;
        running = 0;
        throttled = 0;
        return "Device shut down.";
    }
    if (strcmp(cmd, "DIAG") == 0) {
        return "Voltage=12.5V Temp=46C RPM=1500";
    }

    return "Unknown command.";
}
