#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

string integerToString (int x) {
	if (x == 0) return "0";
	string answer = "";
	while (x) {
		answer += (x % 10) + '0';
		x /= 10;
	}

	reverse(answer.begin(), answer.end());
	return answer;
}

void solve() {
	int N; cin >> N;
	int a = N / 2, b = (N + 1) / 2;

	auto sod = [](int n) {
		int answer = 0;
		while (n > 0) {
			answer += n % 10;
			n /= 10;
		}

		return answer;
	};

	int suma = sod(a), sumb = sod(b);
	if (abs(suma - sumb) <= 1) cout << a << ' ' << b << '\n';
	else {
		int diff = abs(suma - sumb);
		diff >>= 1;

		string aa = integerToString(a), bb = integerToString(b);
		int d = diff;
		for (int i = aa.size() - 1; i >= 0; i--) {
			int x = aa[i] - '0';
			int minn = min(d, x);
			x -= minn;
			d -= minn;
			aa[i] = (x + '0');
			if (d == 0) break;
		}

		d = diff;
		for (int i = bb.size() - 1; i >= 0; i--) {
			int x = bb[i] - '0';
			int minn = min(d, 9 - x);
			x += minn;
			d -= minn;
			bb[i] = (x + '0');
			if (d == 0) break;
		}

		cout << aa << ' ' << bb << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}