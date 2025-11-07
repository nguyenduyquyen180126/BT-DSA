#include "Array.h"

int main(){
    Array a;
    initArray(&a, 10, "5,36,35,7,346,1,23,8,3,57");
    printArray(&a);
    quickSort(&a, 0, a.size - 1);
    printf("\nSorted array: \n");
    printArray(&a);
}