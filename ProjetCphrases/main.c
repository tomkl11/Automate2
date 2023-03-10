#include <stdio.h>
typedef struct Nom{
    char letter;
    struct Nom* next;
    struct Nom* fils;
}Nom;

int main() {
    printf("Hello, World!\n");
    return 0;
}
