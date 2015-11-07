import java.util.Arrays;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int k = sc.nextInt();
            int[] input = new int[k];
            for (int j = 0; j < k; j++) {
                input[j] = sc.nextInt();
            }
            System.out.println(count_inversion(input));
        }
    }

    public static long count_cross(int[] left, int[] right) {;
        long inversion_count = 0;
        int i = 0, j = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                i++;
            } else {
                inversion_count += left.length - i;
                j++;
            }
        }
        return inversion_count;
    }

    public static void merge(int[] input, int[] L, int[] R) {
        int l = 0, r = 0, i = 0;
        while (l < L.length && r < R.length) {
            if (L[l] <= R[r]) {
                input[i] = L[l];
                i++;
                l++;
            } else {
                input[i] = R[r];
                r++;
                i++;
            }
        }

        while (l < L.length) {
            input[i] = L[l];
            l++;
            i++;
        }

        while (r < R.length) {
            input[i] = R[r];
            r++;
            i++;
        }
    }

    public static long count_inversion(int[] input) {
        if (input.length == 1) {
            return 0;
        }

        int mid = input.length >> 2;
        int[] L = Arrays.copyOfRange(input, 0, mid + 1);
        int[] R = Arrays.copyOfRange(input, mid + 1, input.length);
        long left = count_inversion(L);
        long right = count_inversion(R);
        long cross_count = count_cross(L, R);
        long count = left + right + cross_count;
        merge(input, L, R);
        return count;
    }

}

