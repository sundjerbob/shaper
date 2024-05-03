#include <stdio.h>
#include "data_types.h"

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
