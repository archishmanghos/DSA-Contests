#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;
using namespace __gnu_pbds;

template <typename num_t>
using ordered_multiset = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, A[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	vector<int> curCnt(mxN, 0), totCnt(mxN, 0);
	ordered_multiset<int> os;

	for(int i = 1; i <= N; i++){
		cin >> A[i];
		totCnt[A[i]] += 1;
	}

	sort(A + 1, A + N + 1);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		curCnt[A[i]] += 1;
		int lessThan = os.order_of_key(A[i]);
		int greaterThan = N - (i - curCnt[A[i]] + totCnt[A[i]]);
		ans += lessThan * greaterThan;
		os.insert(A[i]);
	}

	cout << ans << '\n';

    return 0;
}