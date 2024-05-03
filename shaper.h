#ifndef SHAPER_H
#define SHAPER_H
#include "data_types.h"


typedef struct Shape {
    int nb_of_dimensions;
    int* dimensions; 
    void* values;
    int nb_of_values;
    DataType data_type;
} Shape;



Shape* shape(int nb_of_dimensions, int* dimensions, void* vales, DataType data_type);
Shape* shape_zeros(int dimensions, int* sizes, DataType data_type);
Shape* shape_value(int dimensions, int* sizes, void* valuePtr, DataType data_type);
Shape* shape_ones(int dimensions, int* sizes, DataType data_type);


void free_shape(Shape* shape);

#endif /* SHAPER_H */


