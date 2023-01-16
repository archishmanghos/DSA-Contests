#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<long long> nextLargerElement(vector<long long> &arr, int n) {
		vector<long long> st, answer (n);
		for (int i = n - 1; i >= 0; i--) {
			while (st.size() > 0 and arr[i] >= st.back()) st.pop_back();
			answer[i] = st.size() ? st.back() : -1ll;
			st.push_back(arr[i]);
		}

		return answer;
	}
};