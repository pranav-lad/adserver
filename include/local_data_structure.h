#ifndef LOCAL_DATA_STRUCTURE_H
#define LOCAL_DATA_STRUCTURE_H

#include "data_structure.h"

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char homepage[MAX_HOMEPAGE_LENGTH];
} UserHomepageMapping;

void initialize_local_data_structure(UserHomepageMapping** data_structure, int size);
void insert_into_local_data_structure(UserHomepageMapping* data_structure, int size, char* username, char* homepage);
char* lookup_local_data_structure(UserHomepageMapping* data_structure, int size, char* username);

#endif // LOCAL_DATA_STRUCTURE_H
