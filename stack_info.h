#ifndef STACK_INFO_H
#define STACK_INFO_H


#include <stdio.h>


const int canary_value = 911;
const int poisoned_data = 666;


enum st_error
{
    any_error = -1,
    no_error = 0,
    canary_fault = 1

};


struct st_t
{
    st_data_type* data;
    int size;
    size_t capacity;
    st_error error;
};


#endif
