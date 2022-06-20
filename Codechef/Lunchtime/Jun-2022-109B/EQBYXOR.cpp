#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, A, B, N;

string integertobinary(int x){
	string ans = "";
	while(x > 0){
		ans += (x % 2) + '0';
		x >>= 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string paddedValue(string S, int N){
	string ans = S;
	reverse(ans.begin(), ans.end());

	int N1 = ans.size();
	for(int i = 1; i <= N - N1; i++) ans += '0';
	reverse(ans.begin(), ans.end());
	return ans;
}

int binarytointeger(string x){
	int ans = 0, m = 1;
	for(int i = x.size() - 1; i >= 0; i--){
		ans += (x[i] - '0') * m;
		m <<= 1;
	}
	return ans;
}

void solve() {
	cin >> A >> B >> N;
	string s1 = integertobinary(A), s2 = integertobinary(B);
	int N1 = max(s1.size(), s2.size());
	s1 = paddedValue(s1, N1), s2 = paddedValue(s2, N1);

	vector<int> posPower;
	string totalPower = "";
	for(int i = 0; i < N1; i++){
		if(s1[i] != s2[i]){
			posPower.push_back(N1 - i - 1);
			totalPower += '1';
		}else totalPower += '0';
	}

	int tPower = binarytointeger(totalPower);

	int ans = 0;
	for(int i = 0; i < posPower.size(); i++){
		ans += 1;
		if(tPower < N) break;

		int shouldBeDeducted = (1LL << posPower[i]);
		if(shouldBeDeducted < N) tPower -= shouldBeDeducted;
		else{
			cout << -1 << '\n';
			return;
		}
	}

	cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}