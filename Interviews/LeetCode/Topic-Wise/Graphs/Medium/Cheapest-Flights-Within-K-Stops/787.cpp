#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<vector<int>> adj[n];
		for (auto edge : flights) adj[edge[0]].push_back({edge[1], edge[2]});
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
		vector<vector<int>> distance(n, vector<int> (k + 2, int(1e9)));
		distance[src][0] = 0;
		pq.push({0, src, 0});

		while (!pq.empty()) {
			int dist = pq.top()[0], from = pq.top()[1], stops = pq.top()[2];
			pq.pop();
			if (stops == k + 1) continue;

			for (auto edge : adj[from]) {
				int to = edge[0], price = edge[1];
				if (distance[to][stops + 1] > distance[from][stops] + price) {
					distance[to][stops + 1] = distance[from][stops] + price;
					pq.push({distance[to][stops + 1], to, stops + 1});
				}
			}
		}

		int answer = 1e9;
		for (int i = 0; i <= k + 1; i++) answer = min (answer, distance[dst][i]);
		if (answer == int(1e9)) return -1;
		return answer;
	}
};