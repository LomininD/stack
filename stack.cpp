#include "stack.h"
#include "stack_dump.h"


st_return_err st_ctor (st_t* st, size_t capacity)
{
    assert(st != NULL);

    if(capacity == 0)
    {
        printf(MAKE_BOLD("WARNING:") " stack of 0 elements is not usable\n");
    }

    st->data = (st_data_type*) calloc (capacity + 2, sizeof(st_data_type));

    assert(st->data != NULL);

    st->size = 0;
    st->capacity = capacity;
    st->error = (st_error) 0;

    //setting up canary protection
    st->data[0] = canary_value;
    st->data[capacity + 1] = canary_value;

    CHECK_STACK(st);

    return no_error;
}


st_return_err st_push (st_t* st, st_data_type value)
{
    CHECK_STACK(st);

    assert(st->size != st->capacity);

    st->data[st->size + 1] = value;
    st->size++;

    CHECK_STACK(st);

    return no_error;
}


st_data_type st_pop (st_t* st)
{
    CHECK_STACK(st);

    assert(st->size != 0);

    return st->data[--(st->size) + 1];

    CHECK_STACK(st);
}


st_return_err st_dtor (st_t* st)
{
    CHECK_STACK(st);

    free(st->data);

    return no_error;
}
