#ifndef _IOSTREAM_
    #include <iostream>
#endif
#define DEBUG 1
#if DEBUG
    #define log(x) std::cout << "DBG: function " << __func__ << ", line " << __LINE__ << ": " << x << std::endl
#else
    #define log(x)
#endif