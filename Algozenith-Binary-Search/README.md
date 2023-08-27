<h2>Rotated Sorted Array </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/Rotated-Sorted-Array-106)

<details><summary>Codes </summary>

```c++

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

</details>