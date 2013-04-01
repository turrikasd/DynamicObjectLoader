#if defined _MSC_VER // Defined by visual studio
  #define slb_TMP_DLL_IMPORT __declspec(dllimport)
  #define slb_TMP_DLL_EXPORT __declspec(dllexport)
#else
  #if __GNUC__ >= 4 // Defined by GNU C Compiler. Also for C++
    #define slb_TMP_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define slb_TMP_DLL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define slb_TMP_DLL_IMPORT
    #define slb_TMP_DLL_EXPORT
  #endif
#endif

#ifdef slb_EXPORTS
    #define slb_API slb_TMP_DLL_EXPORT
#else
    #define slb_API slb_TMP_DLL_IMPORT
#endif

extern "C" void slb_API print_num(int input);