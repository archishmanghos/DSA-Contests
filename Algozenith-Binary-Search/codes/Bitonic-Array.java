package Algozenith.Binary_Search;

import java.util.Scanner;

public class Bitonic_Array {
    public static void main(String[] semicolonised) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (; T > 0; T--) solve();
    }

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), Q = sc.nextInt();

        int pivot = N;
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            if (pivot == N && i > 0 && A[i] < A[i - 1]) pivot = i;
        }

        for (; Q > 0; Q--) {
            int K = sc.nextInt();
            int low = 0, high = pivot - 1, answer = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] == K) {
                    answer = mid + 1;
                    break;
                }
                if (A[mid] < K) low = mid + 1;
                else high = mid - 1;
            }

            if (answer != -1) System.out.printf("%d ", answer);
            low = pivot;
            high = N - 1;
            answer = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] == K) {
                    answer = mid + 1;
                    break;
                }
                if (A[mid] > K) low = mid + 1;
                else high = mid - 1;
            }

            if (answer != -1) System.out.printf("%d", answer);
            System.out.println();
        }
    }
}
