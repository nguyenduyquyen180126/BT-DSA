#include "Array.h"
void initArray(Array *a, int size, const char* data){
    a->p = (int *)malloc(size*sizeof(int));
    a->size = size;
    char buffer[100];
    strcpy(buffer, data);
    char *token = strtok(buffer, ",");
    int index = 0;
    while(token != NULL){
        a->p[index++] = atoi(token);
        token = strtok(NULL, ",");
    }
}
void copyToArray(int *des, Array *src, int startindex, int endIndex){
    int j=0; 
    for(int i = startindex; i <= endIndex; i++){
        des[j] = src->p[i];
        j++;
    }
}
void insertArray(Array *a, int var, int index){
    a->size++;
    int *temp;
    temp = (int *)realloc(a->p, a->size*sizeof(int));
    if(temp == NULL){
        printf("\ninsert fail\n");
        return;
    }
    a->p = temp;
    for(int i=a->size-1; i>= index; i--){
        if(i==index){
            a->p[i] = var;
        }
        else{
            int temp = a->p[i];
            a->p[i] = a->p[i - 1];
            a->p[i - 1] = temp;
        }
    }
}
void printArray(Array *a){
    // printf("\nPrint array %p : \n", a->p);
    printf("\n");
    for(int i=0; i<a->size; i++){
        printf("%d ", a->p[i]);
    }
    printf("\n");
}
void freeArray(Array *a){
    free(a->p);
}
void deleteEle(Array *p, int index){
    for(int i=index; i<p->size-1; i++){
        int temp = p->p[i+1];
        p->p[i+1] = p->p[i];
        p->p[i] = temp;
    }
    int *temp;
    temp = (int *)realloc(p->p, (p->size-1)*sizeof(int));
    if(temp == NULL){
        printf("\ninsert fail\n");
        return;
    }
    p->size--;
    p->p = temp;
}
void selectionSort(Array *p){
    printf("\n Procedure selection sort\n");
    int i, j, min_ind;
    for(i=0; i<p->size - 1; i++){
        min_ind = i;
        for(j=i+1; j<p->size; j++){
            if(p->p[min_ind] > p->p[j]){
                min_ind = j;
            }
        }
        printf("No %d Min %d\n", i+1, p->p[min_ind]);
        int temp = p->p[i];
        p->p[i] = p->p[min_ind];
        p->p[min_ind] = temp;
        printArray(p);
    }
}
void insertSort(Array *p){
    printf("\nProcedure insertion sort\n");
    for(int i=1; i<p->size; i++){
        int j=i;
        int x = p->p[i];
        while(j>0 && p->p[j-1] > x){
            p->p[j] = p->p[j-1];
            j--;
        }
        p->p[j] = x;
        printf("No %d Comp num %d", i, p->p[j]);
        printArray(p);
    }
}
void bubbleSort(Array *p){
    printf("\nProcedure insertion sort\n");
    for(int i=0; i<p->size; i++){
        for(int j=0; j<p->size-i-1; j++){
            if(p->p[j] > p->p[j+1]){
                int temp = p->p[j];
                p->p[j] = p->p[j+1];
                p->p[j+1] = temp;
            }
        }
        printArray(p);
    }
}
int partition(Array *p, int left, int right, int pivot) {
    int i = left + 1;
    int j = right;
    int pivotVal = p->p[pivot];

    while (i <= j){
        while (i <= right && p->p[i] < pivotVal) i++;
        while (j >= left && p->p[j] > pivotVal) j--;

        if (i < j){
            int temp = p->p[i];
            p->p[i] = p->p[j];
            p->p[j] = temp;
            i++;
            j--;
        } 
        else{
            break;
        }
    }

    int temp = p->p[left];
    p->p[left] = p->p[j];
    p->p[j] = temp;

    return j;
}
void quickSort(Array *p, int left, int right){
    if(left >= right){
        return;
    }
    else{
        int pivot = left;
        int pivotPoint = partition(p, left, right, pivot);
        #ifdef PRINT_SORT_STEP
        printf("\nPivot tu %d -> %d:", pivot, pivotPoint);
        printArray(p);
        #endif
        quickSort(p, left, pivotPoint - 1);
        quickSort(p, pivotPoint + 1, right);
    }
}
void buildHeap(Array *p, int n, int i){
    int e = p->p[i];
    int j = 2+i+1;
    while(j < n){
        int k = j+1;
        if(k < n && p->p[j] < p->p[k]) j = k;
        if(p->p[j] < e) break;
        p->p[i] = p->p[j];
        i = j;
        j = 2+i+1;
    }
    p->p[i] = e;
}
void heapSort(Array *p, int n){
    for(int i = (p->size/2)-1; i > 0; i--){
        buildHeap(p, n, i);
    }

    while (n > 1){
        buildHeap(p, n, 0);
        int temp = p->p[0];
        p->p[0] = p->p[--n];
        p->p[n] = temp;
    }
    
}
void mergeSort(Array *p, int left, int right){
    // printf("\n%d %d", left, right);
    if(left < right){
        int center = (right + left)/2;
        mergeSort(p, left, center);
        mergeSort(p, center + 1, right);
        // printf("\nMerge %d %d %d", left, center, right);
        merge(p, left, center, right);
        #ifdef PRINT_SORT_STEP
        printf("\nMerge %d->%d voi %d->%d", left, center, center + 1, right);
        printArray(p); // In mang sao moi vong lap
        #endif
    }
}
void merge(Array *p, int left, int center, int right){
    int leftSize = center - left + 1;
    int rightSize = right - center;
    int leftArray[leftSize];
    copyToArray(leftArray, p, left, center);
    int rightArray[rightSize];
    copyToArray(rightArray, p, center + 1, right);
    int i = 0, j = 0, index = left;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j])
            p->p[index++] = leftArray[i++];
        else
            p->p[index++] = rightArray[j++];
    }
    while (i < leftSize)
        p->p[index++] = leftArray[i++];
    while (j < rightSize)
        p->p[index++] = rightArray[j++];
}
int cmpArray(Array *a, Array *b){
    for(int i = 0; i <a->size; i++){
        if(a->p[i] != b->p[i]){
            return 0;
        }
    }
    return 1;
}