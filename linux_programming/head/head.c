#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_COUNT 10

int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: head <file>\n");
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Read and print the first MAX_LINE_COUNT lines of the file
    char line[256];
    int line_count = 0;
    while (fgets(line, sizeof(line), file) != NULL && line_count < MAX_LINE_COUNT) {
        printf("%s", line);
        line_count++;
    }

    // Close the file
    fclose(file);

    return 0;
}
