#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("test.txt", "r");

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}