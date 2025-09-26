#ifndef STACK_DUMP_H
#define STACK_DUMP_H


#include <stdio.h>
#include <assert.h>

#include "font_styles.h"
#include "stack_info.h"


enum verifier_output
{
    not_verified = 0,
    verified = 1
};


void st_dump(st_t* st);
verifier_output st_verify(st_t* st);


// verifier looks for errors
verifier_output st_verify(st_t* st)
{
    int found_errors = 0;

    if (st == NULL)
    {
        st_dump(st);
        return not_verified;
    }

    // pay attention to if order: some checks may be impossible
    // should check size and capacity here

    if (st->data[0] != canary_value || st->data[st->capacity - 1] != canary_value)
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
        return not_verified;
    }
}


// dump checks if any errors were registered and sends log
void st_dump(st_t* st)
{
    printf("-----------------------------------------------------------\n");

    if (st == NULL)
    {
        printf(MAKE_BOLD_RED("ERROR:") " no such stack existed (got NULL pointer)\n");
    }
    else
    {
        if (st->error == canary_fault)
        {
            printf(MAKE_BOLD_RED("UNAUTHORIZED ACCESS TO DATA:") " canary protection triggered\n\n");
            // TODO: move to bottom
        }
        printf(MAKE_BOLD("stack") "  [%p]\n", st);
        printf("{\n");
        printf("\tsize = %d\n", st->size);
        printf("\tcapacity = %zu\n\n", st->capacity);
        printf("\tdata  [%p]\n", st->data);
        printf("\t{\n");

        for (int i = 0; i < st->size; i++)
        {
            printf("\t\t*[%d] = %d\n", i, st->data[i+1]); // print_el
        }

        for (int i = st->size; i < st->capacity; i++)
        {
            printf("\t\t [%d] = [empty]\n", i); // print_el
        }

        printf("\t}\n");
        printf("}\n");
    }

    printf("-----------------------------------------------------------\n");
}


#endif
