#include <stdio.h>
#include "data_structs.h"
#include"shaper.h"



static DataNode* read_int_value(void* ptr) {
    
    int* int_ptr = (int*)ptr;

    if (ptr == NULL) 
        return NULL; 

    DataNode* node = malloc(sizeof(DataNode));

    if (node == NULL) 
        return NULL; 

    node->int_val = *int_ptr;  
    return node;
}


static DataNode* read_float_value(void* ptr) {
    float* float_ptr = (float*)ptr;

    if (ptr == NULL) 
        return NULL;

    DataNode* node = malloc(sizeof(DataNode));

    if (node == NULL) 
        return NULL; 

    node->float_val = *float_ptr;  
    return node;
}

static DataNode* read_double_value(void* ptr) {
    
    double* double_ptr = (double*)ptr;
    
    if (ptr == NULL) {
        return NULL; 
    }

    DataNode* node = malloc(sizeof(DataNode));
    
    if (node == NULL) {
        return NULL; 
    }

    node->double_val = *double_ptr; 
    
    return node;
}

static void *populate_int_values(void* mem_start, long length, DataNode value)
{
    
    for (long i = 0; i < nb_of_values; i++)
    {
        ((*int)memory_start)[i] = value->int_val;
    }

    return memory_start;
}

static void* populate_float_values(void* mem_start, long length, DataNode value)
{

    for (long i = 0; i < nb_of_values; i++)
    {
        ((*float)memory_start)[i] = value->float_val;
    }

    return memory_start;
}


static void* populate_double_values(void* mem_start, long length, DataNode value)
{
    for (long i = 0; i < nb_of_values; i++)
    {
        ((*double)memory_start)[i] = value->double_val;
    }

    return memory_start;
}








