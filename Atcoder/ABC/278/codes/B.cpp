#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

string conv(int n) {
	string ans = "";
	while (n > 0) {
		ans += (n % 10) + '0';
		n /= 10;
	}

	while (ans.size() < 2) {
		ans += '0';
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h, m; cin >> h >> m;
	int timeNow = h * 60 + m;
	while (timeNow <= 1439) {
		int ch = timeNow / 60;
		int cm = timeNow % 60;
		string chs = conv(ch), cms = conv(cm);
		swap(chs[1], cms[0]);
		if (chs >= "00" and chs <= "23" and cms >= "00" and cms <= "59") {
			swap(chs[1], cms[0]);
			cout << chs << ' ' << cms << '\n';
			return 0;
		}
		timeNow += 1;
	}

	cout << "00 00";
	return 0;
}