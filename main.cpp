// to determine stack data type visit stack_properties.h
#include "stack.h"
#include <stdio.h>

#include "stack_dump.h"


int main()
{
    printf(MAKE_BOLD("+++ LAUNCHING STACK +++\n\n"));

    st_t st = {};
    st_ctor(&st, 10);

    printf("stack created\n");

    st_dump(&st);

    st_push(&st, 10);
    st_push(&st, 20);
    st_push(&st, 30);
    st_push(&st, 40);
    st_push(&st, 50);
    st_push(&st, 60);
    st_push(&st, 70);
    st_push(&st, 80);
    st_push(&st, 90);
    st_push(&st, 100);

    printf("stack full\n");

    st_dump(&st);

    //int el = 0;
    st_push(&st, 110);

    printf("stack reallocated\n");

    st_dump(&st);

    //st_pop(&st, &el);
    //printf("el=%d\n", el);

    //st.data[st.capacity + 1] = 0;
    //st.size = st.capacity + 1;


    st_push(&st, 120);
    st_push(&st, 130);
    printf("stack appended\n");

    st_dump(&st);


    //printf("%d %d\n", error, no_error);

    return 0;
}
