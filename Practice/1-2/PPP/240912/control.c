#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    if ((a%2)==0) {
        printf("even");
    }
    else {
        printf("odd");
    }
    printf("\n");
    return 0;
}