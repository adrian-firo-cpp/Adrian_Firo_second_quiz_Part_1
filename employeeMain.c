//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

//gcc employeeMain.c employeeTable.c employeeTwo.c


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

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 4011);

    //Example found
    if (matchPtr != NULL)
        printf("Employee ID 4011 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //example not found


    //search by name

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    //Example found
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //example not found


    //search by phone

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235");

    //example found
    if (matchPtr != NULL)
        printf("Employee with phone 909-555-1235 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Phone 909-555-1235 is NOT found in the record\n");

    //example not found


    //search by salary

    //example found

    //example not found

    return EXIT_SUCCESS;
}