#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> A(N), cnt(N, 0), pos(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		pos[A[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		int pos1 = (i - 1 + N) % N, pos2 = i, pos3 = (i + 1) % N;
		int dist1 = (pos[pos1] > i ? N - (pos[pos1] - i) : i - pos[pos1]);
		int dist2 = (pos[pos2] > i ? N - (pos[pos2] - i) : i - pos[pos2]);
		int dist3 = (pos[pos3] > i ? N - (pos[pos3] - i) : i - pos[pos3]);
		cnt[dist1] += 1, cnt[dist2] += 1, cnt[dist3] += 1;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, cnt[i]);

	cout << ans;
	return 0;
}