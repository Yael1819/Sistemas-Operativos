#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char c;
    int i;
    float j;

    // Mostrar el nombre del ejecutable
    printf("Nombre del ejecutable: %s\n", argv[0]);

    if (argc > 1) {
        fprintf(stderr, "Error de argumentos\n");
        exit(1);
    }

    while ((c = getchar()) != EOF) {
        i = (int)(c - '0');
        if (i >= 0 && i <= 5) {
            j = (float)i / (float)5; // divide entre 5 y convierte a decimal
            fprintf(stdout, "%.1f\n", j);  // imprime el resultado
        } else {
            fprintf(stderr, "%d\n", i); // error, número fuera de rango
        }
    }

    return 0;
}
