#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

vector<int> funcArrange(vector<int> inputArr) {
	vector<int> answer, even, odd;
	for (int i : inputArr) {
		if (i % 2) {
			odd.push_back(i);
		} else {
			even.push_back(i);
		}
	}

	for (int i : even) {
		answer.push_back(i);
	}
	for (int i : odd) {
		answer.push_back(i);
	}

	return answer;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> ans = funcArrange(arr);
	for (int i : ans) {
		cout << i << ' ';
	}
	return 0;
}