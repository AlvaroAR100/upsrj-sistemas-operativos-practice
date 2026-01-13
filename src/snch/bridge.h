#ifndef BRIDGE_H
#define BRIDGE_H

typedef enum
{
    LEFT = 0,
    RIGHT = 1
} direction_t;

/*------------------------------------------------------------
 * Initializes synchronization primitives.
 *-----------------------------------------------------------*/
void bridge_init(void);

/*------------------------------------------------------------
 * Called by a monkey before crossing the bridge.
 *-----------------------------------------------------------*/
void enter_bridge(direction_t dir);

/*------------------------------------------------------------
 * Called by a monkey after leaving the bridge.
 *-----------------------------------------------------------*/
void leave_bridge(direction_t dir);

#endif
