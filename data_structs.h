#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H

#define DATA_TYPES_NB 3 

int SHAPER_TYPES_SIZES[DATA_TYPES_NB] = {
    sizeof(int),
    sizeof(float),
    sizeof(double),
};


typedef enum DataType {
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
} DataType;


typedef union DataValue {
    int int_val;
    float float_val;
    double double_val;
} DataValue;


static void* populate_int_values(void* mem_start, size_t length, DataValue value);
static void* populate_float_values(void* mem_start, size_t length, DataValue value);
static void* populate_double_values(void* mem_start, size_t length, DataValue value);


 void* (*populate_data_fn[DATA_TYPES_NB])(void* mem_start, size_t length, DataValue value) = {
    populate_int_values, 
    populate_float_values, 
    populate_double_values,
};


#endif /* DATA_STRUCTS_H */
