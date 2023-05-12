#include <bits/stdc++.h>
#define int long long
using namespace std;

long long solve(int Q, vector<vector<int>> &pairs, int N, vector<int> &A) {
	unordered_map<int, int> mp, count;
	for (auto i : pairs) mp[i[0]] = i[1];

	long long answer = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (mp.find(A[i]) != mp.end()) answer += count[mp[A[i]]];
		++count[A[i]];
	}

	return answer;
}