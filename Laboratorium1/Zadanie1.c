#include <stdio.h>

int zawiera(char *linia, char *slowo) {
    while (*linia) {
        char *p1 = linia;
        char *p2 = slowo;

        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (!*p2) {
            return 1; 
        }

        linia++;
    }
    return 0; 
}

int main() {
    FILE *file;
    file = fopen("test.txt", "r");

    char buffer[100];
    char slowo[50];

    printf("\nPodaj slowo do wyszukania: ");
    scanf("%s", slowo);

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (zawiera(buffer, slowo)) {
            printf("%s", buffer);
        }
    }

    fclose(file);
    return 0;
}