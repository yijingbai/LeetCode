// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : Yijing Bai
// Date   : 2015-10-06
/**********************************************************************************
 *
 * Write a function that takes an unsigned integer and returns the number of ’1' bits
 * it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 *
 *
 *
 **********************************************************************************/
#include <stdio.h>
#include <stdint.h>

    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n & 0x1 == 1)
                count = count++;
            n = n>>1;
        }
        return count;
    }

int main() {
    printf("%d\n", hammingWeight(1));
}

