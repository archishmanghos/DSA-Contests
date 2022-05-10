#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

template <typename num_t>
using ordered_multiset = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename num_t>
using ordered_multiset_dec = tree<num_t, null_type, greater_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename num_t>
using ordered_set_dec = tree<num_t, null_type, greater<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve() {
    cin >> N;
    ordered_multiset<int> os;
    vector<int> cnt(N + 2, 0);

    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    int ans = 0;
    for(int i = N; i >= 1; i--){
    	ans += os.order_of_key(A[i]) + cnt[A[i]];
    	os.insert(A[i]);
    	cnt[A[i]] += 1;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}