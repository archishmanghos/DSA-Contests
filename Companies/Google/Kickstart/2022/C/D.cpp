#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e9 + 7;

int T, N;
string S;

bool checkPal(string x){
	string y = x;
	reverse(y.begin(), y.end());
	return x == y;
}

void rec(string s, int &rotation, int &totalPal){
	if(s.size() == 0) {
		rotation++;
		return;
	}
	
	for(int i = 0; i < s.size(); i++){
		string newS = s.substr(0, i);
		if(i + 1 < s.size()) newS += s.substr(i + 1);
		rec(newS, rotation, totalPal);
		totalPal += checkPal(newS);
	}
}

int modexp(int x, int n, int m = INF){
    if (n == 0) return 1;
    else if (n % 2 == 0) return modexp((x * x) % m, n / 2);
    else return (x * modexp((x * x) % m, (n - 1) / 2) % m);
}

void solve() {
    cin >> N >> S;
    int rotation = 0, totalPal = 0;
    rec(S, rotation, totalPal);
    int gcdd = __gcd(totalPal, rotation);
    cerr << totalPal << ' ' << rotation << '\n';
    totalPal /= gcdd, rotation /= gcdd;
    int d = modexp(rotation, INF - 2);
    int ans = ((totalPal % INF) * (d % INF)) % INF;
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}