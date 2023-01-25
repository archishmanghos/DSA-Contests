#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		vector<int> distance (edges.size(), -1), vis (edges.size(), 0);
		int dist = 0;
		while (node1 != -1 and !vis[node1]) {
			distance[node1] = dist;
			vis[node1] = 1;
			node1 = edges[node1];
			dist += 1;
		}

		vector<int> answer(2, int(1e9));
		vis.assign(edges.size(), 0);
		dist = 0;
		while (node2 != -1 and !vis[node2]) {
			if (distance[node2] != -1) {
				int tDist = max (dist, distance[node2]);
				if (tDist <= answer[0]) {
					if (tDist == answer[0]) answer[1] = min (answer[1], node2);
					else answer = {tDist, node2};
				}
			}
			vis[node2] = 1;
			node2 = edges[node2];
			dist += 1;
		}

		return (answer[0] != int(1e9) ? answer[1] : -1);
	}
};