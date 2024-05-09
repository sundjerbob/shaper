#include "shaper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* iterates through dimensions and multiplys them in order to get total count of elements that can be stored in shapes data array */
static size_t shape_data_length(Shape *shape) {
    if (shape == NULL || shape->dimensions_nb == 0 || shape->dimensions == NULL)
        return 0;

    size_t data_length = SHAPER_TYPES_SIZES[shape->data_type];
    
    for(int i = 0; i < shape->dimensions_nb; i++) data_length *= shape->dimensions[i];
    
    return data_length;
}


/* Allocate memory for shape. */ 
static Shape* allocate_shape(unsigned int dimensions_nb, unsigned long long* dimensions, DataType data_type)
{   
    if (dimensions_nb < 1) return NULL;

    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    if (new_shape == NULL) return NULL;

    new_shape->dimensions_nb = dimensions_nb;
    new_shape->data_type = data_type;
    new_shape->length = shape_data_length(new_shape);

    if (new_shape->dimensions = malloc(new_shape->length) == NULL) { free(new_shape);  return NULL; }
    memcpy(new_shape->dimensions, dimensions, new_shape->dimensions_nb * sizeof(unsigned long long));

    new_shape->length = shape_data_length(new_shape);
    
    return new_shape;
}   


/**/
static Shape *shape(unsigned int dimensions_nb, long *dimensions, void *data, DataType data_type) {

    Shape* shape = allocate_shape(dimensions_nb, dimensions, data_type);
    if (shape == NULL) return NULL;
    
    size_t data_size = (size_t)SHAPER_TYPES_SIZES[shape->data_type] * shape->length;
    shape->data = malloc(data_size);

    if(shape->data == NULL) 
    {
        free_shape(shape);
        return NULL;
    }

    memcpy(shape->data, data, data_size);
    return shape;
}


/**/
static Shape *shape_values(unsigned int dimensions_nb, unsigned long long *dimensions, DataValue value, DataType data_type)
{
    if (data_val_is_zero(value))
        return shape_zeros(dimensions_nb, dimensions, data_type);

    Shape* shape = allocate_shape(dimensions_nb, dimensions, data_type);
    if (shape == NULL) return NULL;
    
    populate_data_fn[shape->data_type](shape->data, shape->length, value);

    return shape;
}


static Shape *shape_zeros(unsigned int dimensions_nb, unsigned long long* dimensions, DataType data_type)
{
    Shape* shape = allocate_shape(dimensions_nb, dimensions, data_type);
    if (shape == NULL) return NULL;
    
    if (shape->data = calloc(shape->length, SHAPER_TYPES_SIZES[shape->data_type]) == NULL) { free_shape(shape); return NULL; }
    
    return shape;
}

static Shape *shape_ones(unsigned int dimensions_nb, unsigned long long* dimensions, DataType data_type)
{
    switch (data_type) 
    {
        case INT_TYPE:
            return shape_values(dimensions_nb, dimensions, (DataValue) { .int_val = 1 }, data_type);
        
        case FLOAT_TYPE:
            return shape_values(dimensions_nb, dimensions, (DataValue) { .float_val = 1.0f }, data_type);
        
        case DOUBLE_TYPE: 
            return shape_values(dimensions_nb, dimensions, (DataValue) { .double_val = 1.0 }, data_type);
    }

    return NULL;
}

static int data_val_is_zero(DataValue value) {
    return value.int_val == 0 && value.float_val == 0.0f && value.double_val == 0.0;
}



/* release occupied memory */
static void free_shape(Shape *shape)
{
    if (shape == NULL) return;

    if (shape->dimensions != NULL) free(shape->dimensions);

    if (shape->data != NULL) free(shape->data);

    free(shape);
}





