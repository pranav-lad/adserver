#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#define MAX_USERNAME_LENGTH 50
#define MAX_HOMEPAGE_LENGTH 100

// Structure to represent a mapping of a user to its homepage URL
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char homepage[MAX_HOMEPAGE_LENGTH];
} UserHomepageMapping;

#endif // DATA_STRUCTURE_H
