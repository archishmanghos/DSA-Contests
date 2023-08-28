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

</details>

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

</details>

<br>
<br>

<h2>Minimise Max Diff </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/Minimise-Max-Diff-46)

<details><summary>Codes </summary>

```c++

// c++

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
    if (A[0] == A[N - 1]) {
        cout << 0 << '\n';
        return;
    }

    int low = 1, high = 1e9 + 7, answer = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto check = [&]() {
            int insertions = 0;
            for (int i = 1; i < N; i++) insertions += (A[i] - A[i - 1] - 1) / mid;
            return insertions <= K;
        };

        if (check()) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
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

</details>

<br>
<br>

<h2>Consecutive one </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/Consecutive-one-44)

<details><summary>Codes </summary>

```c++

// c++

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    int A[N], allzero = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        allzero &= A[i] == 0;
    }

    if (allzero and K == 0) {
        cout << 0 << '\n';
        return;
    }

    int low = 1, high = N, answer = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto check = [&]() {
            int zero = 0, i = 0, min_change = 1e9;
            for ( ; i < mid - 1; i++) zero += A[i] == 0;

            while (i < N) {
                zero += A[i++] == 0;
                min_change = min(min_change, zero);
                zero -= A[i - mid] == 0;
            }

            return min_change <= K;
        };

        if (check()) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
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

</details>

<br>
<br>

<h2>ClassRoom </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/ClassRoom-448)

<details><summary>Codes </summary>

```c++

// c++

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A + N);
    int low = 1, high = A[N - 1] - A[0], answer = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto check = [&]() {
            int pre = A[0], i = 1, students = 1;
            while (i < N) {
                if (A[i] - pre >= mid) {
                    students++;
                    pre = A[i];
                }
                i++;
            }

            return students >= K;
        };

        if (check()) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
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

</details>

<br>
<br>

<h2>Famous Painter Partition Problem </h2>

[Link to Problem](https://www.learning.algozenith.com/problems/Famous-Painter-Partition-Problem-449)

<details><summary>Codes </summary>

```c++

// c++

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

    int low = 1, high = accumulate(A, A + N, 0ll), answer = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto check = [&]() {
            int sum = 0, i = 0, painters = 1;
            while (i < N) {
                sum += A[i];
                if (sum > mid) {
                    sum = A[i];
                    if (sum > mid) return false;
                    painters++;
                }
                i++;
            }

            return painters <= K;
        };

        if (check()) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
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

</details>