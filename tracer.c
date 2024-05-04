#include "tracer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ShaperTracer* debug_tracer_create(DebugLevel debug_level) {
    ShaperTracer* tracer = (ShaperTracer*)malloc(sizeof(ShaperTracer));
    if (tracer == NULL) {
        return NULL; 
    }
    tracer->level = debug_level;
    tracer->head = NULL;
    return tracer;
}

void shaper_tracer_free(ShaperTracer* tracer) {
    shaper_tracer_clear(tracer);
    free(tracer);
}

void shaper_tracer_add_log(ShaperTracer* tracer, int code) {
    OperationLog* log = (OperationLog*)malloc(sizeof(OperationLog));
    if (log == NULL) {
        return; 
    }
    log->code = code;
    log->next = NULL;

    if (tracer->head == NULL) {
        tracer->head = log; 
    }
    else {
        OperationLog* current = tracer->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = log;
    }
}

void shaper_tracer_add_log(ShaperTracer* tracer, const char* message, int code) {
    if (tracer->level != LOG_ERR_ONLY) {
        if (tracer->level == LOG_100000) {
            printf("%s\n", message);
        }
        shaper_tracer_add_log(tracer, code);
    }
}

void shaper_tracer_print(ShaperTracer* tracer) {
    printf("Operation logs:\n");
    OperationLog* current = tracer->head;
    while (current != NULL) {
        printf("Code: %d\n", current->code);
        current = current->next;
    }
}

void shaper_tracer_clear(ShaperTracer* tracer) {
    OperationLog* current = tracer->head;
    while (current != NULL) {
        OperationLog* temp = current;
        current = current->next;
        free(temp);
    }
    tracer->head = NULL;
}
