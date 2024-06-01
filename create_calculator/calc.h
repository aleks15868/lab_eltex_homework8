#ifndef MY_CALC_C
#define MY_CALC_C

#define NAME_LENGTH 30
#define PATH_LENGTH 255

typedef struct
{
    char Name_Menu[NAME_LENGTH];
    char Name_Function[NAME_LENGTH];
    char Name_Path[PATH_LENGTH];

}information_plugins;

float calc_result(char* pyth_plagin, char* name_function, float Number_One, float Number_Two);

#endif