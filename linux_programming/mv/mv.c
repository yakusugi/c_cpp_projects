#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file_or_directory> <destination_file_or_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (rename(argv[1], argv[2]) != 0) {
        perror("Error moving file or directory");
        exit(EXIT_FAILURE);
    }

    printf("File or directory moved successfully\n");
    exit(EXIT_SUCCESS);
}
