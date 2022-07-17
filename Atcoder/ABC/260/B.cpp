#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int N, X, Y, Z, A[mxN], B[mxN];

bool comp1(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
	if (a.second.first != b.second.first) {
		return a.second.first < b.second.first;
	}
	return a.first > b.first;
}

bool comp2(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
	if (a.second.second != b.second.second) {
		return a.second.second < b.second.second;
	}
	return a.first > b.first;
}

bool comp3(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
	if ((a.second.first + a.second.second) != (b.second.first + b.second.second)) {
		return (a.second.first + a.second.second) < (b.second.first + b.second.second);
	}
	return a.first > b.first;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	vector<pair<int, pair<int, int>>> v;
	cin >> N >> X >> Y >> Z;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}

	for (int i = 1; i <= N; i++) {
		v.push_back({i, {A[i], B[i]}});
	}

	sort(v.begin(), v.end(), comp1);
	set<int> a;
	int cnt = 0;
	while (cnt < X) {
		a.insert(v.back().first);
		v.pop_back();
		cnt += 1;
	}

	sort(v.begin(), v.end(), comp2);
	cnt = 0;
	while (cnt < Y) {
		a.insert(v.back().first);
		v.pop_back();
		cnt += 1;
	}

	sort(v.begin(), v.end(), comp3);
	cnt = 0;
	while (cnt < Z) {
		a.insert(v.back().first);
		v.pop_back();
		cnt += 1;
	}

	for (int i : a) cout << i << '\n';

	return 0;
}