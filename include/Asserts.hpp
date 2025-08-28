#ifndef ASSERTS_H
#define ASSERTS_H

#define MY_ASSERT(condition, message) \
    if (!(condition)) \
    { \
        fprintf(stderr, "Assertion failed: %s, file: %s, function: %s, line: %d.\n", \
                message, __FILE__, __FUNCTION__, __LINE__);\
    }

#endif
