#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
		int buses = routes.size(), busStops = 0;
		for (auto v : routes) busStops = max(busStops, *max_element(v.begin(), v.end()) + 1);

		map<int, vector<int>> busMap;
		for (int i = 0; i < buses; i++) {
			for (int j : routes[i]) busMap[j].push_back(i);
		}

		queue<vector<int>> q;
		q.push({source, 0});
		int doneBus[buses], doneStops[busStops];
		memset(doneBus, 0, sizeof(doneBus));
		memset(doneStops, 0, sizeof(doneStops));
		doneStops[source] = 1;

		while (!q.empty()) {
			int sz = q.size();
			for (int i = 1; i <= sz; i++) {
				auto it = q.front(); q.pop();
				int busStop = it[0], busCount = it[1];
				if (busStop == target) return busCount;

				for (int b : busMap[busStop]) {
					if (doneBus[b]) continue;
					doneBus[b] = 1;
					for (int stops : routes[b]) {
						if (doneStops[stops]) continue;
						doneStops[stops] = 1;
						q.push({stops, busCount + 1});
					}
				}
			}
		}

		return -1;
	}
};