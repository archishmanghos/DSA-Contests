#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE

// #include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

// #else
// #define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, A, B;

bool check(int X){
	int pro = 1, sum = 0;
	while(X){
		pro *= (X % 10);
		sum += (X % 10);
		X /= 10;
	}
	return (pro % sum == 0);
}

void solve()
{
	cin >> A >> B;
	int ans = 0;
	for(int i = A; i <= B; i++){
		ans += check(i);
	}

	cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("error.txt", "w", stderr);
    // #endif

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
