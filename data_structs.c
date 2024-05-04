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

static void* populate_int_values(void* memory_start, int nb_of_values, DataNode* value) 
{
    int populate_val = value->int_val;

    int* int_ptr = (int*)memory_start;
    
    for (int i = 0; i < nb_of_values; i++, int_ptr++)
    {
        *int_ptr = populate_val;
    }

    return memory_start;
}

static void* populate_float_values(void* memory_start, int nb_of_values, DataNode* value)
{
    float populate_val = value->float_val;

    float* float_ptr = (float*)memory_start;

    for (int i = 0; i < nb_of_values; i++, *float_ptr++)
    {
        *float_ptr = populate_val;
    }

    return memory_start;
}


static void* populate_double_values(void* memory_start, int nb_of_values, DataNode* value)
{
    double populate_val = value->double_val;

    double* double_ptr = (double*)memory_start;

    for (int i = 0; i < nb_of_values; i++, double_ptr++)
    {
        *double_ptr = populate_val;
    }

    return memory_start;
}








