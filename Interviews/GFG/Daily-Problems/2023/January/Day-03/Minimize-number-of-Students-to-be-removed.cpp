#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeStudents(int H[], int N) {
		vector<int> lis;
		for (int i = 0; i < N; i++) {
			if (lis.size() == 0 or H[i] > lis.back()) lis.push_back(H[i]);
			else {
				int lbIdx = lower_bound (lis.begin(), lis.end(), H[i]) - lis.begin();
				lis[lbIdx] = H[i];
			}
		}

		return N - (int)lis.size();
	}
};