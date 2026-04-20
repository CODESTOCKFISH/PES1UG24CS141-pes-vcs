#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Create commit
int commit_create(const char *message) {
    FILE *f;

    // ensure directory exists
    system("mkdir -p .pes/refs/heads");

    f = fopen(".pes/refs/heads/main", "w");
    if (!f) {
        printf("error: commit failed\n");
        return -1;
    }

    time_t now = time(NULL);

    fprintf(f, "commit %ld\n", now);
    fprintf(f, "message %s\n", message ? message : "no message");

    fclose(f);

    printf("Committed successfully\n");
    return 0;
}

// Log commits (used sometimes)
int commit_log(void) {
    FILE *f = fopen(".pes/refs/heads/main", "r");

    if (!f) {
        printf("No commits yet.\n");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }

    fclose(f);
    return 0;
}

// REQUIRED: used by pes.c
int commit_walk(void) {
    FILE *f = fopen(".pes/refs/heads/main", "r");

    if (!f) {
        printf("No commits yet.\n");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }

    fclose(f);
    return 0;
}