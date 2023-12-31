Write a C Program that makes a copy of a file using standard I/O and system calls.

#include <stdio.h>

int main() {
    FILE *src, *dest;
    char ch;

    src = fopen("anil", "r");
    if (src == NULL) {
        printf("Error: Unable to open the source file.");
        return 1;
    }

    dest = fopen("17", "w");
    if (dest == NULL) {
        printf("Error: Unable to open the destination file.");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}

