#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {                      
        printf("Nie moge otworzyc pliku\n");
        return 1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}