//C program to create a specified table in MySQL database dynamically in Linux.

#include "mysql.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char server[16] = "localhost";
    char username[16] = "root";
    char password[16] = "root";
    char database[16] = "MyDb";

    MYSQL* conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("MySQL initialization failed");
        return 1;
    }

    if (mysql_real_connect(conn, server, username, password, database, 0, NULL, 0) == NULL) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "CREATE TABLE Employee(Eid INT PRIMARY KEY AUTO_INCREMENT, Ename VARCHAR(16), Salary INT)")) {
        printf("Unable to create database table in MyDb database\n");
        mysql_close(conn);
        return 1;
    }

    mysql_close(conn);

    printf("Employee table created successfully\n");

    return 0;
}

