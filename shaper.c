#include "shaper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Allocate memory for shape. */ 
static Shape* allocate_shape(int dimensions_nb, long* dimensions, DataType data_type)
{
    if (dimensions < 1) return NULL;

    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    
    if (new_shape == NULL) return NULL;

    shape->dimensions = malloc(shape->dimensions);
    
    if (shape->dimensions == NULL) 
    {
        free_shape(shape);
        return NULL;
    }

    memcpy(shape->dimensions, dimensions, dimensions_nb * sizeof(long));
    new_shape->data_type = data_type;
    new_shape->length = 1;

    for (int i = 0; i < dimensions_nb; i++)
    {
        new_shape->length *= dimensions[i];
    }

    return new_shape;
}   


/* release occupied memory */
static void free_shape(Shape* shape)
{
    if (shape == NULL) return;

    if (shape->dimensions != NULL) free(shape->dimensions);

    if (shape->data != NULL) free(shape->data);

    free(shape);
}



static Shape* shape(int dimensions_nb, long* dimensions, void* data, DataType data_type) {

    Shape* shape = allocate_shape(dimensions_nb, dimensions, data_type);
    if (shape == NULL) return NULL;
    
    size_t data_size = SUPPORTED_DATA_TYPES[shape->data_type] * (size_t)shape->length;
    shape->data = malloc(data_size);

    if(shape->data == NULL) 
    {
        free_shape(shape);
        return NULL;
    }
       
    memcpy(shape->data, data, data_size);
     
    return shape;
}

static Shape *shape_values(int dimensions_nb, long* dimensions, void* value, DataType data_type)
{
    Shape* shape = allocate_shape(dimensions_nb, dimensions, data_type);
    if (shape == NULL) return NULL;

    DataNode data_val = shaper_type_readers[shape->data_type](value);

    shaper_populete_values[shape->data_type](shape->data, shape->length, value);
    
    return shape;
}









