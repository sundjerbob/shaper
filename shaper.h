#ifndef SHAPER_H
#define SHAPER_H

#include "data_structs.h"


typedef struct Shape {
    int nb_of_dimensions;
    int* dimensions; 
    void* values;
    int nb_of_values;
    DataType data_type;
} Shape;



Shape* shape(int, int*, void*, DataType);
Shape* shape_zeros(int, int*, DataType );
Shape* shape_value(int, int*, void*, DataType);
Shape* shape_ones(int ,int*, DataType);


void free_shape(Shape* shape);

#endif /* SHAPER_H */


