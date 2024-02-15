#include "local_data_structure.h"
#include <stdlib.h>
#include <string.h>

// Placeholder function for initializing the local data structure
void initialize_local_data_structure(UserHomepageMapping** data_structure, int size) {
    *data_structure = malloc(size * sizeof(UserHomepageMapping));
    // Initialize data_structure if needed
}

// Placeholder function for inserting data into the local data structure
void insert_into_local_data_structure(UserHomepageMapping* data_structure, int size, char* username, char* homepage) {
    for (int i = 0; i < size; ++i) {
        if (data_structure[i].id == 0) {
            // Assuming id 0 indicates an empty slot
            data_structure[i].id = i + 1;  // Assign a unique ID
            strncpy(data_structure[i].username, username, sizeof(data_structure[i].username) - 1);
            strncpy(data_structure[i].homepage, homepage, sizeof(data_structure[i].homepage) - 1);
            break;
        }
    }
}

// Placeholder function for looking up data in the local data structure
char* lookup_local_data_structure(UserHomepageMapping* data_structure, int size, char* username) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(data_structure[i].username, username) == 0) {
            return data_structure[i].homepage;
        }
    }
    return NULL;  // Placeholder, modify as needed
}
