#include "Array.h"
int main(){
    Array a;
    initArray(&a, 8, "33,44,41,66,55,22,7,4");
    printArray(&a);
    quickSort(&a, 0, a.size - 1);
    printArray(&a);
}