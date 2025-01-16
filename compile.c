#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define INITIAL_BUFFER_SIZE 1024

char *read_file(const char *filename);

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    char *content = read_file(filename);

    if (content == NULL) {
        fprintf(stderr, "Failed to read file: %s\n", filename);
        return 1;
    }

    printf("%s\n", content);
    free(content); // Free the allocated memory
    return 0;
}

char *read_file(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return NULL;
    }

    size_t buffer_size = INITIAL_BUFFER_SIZE;
    char *content = malloc(buffer_size);
    if (content == NULL) {
        perror("Error allocating memory");
        fclose(fptr);
        return NULL;
    }

    size_t length = 0;
    int current;
    while ((current = fgetc(fptr)) != EOF) {
        if (length + 1 >= buffer_size) {
            buffer_size *= 2;
            char *new_content = realloc(content, buffer_size);
            if (new_content == NULL) {
                perror("Error reallocating memory");
                free(content);
                fclose(fptr);
                return NULL;
            }
            content = new_content;
        }
        content[length++] = current;
    }
    content[length] = '\0'; // Null-terminate the string

    fclose(fptr);
    return content;
}
