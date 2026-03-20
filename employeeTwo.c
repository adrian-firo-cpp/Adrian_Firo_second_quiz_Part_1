#include <string.h>
#include <math.h>
#include "Employee.h"
//NOTE: 5 functions have been defined below 
//ptr - points to table to be searched
//tableSize - size of the table
//targetPtr - points to a comparison function below and will perform the associated check

//What does setting a function to static do??
//functionPtr is the address of the function just use the name
//()(The second set of parantheses is the arguments of the function call) 
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, 
    int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    return NULL;
}
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return * (long *) targetPtr != tableValuePtr->number; //const void *targetPtr ==> typecast as int pointer then deference
}
static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->name);//const void *targetPtr ==> typecast as char pointer then pass into strcmp()
}

// Compare employee phone
static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    // Cast targetPtr to char* and compare with employee phone
    return strcmp((char *)targetPtr, tableValuePtr->phone);
}

// Compare employee salary
static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    double targetSalary = *(double *)targetPtr;

    //use tolerance for floating point comparison
    if (fabs(tableValuePtr->salary - targetSalary) < 0.001)
        return 0;  //match

    return 1;  //match
}

//These are called wrappers. These functions are what you will use in your main!!!
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name)
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char *phone)
{
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary)
{
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}