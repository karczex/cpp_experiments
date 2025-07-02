#include <iostream>
#include <functional>
#include <type_traits>

extern "C" {
#include "mylib.h"
}
// A sample callback function
void myCallback(int result) {
    printf("Callback called with value: %d\n", result);
}

void libraryExecutorWrapper(std::function<void(int)> f){
  const int val{17}; 
  process(val, *f.target<CallbackFunction>());
}

using CallbackFunctionType = std::remove_pointer_t<CallbackFunction>;

void fancyLibraryExecutorWrapper(std::function<CallbackFunctionType>  f){
  const int val{17};
  process(val, *f.target<CallbackFunction>());
}

int main() {
    int number = 42;
    process(number, myCallback);
    libraryExecutorWrapper(myCallback);
    fancyLibraryExecutorWrapper(myCallback);

    return 0;
}

