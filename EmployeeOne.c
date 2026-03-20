#include <string.h>
#include <math.h>
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

//search by employee phone number
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, const char *targetPhone) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    //loop through the table
    for (; ptr < endPtr; ptr++) {

        if (strcmp(ptr->phone, targetPhone) == 0) { //compare phone strings
            return (PtrToEmployee)ptr; //return pointer if match
        }
    }

       return NULL; //no match found
}

//search by employee salary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++) {

        // compare with tolerance
        if (fabs(ptr->salary - targetSalary) < 0.001) {
            return (PtrToEmployee)ptr;
        }
    }

    return NULL;
}