#include <stdio.h>

int bitCount(int x);
int bang(int x);
int main() {
    int x = 20;
}

int bitCount(int x) {
    int m1, m2, m4, m8, m16;
    m1 = 0x55 | (0x55<<8);
    m1 = m1 | (m1 << 16);

    m2 = 0x33 | (0x33<<8);
    m2 = m2 | (m2 << 16);

    m4 = 0x0F | (0x0F<<8);
    m4 = m4 | (m4<<16);

    m8 = 0xFF | (0xFF<<16);

    m16 = 0xFF | (0xFF<<8);

    x = (x & m1) + ((x>>1) & m1);
    x = (x & m2) + ((x>>2) & m2);
    x = (x & m4) + ((x>>4) & m4);
    x = (x & m8) + ((x>>8) & m8);
    x = (x & m16) +( (x>>16) & m16);
    return x;
}
int bang(int x) {
    x = (x ^ (~x)) + 1;
    return x;
}