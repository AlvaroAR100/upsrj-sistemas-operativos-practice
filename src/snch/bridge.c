#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "bridge.h"

/*------------------------------------------------------------
 * Shared state
 *-----------------------------------------------------------*/
static int monkeys_on_bridge = 0;
static direction_t current_direction;

/* Synchronization primitives */
static pthread_mutex_t mutex;
static sem_t bridge_sem;

/*------------------------------------------------------------
 * Initialize bridge synchronization
 *-----------------------------------------------------------*/
void bridge_init(void)
{
    pthread_mutex_init(&mutex, NULL);
    sem_init(&bridge_sem, 0, 1);

    monkeys_on_bridge = 0;
}

/*------------------------------------------------------------
 * TODO:
 * Implement synchronization logic so that:
 * - Only one direction uses the bridge at a time
 * - Multiple monkeys in the same direction are allowed
 *-----------------------------------------------------------*/
void enter_bridge(direction_t dir)
{
    /* TODO: Student must implement entry logic */
    (void)dir;
}

/*------------------------------------------------------------
 * TODO:
 * Implement logic to release the bridge when appropriate
 *-----------------------------------------------------------*/
void leave_bridge(direction_t dir)
{
    /* TODO: Student must implement exit logic */
    (void)dir;
}
