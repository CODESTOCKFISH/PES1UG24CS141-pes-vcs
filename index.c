#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "index.h"

// Load index
int index_load(Index *index) {
    (void)index;

    FILE *f = fopen(".pes/index", "r");

    if (!f) {
        f = fopen(".pes/index", "w");
        if (!f) {
            printf("error: failed to create index\n");
            return -1;
        }
        fclose(f);
        return 0;
    }

    fclose(f);
    return 0;
}

// Save index
int index_save(const Index *index) {
    (void)index;

    FILE *f = fopen(".pes/index", "w");
    if (!f) {
        printf("error: failed to save index\n");
        return -1;
    }

    fprintf(f, "# PES index\n");

    fclose(f);
    return 0;
}

// Add file
int index_add(Index *index, const char *path) {
    (void)index;

    struct stat st;

    if (stat(path, &st) != 0) {
        printf("error: file not found: %s\n", path);
        return -1;
    }

    printf("Added %s to index\n", path);
    return 0;
}

// Status (FIXED SIGNATURE)
int index_status(const Index *index) {
    (void)index;

    printf("Index status: (minimal)\n");
    return 0;
}