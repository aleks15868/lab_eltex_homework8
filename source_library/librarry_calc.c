#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdlib.h>

float calc_result(char* pyth_plagin, char* name_function, float Number_One, float Number_Two){
    float result;
    void *handle = dlopen(pyth_plagin, RTLD_LAZY);
    if (handle == NULL) {
        perror("Null path indicator(dlopen)");
        exit(1);
    }
    // Получение указателя на функцию my_function
    float (*my_function_ptr)(float, float) = dlsym(handle, name_function);
    if (my_function_ptr == NULL) {
        perror("Null path indicator(dlsym)");
        dlclose(handle);
        exit(1);
    }
     // Вызов функции из библиотеки
    result = my_function_ptr(Number_One, Number_Two);

    // Закрытие библиотеки
    dlclose(handle);
    return result;
}