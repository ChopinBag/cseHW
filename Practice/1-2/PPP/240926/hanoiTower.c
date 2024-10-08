#include <stdio.h>

void hanoi_tower(int n, int ox, int tx, int mx) {
    if(n<1) printf("Error:invalid value");
    else if (n==1) {
        printf("%d --> %d\n", ox, tx);
        }
    else {
        hanoi_tower(n-1, ox, mx, tx);
        hanoi_tower(1,ox,tx,mx);
        hanoi_tower(n-1,mx,tx,ox);
        }
    }
int main() {
    int n;
    printf("Enter the height of the tower\n");
    scanf("%d",&n);
    hanoi_tower(n, 1, 3, 2);
    return 0;
    }