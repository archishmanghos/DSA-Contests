#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

long getMaximumScore(vector<int> &stockPrice) {
	int n = stockPrice.size();
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = stockPrice[i] - i;

	unordered_map<int, long> mp;
	for (int i = 0; i < n; i++) mp[a[i]] += stockPrice[i];

	long answer = 0;
	for (auto it : mp) answer = max(answer, it.second);
	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	cout << getMaximumScore(A);
	return 0;
}