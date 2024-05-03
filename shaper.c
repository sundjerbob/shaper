#include "shaper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



static Shape* create_empty_shape(DataType data_type)
{
    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    
    if (new_shape == NULL)
        return NULL;

    new_shape->data_type = data_type;
    new_shape->nb_of_dimensions = 0;
    new_shape->nb_of_values = 0;

    return new_shape;
}   



static Shape* shape_dimensions(Shape* shape, int nb_of_dimensions, int* dimensions)
{
    if (shape == NULL)
        return NULL;

    shape->dimensions = malloc(nb_of_dimensions * sizeof(int));

    if (shape->dimensions == NULL)
        return NULL;

    memcpy(shape->dimensions, dimensions, nb_of_dimensions * sizeof(int));

    return shape;
}




static int shape_total_length(Shape* shape)
{
    int nb_of_values = 1;
    for (int i = 0; i < shape->nb_of_dimensions; i++)
    {
        nb_of_values *= shape->dimensions[i];
    }
    return nb_of_values;
}




    
static Shape* shape_values_to_zero(Shape* shape) {
    
    if (
        shape == NULL || 
        shape->nb_of_dimensions < 1 ||
        shape->dimensions == NULL
        )
        return NULL;

    shape->values = calloc(shape->nb_of_values, SHAPER_TYPE_SIZES[shape->data_type]);
    return shape;
}




static void free_shape(Shape* shape)
{
    if (shape == NULL) return;

    if (shape->dimensions != NULL) free(shape->dimensions);

    if (shape->values != NULL) free(shape->values);

    free(shape);
}

static  






static Shape* shape(int nb_of_dimensions, int* dimensions, void* values, DataType data_type) {
   
    Shape* shape = create_empty_shape(data_type);
    
    if (shape == NULL) return NULL;

    if (shape_dimensions(shape, nb_of_dimensions, dimensions) == NULL)
    {
        shaper_free_shape(shape);
        return;
    }

    return shape;
}






Shape* shape_rand(int dimensions, int* sizes, DataType data_type) {

    int total_elements = 1;
    for (int i = 0; i < dimensions; i++) {
        total_elements *= sizes[i];
    }

    void* values;
    switch (data_type) {
    case INT_TYPE:
        values = malloc(total_elements * sizeof(int));
        if (values == NULL) {
            return NULL; 
        }

        for (int i = 0; i < total_elements; i++) {
            ((int*)values)[i] = rand(); 
        }
        break;
    case FLOAT_TYPE:
        values = malloc(total_elements * sizeof(float));
        if (values == NULL) {
            return NULL; 
        }

        for (int i = 0; i < total_elements; i++) {
            ((float*)values)[i] = ((float)rand() / RAND_MAX) * 100.0f; 
        }
        break;
    case DOUBLE_TYPE:
        values = malloc(total_elements * sizeof(double));
        
        if (values == NULL) {
            return NULL; 
        }

        for (int i = 0; i < total_elements; i++) {
            ((double*)values)[i] = ((double)rand() / RAND_MAX) * 100.0; 
        }

        break;

    default:

        return NULL; 
    }

    return shape(dimensions, sizes, values, data_type);
}

Shape* shape_zeros(int dimensions, int* sizes, DataType data_type) {

    int total_elements = 1;

    for (int i = 0; i < dimensions; i++) {
        total_elements *= sizes[i];
    }

    void* values;
    
    switch (data_type) {
    
        case INT_TYPE:
            values = calloc(total_elements, sizeof(int));
            break;

        case FLOAT_TYPE:
            values = calloc(total_elements, sizeof(float));
            break;

        case DOUBLE_TYPE:
            values = calloc(total_elements, sizeof(double));
            break;

        default:
            return NULL; 
    }

    return shape(dimensions, sizes, values, data_type);
}



Shape* shape_set_values(int dimensions, int* sizes, DataType data_type, void* valuePtr) {
    
    Shape* shape = shape(dimensions, sizes, NULL, data_type);
    if (shape == NULL) {
        return NULL; // Shape creation failed
    }

    // Calculate the total number of elements
    int total_elements = 1;
    for (int i = 0; i < dimensions; i++) {
        total_elements *= sizes[i];
    }

    switch (data_type) {
    case INT_TYPE:
    case FLOAT_TYPE:
    case DOUBLE_TYPE:
        // Copy the specified value to all elements
        for (int i = 0; i < total_elements; i++) {
            switch (data_type) {
            case INT_TYPE:
                ((int*)shape->values)[i] = *((int*)valuePtr);
                break;
            case FLOAT_TYPE:
                ((float*)shape->values)[i] = *((float*)valuePtr);
                break;
            case DOUBLE_TYPE:
                ((double*)shape->values)[i] = *((double*)valuePtr);
                break;
            }
        }
        break;
    default:
        return NULL; // Unsupported data type
    }

    return shape;
}

Shape* shape_ones(int dimensions, int* sizes, DataType data_type) {

    int total_elements = 1;
   
    for (int i = 0; i < dimensions; i++) {
        total_elements *= sizes[i];
    }

    void* values;

    switch (data_type) 
    {
        case INT_TYPE:
        {
            values = malloc(total_elements * sizeof(int));
         
            if (values == NULL) 
            {
                return NULL;
            }

            for (int i = 0; i < total_elements; i++) {
                ((int*)values)[i] = 1;
            }
            break;
        }
        case FLOAT_TYPE:
        {
            values = malloc(total_elements * sizeof(float));
            
            if (values == NULL) {
                return NULL;
            }
            for (int i = 0; i < total_elements; i++) {
                ((float*)values)[i] = 1.0f;
            }
            break;
        }

        case DOUBLE_TYPE:
        {
            values = malloc(total_elements * sizeof(double));
            if (values == NULL) 
            {
                return NULL; 
            }
            for (int i = 0; i < total_elements; i++) 
            {
                ((double*)values)[i] = 1.0;
            }
            break; 
        }
        
        default:
            return NULL; 
    }

     return shape(dimensions, sizes, values, data_type);
}


