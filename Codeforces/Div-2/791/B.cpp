#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N, Q, type, ind, x, A[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    int currentSum = 0;
    pair<int, int> lastArrayChange = {-1, -1};
	map<int, pair<int, int>> lastChange;

    for(int i = 1; i <= N; i++) {
    	cin >> A[i];
    	currentSum += A[i];
    	lastChange[i] = {0, A[i]};
    }

	for(int i = 1; i <= Q; i++){
		cin >> type;
		if(type == 1){
			cin >> ind >> x;
			if(lastChange[ind].first > lastArrayChange.first) {
				currentSum += (x - lastChange[ind].second);
			} else {
				currentSum += (x - lastArrayChange.second);
			}
			lastChange[ind] = {i, x};
		}else {
			cin >> x;
			currentSum = x * N;
			lastArrayChange = {i, x};
		}

		cout << currentSum << '\n';
	}

    return 0;
}