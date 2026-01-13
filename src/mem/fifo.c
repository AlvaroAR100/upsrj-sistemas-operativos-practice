#include <stdio.h>
#include "memory_sim.h"

/*------------------------------------------------------------
 * TODO:
 * Implement FIFO page replacement algorithm.
 *-----------------------------------------------------------*/
static void fifo_replace(int frames[],
                         int frame_count,
                         int page,
                         int *fifo_index)
{
    /* TODO: Student must implement FIFO replacement logic */
    (void)frames;
    (void)frame_count;
    (void)page;
    (void)fifo_index;
}

int main(void)
{
    int reference_string[MAX_REF] = {7, 0, 1, 2, 0, 3, 0, 4};
    int ref_length = 8;

    int frames[MAX_FRAMES];
    int aux[MAX_FRAMES]; /* unused but initialized */
    int fifo_index = 0;
    int page_faults = 0;
    int frame_count = 3;

    int i;

    init_frames(frames, aux, frame_count);

    printf("FIFO Page Replacement Simulation\n\n");

    for (i = 0; i < ref_length; i++)
    {
        int page = reference_string[i];

        printf("Page %d -> ", page);

        if (!page_in_frames(frames, frame_count, page))
        {
            fifo_replace(frames,
                         frame_count,
                         page,
                         &fifo_index);

            page_faults++;
            print_frames(frames, frame_count);
            printf("  Page Fault\n");
        }
        else
        {
            print_frames(frames, frame_count);
            printf("  Hit\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
