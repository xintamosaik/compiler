#include <stdio.h>

int main(int argc, char const *argv[])
{
  if (argc == 1)
  {
    fprintf(stderr, "%s", "No filename to work with!");
    return 1;
  }
  if (argc == 2)
  {
    puts(argv[0]);
    puts(argv[1]); // filename
  }

  FILE *fptr;

  // Open a file in read mode
  fptr = fopen("cheapy.md", "r");
  // If the file exist
  if (fptr == NULL)
  {
    fprintf(stderr, "%s", "file does not exist");
    
    return 1;
  }

  // Store the content of the file
  char myString[100];
      // Read the content and print it
    while(fgets(myString, 100, fptr)) {
      printf("%s", myString);
    }
  // Print the file content
  printf("%s", myString);
  // Close the file
  fclose(fptr);
  return 0;
}
