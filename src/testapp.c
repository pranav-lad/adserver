#include <stdio.h>
#include "local_data_structure.h"

int main() {
    UserHomepageMapping* data_structure;
    int size = 20;  // You can change the size as needed

    initialize_local_data_structure(&data_structure, size);

    // Example data for testing
    insert_into_local_data_structure(data_structure, size, "user1", "https://shaileshgalande.com/");
    insert_into_local_data_structure(data_structure, size, "user2", "https://mechanical.pccoepune.com/index.php");
    // Add more data as needed

    // Test lookup
    char* homepage = lookup_local_data_structure(data_structure, size, "user1");
    if (homepage != NULL) {
        printf("Homepage for user1: %s\n", homepage);
    } else {
        printf("User not found\n");
    }

    // Free allocated memory
    free(data_structure);

    return 0;
}
