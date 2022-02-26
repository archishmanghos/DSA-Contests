#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/Clion/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0, cnt = 0, sumRepeat = 0, terms = 0, findX;
    set<int> s;
    vector<int> v;
    while (cnt < K) {
        if (s.find(ans % N) != s.end()) {
            findX = ans % N;
            break;
        }
        terms += 1;
        s.insert(ans % N);
        v.push_back(ans % N);
        ans += A[ans % N];
        cnt += 1;
    }

    if (cnt == K) {
        cout << ans << '\n';
        return 0;
    }

    int repeatTerms = 0, add;
    vector<int> v1;
    do {
        add = v.back();
        sumRepeat += A[add];
        v1.push_back(A[add]);
        repeatTerms += 1;
        v.pop_back();
    } while (add != findX);

    reverse(v1.begin(), v1.end());
    ans -= sumRepeat;
    K -= (terms - repeatTerms);

    ans += (K / repeatTerms) * sumRepeat;
    K %= repeatTerms;

    for (int i = 0; i < K; i++) {
        ans += v1[i];
    }

    cout << ans;

    return 0;
}