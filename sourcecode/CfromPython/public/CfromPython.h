#ifndef CFROMPYTHON_H
#define CFROMPYTHON_H

#ifdef __cplusplus
extern "C" {
#endif

// Function prototype for the device controller
const char* handle_command(const char* cmd);
__attribute__((visibility("default"))) const char* get_status();

#ifdef __cplusplus
}
#endif

#endif // CFROMPYTHON_H
