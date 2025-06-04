// 시스템 소프트웨어 5주차 과제
// practice Problem 3.5

void decode1(long *xp, long *yp, long *zp) {
    long t1 = *xp;
    long t2 = *yp;
    long t3 = *zp;
    *yp = t1;
    *zp = t2;
    *xp = t3;
}