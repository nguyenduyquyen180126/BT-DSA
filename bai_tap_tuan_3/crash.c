#include <stdio.h>
int divInt(int a, int b){
    return a/b;
}
int main(){
    int x = 5, y = 2; 
    printf("%d", divInt(x, y)); 

    x =3; y = 0; 
    printf("%d", divInt(x, y));

    return 0; 
}