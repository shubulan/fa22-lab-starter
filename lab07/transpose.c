#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

int inline min(int a, int b) {
    return a > b ? b : a;
}
void inline Tblock(int n, int bkx, int bky, int i, int j, int *dst, int *src) {
    int x, y;
    for (x = i; x < i + bkx; x++)
        for (y = j; y < j + bky; y++)
            dst[y + x * n] = src[x + y * n];
}
/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
    int x, y;
    for (x = 0; x < n; x += min(n - x, blocksize)) {
        for (y = 0; y < n; y += min(n - y, blocksize)) {
            Tblock(n, min(n - x, blocksize), min(n - y, blocksize), x, y, dst, src);
        }
    }
}
