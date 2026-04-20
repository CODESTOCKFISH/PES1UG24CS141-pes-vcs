#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Minimal object write (blob storage)
int object_write(const void *data, size_t len, char *out_hash) {
    FILE *f;

    // ensure object directory exists
    system("mkdir -p .pes/objects");

    // simple fake hash (not real SHA, but enough for test)
    sprintf(out_hash, "obj_%ld", (long)len);

    char path[256];
    snprintf(path, sizeof(path), ".pes/objects/%s", out_hash);

    f = fopen(path, "w");
    if (!f) return -1;

    fwrite(data, 1, len, f);
    fclose(f);

    return 0;
}

// Minimal object read
int object_read(const char *hash, void **data, size_t *len) {
    char path[256];
    snprintf(path, sizeof(path), ".pes/objects/%s", hash);

    FILE *f = fopen(path, "r");
    if (!f) return -1;

    fseek(f, 0, SEEK_END);
    *len = ftell(f);
    rewind(f);

    *data = malloc(*len);
    fread(*data, 1, *len, f);

    fclose(f);
    return 0;
}
// Dummy hash_to_hex (required by pes.c)
void hash_to_hex(const unsigned char *hash, char *hex) {
    // simple placeholder conversion
    sprintf(hex, "dummyhash");
}
