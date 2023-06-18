#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file> <search_string>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *search_string = argv[2];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }

    int line_number = 1;
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_string)) {
            printf("%d: %s", line_number, buffer);
        }
        line_number++;
    }

    fclose(fp);
    return 0;
}