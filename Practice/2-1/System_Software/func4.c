#include <stdio.h>

int func4(int p1, int p2, int p3){
    int p4 = p3;
    p4 -= p2;
    int p5 = p4;
    p5 >>= 31;
    p5 += p4;
    p5 >>= 1;
    p5 += p2;
    if (p5>p1){
        p3 = p5 - 1;
        return 2 * func4(p1,p2,p3);
    }else if (p5 < p1){
        p3 = p5 + 1;
        return 2*func4(p1,p2,p3)+1;
    }
    return 0;
}

int main(){
    printf("%d",func4(8,0,14));
    return 0;
}