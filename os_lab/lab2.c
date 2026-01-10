#include <stdio.h>
#include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>

#define BUFFER_SIZE 20

sem_t empty, full;
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int size = 10; // Number of items to produce/consume

void* producer(void* arg) {
    int item = 1;
    while (1) {
        sem_wait(&empty); // Wait if buffer is full

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        
        sem_post(&full); // Signal that an item is available

        if (item == size) {
            break;
        }
        item++;
    }
    printf("Sending completed\n");
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full); // Wait if buffer is empty

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&empty); // Signal that a slot is free

        if (item == size) {
            printf("Received all\n");
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE); // 'empty' starts at BUFFER_SIZE
    sem_init(&full, 0, 0);           // 'full' starts at 0

    // Create threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Cleanup
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}