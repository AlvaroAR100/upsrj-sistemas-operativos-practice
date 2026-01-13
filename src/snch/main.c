#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "bridge.h"

#define MONKEYS 10

typedef struct
{
    int id;
    direction_t dir;
} monkey_t;

static void *monkey(void *arg)
{
    monkey_t *m = (monkey_t *)arg;

    printf("Monkey %d wants to cross %s\n",
           m->id,
           m->dir == LEFT ? "LEFT -> RIGHT" : "RIGHT -> LEFT");

    enter_bridge(m->dir);

    printf("Monkey %d is crossing\n", m->id);
    sleep(1);

    leave_bridge(m->dir);

    printf("Monkey %d has crossed\n", m->id);

    return NULL;
}

int main(void)
{
    pthread_t threads[MONKEYS];
    monkey_t monkeys[MONKEYS];
    int i;

    bridge_init();

    for (i = 0; i < MONKEYS; i++)
    {
        monkeys[i].id = i;
        monkeys[i].dir = (i % 2 == 0) ? LEFT : RIGHT;
        pthread_create(&threads[i], NULL, monkey, &monkeys[i]);
    }

    for (i = 0; i < MONKEYS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
