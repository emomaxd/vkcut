#pragma once

#include <iostream>
#include <cstdlib>

#if defined(_MSC_VER)
    #define DEBUG_BREAK() __debugbreak()
#else
    #define DEBUG_BREAK() __builtin_trap()
#endif

#define ASSERT(x) \
    do { if (!(x)) { \
        std::cerr << "ASSERTION FAILED: " << #x << " | " << __FILE__ << ":" << __LINE__ << "\n"; \
        DEBUG_BREAK(); std::abort(); \
    } } while (0)

#define EXPECT_TRUE(x) \
    do { if (!(x)) { \
        std::cerr << "EXPECT_TRUE FAILED: " << #x << " | " << __FILE__ << ":" << __LINE__ << "\n"; \
    } } while (0)

#define EXPECT_FALSE(x) \
    do { if (x) { \
        std::cerr << "EXPECT_FALSE FAILED: " << #x << " | " << __FILE__ << ":" << __LINE__ << "\n"; \
    } } while (0)

#define UNREACHABLE() \
    do { \
        std::cerr << "UNREACHABLE CODE REACHED! | " << __FILE__ << ":" << __LINE__ << "\n"; \
        DEBUG_BREAK(); std::abort(); \
    } while (0)
