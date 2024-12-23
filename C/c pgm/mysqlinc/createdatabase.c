//C program to create MySQL database dynamically in Linux.

#include <mysql.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char server[16] = "localhost";
    char username[16] = "root";
    char password[16] = "root";

    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("MySQL initialization failed");
        return 1;
    }

    if (mysql_real_connect(conn, server, username, password, NULL, 0, NULL, 0) == NULL) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "CREATE DATABASE MyDb")) {
        printf("Unable to create database\n");
        mysql_close(conn);
        return 1;
    }

    mysql_close(conn);

    printf("Database created successfully\n");
    return 0;
}

