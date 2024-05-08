#ifndef SHAPER_H
#define SHAPER_H

#include "data_structs.h"


typedef struct Shape {
    int dimensions_nb;
    long* dimensions; 
    void* data;
    long length;
    DataType data_type;
} Shape;



Shape* shape_zeros(int, long*, DataType );
Shape* shape_values(int, long*, void*, DataType);
Shape* shape_ones(int ,long*, DataType);


void free_shape(Shape* shape);

#endif /* SHAPER_H */


