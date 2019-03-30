/*Beginning*/
#include <Python/Python.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    FILE* file;
    char root[100];
    strcpy("root","/Users/matheus/git/Grafos/plagio.py");
    Py_SetProgramName("plagio.py");
    Py_Initialize();
    file = fopen("root","r");
    PyRun_SimpleFile(file, "root");
    Py_Finalize();
    fclose(file);
    return 0;
}
