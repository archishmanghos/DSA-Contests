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

bool isPrime(int n)    //primality test
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int count = 0;
    for (int i = A; i <= B; i++) {
        bool possible = false;
        for (int j = C; j <= D; j++) {
            if (isPrime(i + j)) {
                possible = true;
                break;
            }
        }
        if (possible) {
            count += 1;
        }
    }

    cout << (count == (B - A + 1) ? "Aoki" : "Takahashi");

    return 0;
}