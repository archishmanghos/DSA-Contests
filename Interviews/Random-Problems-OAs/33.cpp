#include <bits/stdc++.h>
#define int long long
using namespace std;

long long min_time(int N, vector<int> &work) {
	vector<int> A(N);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		A[i] = (work[i] - i - 1);
		answer += abs(A[i]);
	}

	sort(A.begin(), A.end());
	unordered_map<int, int> ump;
	for (int i = 0; i < N; i++) ++ump[A[i]];
	int pref[N];
	pref[0] = A[0];
	for (int i = 1; i < N; i++) pref[i] = A[i] + pref[i - 1];

	for (int i = 0; i < N; i++) {
		auto ub = [&](int val) {
			int answer = N, low = 0, high = N - 1;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (A[mid] > val) {
					answer = mid;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}

			return answer;
		};

		int idx = ub(A[i]);
		int cnt = (ump.find(A[i]) != ump.end() ? ump[A[i]] : 0);
		long long left = idx * A[i] - pref[idx - 1];
		long long right = (pref[N - 1] - pref[idx - 1]) - (N - idx) * A[i];

		answer = min(answer, (left + right));
	}

	return answer;
}