// to determine stack data type visit stack_properties.h
#include "stack.h"
#include <stdio.h>

#include "stack_dump.h"


int main()
{
    st_t st = {};
    st_ctor(&st, 10);
    //int el = 0;
    st_dump(&st);
    //st_pop(&st, &el);

    // st_push(&st, 10);
    // st_push(&st, 20);
    // st_push(&st, 30);
    // st_push(&st, 40);
    // st_push(&st, 50);
    // st_push(&st, 60);
    // st_push(&st, 10);
    // st_push(&st, 20);
    // st_push(&st, 30);
    // st_push(&st, 40);
    // st_push(&st, 50);
    // st_push(&st, 60);
    //st.data[st.capacity + 1] = 0;
    //st.size = st.capacity + 1;
    //int el = 0;
    //st_dump(&st);
    //st_pop(&st, &el);
    //int error = st_push(&st, 70);
    //printf("%p\n", &st);
    //st_dump(&st);
    //printf("el=%d\n", el);
    //printf("%d %d\n", error, no_error);

    return 0;
}
