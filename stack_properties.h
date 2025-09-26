#ifndef STACK_INFO_H
#define STACK_INFO_H


#include <stdio.h>


typedef int st_data_type; // you can change stack type here


const int canary_value = 911;
const int poisoned_data = 666;


enum st_error
{
    any_error = -1,
    no_error,
    no_data,
    stack_overflow,
    canary_fault

};


struct st_t
{
    st_data_type* data;
    int size;
    size_t capacity;
    st_error error;
};


#endif
