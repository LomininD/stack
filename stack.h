#ifndef STACK_H
#define STACK_H


// TODO: st_history mode
// TODO: file logs
// TODO: multiple error output


#include <assert.h>
#include <stdio.h>
#include "stack_properties.h"

//#define CHECK_STACK(ST) !st_verify(ST) ? return any_error :

void st_ctor (st_t* st, size_t capacity);
st_data_type st_dtor (st_t* st);
st_error st_push (st_t* st, st_data_type value);
st_data_type st_pop (st_t* st);


#endif
