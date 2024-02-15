#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structure.h"
#include "local_data_structure.h"

// Function to read configuration file
int read_config_file(const char* config_file_path, int* num_threads, int* memcached_timeout) {
    FILE* config_file = fopen(config_file_path, "r");
    if (config_file == NULL) {
        perror("Error opening config file");
        return -1;  // Return an error code
    }

    // Read and parse the configuration file
    if (fscanf(config_file, "num_threads = %d\nmemcached_timeout = %d", num_threads, memcached_timeout) != 2) {
        fprintf(stderr, "Error parsing config file\n");
        fclose(config_file);
        return -1;  // Return an error code
    }

    fclose(config_file);
    return 0;  // Return success
}

// Function to log errors to Nginx's error log
void log_error(const char* error_message) {
    FILE* error_log = fopen("/var/log/nginx/error.log", "a");
    if (error_log == NULL) {
        perror("Error opening error log file");
        exit(EXIT_FAILURE);
    }

    fprintf(error_log, "%s\n", error_message);
    fclose(error_log);
}

int main() {
    // Read configuration file
    int num_threads, memcached_timeout;
    if (read_config_file("/etc/nginx/adserver_config.conf", &num_threads, &memcached_timeout) != 0) {
        log_error("Error reading config file");
        exit(EXIT_FAILURE);
    }

    // Initialize cache and local data structure
    CacheEntry* cache;
    UserHomepageMapping* local_data_structure;

    initialize_cache(&cache, CACHE_SIZE);
    initialize_local_data_structure(&local_data_structure, LOCAL_DATA_STRUCTURE_SIZE);

    // Insert data into cache and local data structure
    insert_into_cache(cache, CACHE_SIZE, "user1", "http://www.example1.com");
    insert_into_local_data_structure(local_data_structure, LOCAL_DATA_STRUCTURE_SIZE, "user2", "http://www.example2.com");

    // Lookup data in cache and local data structure
    char* homepage_from_cache = lookup_cache(cache, CACHE_SIZE, "user1");
    char* homepage_from_local_data_structure = lookup_local_data_structure(local_data_structure, LOCAL_DATA_STRUCTURE_SIZE, "user2");

    // Print or use results
    printf("Homepage from Cache: %s\n", homepage_from_cache);
    printf("Homepage from Local Data Structure: %s\n", homepage_from_local_data_structure);

    // Cleanup and exit
    free(cache);
    free(local_data_structure);

    return 0;  // Return success
}
