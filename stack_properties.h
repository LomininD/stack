#ifndef STACK_INFO_H
#define STACK_INFO_H

#include <stdio.h>

typedef int st_data_type; // you can change stack type here

const int canary_value = 0xcadef; // cadef - CAnary DEFense
const size_t st_output_size = 8;
//const int poisoned_data = 0xbadf00d;

enum st_error
{
    st_ok,
    no_data,
    stack_overflow,
    canary_fault
};

enum st_return_err
{
    no_error,
    no_stack,
    no_memory,
    verification_error
};

struct st_t
{
    st_data_type* data;
    size_t size;
    size_t capacity;
    st_error error;
};

#endif
