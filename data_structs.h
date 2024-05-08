#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H

#define SUPPORTED_DATA_TYPES 3 

int shaper_type_sizes[SUPPORTED_DATA_TYPES] = { 
    sizeof(int),
    sizeof(float),
    sizeof(double),
};

typedef union DataNode {
    int int_val;
    float float_val;
    double double_val; 
} DataNode;


typedef enum DataType {
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
} DataType;



static DataNode* read_int_value(void*);
static DataNode* read_float_value(void*);
static DataNode* read_double_value(void*);


DataNode* (*shaper_type_readers[SUPPORTED_DATA_TYPES])(void*) = {
  read_int_value,
  read_float_value,
  read_double_value,
};


static void* populate_int_values(void* mem_start, long length, DataNode value);
static void* populate_float_values(void* mem_start, long length, DataNode value);
static void* populate_double_values(void* mem_start, long length, DataNode value);


void* (*shaper_populete_values[SUPPORTED_DATA_TYPES])(void* mem_start, long length, DataNode value) = {
    populate_int_values, 
    populate_float_values, 
    populate_double_values,
};




#endif /* DATA_STRUCTS_H */
