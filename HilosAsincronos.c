#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void* calcular_cuadrado(void* arg) {
    int num = *(int*)arg;
    printf("El cuadrado de %d es %d\n", num, num * num);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int numeros[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Ingresa el número para la posición %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, calcular_cuadrado, &numeros[i]) != 0) {
            printf("Error al crear el hilo %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Todos los hilos han terminado.\n");
    return 0;
}
