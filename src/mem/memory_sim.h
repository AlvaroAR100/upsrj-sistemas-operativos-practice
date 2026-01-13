#ifndef MEMORY_SIM_H
#define MEMORY_SIM_H

#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_REF    50
#define EMPTY_PAGE (-1)

/*------------------------------------------------------------
 * Checks if a page is already loaded in memory frames.
 *-----------------------------------------------------------*/
bool page_in_frames(const int frames[],
                    int frame_count,
                    int page);

/*------------------------------------------------------------
 * Prints the current state of memory frames.
 *-----------------------------------------------------------*/
void print_frames(const int frames[],
                  int frame_count);

/*------------------------------------------------------------
 * Initializes memory frames and auxiliary data.
 *-----------------------------------------------------------*/
void init_frames(int frames[],
                 int aux[],
                 int frame_count);

#endif /* MEMORY_SIM_H */