#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// * **Dynamic Memory Allocation:** The code allocates memory for an integer using `malloc()`.
// * **Process Identification:** It retrieves and prints the current process ID using `getpid()`.
// * **Memory Address Display:** It prints the virtual memory address stored in pointer `p`.
// * **Infinite Counter Loop:** An infinite `while` loop continuously increments and prints the integer value.
// * **Virtual Memory Concept:** Running multiple instances shows identical memory addresses because each process receives its own private virtual address space managed by the operating system.

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int)); // a1
    printf("(%d) address pointed to by p: %p\n",
           getpid(), p); // a2
    *p = 0;              // a3
    while (1)
    {
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p); // a4
    }
    return 0;
}