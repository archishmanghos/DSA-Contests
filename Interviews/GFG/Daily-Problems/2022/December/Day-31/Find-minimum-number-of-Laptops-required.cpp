#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minLaptops(int N, int start[], int end[]) {
		set<int> s;
		for (int i = 0; i < N; i++) {
			s.insert(start[i]);
			s.insert(end[i]);
		}

		unordered_map<int, int> cc;
		int j = 0;
		for (int i : s) cc[i] = j++;

		vector<int> laptops (j + 2, 0);
		for (int i = 0; i < N; i++) {
			laptops[cc[start[i]]] += 1;
			laptops[cc[end[i]]] -= 1;
		}

		int answer = laptops[0];
		for (int i = 1; i < j; i++) {
			laptops[i] += laptops[i - 1];
			answer = max (answer, laptops[i]);
		}

		return answer;
	}
};