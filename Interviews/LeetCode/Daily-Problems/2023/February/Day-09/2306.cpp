#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long distinctNames(vector<string>& ideas) {
		set<string> adj[26];
		for (string idea : ideas) {
			adj[idea[0] - 'a'].insert(idea.substr(1));
		}

		long long answer = 0;
		for (int i = 0; i < 26; i++) {
			for (int j = i + 1; j < 26; j++) {
				int x = adj[i].size(), y = adj[j].size();
				if (x == 0 or y == 0) continue;
				for (string k : adj[i]) {
					if (adj[j].find(k) != adj[j].end()) {
						x -= 1;
						y -= 1;
					}
				}
				answer += x * y * 2;
			}
		}

		return answer;
	}
};