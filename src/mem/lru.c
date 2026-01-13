#include <stdio.h>
#include "memory_sim.h"

/*------------------------------------------------------------
 * TODO:
 * Implement LRU page replacement algorithm.
 *-----------------------------------------------------------*/
static void lru_replace(int frames[],
                        int last_used[],
                        int frame_count,
                        int page,
                        int current_time)
{
    /* TODO: Student must implement LRU replacement logic */
    (void)frames;
    (void)last_used;
    (void)frame_count;
    (void)page;
    (void)current_time;
}

int main(void)
{
    int reference_string[MAX_REF] = {7, 0, 1, 2, 0, 3, 0, 4};
    int ref_length = 8;

    int frames[MAX_FRAMES];
    int last_used[MAX_FRAMES];
    int page_faults = 0;
    int frame_count = 3;
    int time = 0;

    int i;

    init_frames(frames, last_used, frame_count);

    printf("LRU Page Replacement Simulation\n\n");

    for (i = 0; i < ref_length; i++)
    {
        int page = reference_string[i];

        printf("Page %d -> ", page);

        if (!page_in_frames(frames, frame_count, page))
        {
            lru_replace(frames,
                        last_used,
                        frame_count,
                        page,
                        time);

            page_faults++;
            print_frames(frames, frame_count);
            printf("  Page Fault\n");
        }
        else
        {
            print_frames(frames, frame_count);
            printf("  Hit\n");
        }

        time++;
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
