#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;
  
  // go through each string in argv
  for (i = 0; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }
  
  // our own array of strings
  char *states[] = {
    "California", "Oregon", "Washington",
    "Texas", "Pennsylvania", NULL
  };
  int num_states = 6;
  
  for (i = 0; i < num_states; i++) {
    printf("state %d: %s\n", (i+1), states[i]);
  }
  
  return 0;
}
