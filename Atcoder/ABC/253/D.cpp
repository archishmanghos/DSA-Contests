#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N, A, B;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> A >> B;
    int sumTillN = N * (N + 1) / 2;
    int termsMultipleOfA = N / A;
    int sumMultiplesOfA = (termsMultipleOfA * (2 * A + (termsMultipleOfA - 1) * A)) / 2;
    int termsMultipleOfB = N / B;
    int sumMultiplesOfB = (termsMultipleOfB * (2 * B + (termsMultipleOfB - 1) * B)) / 2;
    int lcmm = (A * B) / __gcd(A, B);
    int termsMultipleOfAB = N / lcmm;
    int sumMultiplesOfAB = (termsMultipleOfAB * (2 * lcmm + (termsMultipleOfAB - 1) * lcmm)) / 2;
    int ans = sumTillN - (sumMultiplesOfA + sumMultiplesOfB - sumMultiplesOfAB);
    cout << ans;

    return 0;
}