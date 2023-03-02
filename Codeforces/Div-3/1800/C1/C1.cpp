#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, A[200200];

void solve() {
	cin >> N;
	vector<int> st;
	int answer = 0, zeroes = 0;
	for (int i = 0; i < N; i++) cin >> A[i];

	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		if (A[i]) {
			pq.push(A[i]);
		}
		else {
			if (!pq.empty()) {
				answer += pq.top();
				pq.pop();
			}
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}