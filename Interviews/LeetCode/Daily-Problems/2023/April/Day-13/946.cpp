#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int i = 0, j = 0;
		vector<int> st;
		while (i < pushed.size() and j < popped.size()) {
			if (i < pushed.size() and (st.size() == 0 or (st.size() > 0 and st.back() != popped[j]))) {
				st.push_back(pushed[i++]);
				continue;
			}
			if (j < popped.size() and st.size() > 0 and st.back() == popped[j]) {
				st.pop_back();
				j++;
				continue;
			}

			return false;
		}

		while (j < popped.size() and st.size() > 0 and st.back() == popped[j]) {
			st.pop_back();
			j++;
		}

		return (i == pushed.size() and j == popped.size());
	}
};