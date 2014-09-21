#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Define the PERSON data structure
struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

/*
   This function returns a pointer to a newly created Person. This function 
   accepts name, age, height, and weight as parameters and assigns them to the 
   new Person.
*/
struct Person* Person_create(char *name, int age, int height, int weight) {
  // Allocate memory for the new Person.
  struct Person *who = malloc(sizeof(struct Person));
  // Check if the memory was allocated, if not, throw an error.
  assert(who != NULL);
  
  /* Assign the name parameter to the name component using the strdup function
     to allocate memory and make a copy of the string.  */
  who->name = strdup(name);
  // Assign the age parameter to the age component.
  who->age = age;
  // Assign the height parameter to the height component.
  who->height = height;
  // Assing the weight parameter to the weight component.
  who->weight = weight;
  
  // Return the pointer to the newly created and filled out Person structure.
  return who;
}

/*
   This function deallocates the memory being used by the Person structure 
   that the who parameter points to.
*/
void Person_destroy(struct Person *who) {
  // Check if the pointer is actually pointing to something.
  assert(who != NULL);
  
  // Free the memory being used by the name component of the Person.
  free(who->name);
  // Free the rest of the memory being used by the Person.
  free(who);
}

/*
   This function takes a pointer to a Person as input and prints the Person's 
   information to standard output in a neat format.
*/
void Person_print(struct Person *who) {
  // Print the Person's name.
  printf("Name: %s\n", who->name);
  // Print the Person's age.
  printf("\tAge: %d\n", who->age);
  // Print the Person's height.
  printf("\tHeight: %d\n", who->height);
  // Print the Person's weight.
  printf("\tWeight: %d\n", who->weight);
}

/*
   The MAIN function.
*/
int main(int argc, char *argv[]) {
  // make two people structures
  struct Person *joe = Person_create(
	  "Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create(
	  "Frank Blank", 20, 72, 180);
  
  // print them out where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);
  
  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);
  
  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);
  
  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // destroy them both so we clean up
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}
