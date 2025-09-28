#include "stack.h"
#include "stack_dump.h"


void st_ctor (st_t* st, size_t capacity)
{

    assert(st != NULL);

    if(capacity == 0)
    {
        printf(MAKE_BOLD("WARNING:") " stack of 0 elements is not usable");
    }

    st->data = (st_data_type*) calloc (capacity + 2, sizeof(st_data_type));

    assert(st->data != NULL);

    st->size = 0;
    st->capacity = capacity;
    st->error = no_error;

    //setting up canary protection
    st->data[0] = canary_value;
    st->data[capacity + 1] = canary_value;

    // verify
}


st_error st_push (st_t* st, st_data_type value)
{
    //CHECK_STACK(st);

    if (!st_verify(st))
        return any_error;

    assert(st->size != st->capacity);

    st->data[st->size + 1] = value;
    st->size++;

    if (!st_verify(st))
        return any_error;

    return no_error;
}


st_data_type st_pop (st_t* st)
{
    if(st_verify(st))
    {
        assert(st->size != 0);

        return st->data[--(st->size) + 1];

        if (st_verify(st))
            return no_error;

        return any_error;
    }
    return any_error;
}


st_data_type st_dtor (st_t* st)
{
    if(st_verify(st))
    {
        free(st->data);

        if (st_verify(st))
            return no_error;
        return any_error;
    }
    return any_error;
}
