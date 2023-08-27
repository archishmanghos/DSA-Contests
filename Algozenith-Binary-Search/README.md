<h2>Rotated Sorted Array </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/Rotated-Sorted-Array-106)

<details><summary>Codes </summary>

```c++

// c++

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

    int low = 0, high = N - 1, answer = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] < A[0]) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << (answer == -1 ? 0 : answer) << '\n';
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--)
        solve();
    return 0;
}

```

```java

// java

package Algozenith.Binary_Search;

import java.util.Scanner;

public class Rotated_Sorted_Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (; T > 0; T--) {
            int N = sc.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; i++) A[i] = sc.nextInt();

            int low = 0, high = N - 1, answer = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] < A[0]) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            System.out.println(answer == -1 ? 0 : answer);
        }
    }
}

```

< / details >

<br>
<br>

<h2>Bitonic Array </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/Bitonic-Array-105)

<details><summary>Codes </summary>

```c++

// c++

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, Q; cin >> N >> Q;
    int pivot = N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (pivot == N and i > 0 and A[i] < A[i - 1]) pivot = i;
    }

    while (Q--) {
        int K; cin >> K;
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

        if (answer != -1) cout << answer << ' ';
        low = pivot, high = N - 1, answer = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == K) {
                answer = mid + 1;
                break;
            }
            if (A[mid] > K) low = mid + 1;
            else high = mid - 1;
        }

        if (answer != -1) cout << answer;
        cout << '\n';
    }
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--)
        solve();
    return 0;
}

```

```java

// java

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

```

< / details >