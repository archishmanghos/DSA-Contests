#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int n;

bool check2(int n) {
	while (n > 0) {
		if (n % 10 == 2) return true;
		n /= 10;
	}
	return false;
}

string num(int n) {
	string ans = "";
	while (n > 0) {
		ans += ((n % 10) + '0');
		n /= 10;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

bool check14(int n) {
	string ans = num(n);
	for (int i = 0; i < ans.size() - 1; i++){
		if (ans[i] == '1' and ans[i + 1] == '4') return true;
	}
	return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

	cin >> n;

	int i = 0, cnt = 0;
	while (1) {
		++i;
		if (check2(i)) continue;
		else if (i > 9 and check14(i)) continue;
		cnt += 1;
		if (cnt == n) break;
	}

	cout << i << '\n';

    return 0;
}