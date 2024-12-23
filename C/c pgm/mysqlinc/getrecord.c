//C program to retrieve records from MySql database 
//table in Linux.

#include <mysql.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char server[16] = "localhost";
    char username[16] = "root";
    char password[16] = "root";
    char database[16] = "MyDb";

    MYSQL* conn = mysql_init(NULL);
    MYSQL_ROW record;

    if (conn == NULL) {
        printf("MySQL initialization failed");
        return 1;
    }

    if (mysql_real_connect(conn, server, username, password, database, 0, NULL, 0) == NULL) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "SELECT * FROM Employee")) {
        printf("Unable to connect with MySQL server\n");
        mysql_close(conn);
        return 1;
    }

    MYSQL_RES* rs = mysql_store_result(conn);

    if (rs == NULL) {
        printf("Unable to compile SQL statement\n");
        mysql_close(conn);
        return 1;
    }

    while (record = mysql_fetch_row(rs)) {
        printf("%s %s %s\n", record[0], record[1], record[2]);
    }
    mysql_close(conn);

    return 0;
}

