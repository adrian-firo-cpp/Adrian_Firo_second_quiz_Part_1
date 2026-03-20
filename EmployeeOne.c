#include <string.h>
#include "employee.h"

// Search by employee number
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    // Loop through the table
    for (; ptr < endPtr; ptr++) {   // ptr++ moves to next Employee (pointer arithmetic)
        if (ptr->number == targetNumber) {  // check if numbers match
            return (PtrToEmployee)ptr;      // return pointer to matching employee
        }
    }

    return NULL;  // no match found
}


// Search by employee name
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    // Loop through the table
    for (; ptr < endPtr; ptr++) {
        if (strcmp(ptr->name, targetName) == 0) {  // compare strings
            return (PtrToEmployee)ptr;             // return pointer if match
        }
    }

    return NULL;  // no match found
}

//new search functions
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, const char *targetPhone) {
    //loop through the table

        //compare phone strings
        //return pointer if match

        //no match found
}
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, float targetSalary); {
    //loop through the table

        //compare salary 
        //return pointer if match found

        //no match
}