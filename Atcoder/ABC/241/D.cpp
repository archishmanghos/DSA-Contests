#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/Clion/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;
using namespace __gnu_pbds;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

template<typename num_t>
using ordered_multiset = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename num_t>
using ordered_multiset_dec = tree<num_t, null_type, greater_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename num_t>
using ordered_set_dec = tree<num_t, null_type, greater<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int Q;
    cin >> Q;
    int type, X, K;
    ordered_multiset<int> os;
    unordered_map<int, int> cnt;
    while (Q--) {
        cin >> type;
        if (type == 1) {
            cin >> X;
            cnt[X] += 1;
            os.insert(X);
        } else if (type == 2) {
            cin >> X >> K;
            int elementsLessThanOrEqualToX = 0;
            if (cnt.find(X) != cnt.end()) {
                elementsLessThanOrEqualToX += cnt[X];
            }
            elementsLessThanOrEqualToX += os.order_of_key(X);
            if (elementsLessThanOrEqualToX >= K) {
                int y = elementsLessThanOrEqualToX - K;
                cout << *(os.find_by_order(y)) << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            cin >> X >> K;
            int sz = os.size();
            int elementsGreaterThanOrEqualToX = sz - (int) os.order_of_key(X);
            if (elementsGreaterThanOrEqualToX >= K) {
                int y = sz - elementsGreaterThanOrEqualToX + K - 1;
                cout << *(os.find_by_order(y)) << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}