#include <stdio.h>
#include <ctype.h>
#include <string.h>

// foward declarations
//int can_print_it(char ch);
void print_letters(int len, char arg[]);

void print_arguments(int argc, char *argv[]) {
  int i = 0;
  int s_len = 0;

  for (i = 0; i < argc; i++) {
    s_len = strlen(argv[i]);
    print_letters(s_len, argv[i]);
  }
}

void print_letters(int len, char arg[]) {
  int i = 0;
  
  //for (i = 0; arg[i] != '\0'; i++) {
  for (i = 0; i < len; i++) {
    char ch = arg[i];
    
    //if (can_print_it(ch)) {
    if (isprint(ch)) {
      printf("'%c' == %d ", ch, ch);
    }
  }
  
  printf("\n");
}

//int can_print_it(char ch) {
//  return isalpha(ch) || isblank(ch);
//}

int main(int argc, char *argv[]) {
  print_arguments(argc, argv);
  return 0;
}
