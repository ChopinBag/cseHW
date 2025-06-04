/*
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
*/

#include <stdio.h>
int main(void) {
    int a;
    scanf("%d", &a);
    while (a<5) {
        printf("%d < 5\n", a);
        a++;
    }
    return 0;
}