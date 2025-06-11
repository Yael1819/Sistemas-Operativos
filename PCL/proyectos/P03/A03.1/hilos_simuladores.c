#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Función que ejecutará cada simulador
void* ejecutar_simulador(void* arg) {
    char* comando = (char*)arg;
    int resultado = system(comando);
    if (resultado != 0) {
        printf("Error al ejecutar: %s\n", comando);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[3];

    // Comandos de los simuladores
    char* comandos[] = {
        "./sim_CO2",
        "./sim_H2O",
        "./sim_pos"
    };

    // Crear hilos
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&hilos[i], NULL, ejecutar_simulador, (void*)comandos[i]) != 0) {
            perror("Error creando hilo");
            exit(1);
        }
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Todos los simuladores han terminado.\n");
    return 0;
}
