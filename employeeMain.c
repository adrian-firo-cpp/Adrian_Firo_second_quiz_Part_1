#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "employee.h"
int main(void){
    //defined in employeeOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee Table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, const char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration


    //search by number

    //Example found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 4011);
    if (matchPtr != NULL)
        printf("Employee ID 4011 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //example not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1234);
    if (matchPtr != NULL)
        printf("Employee ID 1234 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");


    //search by name

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //example not found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Bob Ross");
    if (matchPtr != NULL)
        printf("Employee Bob Ross is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Bob Ross is NOT found in the record\n");


    //search by phone

    //example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235");
    if (matchPtr != NULL)
        printf("Employee with phone 909-555-1235 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone 909-555-1235 is NOT found in the record\n");

    //example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "626-626-6262");
    if (matchPtr != NULL)
        printf("Employee with phone 626-626-6262 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone 626-626-6262 is NOT found in the record\n");


    //search by salary

    //example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
    if (matchPtr != NULL)
        printf("Employee with salary 6.34 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Salary 6.34 is NOT found in the record\n");

    //example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.01);
    if (matchPtr != NULL)
        printf("Employee with salary 8.01 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Salary 8.01 is NOT found in the record\n");
    
    return EXIT_SUCCESS;
}