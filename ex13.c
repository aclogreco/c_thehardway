#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: You need at least one argument.\n");
    return 1;
  }
  
  int i, n;
  char letter;

  for (n = 1; n < argc; n++) {
    for (i = 0, letter = '\0'; argv[n][i] != '\0'; i++) {
      letter = argv[n][i];
      letter |= 32;
      
      switch (letter) {
      case 'a':
	printf("%d: 'A'\n", i);
	break;
	
      case 'e':
	printf("%d: 'E'\n", i);
	break;
	
      case 'i':
	printf("%d: 'I'\n", i);
	break;
      
      case 'o':
	printf("%d: 'O'\n", i);
	break;
	
      case 'u':
	printf("%d: 'U'\n", i);
	break;
	
      case 'y':
	if (i > 0) {
	  printf("%d: 'Y'\n", i);
	}
	break;
	
      default:
	letter &= ~(32);
	printf("%d: %c is not a vowel\n", i, letter);
      }
    }

    printf("\n");
  }

  return 0;
}
