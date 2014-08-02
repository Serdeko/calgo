#ifdef NDEBUG
    #define myassert(test) ((void)0)
#else
//    void myfassert(test);
    #define VAL(x) #x
    #define STR(x) VAL(x)
    #define myassert(test) ((test) ? (void)0 : myfassert(" : "#test " " __FILE__ " " STR(__LINE__)))
#endif // NDEBUG
