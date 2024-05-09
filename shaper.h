#ifndef SHAPER_H
#define SHAPER_H

#include "data_structs.h"


typedef struct Shape {
    unsigned int dimensions_nb;
    unsigned long long* dimensions; /* 8bytes */
    void* data;
    size_t length;
    DataType data_type; /* max array length 8bytes */
} Shape;



Shape *shape_zeros(unsigned int, unsigned long long*, DataType);
Shape *shape_values(unsigned int, unsigned long long*, DataValue, DataType);
Shape *shape_ones(unsigned int, unsigned long long*, DataType);
void free_shape(Shape* shape);

#endif /* SHAPER_H */


