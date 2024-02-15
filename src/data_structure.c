#include "../include/data_structure.h"
#include <stdlib.h>
#include <string.h>

void initialize_cache(CacheEntry** cache, int size) {
    *cache = malloc(size * sizeof(CacheEntry));
    for (int i = 0; i < size; ++i) {
        (*cache)[i].username[0] = '\0';  // Initialize username to an empty string
        (*cache)[i].homepage[0] = '\0';  // Initialize homepage to an empty string
    }
}

void insert_into_cache(CacheEntry* cache, int size, char* username, char* homepage) {
    for (int i = 0; i < size; ++i) {
        if (cache[i].username[0] == '\0') {
            strncpy(cache[i].username, username, sizeof(cache[i].username) - 1);
            strncpy(cache[i].homepage, homepage, sizeof(cache[i].homepage) - 1);
            break;
        }
    }
}

char* lookup_cache(CacheEntry* cache, int size, char* username) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(cache[i].username, username) == 0) {
            return cache[i].homepage;
        }
    }
    return NULL;
}
