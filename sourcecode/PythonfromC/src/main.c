#include <python3.11/Python.h>
#include <stdio.h>

int main() {
    printf("Initializing Python...\n");
    Py_Initialize();

    // Pass full mode and custom metrics as arguments
    wchar_t *argv[] = {
        Py_DecodeLocale("script.py", NULL),
        Py_DecodeLocale("--mode", NULL),
        Py_DecodeLocale("full", NULL),
        Py_DecodeLocale("--cpu", NULL),
        Py_DecodeLocale("45", NULL),
        Py_DecodeLocale("--mem", NULL),
        Py_DecodeLocale("70", NULL),
        Py_DecodeLocale("--temp", NULL),
        Py_DecodeLocale("60", NULL),
        NULL
    };
    PySys_SetArgv(9, argv); // Number of arguments (not including NULL)

    // Open the Python script file
    FILE* fp = fopen("/var/tmp/script.py", "r");
    if (fp == NULL) {
        perror("Failed to open Python script");
        Py_Finalize();
        return 1;
    }

    printf("Running Python script from file...\n");
    PyRun_SimpleFile(fp, "/var/tmp/script.py");
    fclose(fp);

    Py_Finalize();
    printf("Python execution complete.\n");

    return 0;
}
