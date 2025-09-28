#include "stack_dump.h"


// verifier looks for errors
verifier_output st_verify(st_t* st)
{
    int found_errors = 0;

    if (st == NULL)
    {
        st_dump(st);
        return not_verified;
    }

    if (st->size > st->capacity)
    {
        st->error = stack_overflow;
        found_errors += 1;
    }

    if (st->data == NULL)
    {
        st->error = no_data;
        st_dump(st);
        return not_verified;
    }

    // pay attention to if order: some checks may be impossible

    if (st->data[0] != canary_value || st->data[st->capacity + 1] != canary_value)
    {
        st->error = canary_fault;
        found_errors += 1;
    }

    if (found_errors == 0)
    {
        return verified ;
    }
    else
    {
        st_dump(st);
        //printf("error num %d\n", found_errors);
        return not_verified;
    }
}


// dump checks if any errors were registered and sends log
void st_dump(st_t* st)
{
    printf("-----------------------------------------------------------\n");

    if (st == NULL)
    {
        printf(MAKE_BOLD_RED("ERROR:") " stack not found (got NULL pointer)\n");
    }
    else
    {
        if (st->error == no_data)
        {
            printf(MAKE_BOLD_RED("ERROR:") " stack data not found (got NULL pointer)\n\n");
        }
        if (st->error == canary_fault)
        {
            printf(MAKE_BOLD_RED("UNAUTHORIZED ACCESS TO DATA:") " canary protection triggered\n\n");
            // TODO: print part of stack
            // TODO: switch and add function
            // TODO: print canaries
            // if canary protection triggered should we print data in dump?
        }
        if (st->error == stack_overflow)
        {
            printf(MAKE_BOLD_RED("ERROR:") " stack overflow\n\n");
        }

        print_st_info(st);
        print_st_data(st);

        printf("}\n");
    }

    printf("-----------------------------------------------------------\n");
}


void print_st_info(st_t* st)
{

    if (st != NULL)
    {
        printf(MAKE_BOLD("stack") "  [%p]\n", st);
        printf("{\n");
        printf("\tsize = %zu\n", st->size);
        printf("\tcapacity = %zu\n\n", st->capacity);
    }
    else
    {
        printf(MAKE_BOLD("stack") "  [not found]\n");
    }
}


void print_st_data(st_t* st)
{
    assert(st != NULL);

    if (st->data != NULL)
        {
            printf("\tdata  [%p]\n", st->data);
            printf("\t{\n");

            printf(MAKE_GREY("\t\t [0] = %d (canary protection)\n"), st->data[0]);

            if (st->error != stack_overflow)
            {
                for (int i = 0; i < st->size; i++)
                {
                    printf("\t\t*[%d] = %d\n", i + 1, st->data[i+1]); // TODO: print_el
                }

                for (int i = st->size; i < st->capacity; i++)
                {
                    printf("\t\t [%d] = [empty]\n", i + 1); // TODO: print_el
                }
            }
            else
            {
                for (int i = 0; i < st->capacity; i++)
                {
                    printf("\t\t?[%d] = %d\n", i + 1, st->data[i+1]); // TODO: print_el
                }
            }

            printf(MAKE_GREY("\t\t [%zu] = %d (canary protection)\n"), st->capacity + 1, st->data[st->capacity+1]);

            printf("\t}\n");
        }
        else
        {
            printf("\tdata  [not found]\n");
        }
}


size_t max(size_t a, size_t b)
{
    if (a > b)
        return a;
    return b;
}

size_t min(size_t a, size_t b)
{
    if (a < b)
        return a;
    return b;
}
