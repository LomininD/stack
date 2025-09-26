typedef int st_data_type;
#include "stack.h"

#include <stdio.h>


int main()
{
    st_t st = {};
    st_ctor(&st, 5);

    st_push(&st, 10);
    st_push(&st, 40);
    //st.data[0] = 0;
    // if error occured should we continue working?
    st_error error = st_push(&st, 30);

    if (error == no_error)
        st_pop(&st);

    for (int i = 0; i < 2; i++)
    {
        printf("el %d: %d\n", 2-i, st_pop(&st)); // %?
    }

    return 0;
}
