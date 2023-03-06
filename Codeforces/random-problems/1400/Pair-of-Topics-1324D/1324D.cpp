#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define i64 int64_t
using namespace __gnu_pbds;

template <typename num_t>
using ordered_multiset = tree<num_t, null_type, std::less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	int A[N + 2]; for (int i = 1; i <= N; i++) std::cin >> A[i];
	int B[N + 2]; for (int i = 1; i <= N; i++) std::cin >> B[i];

	ordered_multiset<int> oms;
	i64 answer = 0;
	for (int i = N; i >= 1; i--) {
		answer += 0ll + oms.order_of_key(A[i] - B[i]);
		oms.insert(B[i] - A[i]);
	}

	std::cout << answer;
	return 0;
}