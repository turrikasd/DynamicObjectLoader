#ifdef _WIN32
	#include <Windows.h>
#else
	#include <dlfcn.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void errorOut(const char* msg)
{
    printf(msg);
    exit(1);
}

#ifdef _WIN32

int main()
{
	typedef void (*print_num_type)(int input);

	HMODULE slb	= LoadLibrary("slb.dll");
	if (slb == NULL)
		errorOut("Unable to open slb.dll");

	FARPROC func = GetProcAddress(slb, "print_num");
	if (func == NULL)
		errorOut("Unable to fetch function print_num from shared library");

	print_num_type print_num = (print_num_type)func;
	print_num(12);
	FreeLibrary(slb);

	return 0;
}

#else
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
#endif