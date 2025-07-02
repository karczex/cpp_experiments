#include <stdio.h>
#include "mylib.h"

// A function that takes a callback as a parameter
void process(int value, CallbackFunction callback) {
    printf("Processing value: %d\n", value);
    callback(value);  // Call the callback function
}

