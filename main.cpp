// to determine stack data type visit stack_properties.h
#include "stack.h"
#include <stdio.h>

#include "stack_dump.h"


int main()
{
    st_t st = {};
    st_ctor(&st, 7);

    st_push(&st, 10);
    st_push(&st, 40);
    //st.data[st.capacity + 1] = 0;
    //st.size = st.capacity-1;
    // if error occurred should we continue working?
    st_error error = st_push(&st, 30);
    st_dump(&st);
    //printf("%d %d\n", error, no_error);



    return 0;
}
