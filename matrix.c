#include <stdio.h>
#include <pthread.h>

#define N 2
#define M 2

int A[N][M] = {{1, 2}, {3, 4}};
int B[N][M] = {{5, 6}, {7, 8}};
int C[N][M];

struct thread_data {
    int row, col;
};

void* multiply(void* arg) {
    struct thread_data* data = (struct thread_data*) arg;
    int sum = 0;
    for (int k = 0; k < M; k++)
        sum += A[data->row][k] * B[k][data->col];
    int* result = (int*) malloc(sizeof(int));
    *result = sum;
    pthread_exit(result);
}

int main() {
    pthread_t threads[N][M];
    struct thread_data td[N][M];
    int* res;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            td[i][j].row = i;
            td[i][j].col = j;
            pthread_create(&threads[i][j], NULL, multiply, &td[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pthread_join(threads[i][j], (void**) &res);
            C[i][j] = *res;
            free(res);
        }
    }

    printf("Resultant Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
