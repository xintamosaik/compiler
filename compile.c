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
  fptr = fopen(argv[1], "r");
  // If the file exist
  if (fptr == NULL)
  {
    fprintf(stderr, "%s", "file does not exist");
    return 1;
  }

  // Store the content of the file
  char content[1024 * 8];
  int i = 0;
  char current;
  // Read the content and print it
  while ((current = fgetc(fptr)) != EOF)
  {
    content[i++] = current;
  }
  content[i++] = '\0';
  printf("%s", content);

  // Close the file
  fclose(fptr);
  return 0;
}
