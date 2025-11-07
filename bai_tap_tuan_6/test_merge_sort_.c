#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Array.h"
int main(){
    FILE *testCase = fopen("test_vector.txt", "r");
    assert(testCase != NULL);
    FILE *result = fopen("expected.txt", "r");
    assert(result != NULL);
    char line[100];
    char line_sorted[100];
    int testCaseIndex = 1;
    while (fgets(line, sizeof(line), testCase)) {
        // printf("%s\n", line);
        fgets(line_sorted, sizeof(line_sorted), result);
        Array a,b;
        int dem = 0; 
        for(int i = 0; line[i] != '\0'; i++){
            if(line[i] == ','){
                dem++;
            }
        }
        initArray(&a, dem + 1, line);
        initArray(&b, dem + 1, line_sorted);
        // printArray(&a);
        mergeSort(&a, 0, a.size - 1);
        if(cmpArray(&a, &b) == 1){
            printf("\nTest case %d: Pass\n", testCaseIndex);
            testCaseIndex++;
        }
        else if(cmpArray(&a, &b) == 0){
            printf("\nTest case %d: False\n", testCaseIndex);
            testCaseIndex++;
        }
        freeArray(&a);
        freeArray(&b);
    }
    
    fclose(testCase);
    fclose(result);
}