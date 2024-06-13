#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

void printFrames(int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == -1) {
            printf("  -");
        } else {
            printf("  %d", frames[i]);
        }
    }
    printf("\n");
}

int findOptimal(int pages[], int pageCount, int frames[], int frameCount, int currentIndex) {
    int pos = -1;
    int farthest = currentIndex;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentIndex; j < pageCount; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == pageCount) {
            return i;
        }
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int pageCount, frameCount;
    int pageFaults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\nPage Reference String\tFrames\n");
    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int pos = findOptimal(pages, pageCount, frames, frameCount, i + 1);
            frames[pos] = page;
            pageFaults++;
        }
        printf("       %d\t\t", page);
        printFrames(frames, frameCount);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
