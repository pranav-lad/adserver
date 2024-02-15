#ifndef LOCAL_DATA_STRUCTURE_H
#define LOCAL_DATA_STRUCTURE_H

#include "data_structure.h"
#include <stdlib.h>
#include <string.h>

// Define the structure to hold user homepage mapping
typedef struct {
    char username[20];
    char homepage[MAX_HOMEPAGE_LENGTH];
} UserHomepageMapping;

// Function prototypes and definitions for local data structure operations
void initialize_local_data_structure(UserHomepageMapping** data_structure, int size) {
    *data_structure = (UserHomepageMapping*)malloc(size * sizeof(UserHomepageMapping));
    if (*data_structure == NULL) {
        printf("ERROR: Memory allocation failed\n");
        exit(0);
    }
}

void insert_into_local_data_structure(UserHomepageMapping* data_structure, int size, char* username, char* homepage) {
    // Implement the insertion logic here
    for (int i = 0; i < size; ++i) {
        if (strcmp(data_structure[i].username, "") == 0) {
            strncpy(data_structure[i].username, username, sizeof(data_structure[i].username) - 1);
            strncpy(data_structure[i].homepage, homepage, sizeof(data_structure[i].homepage) - 1);
            return;
        }
    }

    printf("ERROR: Unable to insert into local data structure. Structure full.\n");
    exit(0);
}

char* lookup_local_data_structure(UserHomepageMapping* data_structure, int size, char* username) {
    // Implement the lookup logic here
    for (int i = 0; i < size; ++i) {
        if (strcmp(data_structure[i].username, username) == 0) {
            return data_structure[i].homepage;
        }
    }

    return NULL;
}

#endif // LOCAL_DATA_STRUCTURE_H
