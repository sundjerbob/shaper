#include <stdio.h>
#include "data_structs.h"
#include"shaper.h"



static void *populate_int_values(void* mem_start, long length, DataValue value)
{
    for (long i = 0; i < length; i++)
    {
        ((int*)mem_start)[i] = value.int_val;
    }

    return mem_start;
}

static void* populate_float_values(void* mem_start, long length, DataValue value)
{
    
    for (long i = 0; i < length; i++)
    {
        ((float*)mem_start)[i] = value.float_val;
    }

    return mem_start;
}


static void* populate_double_values(void* mem_start, long length, DataValue value)
{
    
    for (long i = 0; i < length; i++)
    {
        ((double*)mem_start)[i] = value.double_val;
    }

    return mem_start;
}








