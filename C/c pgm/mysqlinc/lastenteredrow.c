//C program to print the last insertion row id of 
//MySql table in Linux.

#include <mysql.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char server[16] = "localhost";
    char username[16] = "root";
    char password[16] = "root";
    char database[16] = "MyDb";
    int rowid = 0;

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

    if (mysql_query(conn, "CREATE TABLE Employee(Eid INT, Ename VARCHAR(16), Salary INT)")) {
        printf("Unable to create database table in MyDb database\n");
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "insert into Employee values(101,'KIRAN', 10000)")) {
        printf("Unable to insert data into Employee table\n");
        mysql_close(conn);
        return 1;
    }
    if (mysql_query(conn, "Insert into Employee values(102,'SUMAN', 12000)")) {
        printf("Unable to insert data into Employee table\n");
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "Insert into Employee values(103,'RAMAN', 16000)")) {
        printf("Unable to insert data into Employee table\n");
        mysql_close(conn);
        return 1;
    }

    rowid = mysql_insert_id(conn);
    printf("The last inserted row id is: %d\n", rowid);

    mysql_close(conn);

    return 0;
}

