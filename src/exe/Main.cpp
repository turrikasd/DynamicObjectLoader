#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void errorOut(const char* msg)
{
    printf(msg);
    exit(1);
}

int main()
{
    typedef void (*print_num_type)(int input);

    void *slb = dlopen("slb.so", RTLD_NOW);
    if (slb == NULL)
        errorOut("Unable to open slb.so");

    void* func = dlsym(slb, "print_num");
    if (func == NULL)
        errorOut("Unbale to fetch function print_num from shared library");

    print_num_type print_num = (print_num_type)func;
    print_num(12);
    dlclose(slb);

    return 0;
}
