#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int solution(vector<int> &A, int X, int Y) {
	int answer = INT_MAX, N = A.size();
	for (int i = 0; i + Y < N; i++) {
		priority_queue<int> pq;
		for (int j = i; j < N; j += Y) {
			pq.push(A[j]);
			if (pq.size() > X) pq.pop();
		}

		if (pq.size() == X) {
			int sum = 0;
			while (!pq.empty()) {
				sum += pq.top();
				pq.pop();
			}
			answer = min(answer, sum);
		}
	}

	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, X, Y; cin >> N >> X >> Y;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	cout << solution(A, X, Y);
	return 0;
}