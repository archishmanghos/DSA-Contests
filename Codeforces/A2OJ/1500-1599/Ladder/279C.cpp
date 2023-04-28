#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	bool incr = true;
	int i = 0, pre = -1, l = 0, cnt = 0;
	vector<pair<int, int>> v;

	while (i < N) {
		if (incr) {
			if (A[i] < pre) {
				incr = false;
				cnt = 1;
			}
		} else {
			if (A[i] == pre) cnt++;
			else if (A[i] < pre) cnt = 1;
			if (A[i] > pre) {
				v.push_back({l, i - 1});
				l = i - cnt;
				incr = true;
			}
		}
		pre = A[i];
		i++;
	}

	v.push_back({l, N - 1});

	while (M--) {
		int L, R; cin >> L >> R; L--, R--;
		if (R - L + 1 <= 2) {
			cout << "Yes" << '\n';
			continue;
		}

		auto f = [&]() -> int {
			int low = 0, high = v.size() - 1, answer = -1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (v[mid].first <= L) {
					answer = mid;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}

			return answer;
		};

		int idx = f();
		if (idx == -1) {
			cout << "No" << '\n';
		} else {
			if (v[idx].first <= L and v[idx].second >= R) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}

	return 0;
}