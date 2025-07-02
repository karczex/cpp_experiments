#ifndef MYLIB_H
#define MYLIB_H


// Define a callback function type
typedef void (*CallbackFunction)(int);

void process(int value, CallbackFunction callback);

void say_hello();

#endif
