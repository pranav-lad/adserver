#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>  // Include MySQL client library

#define MAX_HOMEPAGE_LENGTH 256

typedef struct {
    char username[20];
    char homepage[MAX_HOMEPAGE_LENGTH];
} UserHomepageMapping;

void open_url(const char *url) {
    char command[256];
    snprintf(command, sizeof(command), "xdg-open %s", url);
    system(command);
}

void process_http_request(char *username, int random_number, char *page_url, MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;

    // Prepare and execute the MySQL query
    char query[256];
    snprintf(query, sizeof(query), "SELECT homepage FROM user_mapping WHERE username='%s'", username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "MySQL query error: %s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);

    // Check if user exists in the database
    if ((row = mysql_fetch_row(res)) != NULL) {
        char *homepage = row[0];
        printf("Redirecting to homepage: %s\n", homepage);
        open_url(homepage);
    } else {
        printf("ERROR: User not found in the database\n");
        // Add additional error handling logic...
    }

    mysql_free_result(res);
}

int main() {
    // Initialize MySQL connection
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    // Connect to the MySQL server
    if (mysql_real_connect(conn, "localhost", "adserveruser", "Pr@n@v23", "adserverdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Example HTTP request
    process_http_request("user2", 23, "https://example.com", conn);

    // Close MySQL connection
    mysql_close(conn);

    return 0;
}