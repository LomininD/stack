#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <stdio.h>
#include "stack_properties.h"



st_return_err st_ctor (st_t* st, size_t capacity);
st_return_err st_dtor (st_t* st);
st_return_err st_push (st_t* st, st_data_type value);
st_data_type st_pop (st_t* st); // st_return_err

#endif
