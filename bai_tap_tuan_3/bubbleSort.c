#include <stdio.h>
void bubbleSort(int *a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] >= a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void printArr(int *a, int n){
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int a[10] = {2,5,7,1,5,6,2,6,9,8};
    bubbleSort(a, 10);
    printArr(a, 10);
}