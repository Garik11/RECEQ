#ifndef REC_SOLVER
#define REC_SOLVER

#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef long long RecType;

#define syntax_assert(expression, text)                                                                              \
    if (!(expression))                                                                                               \
    {                                                                                                                \
        printf("syntax_error DETECT in file:%s, in line: %d, in func%s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__); \
        printf("expression : %s\n", #expression);                                                                    \
        printf("ERROR : %s\n", text);                                                                                \
        abort();                                                                                                     \
    }

RecType RecCalculate(const char *str_equation);

#endif // REC_SOLVER