#include "tracer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new ShaperTracer object
ShaperTracer* debug_tracer_create(DebugLevel debug_level) {
    // Allocate memory for the ShaperTracer structure
    ShaperTracer* tracer = (ShaperTracer*)malloc(sizeof(ShaperTracer));
    if (tracer == NULL) {
        return NULL; // Memory allocation failed
    }
    // Set the debug level
    tracer->level = debug_level;
    // Initialize the head pointer to NULL
    tracer->head = NULL;
    return tracer;
}

// Function to free memory allocated for a ShaperTracer object
void shaper_tracer_free(ShaperTracer* tracer) {
    // Clear the list of operation logs
    shaper_tracer_clear(tracer);
    // Free the memory allocated for the tracer structure
    free(tracer);
}

// Function to add a log with only code to the tracer
void shaper_tracer_add_log(ShaperTracer* tracer, int code) {
    // Create a new operation log
    OperationLog* log = (OperationLog*)malloc(sizeof(OperationLog));
    if (log == NULL) {
        return; // Memory allocation failed
    }
    // Set the error code
    log->code = code;
    // Set the next pointer to NULL
    log->next = NULL;

    // Append the new log to the end of the linked list
    if (tracer->head == NULL) {
        tracer->head = log; // The new log becomes the head if the list is empty
    }
    else {
        // Traverse the list to find the last node
        OperationLog* current = tracer->head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Append the new log to the end of the list
        current->next = log;
    }
}

// Function to add a log with message and code to the tracer
void shaper_tracer_add_log(ShaperTracer* tracer, const char* message, int code) {
    // Only add the log if the debug level allows it
    if (tracer->level != LOG_ERR_ONLY) {
        // Print the message if the debug level allows it
        if (tracer->level == LOG_100000) {
            printf("%s\n", message);
        }
        // Add the log to the tracer
        shaper_tracer_add_log(tracer, code);
    }
}

// Function to print the list of operation logs
void shaper_tracer_print(ShaperTracer* tracer) {
    printf("Operation logs:\n");
    OperationLog* current = tracer->head;
    while (current != NULL) {
        printf("Code: %d\n", current->code);
        current = current->next;
    }
}

// Function to clear the list of operation logs
void shaper_tracer_clear(ShaperTracer* tracer) {
    OperationLog* current = tracer->head;
    while (current != NULL) {
        OperationLog* temp = current;
        current = current->next;
        free(temp);
    }
    // Reset the head pointer to NULL
    tracer->head = NULL;
}
