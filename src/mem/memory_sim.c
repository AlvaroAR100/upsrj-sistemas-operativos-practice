#include "memory_sim.h"
#include <stdio.h>

/*------------------------------------------------------------
 * Function: page_in_frames
 *-----------------------------------------------------------*/
bool page_in_frames(const int frames[],
                    int frame_count,
                    int page)
{
    int i;

    for (i = 0; i < frame_count; i++)
    {
        if (frames[i] == page)
        {
            return true;
        }
    }

    return false;
}

/*------------------------------------------------------------
 * Function: print_frames
 *-----------------------------------------------------------*/
void print_frames(const int frames[],
                  int frame_count)
{
    int i;

    printf("[ ");
    for (i = 0; i < frame_count; i++)
    {
        if (frames[i] == EMPTY_PAGE)
        {
            printf("- ");
        }
        else
        {
            printf("%d ", frames[i]);
        }
    }
    printf("]");
}

/*------------------------------------------------------------
 * Function: init_frames
 *
 * Initializes frames and auxiliary array.
 * The auxiliary array can be used for FIFO index, timestamps,
 * counters, etc.
 *-----------------------------------------------------------*/
void init_frames(int frames[],
                 int aux[],
                 int frame_count)
{
    int i;

    for (i = 0; i < frame_count; i++)
    {
        frames[i] = EMPTY_PAGE;
        aux[i]    = -1;
    }
}