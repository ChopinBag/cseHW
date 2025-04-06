#include <stdio.h>

void decode1(long *xp, long *yp, long *zp);
short scale3 (short x, short y, short z);
int main() {

}
// rdi = x
// rsi = y
// rdx = z

void decode1(long *xp, long *yp, long *zp) {
    long t1 = *xp;
    long t2 = *yp;
    long t3 = *zp;
    *yp = t1;
    *zp = t2;
    *xp = t3;
}


/*
 * x= rdi
 * y= rsi
 * z= rdx
 *
 * (rsi, rsi,9), rbx : y+9y = z
 * (rbx, rdx), rbx : z+z = z
 * (rbx, rdi, rsi), rbx : z + x*y = z
 */
short scale3 (short x, short y, short z) {
    short t = y * 10 + z + x*y;
    // t = y + y*9 = 10y;
    // t = t + z; = 10y + z
    // t = t + x * y; = 10y +z +xy

    return t;
}