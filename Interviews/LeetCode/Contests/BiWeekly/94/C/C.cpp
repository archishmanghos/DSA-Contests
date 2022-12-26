#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
		int64_t lcm = (divisor1 * divisor2) / (__gcd(divisor1, divisor2));

		auto possible = [&](int count) {
			int64_t reqd1 = count - count / divisor1;
			int64_t reqd2 = count - count / divisor2;
			int64_t notReqd = count - count / lcm;
			if (reqd1 >= (int64_t)uniqueCnt1 and reqd2 >= (int64_t)uniqueCnt2 and notReqd >= uniqueCnt1 + uniqueCnt2) return 1;
			return 0;
		};

		int low = 0, high = 30, ans = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (possible(mid)) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return ans;
	}
};