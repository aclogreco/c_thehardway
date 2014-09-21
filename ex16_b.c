#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Define the PERSON data structure
typedef struct person {
  char *name;
  int age;
  int height;
  int weight;
} Person;

/*
   This function accepts name, age, height, and weight as parameters and 
   assigns them to a new Person.
*/
Person Person_create(char *name, int age, int height, int weight) {
  Person who;
  
  who.name = strdup(name);
  who.age = age;
  who.height = height;
  who.weight = weight;
  
  return who;
}


/*
   This function takes a Person as input and prints the Person's 
   information to standard output in a neat format.
*/
void Person_print(Person who) {
  // Print the Person's name.
  printf("Name: %s\n", who.name);
  // Print the Person's age.
  printf("\tAge: %d\n", who.age);
  // Print the Person's height.
  printf("\tHeight: %d\n", who.height);
  // Print the Person's weight.
  printf("\tWeight: %d\n", who.weight);
}

/*
   The MAIN function.
*/
int main(int argc, char *argv[]) {
  // make two people structures
  Person joe = Person_create(
	  "Joe Alex", 32, 64, 140);
  Person frank = Person_create(
	  "Frank Blank", 20, 72, 180);
  
  // print them out
  Person_print(joe);
  Person_print(frank);
  
  // make everyone age 20 years and print them again
  printf("\n20 years later...\n\n");
  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;
  Person_print(joe);
  
  frank.age += 20;
  frank.weight += 20;
  Person_print(frank);

  // clean up
  free(joe.name);
  free(frank.name);
  
  return 0;
}
