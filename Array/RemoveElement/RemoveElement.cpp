// Source : https://leetcode.com/problems/remove-element/
// Author : Yijing Bai
// Date   : 2015-10-04

/**********************************************************************************
 *
 * Given an array and a value, remove all instances of that value in place and return
 * the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the
 * new length.
 *
 *
 *
 *
 *
 **********************************************************************************/


public class Solution {
    public int removeElement(int[] A, int elem) {
        if (A.length == 0) {
            return 0;
        }
        Arrays.sort(A);
        int len = A.length;
        int start, end;
        for (start = 0, end = A.length - 1;
             start <= end;) {
            int mid = (int) start + (end - start) / 2;
            if (elem == A[mid]) {
                int e = A.length - 1;
                int i = mid;
                int j = mid + 1;
                while (i >= 0 && A[i] == elem) {
                    len--;
                    i--;
                }
                while (j < A.length && A[j] == elem) {
                    len--;
                    j++;
                }

                i++;
                while (i >= 0 && e >= 0 && A[i] == elem && A[e] != elem) {
                    A[i] = A[e];
                    i++;
                    e--;
                }

                return len;
            } else if (elem < A[mid]) {
                end = mid - 1;
                continue;
            } else {
                start = mid + 1;
                continue;
            }
        }
        return len;
    }
}
