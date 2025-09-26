#ifndef STACK_DUMP_H
#define STACK_DUMP_H


#include <stdio.h>
#include <assert.h>

#include "font_styles.h"
#include "stack_properties.h"


enum verifier_output
{
    not_verified = 0,
    verified = 1
};


void st_dump(st_t* st);
verifier_output st_verify(st_t* st);


#endif
