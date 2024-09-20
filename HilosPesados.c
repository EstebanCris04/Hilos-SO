#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void procesoPesado(int id) {
    char texto[100];
    printf("Proceso %d: Introduce un texto: ", id);
    fgets(texto, sizeof(texto), stdin);
    printf("Proceso %d: Texto introducido: %s", id, texto);
}

int main() {
    const int NUM_PROCESOS = 3;
    pid_t pids[NUM_PROCESOS]; 

    for (int i = 0; i < NUM_PROCESOS; i++) {
        pids[i] = fork(); 
        if (pids[i] < 0) {
            perror("Error al crear el proceso");
            return 1;
        } else if (pids[i] == 0) {
            procesoPesado(i + 1);
            exit(0);
        }
    }

    for (int i = 0; i < NUM_PROCESOS; i++) {
        wait(NULL); 
    }

    printf("Todos los procesos han terminado.\n");
    return 0;
}
