

#define SUPPORTED_DATA_TYPES 3 


typedef union DataNode {
    int int_val;
    float float_val;
    char double_val; 
} DataNode;


typedef enum DataType {
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
} DataType;


int SHAPER_TYPE_SIZES[SUPPORTED_DATA_TYPES] = {sizeof(int), sizeof(float), sizeof(double)};

double (*SHAPER_TYPE_PARSERS[SUPPORTED_DATA_TYPES])(void*) = {
  read_int_value,
  read_float_value,
  read_double_value,
};

static DataNode* read_int_value(void* ptr);
static DataNode*  read_float_value(void* ptr);
static DataNode* read_double_value(void* ptr);
