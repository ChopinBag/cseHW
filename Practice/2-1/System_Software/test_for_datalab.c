#include <stdio.h>

// int bitAnd(int x, int y);
// int getByte(int x, int n);
// int logicalShift(int x, int n);
// int bitCount(int x);
// int bang(int x);
// int tmin(void);
// int fitsBits(int x, int n);
// int divpwr2(int x, int n);
// int negate(int x);
// int isPositive(int x);
// int isLessOrEqual(int x, int y);
int ilog2(int x);
unsigned float_neg(unsigned uf);
unsigned float_i2f(int x);
unsigned float_twice(unsigned uf);

int main() {
    int n=-33;
    int m=-4;
    printf("%d",15>>4);
    return 0;
}

int bitAnd(int x, int y) {
  return ~(~x|~y);
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
* 78 56 34 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return x & (0xFF << (n << 3)) >> (n << 3);
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
  return ((x>>1)&(~(1<<31))) >> (n + ~0);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 404
 *   Rating: 1
 */
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
  x = (x & m16) +((x>>16) & m16);

  return x;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
      return (x|(~x+1) >> 31)^1;
     }
/*
* tmin - return minimum two's complement integer
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 4
*   Rating: 1
*/
int tmin(void) {
  return 0x00|(0x01<<31);
}
/*
 * fitsBits - return 1 if x can be represented as an n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift = 32 + (~n + 1);
  return !(x ^ ((x << shift) >> shift));
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int bias = (x >> 31) & ((1 << n) + ~0);
    return (x + bias) >> n;
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !(x>> 31) & !!x;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int mask = ((0x80 << 8) | 0x00) << 16;
    return !(x ^ mask) | !((y + (~x + 1)) >> 31);;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    int result = 0;
    int shift;

    shift = (!!(x >> 16)) << 4; // if high 16 bits are set, shift = 16
    result += shift;
    x = x >> shift;

    shift = (!!(x >> 8)) << 3; // if high 8 bits are set, shift = 8
    result += shift;
    x = x >> shift;

    shift = (!!(x >> 4)) << 2; // 4-bit check
    result += shift;
    x = x >> shift;

    shift = (!!(x >> 2)) << 1; // 2-bit check
    result += shift;
    x = x >> shift;

    shift = (!!(x >> 1));      // 1-bit check
    result += shift;

    return result;
}
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
