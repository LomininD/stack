// to determine stack data type visit stack_properties.h
#include "stack.h"
#include <stdio.h>


int main()
{
    st_t st = {};
    st_ctor(&st, 5);

    st_push(&st, 10);
    st_push(&st, 40);
    //st.data[0] = 0;
    st.size = st.capacity;
    // if error occurred should we continue working?
    st_error error = st_push(&st, 30);
    //printf("%d %d\n", error, no_error);



    return 0;
}
