#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }
    int line_number = 1;
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%d: %s", line_number++, buffer);
    }
    fclose(fp);
    return 0;
}
