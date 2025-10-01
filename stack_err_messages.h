#ifndef STACK_ERR_MESSAGES_H
#define STACK_ERR_MESSAGES_H

#include <stdio.h>
#include "stack_properties.h"

#define CTOR_ASSERT_ST(ST) do { \
    if (ST == NULL) \
        { \
            printf("st_ctor: " MAKE_BOLD_RED("ERROR:") " no access to stack (got NULL pointer)\n"); \
            return no_stack; \
        } \
    } while(0)


#define CTOR_ASSERT_CAPACITY(CAP) do{ \
    if(CAP == 0) \
            printf(MAKE_BOLD("WARNING:") " stack of 0 elements is not usable\n"); \
    } while(0)


#define CTOR_ASSERT_DATA(DATA) do{ \
    if (DATA == NULL) \
        { \
            printf("st_ctor: " MAKE_BOLD_RED("ERROR:") " could not allocate memory for stack data\n"); \
            return no_memory; \
        } \
    } while(0)


#endif
