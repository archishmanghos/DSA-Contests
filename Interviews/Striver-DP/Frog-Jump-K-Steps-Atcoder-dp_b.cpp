#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N, K; cin >> N >> K;
    vector<int> H(N), cache(N, INT_MAX);
    for (int i = 0; i < N; i++) cin >> H[i];

    cache[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= (i + K) and j < N; j++) {
            cache[j] = min(cache[j], cache[i] + abs(H[j] - H[i]));
        }
    }

    cout << cache[N - 1];

    return 0;
}