#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include "calc.h"

#define COUT_PLAGIN 4

int main(void) {
  information_plugins Array_Plugin_Menu[COUT_PLAGIN]={
    {"Addition","add","./plugin/add.so"},
    {"Subtraction","sub","./plugin/subtraction.so"},
    {"Multiplication","mul","./plugin/multiplication.so"},
    {"Division","division","./plugin/division.so"}
  };
  float Number_One, Number_Two;
  int choice;
  char buffer[5];
  if (COUT_PLAGIN != 0){
    while (1) { // Endless cycle
    printf("\nMenu:\n");
    for(int i = 0; i<COUT_PLAGIN; i++){
       printf("%d) %s\n", i+1, Array_Plugin_Menu[i].Name_Menu);
    }
    printf("%d) Exit\n", COUT_PLAGIN+1);
    printf("Input: ");

    fgets(buffer, sizeof(buffer), stdin);
    choice = atoi(buffer);
    if (choice == COUT_PLAGIN+1) {
      printf("Exit from the menu.\n");
      break; // Interruption of the cycle
    } else if (choice >= 1 && choice <= COUT_PLAGIN) {
      printf("Number one:");
      fgets(buffer, sizeof(buffer), stdin);
      Number_One = strtof(buffer, NULL);
      // Number Buffer
      memset(buffer, 0, sizeof(buffer));

      printf("Number two:");
      fgets(buffer, sizeof(buffer), stdin);
      Number_Two = strtof(buffer, NULL);
      // Number Buffer
      memset(buffer, 0, sizeof(buffer));
      printf("Result %s:%.4f.\n", Array_Plugin_Menu[choice-1].Name_Menu, 
      calc_result(Array_Plugin_Menu[choice-1].Name_Path, Array_Plugin_Menu[choice-1].Name_Function,
      Number_One,Number_Two));
    } else {
      printf("The wrong choice.\n");
    }
  }
  }
  else{
    printf("The plugins were not selected or you did not change COUT_PLAGIN.\n");
  }
  return 0;
}