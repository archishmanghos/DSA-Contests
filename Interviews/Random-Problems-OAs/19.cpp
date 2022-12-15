#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int max_gangsters_arrested(string inp_string, int distance_police_can_catch) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < inp_string.size(); i++) {
		if (inp_string[i] == 'G') {
			pq.push(i);
		}
	}

	int ans = 0;
	for (int i = 0; i < inp_string.size(); i++) {
		if (inp_string[i] == 'P') {
			while (pq.size() > 0) {
				if (i - pq.top() > distance_police_can_catch) {
					pq.pop();
				} else if (pq.top() - i > distance_police_can_catch) {
					break;
				} else {
					ans += 1;
					pq.pop();
					break;
				}
			}
		}
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int d;
	cin >> s >> d;
	cout << max_gangsters_arrested(s, d);
	return 0;
}