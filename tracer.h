#ifndef TRACER_H
#define TRACER_H

#define MAX_ERROR_CODES 10

typedef struct OperationLog {
    int code;                   
    struct OperationLog* next;
} OperationLog;

typedef enum {
    SUCCESS,
    INVALID_DIMENSIONS,
} ProcessCode;

typedef enum {
    LOG_100000,
    LOG_1000,
    LOG_ERR_ONLY

} DebugLevel;


typedef struct {
    DebugLevel level;
    OperationLog* head;
} ShaperTracer;

static const char* process_messages[MAX_ERROR_CODES] = {
    "Success",
    "Invalid dimensions"
};

ShaperTracer* debug_tracer_create(DebugLevel debug_level);

void shaper_tracer_free(ShaperTracer* tracer);

void shaper_tracer_add_log(ShaperTracer* tracer, int code);

void shaper_tracer_add_log(ShaperTracer* tracer, const char* message, int code);

char** get_stack_trace(ShaperTracer* tracer);

void shaper_tracer_print(ShaperTracer* tracer);

void shaper_tracer_clear(ShaperTracer* tracer);

#endif /* TRACER_H */
